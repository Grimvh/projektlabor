#pragma once

#include <string.h>
#include <QFile>
#include <iostream>
#include <QTextStream>
#include "EngineHandler.h"

class Core : public QObject {
	Q_OBJECT
	public:
		Core();
	private:
		void addEngine();
		int loadDataset();
		QList<int> data_list;
	signals:
		void addSignal();
};
