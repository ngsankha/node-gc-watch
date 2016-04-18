# node-gc-watch

`node-gc-watch` helps you attach your own event handlers to track when a GC is being fired in your Node.js application. Currently it provides a `beforeGC` and `afterGC` event.

### Installation

```
npm install gc-watch --save
```

### Usage

```js
var gcWatch = require('gc-watch');

gcWatch.on('beforeGC', function() {
  // detect memory usage, push stats etc.
});

gcWatch.on('afterGC', function() {
  // calculate memory freed by GC, etc.
});
```

### License

MIT
