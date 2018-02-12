#include "timewidget.h"

TimeWidget::TimeWidget(QWidget* parent) : QWidget(parent)
{
	reset();

	hour.setMinimumSize(100, 80);
	hour.setTextInteractionFlags(Qt::NoTextInteraction);
	hour.setAutoFillBackground(true);
	hour.setPalette(Qt::white);
	hour.setFrameShape(QFrame::Panel);
	hour.setFrameShadow(QFrame::Raised);
	hour.setAlignment(Qt::AlignCenter);
	minutes.setMinimumSize(100, 80);
	minutes.setTextInteractionFlags(Qt::NoTextInteraction);
	minutes.setAutoFillBackground(true);
	minutes.setPalette(Qt::white);
	minutes.setFrameShape(QFrame::Panel);
	minutes.setFrameShadow(QFrame::Raised);
	minutes.setAlignment(Qt::AlignCenter);
	seconds.setMinimumSize(100, 80);
	seconds.setTextInteractionFlags(Qt::NoTextInteraction);
	seconds.setAutoFillBackground(true);
	seconds.setPalette(Qt::white);
	seconds.setFrameShape(QFrame::Panel);
	seconds.setFrameShadow(QFrame::Raised);
	seconds.setAlignment(Qt::AlignCenter);
	milliseconds.setMinimumSize(150, 80);
	milliseconds.setTextInteractionFlags(Qt::NoTextInteraction);
	milliseconds.setAutoFillBackground(true);
	milliseconds.setPalette(Qt::white);
	milliseconds.setFrameShape(QFrame::Panel);
	milliseconds.setFrameShadow(QFrame::Raised);
	milliseconds.setAlignment(Qt::AlignCenter);

	for(int i = 0; i < 3; ++i)
	{
		separator[i].setText(":");
		separator[i].setFixedSize(20, 80);
		separator[i].setTextInteractionFlags(Qt::NoTextInteraction);
		separator[i].setAlignment(Qt::AlignCenter);
	}

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
	hour.setFont(QFont("times", hour.width() / 2));
	minutes.setFont(QFont("times", minutes.width() / 2));
	seconds.setFont(QFont("times", seconds.width() / 2));
	milliseconds.setFont(QFont("times", milliseconds.width() / 3));

	for(int i = 0; i < 3; ++i)
	{
		separator[i].setFont(QFont("times", width() / 25, QFont::ExtraLight));
	}

	event->accept();
}

void TimeWidget::updateMS()
{
	time = time.addMSecs(1);
	hour.setText(QString::number(time.hour()));
	minutes.setText(QString::number(time.minute() % 60));
	seconds.setText(QString::number(time.second() % 60));
	milliseconds.setText(QString::number(time.msec() % 1000));
}

void TimeWidget::reset()
{
	time.setHMS(0, 0, 0);
	hour.setText("0");
	minutes.setText("0");
	seconds.setText("0");
	milliseconds.setText("000");
}
