#include "EngineHandler.h"

EngineHandler::EngineHandler(){
	std::cout << "ENGINEHANDLER" << std::endl;
}

void EngineHandler::addToEngineList() {
	engines.append("ASDASDASDASD");
	listEngines();
}

void EngineHandler::listEngines() {
	for(QList<std::string>::iterator it = engines.begin(); it < engines.end(); ++it) {
		std::cout << *it << std::endl;
	}
}
