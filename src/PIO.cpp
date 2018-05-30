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
   interrupt = false;
 }

 void PIO::write_in_reg(uint32_t n, uint32_t val)
 {
   regs[n].write(val);
 }

 uint32_t PIO::read_in_reg(uint32_t n)
 {
   return regs[n].read();
 }

 void PIO::write_bit_in_reg(uint32_t n, uint8_t bit_index, bool bit_value)
 {
   regs[n].write_bit(bit_index, bit_value);
 }

 bool PIO::read_bit_in_reg(uint32_t n, uint8_t bit_index)
 {
   return regs[n].read_bit(bit_index);
 }


 void PIO::initRegs()
 {
   regs.push_back(*(new Register(base_address, PIO_PER_OFFSET, READ_WRITE, 0)));
   regs.push_back(*(new Register(base_address, PIO_PDR_OFFSET, READ_WRITE, 0)));
   regs.push_back(*(new Register(base_address, PIO_PSR_OFFSET, READ_WRITE, 0)));
   regs.push_back(*(new Register())); // RESERVED
   regs.push_back(*(new Register(base_address, PIO_OER_OFFSET, READ_WRITE, 0)));
   regs.push_back(*(new Register(base_address, PIO_ODR_OFFSET, READ_WRITE, 0)));
   regs.push_back(*(new Register(base_address, PIO_OSR_OFFSET, READ_WRITE, 0)));
   regs.push_back(*(new Register())); // RESERVED
   regs.push_back(*(new Register(base_address, PIO_IFER_OFFSET, READ_WRITE, 0)));
   regs.push_back(*(new Register(base_address, PIO_IFDR_OFFSET, READ_WRITE, 0)));
   regs.push_back(*(new Register(base_address, PIO_IFSR_OFFSET, READ_WRITE, 0)));
   regs.push_back(*(new Register())); // RESERVED
   regs.push_back(*(new Register(base_address, PIO_SODR_OFFSET, READ_WRITE, 0)));
   regs.push_back(*(new Register(base_address, PIO_CODR_OFFSET, READ_WRITE, 0)));
   regs.push_back(*(new Register(base_address, PIO_ODSR_OFFSET, READ_WRITE, 0)));
   regs.push_back(*(new Register(base_address, PIO_PDSR_OFFSET, READ_WRITE, 0)));
   regs.push_back(*(new Register(base_address, PIO_IER_OFFSET, READ_WRITE, 0)));
   regs.push_back(*(new Register(base_address, PIO_IDR_OFFSET, READ_WRITE, 0)));
   regs.push_back(*(new Register(base_address, PIO_IMR_OFFSET, READ_WRITE, 0)));
   regs.push_back(*(new Register(base_address, PIO_ISR_OFFSET, READ_WRITE, 0)));
   regs.push_back(*(new Register(base_address, PIO_MDER_OFFSET, READ_WRITE, 0)));
   regs.push_back(*(new Register(base_address, PIO_MDDR_OFFSET, READ_WRITE, 0)));
   regs.push_back(*(new Register(base_address, PIO_MDSR_OFFSET, READ_WRITE, 0)));
   regs.push_back(*(new Register())); // RESERVED
   regs.push_back(*(new Register(base_address, PIO_PUDR_OFFSET, READ_WRITE, 0)));
   regs.push_back(*(new Register(base_address, PIO_PUER_OFFSET, READ_WRITE, 0)));
   regs.push_back(*(new Register(base_address, PIO_PUSR_OFFSET, READ_WRITE, 0)));
   regs.push_back(*(new Register())); // RESERVED
   regs.push_back(*(new Register(base_address, PIO_ABSR_OFFSET, READ_WRITE, 0)));
   regs.push_back(*(new Register())); // RESERVED
   regs.push_back(*(new Register(base_address, PIO_SCIFSR_OFFSET, READ_WRITE, 0)));
   regs.push_back(*(new Register(base_address, PIO_IFDGSR_OFFSET, READ_WRITE, 0)));
   regs.push_back(*(new Register(base_address, PIO_SCDR_OFFSET, READ_WRITE, 0)));
   regs.push_back(*(new Register())); // RESERVED
   regs.push_back(*(new Register(base_address, PIO_OWER_OFFSET, READ_WRITE, 0)));
   regs.push_back(*(new Register(base_address, PIO_OWDR_OFFSET, READ_WRITE, 0)));
   regs.push_back(*(new Register())); // RESERVED
   regs.push_back(*(new Register(base_address, PIO_AIMER_OFFSET, READ_WRITE, 0)));
   regs.push_back(*(new Register(base_address, PIO_AIMDR_OFFSET, READ_WRITE, 0)));
   regs.push_back(*(new Register(base_address, PIO_AIMMR_OFFSET, READ_WRITE, 0)));
   regs.push_back(*(new Register())); // RESERVED
   regs.push_back(*(new Register(base_address, PIO_ESR_OFFSET, READ_WRITE, 0)));
   regs.push_back(*(new Register(base_address, PIO_LSR_OFFSET, READ_WRITE, 0)));
   regs.push_back(*(new Register(base_address, PIO_ELSR_OFFSET, READ_WRITE, 0)));
   regs.push_back(*(new Register())); // RESERVED
   regs.push_back(*(new Register(base_address, PIO_FELLSR_OFFSET, READ_WRITE, 0)));
   regs.push_back(*(new Register(base_address, PIO_REHLSR_OFFSET, READ_WRITE, 0)));
   regs.push_back(*(new Register(base_address, PIO_FRLHSR_OFFSET, READ_WRITE, 0)));
   regs.push_back(*(new Register())); // RESERVED
   regs.push_back(*(new Register(base_address, PIO_LOCKSR_OFFSET, READ_WRITE, 0)));
   regs.push_back(*(new Register(base_address, PIO_WPMR_OFFSET, READ_WRITE, 0)));
   regs.push_back(*(new Register(base_address, PIO_WPSR_OFFSET, READ_WRITE, 0)));

   pointToCallback();
 }

 void PIO::pointToCallback()
 {
   regs[0].init_write_handler(this, &PIO::Callback_PER);
   regs[1].init_write_handler(this, &PIO::Callback_PER);
   regs[PIO_PUDR_OFFSET/4].init_write_handler(this, &PIO::Callback_pull_up);
   regs[PIO_PUER_OFFSET/4].init_write_handler(this, &PIO::Callback_pull_up);
   regs[PIO_PER_OFFSET/4].init_write_handler(this, &PIO::Callback_selection_IOline_peripheral);
   regs[PIO_PDR_OFFSET/4].init_write_handler(this, &PIO::Callback_selection_IOline_peripheral);
   regs[PIO_PSR_OFFSET/4].init_write_handler(this, &PIO::Callback_selection_peripheral);
   regs[PIO_OER_OFFSET/4].init_write_handler(this, &PIO::Callback_Output_control_OSR);
   regs[PIO_ODR_OFFSET/4].init_write_handler(this, &PIO::Callback_Output_control_OSR);
   regs[PIO_SODR_OFFSET/4].init_write_handler(this, &PIO::Callback_Output_control_ODSR);
   regs[PIO_CODR_OFFSET/4].init_write_handler(this, &PIO::Callback_Output_control_ODSR);
   regs[PIO_SCIFSR_OFFSET/4].init_write_handler(this, &PIO::Callback_Glitch_debounce);
   regs[PIO_DIFSR_OFFSET/4].init_write_handler(this, &PIO::Callback_Glitch_debounce);
   regs[PIO_MDER_OFFSET/4].init_write_handler(this, &PIO::Callback_multi_drive_control);
   regs[PIO_MDDR_OFFSET/4].init_write_handler(this, &PIO::Callback_multi_drive_control);
   regs[PIO_IER_OFFSET/4].init_write_handler(this, &PIO::Callback_IMR);
   regs[PIO_IDR_OFFSET/4].init_write_handler(this, &PIO::Callback_IMR);
   regs[PIO_AIMER_OFFSET/4].init_write_handler(this, &PIO::Callback_AIMMR);
   regs[PIO_AIMDR_OFFSET/4].init_write_handler(this, &PIO::Callback_AIMMR);
   regs[PIO_ESR_OFFSET/4].init_write_handler(this, &PIO::Callback_ELSR);
   regs[PIO_LSR_OFFSET/4].init_write_handler(this, &PIO::Callback_ELSR);
   regs[PIO_FELLSR_OFFSET/4].init_write_handler(this, &PIO::Callback_FRLHSR);
   regs[PIO_REHLSR_OFFSET/4].init_write_handler(this, &PIO::Callback_FRLHSR);
   regs[PIO_IFSR_OFFSET/4].init_write_handler(this, &PIO::Callback_inputEdge_LevelEdge);
}

// Paragraph 31.5.2
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

// §31.5.2 if PIO_PSR value = 0, pin is controlled by PIO_ABSR, if PIO_PSR value = 1,pin is controlled by PIO controller
 void PIO::Callback_selection_IOline_peripheral()
 {
    regs[PIO_PSR_OFFSET/4].value = (regs[PIO_PER_OFFSET/4].value &
                                    ~regs[PIO_PDR_OFFSET/4].value);
 }
// §31.5.10 Input Edge/Level Interrupt
void PIO::Callback_inputEdge_LevelEdge()
{
//if (regs[PIO_PDSR_OFFSET/4].value != regs[PIO_PDSR_OFFSET/4].previous_value)
    regs[PIO_ISR_OFFSET/4].value = regs[PIO_PDSR_OFFSET/4].value &
                                   regs[PIO_IMR_OFFSET/4].value;
}

// PIO interrupt generation
void PIO::Callback_IMR()
{
    regs[PIO_IMR_OFFSET/4].value = regs[PIO_IER_OFFSET/4].value &
                                   ~regs[PIO_IDR_OFFSET/4].value;
}

// Additional interrupt mode activation
void PIO::Callback_AIMMR()
{
    regs[PIO_AIMMR_OFFSET/4].value = regs[PIO_AIMER_OFFSET/4].value &
                                   ~regs[PIO_AIMDR_OFFSET/4].value;
}

// Additional interrupt mode event selection
void PIO::Callback_ELSR()
{
   regs[PIO_ELSR_OFFSET/4].value = regs[PIO_ESR_OFFSET/4].value &
                                   ~regs[PIO_LSR_OFFSET/4].value;
}

// Additional interrupt mode : polarity event selection
void PIO::Callback_FRLHSR()
{
  regs[PIO_FRLHSR_OFFSET/4].value = regs[PIO_FELLSR_OFFSET/4].value &
                                      ~regs[PIO_REHLSR_OFFSET/4].value;
}

/*void selection_peripheral(); // bit = 0 (periph A), =1 (periph B) */
// §31.5.3 PIO_ABSR value = 0, pin is on peripheral A, PIO_ABSR value = 1, pin is on peripheral B
 void PIO::Callback_selection_peripheral()
{
    regs[PIO_ABSR_OFFSET/4].value = regs[PIO_PSR_OFFSET/4].value & 0xFFFFFFFF;
}

// Paragraph 31.5.4
 void PIO::Callback_Output_control_OSR()
 {
   regs[PIO_OSR_OFFSET/4].value = (regs[PIO_OER_OFFSET/4].value & ~regs[PIO_ODR_OFFSET/4].value); // OSR = OER  and not(ODR)
 }

 void PIO::Callback_Output_control_ODSR()
 {
 	uint32_t temp_val = 0;
 	uint32_t mask_set, mask_clear;
 	// To avoid modification of inputs
 	mask_set = regs[PIO_SODR_OFFSET/4].value & regs[PIO_OSR_OFFSET/4].value;
 	mask_clear = regs[PIO_CODR_OFFSET/4].value & regs[PIO_OSR_OFFSET/4].value;
 	regs[PIO_ODSR_OFFSET/4].value = mask_set & ~mask_clear; // ODSR = SODR  and not(CODR)
 }

// Paragraph 31.5.6
void PIO::Callback_multi_drive_control()
{
    regs[PIO_MDSR_OFFSET/4].value = (regs[PIO_MDER_OFFSET/4].value & ~regs[PIO_MDDR_OFFSET/4].value);
}

// Paragraph 31.5.8

// Paragraph 31.5.9
 void PIO::Callback_Glitch_debounce()
 {
   regs[PIO_IFDGSR_OFFSET/4].value = (regs[PIO_SCIFSR_OFFSET/4].value & ~regs[PIO_DIFSR_OFFSET/4].value); // PSR = SCIFSR  and not(DIFSR)
 }

// Paragraph 31.5.11 I/O lines lock
// If a GPIO is locked by a peripheral (mainly by PWM), writing in PER,PDR, MDER
//    PUDR, PUER and ABSR is discarded.
// Not implemented
