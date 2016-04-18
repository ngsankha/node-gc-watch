#include <nan.h>

using namespace v8;

Nan::Persistent<Function> beforeGCCallback;
Nan::Persistent<Function> afterGCCallback;

NAN_GC_CALLBACK(beforeGC) {
  Nan::HandleScope scope;
  Nan::MakeCallback(Nan::GetCurrentContext()->Global(), Nan::New(beforeGCCallback), 0, NULL);
}

NAN_GC_CALLBACK(afterGC) {
  Nan::HandleScope scope;
  Nan::MakeCallback(Nan::GetCurrentContext()->Global(), Nan::New(afterGCCallback), 0, NULL);
}

NAN_METHOD(SetBeforeGCCallback) {
  if (info.Length() == 1 && info[0]->IsFunction()) {
    beforeGCCallback.Reset(info[0].As<Function>());
    Nan::AddGCPrologueCallback(beforeGC, kGCTypeMarkSweepCompact);
  }
}

NAN_METHOD(SetAfterGCCallback) {
  if (info.Length() == 1 && info[0]->IsFunction()) {
    afterGCCallback.Reset(info[0].As<Function>());
    Nan::AddGCEpilogueCallback(afterGC, kGCTypeMarkSweepCompact);
  }
}

NAN_MODULE_INIT(Init) {
  Local<Function> cb_beforeGC = Nan::GetFunction(Nan::New<FunctionTemplate>(SetBeforeGCCallback)).ToLocalChecked();
  Nan::Set(target, Nan::New("beforeGC").ToLocalChecked(), cb_beforeGC);

  Local<Function> cb_afterGC = Nan::GetFunction(Nan::New<FunctionTemplate>(SetAfterGCCallback)).ToLocalChecked();
  Nan::Set(target, Nan::New("afterGC").ToLocalChecked(), cb_afterGC);
}

NODE_MODULE(gc_watch_impl, Init)
