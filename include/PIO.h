/**
 *  @file    PIO.h
 *  @author Thibaud Marazano (ThibaudMZN)
 *  @date    29/05/2018
 *  @version 1.0
 *
 *  @section DESCRIPTION
 *
 *  Class container for PIO
 *
 */

using namespace std;

#include "register.h"
#include "adr.h"


 class PIO
 {
 	uint32_t base_address;

 public:
 	 PIO(uint32_t base);
   void initRegs();
   //void pointToCallback();
   void update();
   void write_in_reg(uint32_t n, uint32_t val);
   uint32_t read_in_reg(uint32_t n);
   /*// Pin
   Register PIO_PER = Register(base_address, PIO_PER_OFFSET, 0);
   Register PIO_PDR = Register(base_address, PIO_PDR_OFFSET, 0);
   Register PIO_PSR = Register(base_address, PIO_PSR_OFFSET, 0);
   // Pull Up
   Register PIO_PUER = Register(base_address, PIO_PUER_OFFSET, 0);
   Register PIO_PUDR = Register(base_address, PIO_PUDR_OFFSET, 0);
   Register PIO_PUSR = Register(base_address, PIO_PUSR_OFFSET, 0);
   // Output
   Register PIO_OER = Register(base_address, PIO_OER_OFFSET, 0);
   Register PIO_ODR = Register(base_address, PIO_ODR_OFFSET, 0);
   Register PIO_OSR = Register(base_address, PIO_OSR_OFFSET, 0);*/
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
