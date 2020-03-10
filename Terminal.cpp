#include "Terminal.h"
#include <iostream>
#include <string>
#include <string.h>
#include "readerConsts.h"

Terminal::Terminal()
{
	try {
		c.init();
	}
	catch (xpcsc::PCSCError &e) {
		std::cerr << "Connection to PC/SC failed: " << e.what() << std::endl;
		return;
	}
	
	std::vector<std::string> readers = c.readers();
	if (readers.size() == 0) {
		std::cerr << "[E] No connected readers" << std::endl;
		return;
	}

	try {
		std::string reader_name = *readers.begin();
		std::cout << "Found reader: " << reader_name << std::endl;
		reader = c.wait_for_reader_card(reader_name);
	}
	catch (xpcsc::PCSCError &e) {
		std::cerr << "Wait for card failed: " << e.what() << std::endl;
		return;
	}
}

int Terminal::read()
{
	xpcsc::Bytes command;
	xpcsc::Bytes response;
	// загружаем ACTIVE_KEY_A
	command.assign(CMD_LOAD_KEYS, sizeof(CMD_LOAD_KEYS));
	command.replace(5, 6, ACTIVE_KEY_A, 6);
	c.transmit(reader, command, &response);
	if (c.response_status(response) != 0x9000) {
		std::cerr << "Failed to load key" << std::endl;
	}

	// аутентифицируемся ключом A, чтобы получить доступ к блоку CARD_BLOCK 
	command.assign(CMD_GENERAL_AUTH, sizeof(CMD_GENERAL_AUTH));
	command[7] = CARD_BLOCK;
	command[8] = 0x60;
	c.transmit(reader, command, &response);
	if (c.response_status(response) != 0x9000) {
		std::cerr << "Cannot authenticate using ACTIVE_KEY_A!" << std::endl;
	}

	// читаем CARD_BLOCK
	command.assign(CMD_READ_BINARY, sizeof(CMD_READ_BINARY));
	command[3] = CARD_BLOCK;
	c.transmit(reader, command, &response);
	if (c.response_status(response) != 0x9000) {
		std::cerr << "Cannot read block!" << std::endl;
	}

	uint16_t id = 0;
	memcpy(&id, response.c_str(), 2);

	std::cout << "Card ID is: " << id << std::endl;
	return id;
}
