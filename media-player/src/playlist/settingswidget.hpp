//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QFrame>
#include <QVBoxLayout>

class PlaylistSettingsWidget : public QFrame {
	Q_OBJECT
public:
	PlaylistSettingsWidget();
	~PlaylistSettingsWidget();
private:
	QVBoxLayout *layout;
	void initStructDefaults();
private slots:
	void onSaveButtonClicked();
	void onOpenButtonClicked();
	void onInOrderToggled();
	void onRandomlyToggled();
}; 
