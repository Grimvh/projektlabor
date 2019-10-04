#include "EngineHandler.h"

EngineHandler::EngineHandler() {

}

EngineHandler::~EngineHandler() {

}

void EngineHandler::addEngineSlot(QList<int> data, QString mode, int uuid) {
	engine = new Engine(data, mode, uuid);
	connect(this, &EngineHandler::startEnginesSignal, engine, &Engine::startEnginesSlot, Qt::QueuedConnection);
	connect(engine, &Engine::engineDoneSignal, this, &EngineHandler::engineDoneSlot, Qt::QueuedConnection);
	engine->start();
	engines.append(engine);
}

void EngineHandler::listEnginesSlot() {
	for(auto engine : engines) {
		qDebug() << engine->getMode();
	}
}

void EngineHandler::engineDoneSlot(double duration) {
	qDebug() << "Process finished in " << duration << " milliseconds";
}

