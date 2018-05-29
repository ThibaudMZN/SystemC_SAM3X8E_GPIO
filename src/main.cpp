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


#include "systemc.h"
#include "PIO.h"
#include "adr.h"
#include <iostream>

int sc_main(int argc, char* argv[])
{

  PIO p = PIO(PIOA_BASE_ADDR);
  p.PIO_PER.write(1);
  p.PIO_PDR.write(2);
  p.update();
  std::cout << p.PIO_PSR.read() << std::endl;
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

  return 0;

}
