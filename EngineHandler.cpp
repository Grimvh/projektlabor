#include "EngineHandler.h"

EngineHandler::EngineHandler(){
	std::cout << "=== ENGINE HANDLER CONSTRUCTOR ===" << std::endl;
}

void EngineHandler::addEngineSlot(QList<int> data, std::string mode, int uuid) {
	engines.append(new Engine(data, mode, uuid));
}

void EngineHandler::listEnginesSlot() {
	for(auto engine : engines) {
		std::cout << engine->getMode() << std::endl;
	}
}

