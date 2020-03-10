#pragma once

#include <QtWidgets/QWidget>

namespace Ui {
	class UserProfile;
} // namespace Ui

class UserProfile : public QWidget
{
	Q_OBJECT
    
	public :
		explicit UserProfile(QWidget *parent = 0);
		~UserProfile();
	
protected slots :
    void ButtonCancel();
	void ButtonConfirm();

private:
	Ui::UserProfile *ui;
};

