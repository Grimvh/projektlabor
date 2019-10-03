#pragma once

#include <iostream>
#include <QObject>
#include <QList>
#include <QString>
#include <QDebug>

#include "Engine.h"

class EngineHandler : public QObject {
	Q_OBJECT

public:
	EngineHandler();
private:
	QList<Engine*> engines;
public slots:
	void addEngineSlot(QList<int> data, QString mode, int uuid);
	void listEnginesSlot();
	void engineDoneSlot(QString data);
signals:
	void startEnginesSignal();
};
