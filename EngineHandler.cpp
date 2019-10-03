#include "EngineHandler.h"

EngineHandler::EngineHandler(){
	qDebug() << "=== ENGINE HANDLER CONSTRUCTOR ===";
}

void EngineHandler::addEngineSlot(QList<int> data, QString mode, int uuid) {
	Engine *engine = new Engine(data, mode, uuid);
	connect(this, &EngineHandler::startEnginesSignal, engine, &Engine::startEnginesSlot);
	connect(engine, &Engine::engineDoneSignal, this, &EngineHandler::engineDoneSlot);
	engines.append(engine);
}

void EngineHandler::listEnginesSlot() {
	for(auto engine : engines) {
		qDebug() << engine->getMode();
	}
}

void EngineHandler::engineDoneSlot(QString data) {
	qDebug() << data;
}

