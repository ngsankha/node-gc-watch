{
  "targets": [
    {
      "target_name": "gc-watch-impl",
      "sources": [ "src/gc-watch.cc" ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
      ]
    }
  ]
}
