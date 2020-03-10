#pragma once

#include <QtWidgets/QWidget>

namespace Ui {
	class testsWindow;
} // namespace Ui

class TestsWindow : public QWidget
{
	Q_OBJECT
    
public:
		explicit TestsWindow(QWidget *parent = 0);
		~TestsWindow();
	
private slots:
	void ButtonTermomether(); //therm
	void ButtonPressure(); //tonom
	void ButtonAlcotester(); //alco
	void ButtonCamera(); //cam
	void ButtonConfirm(); //confirm
	void ButtonCancel(); 

private:
	Ui::testsWindow *ui;
};
