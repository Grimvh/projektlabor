#include <QCoreApplication>

#include "Core.h"

#include <memory>

int main(int argc, char *argv[]) {
	QCoreApplication app(argc, argv);

	qDebug() << "Main thread id:" << QThread::currentThreadId();
	//std::unique_ptr<Core> p(new Core());
	auto core = std::make_unique<Core>();
	core->start();;
	return QCoreApplication::exec();
}
