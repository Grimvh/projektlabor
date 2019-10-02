#include <iostream>
#include <QCoreApplication>
#include <QDebug>
#include <QList>
#include <QFile>

QList<int> data_list;
QFile file("../data/data.txt");

int loadDataset() {
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

int printData() {
	std::cout << "printing..." << std::endl;
	for(QList<int>::iterator i = data_list.begin(); i != data_list.end(); ++i) {
		std::cout << *i << std::endl;
	}
}

int main(int argc, char *argv[]) {
	std::cout << "Starting..." << std::endl;
	loadDataset();
	printData();
	return 0;
}

