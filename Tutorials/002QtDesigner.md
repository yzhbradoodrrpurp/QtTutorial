# Qt Designer

## Introduction

使用 Qt Designer 能够图形化地编辑界面，而不用一个一个地敲 C++ 代码。由于我并没有安装 Qt Creator，而是通过 `brew install qt` 安装的 Qt 包，所以我需要手动地找到 Qt Creator。

## How to Find It

1. 打开 Terminal，输入 `brew --prefix qt` 找到 Qt 的安装路径。
2. 在 Qt 的安装路径后加上 `./bin/designer` 就是 Qt Designer 的路径。
3. 在命令行中输入 `path-to-qt/bin/designer` 就能打开 Qt Designer。

## How to Design It

有很多教程，非常直观，不再赘述。

## How to Save It

1. 设计完成后保存为 .ui 文件。
2. 在 C++ 中引入 .ui 文件对应的 .h 文件 `#include "ui_<ui 文件名>.h"`