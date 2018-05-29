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
#include "port.h"
#include "tb.h"

#define PORT_A_SIZE 32

int sc_main(int argc, char* argv[])
{
  sc_signal<bool> clkSig, rstSig;
  sc_signal<int> port_out;

  stim Stim1("Stimulus");
  Stim1.clk(clkSig);
  Stim1.rst(rstSig);

  port_n<PORT_A_SIZE> PORT_A("port_A");
  PORT_A.clk(clkSig);
  PORT_A.rst(rstSig);
  PORT_A.gpio(port_out);

  sc_start(); // run forever*/

  return 0;

}
