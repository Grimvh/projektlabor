#include "Core.h"

Core::Core() {
	engineHandler = new EngineHandler();
	connect(this, &Core::addEngineSignal, engineHandler, &EngineHandler::addEngineSlot);
	connect(this, &Core::listEnginesSignal, engineHandler, &EngineHandler::listEnginesSlot);
	connect(this, &Core::startEnginesSignal, engineHandler, &EngineHandler::startEnginesSignal);
	connect(engineHandler, &EngineHandler::finished, engineHandler, &EngineHandler::deleteLater);

	engineHandler->start();

	QList<int> temp;
	temp.append(123);
	temp.append(412);
	temp.append(361);

	addEngine(temp, "bubblesort", 37264);
	addEngine(temp, "selectionsort", 23713);
	addEngine(temp, "quicksort", 23714);
	//listEngines();
	startEngines();
}

Core::~Core() {
	engineHandler->quit();
	engineHandler->wait();
}

void Core::addEngine(QList<int> data, QString mode, int uuid) {
	emit addEngineSignal(data, mode, uuid);
}

void Core::listEngines() {
	emit listEnginesSignal();
}

void Core::startEngines() {
	emit startEnginesSignal();
}

int Core::loadDataset() {
	QFile file("../data/data.txt");
	if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
		return 1;
	}

	QTextStream qts(&file);
	while(!qts.atEnd()) {
		QString line = qts.readLine();
		data_list.append(line.toInt());
	}

	return 0;
}

