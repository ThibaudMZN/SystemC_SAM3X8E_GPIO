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

Register::Register (uint32_t base, uint32_t offset, uint8_t access)
{
	srand (time(NULL));

	address_base = base;
	address_offset = offset;

	value = rand() % 2^32;	// The value of register at power up is random

	// To prepare the rigth
	read_access = access & READ;
	write_access = access & WRITE;
}

Register::Register (uint32_t base, uint32_t offset, uint8_t access, uint32_t reset_value)
{
	address_base = base;
	address_offset = offset;

	value = reset_value; 	// Value is define in documentation

	// To prepare the rigth
	read_access = access & READ;
	write_access = access & WRITE;
}

void Register::write(uint32_t value)
{
	if (write_access)
		value = value;
}

uint32_t Register::read(void)
{
	uint32_t respons;

	if (read_access)
	{
		respons = value;
	}
	else
		respons = 0;
	return value;
}

void Register::write_bit(uint8_t bit_index, bool value)
{
	uint32_t temp_value = 0;

	if (write_access)
	{
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
}

bool Register::read_bit(uint8_t bit_index)
{
	uint32_t temp_value = 0;
	uint32_t respons;

	if (read_access)
	{
		temp_value = 1 << bit_index;
		respons = value & temp_value;;
	}
	else
		respons = 0;
}
