# Having fun with C

I'm using [c/c++ plugin for VS Code](https://code.visualstudio.com/docs/languages/cpp)

## How to build code?

Just hit ⇧⌘B (Shift+Command+B) - and compiler will build executable binaries.

Then you just need to run `$ ./a.out`

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

## Tutorials

* https://www.youtube.com/watch?v=-CpG3oATGIs (4:38:52) - basic tutorial; use x2 speed, otherwise it's unbearable.

## Lynda courses

* [C Essential Training](https://www.lynda.com/C-tutorials/C-Essential-Training/164457-2.html)
