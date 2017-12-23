#!/bin/bash

# `ccall`, `cwrap` and `Pointer_stringify` are preamble.js methods and you need to export them in order to use
# @link https://kripken.github.io/emscripten-site/docs/api_reference/preamble.js.html
emcc ./c/main-wasm.c \
     ./c/todoModel.c \
     ./c/format.c \
     -s WASM=1 \
     -O3 \
     -s 'EXTRA_EXPORTED_RUNTIME_METHODS=["ccall", "cwrap", "Pointer_stringify"]' \
     -o build/todo.js
