# ToDo - WASM

On Mac

* Install `git`
* Install `XCode`
* Install `Python 2.7.x`
* Install `CMAKE`
    `brew install cmake`
* Install `emscripten`
    https://kripken.github.io/emscripten-site/docs/getting_started/downloads.html

For other OS look here: https://developer.mozilla.org/en-US/docs/WebAssembly/C_to_wasm

## How to build wasm?

First make sure that PATH and other environment variables are set up.
After running `source ./emsdk_env.sh` in your `emscripten sdk` folder.

Now you can build it:

```
$ npm run build
```

## How to build code? (separately from emcc)

Just hit ⇧⌘B (Shift+Command+B) - and compiler will build executable binaries.

Then you just need to run `$ ./program.out`

Main configuration is in `.vscode/tasks.json` Notice some important things:

* Code will be build for debugging (`-g` flag in `args` array). You should remove it if you want to build it without this feature.
* In order to *debug* this code you'll need to open debug tab and run it from there.
* Which builded file to run on debug defined here: `.vscode/launch.json`
* Breakpoints work, you need to rebuild app after placing them.

## g++ args

Open `.vscode/tasks.json`:

```js
{
    "tasks": [
        {
            //...
            "args": [
                // Which standart to use
                "-std=c11",
                // Generate source level debug information
                // (remove this flag for production ready code)
                "-g",
                // Input language (c++ is default)
                "-x",
                "c",
                // Output file name
                "-o",
                "program.out",
                // Main app
                "main.c",
                // Module, you need to add it manually here,
                // if you're importing it in your main app
                "myLibary.c"
            ],
            // ...
        }
    ]
} 
```

## launch.json

This file contains settings for debuggin

```js
{
    "configurations": [
        {
            // External console is important.
            // For instance when you debuggin `scanf` (and `externalConsole` is `false` )
            // debug mode will stop working on input
            "externalConsole": true,
            // ...
        }
    ]
} 
```
