#include "Core.h"

Core::Core() {
	EngineHandler *eh;
	connect(this, &Core::addSignal, eh, &EngineHandler::addEngineSlot);
}

void Core::addEngine(std::string engine_name) {
	emit addSignal();
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

