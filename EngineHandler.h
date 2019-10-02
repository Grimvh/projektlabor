#pragma once

#include <iostream>
#include <QObject>
#include <string.h>

#include "Engine.h"

class EngineHandler : public QObject {
	Q_OBJECT

public:
	EngineHandler();
public slots:
	void addEngineSlot(QList<int> data, std::string mode, int uuid);
	void listEnginesSlot();
private:
	QList<Engine*> engines;
};
