#pragma once

#include <string.h>
#include <QFile>
#include <iostream>
#include <QTextStream>
#include "EngineHandler.h"
#include <QObject>

class Core : public QObject {
	Q_OBJECT
	public:
		Core();
	private:
		void addEngine(QList<int> data, std::string mode, int uuid);
		void listEngines();
		int loadDataset();
		QList<int> data_list;
	signals:
		void addEngineSignal(QList<int> data, std::string mode, int uuid);
		void listEnginesSignal();
};
