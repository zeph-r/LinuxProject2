#include "ui_alcotesterWindow.h"
#include "alcotesterWindow.h"
#include <string>
#include <locale>

AlcotesterWindow::AlcotesterWindow(QWidget *parent)
	: QWidget(parent),
	ui(new Ui::AlcotesterWindow)
{
	ui->setupUi(this);
	QObject::connect(ui->pushButton, SIGNAL(clicked()), SLOT(ButtonStart()));
	QObject::connect(ui->pushButton_2, SIGNAL(clicked()), SLOT(ButtonBack()));
	
	ui->textEdit->setFontPointSize(40);
}

AlcotesterWindow::~AlcotesterWindow()
{
	delete ui;
}

void AlcotesterWindow::setText(const char *s)
{
	if (ui->textEdit->toPlainText() == s)
		return;
	ui->textEdit->setText(s);
	ui->textEdit->setAlignment(Qt::AlignCenter);
	ui->textEdit->repaint();
}

void AlcotesterWindow::ButtonStart()
{
	ui->pushButton->setDisabled(true);
	char * rec = new char[32];
	tester.writemsg("$STARTSENTECH\r\n");
	while (1)
	{
		tester.readmsg(rec);
		if (strncmp(rec, "$WAIT", 5) == 0)
		{
			setText("ЖДИТЕ");
		}
		else if (strncmp(rec, "$STANBY", 7) == 0)
			setText("ДЫШИТЕ");
		else if (strncmp(rec, "$FLOW", 5) == 0)
			setText("Ошибка, повторите");
		else if (strncmp(rec, "$R:", 3)==0)
		{
			char measure[6];
			strncpy(measure, rec + 3, 5);
			measure[5] = '\0';
			setText(measure);
			break;
		}
	}
	delete[] rec;
	ui->pushButton->setEnabled(true);
}

void AlcotesterWindow::ButtonBack()
{
	this->close();
}