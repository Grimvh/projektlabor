#pragma once

#include <iostream>
#include <QObject>
#include <QString>
#include <QDebug>
#include <QThread>
#include <QMap>
#include <QUuid>

#include "Engine.h"

class EngineHandler : public QThread {
	Q_OBJECT
public:
	EngineHandler();
	~EngineHandler();
protected:
	void run() override;
private:
	QMap<QUuid, Engine*> *engines;
	bool canExit = false;
public slots:
	void addEngineSlot(QList<int> data, QString mode, QUuid id);
	void listEnginesSlot();
	void engineDoneSlot(double duration, QUuid id);
	void startEngines_slot();
signals:
	void startEnginesSignal();
	void canExitSignal();
};
