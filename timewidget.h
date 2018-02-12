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

	QTime time;
	QLabel separator[3];
	QLabel hour;
	QLabel minutes;
	QLabel seconds;
	QLabel milliseconds;

	virtual void resizeEvent(QResizeEvent* event) override;

public:
	TimeWidget(QWidget* parent = nullptr);

public slots:
	void updateMS();
	void reset();
};

#endif // TIMEWIDGET_H
