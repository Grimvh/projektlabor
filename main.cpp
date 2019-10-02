#include <QCoreApplication>

#include "Core.h"

#include <memory>

int main(int argc, char *argv[]) {
	QCoreApplication app(argc, argv);

	std::unique_ptr<Core> p(new Core());

	return 0;
}
