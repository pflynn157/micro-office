## CppSheets

### Introduction

CppSheets is a simple spreadsheet application that I work on as a hobby project.

### Features

Some of our features:
* Basic formatting (bold, italic, underline text; cell background color; text color; cell borders)
* Cell merge
* Custom XML-based file format
* Basic xlsx (MS Excel) support
* CSV loading support
* Formula support (which is fairly good)
* Basic graphing support

### Building

Building is very easy; the only external dependency required is Qt6 (Core, Widgets, Gui). To build, simply run CMake and Make. It should work without any issues on Windows and MacOS. However, I have not tested it in a long time.


### Licensing

CppSheets is in the public domain.

The following built-in libraries are licensed as follows:
* The built-in TinyXML2 library is licensed under the zlib license.
* The xlnt library is licensed under MIT.
* The KDE icons are licensed under LGPL.

