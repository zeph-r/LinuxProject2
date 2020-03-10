#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "Terminal.h"
#include "userProfile.h"

#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	
	
	QTimer::singleShot(1000, this, SLOT(wait()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loop()
{	
	Terminal terminal;
	int id = terminal.read();
	UserProfile* userp = new UserProfile;
	userp->show();
	this->close();
	
}

void MainWindow::wait()
{
	loop();
}
