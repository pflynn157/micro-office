## Media Player
CppMediaPlayer is a simple media player written in C++. It uses the Qt library for the GUI and multimedia playback.

### Dependencies
CppMediaPlayer requires the following build and runtime dependencies:
* Qt Core
* Qt Widgets
* Qt Gui
* Qt Multimedia
* Qt MultimediaWidgets

To build, you need a C++ compiler and cmake. Simply create a build folder, move into it, and run cmake and make.

### Note to Windows users:
If you have trouble with the player not starting playback, you may have to install the K-Lite codecs. The basic package will work fine. They can be downloaded from here:
https://www.codecguide.com/download_k-lite_codec_pack_basic.htm


### Note with merger into Micro Desktop

The switch from Qt5 to Qt6 apparently changed a lot in the multimedia layer, so this is not fully updated. It will build and run with Qt6, and it seems to play audio and video back just fine, but some features aren't working. I might update them at a future date, but for now I just wanted to get the project integrated.

