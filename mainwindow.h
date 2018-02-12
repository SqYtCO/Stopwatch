#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "timewidget.h"
#include <QMainWindow>
#include <QGridLayout>
#include <QPushButton>
#include <QTimer>

class MainWindow : public QMainWindow
{
	QGridLayout grid;

	// manage timer and display time
	TimeWidget timewidget;
	// control buttons
	QPushButton startbutton;
	QPushButton stopbutton;
	QPushButton resetbutton;

	void setupGUI();

public:
	MainWindow(QWidget* parent = nullptr);
};

#endif // MAINWINDOW_H
