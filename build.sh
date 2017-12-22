#!/bin/bash

emcc todoModel.c -s WASM=1 -O3 -o build/index.js