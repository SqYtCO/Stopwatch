#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "timewidget.h"
#include <QMainWindow>
#include <QGridLayout>
#include <QPushButton>
#include <QAction>

class MainWindow : public QMainWindow
{
	QGridLayout grid;

	// manage timer and display time
	TimeWidget timewidget;
	// control buttons
	QPushButton startbutton;
	QPushButton stopbutton;
	QPushButton resetbutton;

	QAction startaction;
	QAction stopaction;
	QAction resetaction;

	void setupGUI();

public:
	MainWindow(QWidget* parent = nullptr);
};

#endif // MAINWINDOW_H
