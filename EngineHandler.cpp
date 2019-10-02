#include "EngineHandler.h"

EngineHandler::EngineHandler(){
	std::cout << "ENGINEHANDLER" << std:endl;
}

EngineHandler::addToEngineList() {
	engines.append("ASDASDASDASD");
	listEngines();
}

EngineList::listEngines() {
	for(QList<std::string>::iterator it = engines.begin(); it < engines.end(); ++it) {
		std::cout << *it << std::endl;
	}
}
