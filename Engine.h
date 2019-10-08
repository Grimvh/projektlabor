#pragma once

#include <QList>
#include <QString>
#include <QThread>
#include <QDebug>
#include <QObject>
#include <QUuid>

class Engine : public QThread {
	Q_OBJECT
public:
	Engine(QList<int> _data, QString _mode, QUuid _id);
	~Engine();
	QString getMode();
protected:
	void run() override;
private:
	QList<int> data;
	QString mode;
	QUuid id;
	void bubbleSort(QList<int> input);
//public slots:
//	void startEnginesSlot();
signals:
	void engineDoneSignal(double duration, QUuid id);
	void startEngineSignal();
};
