#include "Core.h"

Core::Core() {
	connect(this, &Core::initCore_signal, this, &Core::initCore_slot);
	connect(this, &Core::loadEngines_signal, this, &Core::loadEngines_slot);
	this->start();
}

Core::~Core() {
	engineHandler->quit();
	engineHandler->wait();
}

void Core::initCore_slot() {
	init();
}

void Core::loadEngines_slot() {
	loadEngines();
}

void Core::printArray(QList<int> arr) {
	for(int i = 0; i < arr.size(); ++i) {
		qDebug() << arr[i];
	}
}

int Core::init() {
	printArray(data_list);
	qDebug() << "[Core] Starting engine handler";
	engineHandler = new EngineHandler();
	engineHandler->moveToThread(this);
	connect(this, &Core::addEngineSignal, engineHandler, &EngineHandler::addEngineSlot, Qt::DirectConnection);
	connect(this, &Core::listEnginesSignal, engineHandler, &EngineHandler::listEnginesSlot, Qt::QueuedConnection);
	connect(this, &Core::startEnginesSignal, engineHandler, &EngineHandler::startEnginesSignal, Qt::QueuedConnection);
	connect(engineHandler, &EngineHandler::finished, engineHandler, &EngineHandler::deleteLater);
	engineHandler->start();
	return 0;
}

void Core::run() {
	loadDataset();
	emit initCore_signal();
	emit loadEngines_signal();
	QThread::run();
}

void Core::loadEngines() {
	emit addEngineSignal(data_list, "bubblesort", QUuid::createUuid());
	emit addEngineSignal(data_list, "selectionsort", QUuid::createUuid());
	startEngines();
}

void Core::listEngines() {
	emit listEnginesSignal();
}

void Core::startEngines() {
	emit startEnginesSignal();
}

int Core::canExitSlot() {
	return 0;
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

