//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

class Actions {
public:
    static void open();
    static void setWindowFullscreen();
    static void seekBack();
    static void seekForward();
private:
	static bool maximized;
};
