#ifndef TIMEWIDGET_H
#define TIMEWIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QTime>
#include <QResizeEvent>

class TimeWidget : public QWidget
{
	Q_OBJECT

	QHBoxLayout layout;

	// store current time
	QTime time;

	QLabel separator[3];
	QLabel hour;
	QLabel minutes;
	QLabel seconds;
	QLabel milliseconds;

	// update font size on resize
	virtual void resizeEvent(QResizeEvent* event) override;

public:
	TimeWidget(QWidget* parent = nullptr);

public slots:
	// increase time by 1
	void updateMS();
	// set time to 00:00:00:000
	void reset();
};

#endif // TIMEWIDGET_H
