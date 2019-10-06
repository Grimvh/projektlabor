#include "EngineHandler.h"

EngineHandler::EngineHandler() {
	qDebug() << "EngineHandler constructor thread id: " << QThread::currentThreadId();
}

EngineHandler::~EngineHandler() {}

void EngineHandler::run() {
	qDebug() << "[EngineHandler] EngineHandler thread id"  << QThread::currentThreadId();
	QThread::run();
}

void EngineHandler::startEngines_slot() {
	emit startEnginesSignal();
}

void EngineHandler::addEngineSlot(QList<int> data, QString mode, QUuid id) {
	qDebug() << "[EngineHandler] addEngineSlot thread id:" << QThread::currentThreadId();
	Engine *engine = new Engine(data, mode, id);
	connect(this, &EngineHandler::startEnginesSignal, engine, &Engine::startEnginesSlot, Qt::QueuedConnection);
	connect(engine, &Engine::engineDoneSignal, this, &EngineHandler::engineDoneSlot, Qt::QueuedConnection);
	connect(engine, &Engine::finished, engine, &Engine::deleteLater);
	engines.insert(id, engine);
	engine->start();
	qDebug() << "[EngineHandler] New engine added!";
}

void EngineHandler::listEnginesSlot() {
	for(auto engine : engines) {
		qDebug() << engine->getMode();
	}
}

void EngineHandler::engineDoneSlot(double duration, QUuid id) {
	qDebug() << "[EngineHandler] Process " << id << " finished in " << duration << " milliseconds";
	qDebug() << "engines.size=" << engines.size();
	engines.remove(id);
	qDebug() << "engines.size=" << engines.size();
	if(engines.size() < 1) emit canExitSignal();
}

