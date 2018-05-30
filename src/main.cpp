/**
 *  @file    main.cpp
 *  @author Thibaud Marazano (ThibaudMZN)
 *  @date    29/05/2018
 *  @version 1.0
 *
 *  @section DESCRIPTION
 *
 *  Generic main file for SystemC program.
 *
 */


#include <iostream>
#include "systemc.h"
#include "pio_controller.h"
#include "adr.h"

int sc_main(int argc, char* argv[])
{

  /*PIO p = PIO(PIOA_BASE_ADDR);
  p.regs[0].write(1);
  p.regs[1].write(2);
  //p.update();
  std::cout << p.regs[2].read() << std::endl;*/
  /*sc_signal<bool> clkSig, rstSig;
  sc_signal<int> port_out;

  stim Stim1("Stimulus");
  Stim1.clk(clkSig);
  Stim1.rst(rstSig);
  Stim1.gpio(port_out);

  port_n<PORT_A_SIZE, PIOA_BASE_ADDR> PORT_A("port_A");
  PORT_A.clk(clkSig);
  PORT_A.rst(rstSig);
  PORT_A.gpio(port_out);

  sc_start(); // run forever*/

  pio_controller<PIOA_BASE_ADDR> PIO_A("pio_A");
  //Top top_module("top");
  sc_start();

  return 0;

}
