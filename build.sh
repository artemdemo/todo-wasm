#!/bin/bash

# `ccall` and `cwrap` are preamble.js methods and you need to export them in order to use
# @link https://kripken.github.io/emscripten-site/docs/api_reference/preamble.js.html

emcc ./c/main-wasm.c \
     ./c/todoModel.c \
     -s WASM=1 \
     -O3 \
     -s 'EXTRA_EXPORTED_RUNTIME_METHODS=["ccall", "cwrap"]' \
     -o build/todo.js
