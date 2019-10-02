#include "Engine.h"

Engine::Engine(QList<int> data, std::string mode, int uuid):
	data(data),
	mode(mode),
	uuid(uuid)
{
		
}

std::string Engine::getMode(){
	return mode;
}
