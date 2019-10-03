#pragma once

#include <QList>
#include <string>

class Engine{
	public:
		Engine(QList<int> data, std::string mode, int uuid);
		std::string getMode();
	private:
		QList<int> data;
		std::string mode;
		int uuid;
};
