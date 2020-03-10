#pragma once

#include <QtWidgets/QWidget>
#include "alcotester.h"

namespace Ui {
	class AlcotesterWindow;
} // namespace Ui

class AlcotesterWindow : public QWidget
{
	Q_OBJECT
    
	public :
		explicit AlcotesterWindow(QWidget *parent = 0);
		~AlcotesterWindow();
	
	protected slots :
	    void ButtonBack();
		void ButtonStart();

private:
	void setText(const char * s);

	Ui::AlcotesterWindow *ui;
	Alcotester tester;
}
;