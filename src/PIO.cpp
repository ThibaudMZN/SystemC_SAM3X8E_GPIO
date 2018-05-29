/**
 *  @file    PIO.cpp
 *  @author Thibaud Marazano (ThibaudMZN)
 *  @date    29/05/2018
 *  @version 1.0
 *
 *  @section DESCRIPTION
 *
 *  Instanciate all registers and register logic for PIO
 *
 */

 #include <stdint.h>
 #include "PIO.h"

 PIO::PIO (uint32_t base)
 {
   base_address = base;
   initRegs();
 }

 void PIO::initRegs()
 {
   regs.push_back(*(new Register(base_address, PIO_PER_OFFSET, WRITE_ONLY, 0)));
   regs.push_back(*(new Register(base_address, PIO_PDR_OFFSET, WRITE_ONLY, 0)));
   regs.push_back(*(new Register(base_address, PIO_PSR_OFFSET, READ_ONLY, 0)));

   regs.push_back(*(new Register())); // RESERVED

   regs.push_back(*(new Register(base_address, PIO_OER_OFFSET, WRITE_ONLY, 0)));
   regs.push_back(*(new Register(base_address, PIO_ODR_OFFSET, WRITE_ONLY, 0)));
   regs.push_back(*(new Register(base_address, PIO_OSR_OFFSET, READ_ONLY, 0)));

   regs.push_back(*(new Register())); // RESERVED

   //pointToCallback();
 }

 /*void pointToCallback()
 {

 }*/

 void PIO::update()
 {
   regs[2].value = (regs[0].value & ~regs[1].value); // PSR = PER  and not(PDR)
 }

 /*void PIO::update()
 {
   // Pin
   PIO_PSR.write(PIO_PER.value & ~PIO_PDR.value);
   // Pull Up
   PIO_PUSR.write(PIO_PUER.value & ~PIO_PUDR.value);
   // Output
   PIO_OSR.write(PIO_OER.value & ~PIO_ODR.value);
 }*/

 void PIO::write_in_reg(uint32_t n, uint32_t val)
 {
   regs[n].write(val);
 }

 uint32_t PIO::read_in_reg(uint32_t n)
 {
   return regs[n].read();
 }
