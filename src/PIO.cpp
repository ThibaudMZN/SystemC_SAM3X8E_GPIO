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
 #include <iostream>
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
   regs.push_back(*(new Register(base_address, PIO_IFER_OFFSET, WRITE_ONLY, 0)));
   regs.push_back(*(new Register(base_address, PIO_IFDR_OFFSET, WRITE_ONLY, 0)));
 	 regs.push_back(*(new Register(base_address, PIO_IFSR_OFFSET, READ_ONLY, 0)));
 	 regs.push_back(*(new Register())); // RESERVED
 	 regs.push_back(*(new Register(base_address, PIO_SODR_OFFSET, WRITE_ONLY, 0)));
 	 regs.push_back(*(new Register(base_address, PIO_CODR_OFFSET, WRITE_ONLY, 0)));
 	 regs.push_back(*(new Register(base_address, PIO_ODSR_OFFSET, READ_WRITE, 0)));
 	 regs.push_back(*(new Register(base_address, PIO_PDSR_OFFSET, READ_ONLY, 0)));
 	 regs.push_back(*(new Register(base_address, PIO_IER_OFFSET, WRITE_ONLY, 0)));
 	 regs.push_back(*(new Register(base_address, PIO_IDR_OFFSET, WRITE_ONLY, 0)));
 	 regs.push_back(*(new Register(base_address, PIO_IMR_OFFSET, READ_ONLY, 0)));
 	 regs.push_back(*(new Register(base_address, PIO_ISR_OFFSET, READ_ONLY, 0)));
 	 regs.push_back(*(new Register(base_address, PIO_MDER_OFFSET, WRITE_ONLY, 0)));
 	 regs.push_back(*(new Register(base_address, PIO_MDDR_OFFSET, WRITE_ONLY, 0)));
 	 regs.push_back(*(new Register(base_address, PIO_MDSR_OFFSET, READ_ONLY, 0)));
 	 regs.push_back(*(new Register())); // RESERVED
 	 regs.push_back(*(new Register(base_address, PIO_PUDR_OFFSET, WRITE_ONLY, 0)));
 	 regs.push_back(*(new Register(base_address, PIO_PUER_OFFSET, WRITE_ONLY, 0)));
 	 regs.push_back(*(new Register(base_address, PIO_PUSR_OFFSET, READ_ONLY, 0)));
 	 regs.push_back(*(new Register())); // RESERVED
 	 regs.push_back(*(new Register(base_address, PIO_ABSR_OFFSET, READ_WRITE, 0)));
 	 regs.push_back(*(new Register())); // RESERVED
 	 regs.push_back(*(new Register(base_address, PIO_SCIFSR_OFFSET, WRITE_ONLY, 0)));
 	 regs.push_back(*(new Register(base_address, PIO_IFDGSR_OFFSET, WRITE_ONLY, 0)));
 	 regs.push_back(*(new Register(base_address, PIO_SCDR_OFFSET, READ_WRITE, 0)));
 	 regs.push_back(*(new Register())); // RESERVED
 	 regs.push_back(*(new Register(base_address, PIO_OWER_OFFSET, WRITE_ONLY, 0)));
 	 regs.push_back(*(new Register(base_address, PIO_OWDR_OFFSET, WRITE_ONLY, 0)));
 	 regs.push_back(*(new Register())); // RESERVED
 	 regs.push_back(*(new Register(base_address, PIO_AIMER_OFFSET, WRITE_ONLY, 0)));
 	 regs.push_back(*(new Register(base_address, PIO_AIMDR_OFFSET, WRITE_ONLY, 0)));
 	 regs.push_back(*(new Register(base_address, PIO_AIMMR_OFFSET, READ_ONLY, 0)));
 	 regs.push_back(*(new Register())); // RESERVED
 	 regs.push_back(*(new Register(base_address, PIO_ESR_OFFSET, WRITE_ONLY, 0)));
 	 regs.push_back(*(new Register(base_address, PIO_LSR_OFFSET, WRITE_ONLY, 0)));
 	 regs.push_back(*(new Register(base_address, PIO_ELSR_OFFSET, READ_ONLY, 0)));
 	 regs.push_back(*(new Register())); // RESERVED
 	 regs.push_back(*(new Register(base_address, PIO_FELLSR_OFFSET, WRITE_ONLY, 0)));
 	 regs.push_back(*(new Register(base_address, PIO_REHLSR_OFFSET, WRITE_ONLY, 0)));
 	 regs.push_back(*(new Register(base_address, PIO_FRLHSR_OFFSET, READ_ONLY, 0)));
 	 regs.push_back(*(new Register())); // RESERVED
 	 regs.push_back(*(new Register(base_address, PIO_LOCKSR_OFFSET, READ_ONLY, 0)));
 	 regs.push_back(*(new Register(base_address, PIO_WPMR_OFFSET, READ_WRITE, 0)));
 	 regs.push_back(*(new Register(base_address, PIO_WPSR_OFFSET, READ_ONLY, 0)));

   pointToCallback();
 }

 void PIO::pointToCallback()
 {
   regs[0].init_write_handler(this, &PIO::Callback_PER);
   regs[1].init_write_handler(this, &PIO::Callback_PER);
 }

 void PIO::Callback_PER()
 {
   regs[2].value = (regs[0].value & ~regs[1].value); // PSR = PER  and not(PDR)
 }



// §31.5.1 pull-up disabled PIO_PUSR = 1, pull_up enabled PIO_PUSR = 0
void PIO::Callback_pull_up()
 {
   regs[PIO_PUSR_OFFSET/4].value = (regs[PIO_PUDR_OFFSET/4].value &
                                    regs[PIO_PUER_OFFSET/4].value);
    
 }

// §
/* void PIO::selection_IOline_peripheral()
{
    PIO_PSR = PIO_PER & not(PIO_PDR);
    PIO_PSR = 1            // lreset value of PIO_PSR
    if PIO_PSR = 1
    then I/O_line = PIO_ABSR
    else PIO_PSR = 0
    then I/O_line = PIO_controller
    }
    void selection_peripheral(); // bit = 0 (periph A), =1 (periph B)
    {
        
    }
*/

 /* void PIO::update()
 {
   regs[2].value = (regs[0].value & ~regs[1].value); // PSR = PER  and not(PDR)
 }*/

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
