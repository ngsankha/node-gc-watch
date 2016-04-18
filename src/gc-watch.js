var EventEmitter = require('events').EventEmitter;
var util = require('util');
var GCWatchImpl = require('bindings')('gc-watch-impl');

function GCWatch() {
  EventEmitter.call(this);
}
util.inherits(GCWatch, EventEmitter);

var gcWatch = new GCWatch();

GCWatchImpl.beforeGC(function() {
  gcWatch.emit('beforeGC');
});

GCWatchImpl.afterGC(function() {
  gcWatch.emit('afterGC');
});

module.exports = gcWatch;
