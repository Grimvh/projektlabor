#pragma once

class Engine{
	public:
		Engine(QList<std::string> data, std::string mode, int uuid);
		std::string getMode();
	private:
		QList<int> data;
		std::string mode;
		int uuid;
};
