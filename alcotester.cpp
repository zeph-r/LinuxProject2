#include "alcotester.h"
#include <string.h>
#include <iostream>

Alcotester::Alcotester()
	: fd(open("/dev/ttyACM0", O_RDWR | O_NOCTTY))
{
	if (fd == -1)						/* Error Checking */
	std::cerr << "\n  ConnectionError  ";
	
	tcgetattr(fd, &SerialPortSettings); /* Get the current attributes of the Serial port */

	/* Setting the Baud rate */
	cfsetispeed(&SerialPortSettings, B9600); /* Set Read  Speed as 9600                       */
	cfsetospeed(&SerialPortSettings, B9600); /* Set Write Speed as 9600                       */

	/* 8N1 Mode */
	SerialPortSettings.c_cflag &= ~PARENB; /* Disables the Parity Enable bit(PARENB),So No Parity   */
	SerialPortSettings.c_cflag &= ~CSTOPB; /* CSTOPB = 2 Stop bits,here it is cleared so 1 Stop bit */
	SerialPortSettings.c_cflag &= ~CSIZE; /* Clears the mask for setting the data size             */
	SerialPortSettings.c_cflag |=  CS8; /* Set the data bits = 8                                 */
		
	SerialPortSettings.c_cflag &= ~CRTSCTS; /* No Hardware flow Control                         */
	SerialPortSettings.c_cflag |= CREAD | CLOCAL; /* Enable receiver,Ignore Modem Control lines       */ 
		
		
	SerialPortSettings.c_iflag &= ~(IXON | IXOFF | IXANY); /* Disable XON/XOFF flow control both i/p and o/p */
	SerialPortSettings.c_iflag &= ~(ICANON | ECHO | ECHOE | ISIG); /* Non Cannonical mode                            */

	SerialPortSettings.c_oflag &= ~OPOST; /*No Output Processing*/
		
	/* Setting Time outs */
	SerialPortSettings.c_cc[VMIN] = 10; /* Read at least 10 characters */
	SerialPortSettings.c_cc[VTIME] = 0; /* Wait indefinetly   */

	if ((tcsetattr(fd, TCSANOW, &SerialPortSettings)) != 0) /* Set the attributes to the termios structure*/
		std::cerr << "\n  ERROR ! in Setting attributes";
	else
		std::cerr << "\n  BaudRate = 9600 \n  StopBits = 1 \n  Parity   = none";
}

Alcotester::~Alcotester()
{
	close(fd);
}

void Alcotester::writemsg(const char* msg)
{
	write(fd, msg, strlen(msg));                        
}

void Alcotester::readmsg(char* rec)
{
	tcflush(fd, TCIFLUSH);
	int  bytes_read = 0;
	
	do
		bytes_read = read(fd, rec, 32); 
	while (bytes_read == 1);
}