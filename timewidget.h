#ifndef TIMEWIDGET_H
#define TIMEWIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QElapsedTimer>
#include <QTimer>
#include <QResizeEvent>

class TimeWidget : public QWidget
{
	Q_OBJECT

	QHBoxLayout layout;

	// measure time since start
	QElapsedTimer timer;
	// update displayed time on timeout of updateTimer
	QTimer updateTimer;
	// store current time when stopped
	std::size_t stopTime;

	// labels to display time
	QLabel separator[3];
	QLabel hour;
	QLabel minutes;
	QLabel seconds;
	QLabel milliseconds;

	// update font size on resize
	virtual void resizeEvent(QResizeEvent*) override;

	void setupGUI();

public:
	TimeWidget(QWidget* parent = nullptr);

	inline bool isRunning() { return timer.isValid(); }

public slots:
	void start();
	void stop();
	void reset();

private slots:
	// update displayed time
	void updateStopwatch();
};

#endif // TIMEWIDGET_H
