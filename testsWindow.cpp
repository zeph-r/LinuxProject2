#include "ui_testsWindow.h"
#include "testsWindow.h"
#include "MainWindow.h"
#include "alcotesterWindow.h"

TestsWindow::TestsWindow(QWidget *parent)
	: QWidget(parent), 
	ui(new Ui::testsWindow)
{
	ui->setupUi(this);
	
	QObject::connect(ui->pushButton, SIGNAL(clicked()), SLOT(ButtonTermomether())); //therm
	QObject::connect(ui->pushButton_2, SIGNAL(clicked()), SLOT(ButtonPressure())); //tonom
	QObject::connect(ui->pushButton_3, SIGNAL(clicked()), SLOT(ButtonAlcotester())); //alco
	QObject::connect(ui->pushButton_4, SIGNAL(clicked()), SLOT(ButtonCamera())); //cam
	QObject::connect(ui->pushButton_5, SIGNAL(clicked()), SLOT(ButtonConfirm())); //confirm
	QObject::connect(ui->pushButton_6, SIGNAL(clicked()), SLOT(ButtonCancel())); //cancel
}

TestsWindow::~TestsWindow()
{
	delete ui;
}

void TestsWindow::ButtonTermomether()
{
	
}
void TestsWindow::ButtonPressure()
{
	
}
void TestsWindow::ButtonAlcotester()
{
	AlcotesterWindow* alcW = new AlcotesterWindow;
	alcW->show();
}
void TestsWindow::ButtonCamera()
{
	
}
void TestsWindow::ButtonConfirm()
{
	
}
void TestsWindow::ButtonCancel()
{
	MainWindow * mw = new MainWindow();
	mw->show();
	this->close();
}
