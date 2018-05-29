/**
 *  @file    register.h
 *  @author jfGr
 *  @date    29/05/2018
 *  @version 1.0
 *
 *  @section DESCRIPTION
 *
 *  Header for resgiter class to manage register in SystemC.
 *
 */

using namespace std;

#define NO_ACCESS	0x00
#define READ 0x01
#define WRITE 0x02
#define READ_ONLY	READ
#define WRITE_ONLY	WRITE
#define READ_WRITE	READ + WRITE

class Register
{
	// Declaration des membres privees
	uint32_t address_base;
	uint32_t address_offset;
	uint32_t value;
	bool read_access;
	bool write_access;

public:
	Register(uint32_t base, uint32_t offset, uint8_t access);
	Register(uint32_t base, uint32_t offset, uint8_t access, uint32_t reset_value);
	void write(uint32_t value);
	uint32_t read(void);
	void write_bit(uint8_t bit_index, bool value);
	bool read_bit(uint8_t bit_index);
};

