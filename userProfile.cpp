#include "ui_userProfile.h"
#include "userProfile.h"
#include "MainWindow.h"
#include "testsWindow.h"

UserProfile::UserProfile(QWidget *parent)
	: QWidget(parent), 
	ui(new Ui::UserProfile)
{
	ui->setupUi(this);
	QObject::connect(ui->pushButton_2, SIGNAL(clicked()), SLOT(ButtonCancel()));
	QObject::connect(ui->pushButton, SIGNAL(clicked()), SLOT(ButtonConfirm()));
}

UserProfile::~UserProfile()
{
	delete ui;
}

void UserProfile::ButtonCancel()
{
	MainWindow* main = new MainWindow();
	main->show();
	this->close();
}

void UserProfile::ButtonConfirm()
{
	TestsWindow *tW = new TestsWindow();
	tW->show();
	this->close();
}