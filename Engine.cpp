#include "Engine.h"

Engine::Engine(QList<int> _data, QString _mode, int _uuid):
	data(_data),
	mode(_mode),
	uuid(_uuid)
{
		
}

QString Engine::getMode() {
	return mode;
}

void Engine::startEnginesSlot() {
	auto start = std::chrono::high_resolution_clock::now();
	qDebug() << "Start engine";
	qDebug() << "DONE";
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> diff = end - start;
	emit engineDoneSignal(diff.count());
}

void bubbleSort(QList<int> input) {
	/*int i, j, n;
	n = input.length();
	for(i = 0; i < n-1) {
		
	}*/
}
