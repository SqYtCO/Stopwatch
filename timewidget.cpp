#include "timewidget.h"

TimeWidget::TimeWidget(QWidget* parent) : QWidget(parent)
{
	// set timer to 0
	reset();

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

void TimeWidget::resizeEvent(QResizeEvent* event)
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

void TimeWidget::updateMS()
{
	// increase time by 1
	time = time.addMSecs(1);
	// display current time
	hour.setText(QString::number(time.hour()));
	minutes.setText(QString::number(time.minute()));
	seconds.setText(QString::number(time.second()));
	milliseconds.setText(QString::number(time.msec()));
}

void TimeWidget::reset()
{
	// set time to 0
	time.setHMS(0, 0, 0);
	// show 0:0:0:000
	hour.setText("0");
	minutes.setText("0");
	seconds.setText("0");
	milliseconds.setText("000");
}
