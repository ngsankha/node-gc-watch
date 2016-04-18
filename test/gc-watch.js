var should = require('should');
var gcWatch = require('../src/gc-watch');

describe('the library', function() {
  it('should export a couple of functions', function() {
    should.exist(gcWatch.on);
    should.exist(gcWatch.once);
    should.exist(gcWatch.removeAllListeners);
  });
});

describe('setting event handlers', function() {
  it('raises beforeGC event', function() {
    var beforeGCTime;
    gcWatch.once('beforeGC', function() {
      beforeGCTime = Date.now();
    });
    var beforeGCFired = Date.now();
    global.gc();
    Date.now().should.be.above(beforeGCTime);
    beforeGCTime.should.be.aboveOrEqual(beforeGCFired);
  });

  it('raises afterGC event', function() {
    var afterGCTime;
    gcWatch.once('afterGC', function() {
      afterGCTime = Date.now();
    });
    var beforeGCFired = Date.now();
    global.gc();
    Date.now().should.be.aboveOrEqual(afterGCTime);
    afterGCTime.should.be.above(beforeGCFired);
  });
});
