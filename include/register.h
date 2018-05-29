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
	bool read_access;
	bool write_access;
	void (*handler_write)(uint32_t value);
	void (*handler_read)(void);

public:
	uint32_t value;

	Register(uint32_t base, uint32_t offset, uint8_t access);
	Register(uint32_t base, uint32_t offset, uint8_t access, uint32_t reset_value);
	void init_write_handler(void (*handler_write)(uint32_t write_value));
	void init_read_handler(void (*handler_read)(void));

	void write(uint32_t write_value);
	uint32_t read(void);
	void write_bit(uint8_t bit_index, bool bit_value);
	bool read_bit(uint8_t bit_index);
};

/*
enum
{
	PER,
	PDR,
	PSR,
	N_Used_1,
	OER,
	ODR,
	OSR,
	N_Used_2,
	IFER,
	IFDR,
	IFSR,
	N_Used_3,
	SODR,
	CODR,
	ODSR,
	PDSR,
	IER,
	IDR,
	IMR,
	ISR,
	MDER,
	MDDR,
	MDSR,
	N_Used_4,
	PUDR,
	PUER,
	PUSR,
	N_Used_5,
	ABSR,
	N_Used_6,
	SCIFSR,
	IFDGSR,
	SCDR,
	N_Used_7,
	OWER,
	OWDR,
	N_Used_8,
	AIMER,
	AIMDR,
	AIMMR,
	N_Used_9,
	ESR,
	LSR,
	ELSR,
	N_Used_10,
	FELLSR,
	REHLSR,
	FRLHSR,
	N_Used_11,
	LOCKSR,
	WPMR,
	WPSR
} Registers_list;
*/