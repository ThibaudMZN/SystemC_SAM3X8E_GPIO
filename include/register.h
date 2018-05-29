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

class Register
{
	// Declaration des membres privees
	uint32_t address_base;
	uint32_t address_offset;
	uint32_t value;

public:
	Register(uint32_t base, uint32_t offset);
	Register(uint32_t base, uint32_t offset, uint32_t reset_value);
	void write(uint32_t value);
	uint32_t read(void);
	void write_bit(uint8_t bit_index, bool value);
	bool read_bit(uint8_t bit_index);
};

