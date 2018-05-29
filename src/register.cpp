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

Register::Register()
{

}

Register::Register (uint32_t base, uint32_t offset, uint8_t access)
{
	srand (time(NULL));

	address_base = base;
	address_offset = offset;

	value = rand() % 2^32;	// The value of register at power up is random

	// To prepare the rigth
	read_access = access & READ;
	write_access = access & WRITE;

	// No handler after init
	handler_write = NULL;
	handler_read = NULL;
}

Register::Register (uint32_t base, uint32_t offset, uint8_t access, uint32_t reset_value)
{
	address_base = base;
	address_offset = offset;

	value = reset_value; 	// Value is define in documentation

	// To prepare the rigth
	read_access = access & READ;
	write_access = access & WRITE;

	// No handler after init
	handler_write = NULL;
	handler_read = NULL;
}

void Register::init_write_handler(void (*handler)(uint32_t value))
{
	handler_write = handler;
}

void Register::init_read_handler(void (*handler)(void))
{
	handler_read = handler;
}

void Register::write(uint32_t write_value)
{
	if (write_access)
	{
		value = write_value;
		if (handler_write != NULL)
			handler_write(value);
	}
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

	if (handler_read != NULL)
		handler_read();

	return value;
}

void Register::write_bit(uint8_t bit_index, bool bit_value)
{
	uint32_t temp_value = 0;

	if (write_access)
	{
		temp_value = 1 << bit_index;
		if (bit_value==1)
		{
			value |= temp_value;
		}
		else
		{
			value &= !temp_value;
		}
		if (handler_write != NULL)
			handler_write(value);
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

	if (handler_read != NULL)
		handler_read();

	return respons;
}
