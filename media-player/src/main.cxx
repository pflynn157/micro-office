// Copyright 2017 Patrick Flynn
//
// Redistribution and use in source and binary forms, with or without modification,
// are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice,
//	this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice, this
//	list of conditions and the following disclaimer in the documentation and/or
//	other materials provided with the distribution.
//
// 3. Neither the name of the copyright holder nor the names of its contributors may
//	be used to endorse or promote products derived from this software
//	without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
// IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
// INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
// NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
// EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#include <QApplication>
#include <QCoreApplication>
#include <QPixmap>
#include <QMediaContent>
#include <cpplib/settings.hh>

#include "window.hh"
#include "videopane.hh"
#include "global.hh"

using namespace CppLib;
Vars globalVars;

int main(int argc, char *argv[]) {
    Settings::registerApp("cpp-media-player");
    Settings::setDefaultSettingsFile(":/rsc/settings.xml");
    Settings::initPaths();

    QApplication app(argc,argv);

    QCoreApplication::setOrganizationName("CppMediaPlayer");
    QCoreApplication::setApplicationName("CppMediaPlayer");

    globalVars.window = new Window();
    globalVars.window->showMaximized();

    if (argc>1) {
        QString entry = argv[1];
        VideoPane::player->setMedia(QMediaContent(QUrl::fromLocalFile(entry)));
        VideoPane::startPlaying();
    }

    return app.exec();
}
