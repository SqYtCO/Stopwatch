#include "mainwindow.h"
#include <qdebug.h>
MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent)
{
	setupGUI();

	// on startbutton-click: if stopwatch is not running, start it
	QObject::connect(&startbutton, &QPushButton::clicked, [this]() { if(!timewidget.isRunning()) timewidget.start(); });
	startaction.setShortcuts( { QKeySequence(Qt::CTRL + Qt::Key_S), QKeySequence(Qt::Key_Space) } );
	this->addAction(&startaction);
	QObject::connect(&startaction, &QAction::triggered, [this]() { if(!timewidget.isRunning()) timewidget.start(); });

	// on stopbutton-click: if stopwatch is running, stop it
	QObject::connect(&stopbutton, &QPushButton::clicked, [this]() { if(timewidget.isRunning()) timewidget.stop(); });
	stopaction.setShortcuts( { QKeySequence(Qt::CTRL + Qt::Key_P), QKeySequence(Qt::Key_Return) } );
	this->addAction(&stopaction);
	QObject::connect(&stopaction, &QAction::triggered, [this]() { if(timewidget.isRunning()) timewidget.stop(); });

	// on resetbutton-click: reset stopwatch
	QObject::connect(&resetbutton, &QPushButton::clicked, &timewidget, &TimeWidget::reset);
	resetaction.setShortcuts( { QKeySequence(Qt::CTRL + Qt::Key_R), QKeySequence(Qt::Key_Escape) } );
	this->addAction(&resetaction);
	QObject::connect(&resetaction, &QAction::triggered, &timewidget, &TimeWidget::reset);
}

void MainWindow::setupGUI()
{
	QWidget* central = new QWidget(this);

	// setup buttons
	startbutton.setText(tr("Start (Space)"));
	startbutton.setToolTip(tr("CTRL+S"));
	stopbutton.setText(tr("Stop (Return)"));
	stopbutton.setToolTip(tr("CTRL+P"));
	resetbutton.setText(tr("Reset (Esc)"));
	resetbutton.setToolTip(tr("CTRL+R"));
	// setup layout
	grid.addWidget(&startbutton, 0, 0);
	grid.addWidget(&stopbutton, 0, 1);
	grid.addWidget(&resetbutton, 0, 2);
	grid.addWidget(&timewidget, 1, 0, 1, 3);

	// set layout
	central->setLayout(&grid);
	this->setCentralWidget(central);
}
