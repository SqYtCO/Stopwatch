#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
    app.setWindowIcon(QIcon("icon/stopwatch-icon.png"));
	MainWindow w;
	w.show();

	return app.exec();
}
