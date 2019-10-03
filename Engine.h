#pragma once

#include <QList>
#include <QString>
#include <QThread>
#include <QDebug>
#include <QObject>

class Engine : public QThread{
	Q_OBJECT
public:
	Engine(QList<int> _data, QString _mode, int _uuid);
	QString getMode();
private:
	QList<int> data;
	QString mode;
	int uuid;
public slots:
	void startEnginesSlot();
signals:
	void engineDoneSignal(QString data);
};
