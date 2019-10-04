#pragma once

#include <iostream>
#include <QObject>
#include <QList>
#include <QString>
#include <QDebug>
#include <QThread>

#include "Engine.h"

class EngineHandler : public QThread {
	Q_OBJECT
public:
	EngineHandler();
	~EngineHandler();
private:
	QList<Engine*> engines;
	Engine *engine;
public slots:
	void addEngineSlot(QList<int> data, QString mode, int uuid);
	void listEnginesSlot();
	void engineDoneSlot(double duration);
signals:
	void startEnginesSignal();
};
