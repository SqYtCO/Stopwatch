#include "mainwindow.h"
#include "icon.xpm"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	app.setWindowIcon(QIcon(QPixmap(icon_xpm)));
	MainWindow w;
	w.show();

	return app.exec();
}
