#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent)
{
	setupGUI();

	// on startbutton-click: if stopwatch is not running, start it
	QObject::connect(&startbutton, &QPushButton::clicked, [this]() { if(!timewidget.isRunning()) timewidget.start(); });
	// on stopbutton-click: if stopwatch is running, stop it
	QObject::connect(&stopbutton, &QPushButton::clicked, [this]() { if(timewidget.isRunning()) timewidget.stop(); });
	// on resetbutton-click: reset stopwatch
	QObject::connect(&resetbutton, &QPushButton::clicked, &timewidget, &TimeWidget::reset);
}

void MainWindow::setupGUI()
{
	QWidget* central = new QWidget(this);

	// setup buttons
	startbutton.setText(tr("Start"));
	stopbutton.setText(tr("Stop"));
	resetbutton.setText(tr("Reset"));
	// setup layout
	grid.addWidget(&startbutton, 0, 0);
	grid.addWidget(&stopbutton, 0, 1);
	grid.addWidget(&resetbutton, 0, 2);
	grid.addWidget(&timewidget, 1, 0, 1, 3);

	// set layout
	central->setLayout(&grid);
	this->setCentralWidget(central);
}
