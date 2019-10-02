#include "EngineHandler.h"

EngineHandler::EngineHandler(){
	std::cout << "=== ENGINE HANDLER CONSTRUCTOR ===" << std::endl;
}

void EngineHandler::addEngineSlot(QList<int> data, std::string mode, int uuid) {
	Engine *engine = new Engine(data, mode, uuid);
	engines.append(engine);
}

void EngineHandler::listEnginesSlot() {
	for(QList<Engine*>::iterator it = engines.begin(); it < engines.end(); ++it) {
		std::cout << *it->getMode() << std::endl;
	}
}

