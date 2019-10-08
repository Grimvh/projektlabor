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

void Engine::bubbleSort(QList<int> input) {
	int i, j, n;
	n = input.length();
	for(i = 0; i < n-1; ++i) {
		for(j = 0; j < n-i-1; ++j) {
			if (input[j] > input[j+1]) {
				int temp;
				temp = input[j];
				input[j] = input[j+1];
				input[j+1] = temp;
			}
		}
	}

	for(int i = 0; i < input.length(); ++i) {
		qDebug() << input[i];
	}
}

void Engine::selectionSort(QList<int> input) {
	int i, j, min_idx, n;
	n = input.length();
	for (i = 0; i < n - 1; ++i){
		min_idx = i;
		for(j = i + 1; j < n; ++j) {
			if(input[j] < input[min_idx]) {
				min_idx = j;
			}
			int temp;
			temp = input[min_idx];
			input[min_idx] = input[i];
			input[i] = temp;
		}
	}

	qDebug() << "SELECTION SORT";
}

void Engine::run() {
	auto start = std::chrono::high_resolution_clock::now();
	qDebug() << "[Engine] Engine started:" << id;
	
	if(mode == "bubblesort") {
		bubbleSort(data);
	} else if(mode == "selectionsort") {
		selectionSort(data);
	} else {
		qDebug() << "Undefined sorting mode";
	}

	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> diff = end - start;
	qDebug() << "[Engine] Engine task finished, emitting done";
	emit engineDoneSignal(diff.count(), id);
}

