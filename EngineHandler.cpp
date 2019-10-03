#include "EngineHandler.h"

EngineHandler::EngineHandler(){
	qDebug() << "=== ENGINE HANDLER CONSTRUCTOR ===";
}

void EngineHandler::addEngineSlot(QList<int> data, QString mode, int uuid) {
	engines.append(new Engine(data, mode, uuid));
}

void EngineHandler::listEnginesSlot() {
	for(auto engine : engines) {
		qDebug() << engine->getMode();
	}
}

