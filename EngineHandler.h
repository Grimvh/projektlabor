#pragma once

#include <iostream>
#include <QObject>
#include <string.h>

class EngineHandler : public QObject {
	Q_OBJECT

public:
	EngineHandler();
public slots:
	void addEngineSlot();
	void printEnginesSlot();
private:
	QList<std::string> engines;
	void addToEngineList();
	void listEngines();
};
