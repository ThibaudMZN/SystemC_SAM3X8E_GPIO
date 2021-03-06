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

#ifndef PIO_H
#define PIO_H

#include "register.h"
#include "adr.h"
#include <vector>

#define MUX_PERIPH_A	1
#define MUX_PERIPH_B	2
#define MUX_GPIO		3


 class PIO
 {
 	uint32_t base_address;
   std::vector<Register> regs;
   void Callback_PER();
   void Callback_Glitch_debounce();
   void Callback_pull_up();
   void Callback_selection_IOline_peripheral();
   void Callback_inputEdge_LevelEdge();
   void Callback_selection_peripheral();
   void Callback_IMR();
   void Callback_FRLHSR();
   void Callback_ELSR();
   void Callback_AIMMR();
   void Callback_Output_control_OSR();
   void Callback_Output_control_ODSR();
   void Callback_multi_drive_control();

 public:
   PIO(uint32_t base);
   void initRegs();
   void pointToCallback();
   void write_in_reg(uint32_t n, uint32_t val);
   uint32_t read_in_reg(uint32_t n);
   void write_bit_in_reg(uint32_t n, uint8_t bit_index, bool bit_value);
   bool read_bit_in_reg(uint32_t n, uint8_t bit_index);
   bool interrupt;
   uint8_t select_peripheral(uint32_t index_register, uint8_t bit_index);
};

#endif
