#include "Engine.h"

Engine::Engine(QList<int> _data, QString _mode, QUuid _id):
	data(_data),
	mode(_mode),
	id(_id)
{
}

Engine::~Engine() {
	qDebug() << "[Engine] Engine finished";
}

void Engine::run() {
	qDebug() << "[Engine] Starting engine";
	QThread::run();
}

QString Engine::getMode() {
	return mode;
}

void Engine::startEnginesSlot() {
	qDebug() << "Engine thread id: " << QThread::currentThreadId();	
	auto start = std::chrono::high_resolution_clock::now();
	qDebug() << "[Engine] Start engine " << id;
	
	for(int i = 0; i < 10; ++i){
		qDebug() << i;
	}
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> diff = end - start;
	qDebug() << "[Engine] emitting done signal to handler";
	emit engineDoneSignal(diff.count(), id);
}

void bubbleSort(QList<int> input) {
	/*int i, j, n;
	n = input.length();
	for(i = 0; i < n-1) {
		
	}*/
}
