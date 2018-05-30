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
#include <vector>


 class PIO
 {
 	uint32_t base_address;

 public:
 std::vector<Register> regs;
 	 PIO(uint32_t base);
   void initRegs();
   void pointToCallback();
   void write_in_reg(uint32_t n, uint32_t val);
   uint32_t read_in_reg(uint32_t n);

   void Callback_PER();
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
