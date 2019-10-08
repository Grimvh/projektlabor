#include "EngineHandler.h"

EngineHandler::EngineHandler() {
	qDebug() << "[EngineHandler] EngineHandler created";
	engines = new QMap<QUuid, Engine*>();
	this->start();
}

EngineHandler::~EngineHandler() {
	qDebug() << "[EngineHandler] EngineHandler deleted";
	delete engines;
}

void EngineHandler::run() {
	qDebug() << "[EngineHandler] EngineHandler started";
	QThread::run();
}

void EngineHandler::addEngineSlot(QList<int> data, QString mode, QUuid id) {
	qDebug() << "[EngineHandler] Adding engine, mode:" << mode;
	Engine *engine = new Engine(data, mode, id);
	connect(engine, &Engine::engineDoneSignal, this, &EngineHandler::engineDoneSlot, Qt::QueuedConnection);
	connect(engine, &Engine::finished, engine, &Engine::deleteLater);
	engines->insert(id, engine);
	engine->start();
	qDebug() << "[EngineHandler] Added engine";
}

void EngineHandler::listEnginesSlot() {
	for(auto engine : *engines) {
		qDebug() << engine->getMode();
	}
}

void EngineHandler::engineDoneSlot(double duration, QUuid id) {
	qDebug() << "[EngineHandler] Process " << id << " finished in " << duration << " milliseconds";
	qDebug() << "[EngineHandler] Array size before:" << engines->size();
	engines->remove(id);
	qDebug() << "[EngineHandler] Array size after:" << engines->size();
	if(engines->size() < 1) emit canExitSignal();
}

