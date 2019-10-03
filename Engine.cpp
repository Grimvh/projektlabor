#include "Engine.h"

#include <thread>
#include <chrono>

Engine::Engine(QList<int> _data, QString _mode, int _uuid):
	data(_data),
	mode(_mode),
	uuid(_uuid)
{
		
}

QString Engine::getMode(){
	return mode;
}

void Engine::startEnginesSlot() {
	auto start = std::chrono::high_resolution_clock::now();
	qDebug() << "Start engine";
	qDebug() << "DONE";
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end-start).count();
	emit engineDoneSignal(QString::number(duration));
}
