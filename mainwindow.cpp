#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent)
{
	setupGUI();

	// emit every ms timeout-signal
	timer.setInterval(1);
	timer.setSingleShot(false);

	// increase time on timewidget every ms (timeout)
	QObject::connect(&timer, &QTimer::timeout, &timewidget, &TimeWidget::updateMS);
	// start timer on startbutton click
	QObject::connect(&startbutton, &QPushButton::clicked, &timer, static_cast<void (QTimer::*)()>(&QTimer::start));
	// stop timer on stopbutton click
	QObject::connect(&stopbutton, &QPushButton::clicked, &timer, &QTimer::stop);
	// reset timewidget and timer on resetbutton click
	QObject::connect(&resetbutton, &QPushButton::clicked, &timewidget, &TimeWidget::reset);
	QObject::connect(&resetbutton, &QPushButton::clicked, &timer, &QTimer::stop);
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
