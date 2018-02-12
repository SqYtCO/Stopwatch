#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent)
{
	setupGUI();

	timer.setInterval(1);
	timer.setSingleShot(false);
	QObject::connect(&timer, &QTimer::timeout, &timewidget, &TimeWidget::updateMS);
//	QObject::connect(&startbutton, &QPushButton::clicked, &timewidget, &TimeWidget::start);
	QObject::connect(&startbutton, &QPushButton::clicked, &timer, static_cast<void (QTimer::*)()>(&QTimer::start));
//	QObject::connect(&stopbutton, &QPushButton::clicked, &timewidget, &TimeWidget::stop);
	QObject::connect(&stopbutton, &QPushButton::clicked, &timer, &QTimer::stop);
	QObject::connect(&resetbutton, &QPushButton::clicked, &timewidget, &TimeWidget::reset);
	QObject::connect(&resetbutton, &QPushButton::clicked, &timer, &QTimer::stop);
}

void MainWindow::setupGUI()
{
	QWidget* central = new QWidget(this);

	startbutton.setText(tr("Start"));
	stopbutton.setText(tr("Stop"));
	resetbutton.setText(tr("Reset"));
	grid.addWidget(&startbutton, 0, 0);
	grid.addWidget(&stopbutton, 0, 1);
	grid.addWidget(&resetbutton, 0, 2);
	grid.addWidget(&timewidget, 1, 0, 1, 3);

	central->setLayout(&grid);
	this->setCentralWidget(central);
}
