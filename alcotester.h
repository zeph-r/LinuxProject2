#pragma once

#include <stdio.h>
#include <fcntl.h>   /* File Control Definitions           */
#include <termios.h> /* POSIX Terminal Control Definitions */
#include <unistd.h>  /* UNIX Standard Definitions 	   */ 
#include <errno.h>   /* ERROR Number Definitions           */

class Alcotester
{
public:
	Alcotester();
	~Alcotester();
	
	void readmsg(char* rec);
	void writemsg(const char* msg);
	
private:
	int fd;
	termios SerialPortSettings;
};