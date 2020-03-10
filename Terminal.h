#pragma once
#include <xpcsc.hpp>

class Terminal
{
public:
	Terminal();
	
	int read();
	
private:
	xpcsc::Connection c;
	xpcsc::Reader reader;
	
};