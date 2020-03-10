#pragma once
#include <xpcsc.hpp>

typedef enum { Key_None, Key_A, Key_B } CardBlockKeyType;
struct AccessBits {
	xpcsc::Byte C1 : 1, C2 : 1, C3 : 1;
	bool is_set;
	AccessBits()
		: is_set(false) {}
	;
};
struct CardContents {
	xpcsc::Byte blocks_data[64][16];
	xpcsc::Byte blocks_keys[64][6];

	CardBlockKeyType blocks_key_types[64];
	AccessBits blocks_access_bits[64];
};

const uint8_t CARD_SECTOR  = 0x5;
const uint8_t CARD_SECTOR_BLOCK = 0x2;
const uint8_t CARD_BLOCK = ((CARD_SECTOR * 4) + CARD_SECTOR_BLOCK);
const uint8_t CARD_SECTOR_TRAILER = ((CARD_SECTOR * 4) + 3);
const uint8_t ACTIVE_KEY_A[6] = { 0x02, 0x01, 0x01, 0x02, 0x01, 0x01 };
const uint16_t INITIAL_BALANCE = 15000;
const uint16_t TICKET_PRICE = 170;

const xpcsc::Byte CMD_LOAD_KEYS[] = {
	0xFF,
	0x82,
	0x00,
	0x00, 
	0x06,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00 
};

// template for General Auth command
const xpcsc::Byte CMD_GENERAL_AUTH[] = {
	0xFF,
	0x86,
	0x00,
	0x00, 
	0x05,
	0x01,
	0x00,
	0x00,
	0x60,
	0x00
};

const xpcsc::Byte CMD_READ_BINARY[] = { 0xFF, 0xB0, 0x00, 0x00, 0x10 };
