#pragma once

#include <QFile>
#include <iostream>
#include <QTextStream>
#include "EngineHandler.h"
#include <QThread>
#include <QDebug>
#include <QString>
#include <QUuid>
#include <QObject>

class Core : public QThread {
	Q_OBJECT
	public:
		Core();
		~Core();
		int init();
		void loadEngines();

	public slots:
		void initCore_slot();
		void loadEngines_slot();
	

	protected:
		void run() override;
	private:
		void listEngines();
		int loadDataset();
		QList<int> data_list;
		void startEngines();
		EngineHandler *engineHandler;
	signals:
		void initCore_signal();
		void loadEngines_signal();
		void addEngineSignal(QList<int> data, QString mode, QUuid id);
		void listEnginesSignal();
		void startEnginesSignal();
	public slots:
		int canExitSlot();
};
