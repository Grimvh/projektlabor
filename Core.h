#pragma once

#include <QFile>
#include <iostream>
#include <QTextStream>
#include "EngineHandler.h"
#include <QObject>
#include <QDebug>
#include <QString>

class Core : public QObject {
	Q_OBJECT
	public:
		Core();
	private:
		void addEngine(QList<int> data, QString mode, int uuid);
		void listEngines();
		int loadDataset();
		QList<int> data_list;
		void startEngines();
	signals:
		void addEngineSignal(QList<int> data, QString mode, int uuid);
		void listEnginesSignal();
		void startEnginesSignal();
};
