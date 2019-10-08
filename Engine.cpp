#include "Engine.h"

Engine::Engine(QList<int> _data, QString _mode, QUuid _id):
	data(_data),
	mode(_mode),
	id(_id)
{
	qDebug() << "[Engine] Engine created";
}

Engine::~Engine() {
	qDebug() << "[Engine] Engine deleted";
}

QString Engine::getMode() {
	return mode;
}

void Engine::run() {
	auto start = std::chrono::high_resolution_clock::now();
	qDebug() << "[Engine] Engine started:" << id;
	
	for(int i = 0; i < 10; ++i){
		qDebug() << i;
		QThread::sleep(1);
	}
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> diff = end - start;
	qDebug() << "[Engine] Engine task finished, emitting done";
	emit engineDoneSignal(diff.count(), id);
}

void bubbleSort(QList<int> input) {
	/*int i, j, n;
	n = input.length();
	for(i = 0; i < n-1) {
		
	}*/
}
