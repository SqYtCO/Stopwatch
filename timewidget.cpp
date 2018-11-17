#include "timewidget.h"
#include <QTimer>

TimeWidget::TimeWidget(QWidget* parent) : QWidget(parent)
{
	setupGUI();

	// set update interval of displayed time
	updateTimer.setInterval(3);
	updateTimer.setSingleShot(false);

	// enable update of displayed time
	QObject::connect(&updateTimer, &QTimer::timeout, this, &TimeWidget::updateStopwatch);

	// set timer to 0
	reset();
}

void TimeWidget::setupGUI()
{
	// setup style of hour
	hour.setMinimumSize(100, 80);
	hour.setTextInteractionFlags(Qt::NoTextInteraction);
	hour.setAutoFillBackground(true);
	hour.setPalette(Qt::white);
	hour.setFrameShape(QFrame::Panel);
	hour.setFrameShadow(QFrame::Raised);
	hour.setAlignment(Qt::AlignCenter);
	// setup style of minutes
	minutes.setMinimumSize(100, 80);
	minutes.setTextInteractionFlags(Qt::NoTextInteraction);
	minutes.setAutoFillBackground(true);
	minutes.setPalette(Qt::white);
	minutes.setFrameShape(QFrame::Panel);
	minutes.setFrameShadow(QFrame::Raised);
	minutes.setAlignment(Qt::AlignCenter);
	// setup style of seconds
	seconds.setMinimumSize(100, 80);
	seconds.setTextInteractionFlags(Qt::NoTextInteraction);
	seconds.setAutoFillBackground(true);
	seconds.setPalette(Qt::white);
	seconds.setFrameShape(QFrame::Panel);
	seconds.setFrameShadow(QFrame::Raised);
	seconds.setAlignment(Qt::AlignCenter);
	// setup style of milliseconds
	milliseconds.setMinimumSize(150, 80);
	milliseconds.setTextInteractionFlags(Qt::NoTextInteraction);
	milliseconds.setAutoFillBackground(true);
	milliseconds.setPalette(Qt::white);
	milliseconds.setFrameShape(QFrame::Panel);
	milliseconds.setFrameShadow(QFrame::Raised);
	milliseconds.setAlignment(Qt::AlignCenter);

	// setup separator character and style of the separators
	for(int i = 0; i < 3; ++i)
	{
		separator[i].setText(":");
		separator[i].setFixedSize(20, 80);
		separator[i].setTextInteractionFlags(Qt::NoTextInteraction);
		separator[i].setAlignment(Qt::AlignCenter);
	}

	// setup layout
	layout.addWidget(&hour);
	layout.addWidget(&separator[0]);
	layout.addWidget(&minutes);
	layout.addWidget(&separator[1]);
	layout.addWidget(&seconds);
	layout.addWidget(&separator[2]);
	layout.addWidget(&milliseconds);

	this->setLayout(&layout);
}

void TimeWidget::updateStopwatch()
{
	if(timer.isValid())
	{
		// add stoptime to current time and divide it by h/ms, min/ms and s/ms
		hour.setText(QString::number(((timer.elapsed() + stopTime) / 3600000LL) % 99));
		minutes.setText(QString::number(((timer.elapsed() + stopTime) / 60000L) % 60));
		seconds.setText(QString::number(((timer.elapsed() + stopTime) / 1000) % 60));
		milliseconds.setText(QString::number((timer.elapsed() + stopTime) % 1000));
	}
}

void TimeWidget::resizeEvent(QResizeEvent*)
{
	// increase / decrease font size on resizeevent
	hour.setFont(QFont("times", hour.width() / 2));
	minutes.setFont(QFont("times", minutes.width() / 2));
	seconds.setFont(QFont("times", seconds.width() / 2));
	milliseconds.setFont(QFont("times", milliseconds.width() / 3));

	for(int i = 0; i < 3; ++i)
	{
		separator[i].setFont(QFont("times", width() / 25, QFont::ExtraLight));
	}
}

void TimeWidget::start()
{
	// enable stopwatch update
	updateTimer.start();
	// start timer
	timer.start();
}

void TimeWidget::stop()
{
	// disable stopwatch update
	updateTimer.stop();
	// update stopwatch independent of update interval
	updateStopwatch();
	// save current time
	stopTime += timer.elapsed();
	// stop timer
	timer.invalidate();
}

void TimeWidget::reset()
{
	// disable stopwatch update
	updateTimer.stop();
	// stop timer
	timer.invalidate();

	// set text to 0:0:0:000
	hour.setText("0");
	minutes.setText("0");
	seconds.setText("0");
	milliseconds.setText("000");

	// reset stored stoptime
	stopTime = 0;
}
