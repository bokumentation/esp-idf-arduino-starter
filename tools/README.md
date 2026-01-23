# Some usefull tools

## `clangd` and `clang-format`

This is my `clangd` and `clang-format` configuration that i use in all operating system that i have.
For those who dont know, `clangd` is LSP that gives you code navigation, drop down code completion. `clang-format` are formatter for making your code pretty.

How to use it:
- Just copy the `.clang-format` and `.clangd` to the project's root folder.

ESP-IDF V5.5.1 still uses clang-18 if i not mistaken. I need my vscode can render exactly Doxygen format like the builtin intellisense. So in my machine, i installed clangd-22 then in vscode configuration, i added the clangd path `/usr/bin/clangd-22`.

I created workspace configuration `./.vscode/settings.json` look like this.
```json
{
    "clangd.path": "clangd-22",
}
```

## Python script for parsing serial port data

You can use python `pyserial` library to access ESP32 via serial port on your computer.
