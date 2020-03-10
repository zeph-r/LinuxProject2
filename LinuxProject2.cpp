#include "MainWindow.h"
#include "Terminal.h"
#include <QApplication>

#include "alcotesterWindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
	
	MainWindow aw;
	aw.show();
    return a.exec();
}
