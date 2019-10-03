#pragma once

#include <QList>
#include <QString>

class Engine{
	public:
		Engine(QList<int> _data, QString _mode, int _uuid);
		QString getMode();
	private:
		QList<int> data;
		QString mode;
		int uuid;
};
