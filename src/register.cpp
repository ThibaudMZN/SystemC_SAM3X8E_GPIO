/**
 *  @file    register.cpp
 *  @author jfGr
 *  @date    29/05/2018
 *  @version 1.0
 *
 *  @section DESCRIPTION
 *
 *  Resgiter class to manage register in SystemC.
 *
 */


#include <stdlib.h>     /* srand, rand */

#include "systemc.h"

#include "register.h"

using namespace std;

Register::Register (uint32_t base, uint32_t offset)
{
	srand (time(NULL));

	address_base = base;
	address_offset = offset;

	value = rand() % 2^32;	// The value of register at power up is random
}

Register::Register (uint32_t base, uint32_t offset, uint32_t reset_value)
{
	address_base = base;
	address_offset = offset;

	value = reset_value; 	// Value is define in documentation
}

void Register::write(uint32_t value)
{
	value = value;
}

uint32_t Register::read(void)
{
	return value;
}

void Register::write_bit(uint8_t bit_index, bool value)
{
	uint32_t temp_value = 0;

	temp_value = 1 << bit_index;
	if (value==1)
	{
		value |= temp_value;
	}
	else
	{
		value &= !temp_value;
	}
}

bool Register::read_bit(uint8_t bit_index)
{
	uint32_t temp_value = 0;

	temp_value = 1 << bit_index;
	return(value & temp_value);
}
