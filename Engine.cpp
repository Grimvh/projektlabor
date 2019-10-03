#include "Engine.h"

Engine::Engine(QList<int> _data, std::string _mode, int _uuid):
	data(_data),
	mode(_mode),
	uuid(_uuid)
{
		
}

std::string Engine::getMode(){
	return mode;
}
