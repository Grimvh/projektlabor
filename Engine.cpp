#include "Engine.h"

Engine::Engine(QList<int> _data, QString _mode, int _uuid):
	data(_data),
	mode(_mode),
	uuid(_uuid)
{
		
}

QString Engine::getMode(){
	return mode;
}
