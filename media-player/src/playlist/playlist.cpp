//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#include "playlist.hpp"
#include "listwidget.hpp"
#include "settingswidget.hpp"

PlayList::PlayList() {
    this->setWindowTitle("Playlist");

	tabs = new QTabWidget;
    this->setWidget(tabs);
	
	tabs->addTab(new PlayListWidget,"Playlist");
	tabs->addTab(new PlaylistSettingsWidget,"Settings");
}

PlayList::~PlayList() {
} 
