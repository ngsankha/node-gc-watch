var should = require('should');
var gcWatch = require('../src/gc-watch');

describe('the library', function() {
  it('should export a couple of functions', function() {
    should.exist(gcWatch.on);
    should.exist(gcWatch.once);
    should.exist(gcWatch.removeAllListeners);
  });
});
