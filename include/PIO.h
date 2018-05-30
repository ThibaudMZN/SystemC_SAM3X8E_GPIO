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
   void Callback_pull_up();

 };
