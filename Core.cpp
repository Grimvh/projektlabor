#include "Core.h"

auto *eh = new EngineHandler();

Core::Core() {
	connect(this, &Core::addEngineSignal, eh, &EngineHandler::addEngineSlot);
	connect(this, &Core::listEnginesSignal, eh, &EngineHandler::listEnginesSlot);

	QList<int> temp;
	temp.append(123);
	temp.append(412);
	temp.append(361);

	addEngine(temp, "bubblesort", 37264);
	addEngine(temp, "selectionsort", 23713);
	addEngine(temp, "quicksort", 23714);
	listEngines();
}

void Core::addEngine(QList<int> data, std::string mode, int uuid) {
	emit addEngineSignal(data, mode, uuid);
}

void Core::listEngines() {
	emit listEnginesSignal();
}

int Core::loadDataset() {
	QFile file("../data/data.txt");
	if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
		return 1;
	}

	QTextStream qts(&file);
	while(!qts.atEnd()) {
		QString line = qts.readLine();
		data_list.append(line.toInt());
	}

	return 0;
}

