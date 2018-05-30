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

#include "testbench_class.h"
#include <vector>

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

  /*pio_controller<PIOA_BASE_ADDR> PIO_A("pio_A");
  //Top top_module("top");
  sc_start();

  return 0;*/
  pio_controller<PIOA_BASE_ADDR> pio_controller("top_pio_controller");
  NVIC_TARGET nvic_target("nvic_target_tb");
  PMC_INITIATOR pmc_initiator("pmc_target_tb");

  std::vector<GPIO_TARGET_TB*> periph_A_tb;
  std::vector<GPIO_TARGET_TB*> periph_B_tb;

  std::vector<GPIO_INITIATOR_TB*> pins_tb;

  for(int i = 0; i < 32; i++)
  {
    periph_A_tb.push_back(new GPIO_TARGET_TB("peripheral_A"));
    periph_B_tb.push_back(new GPIO_TARGET_TB("peripheral_B"));
    pins_tb.push_back(new GPIO_INITIATOR_TB("pin"));

    pio_controller.peripheral_A[i]->socket.bind(periph_A_tb[i]->socket);
    pio_controller.peripheral_B[i]->socket.bind(periph_B_tb[i]->socket);
    pio_controller.pins[i]->socket.bind(pins_tb[i]->socket);
  }



  // Bind initiator socket to target sockets
  pmc_initiator.socket.bind(pio_controller.pmc_target.socket);
  pio_controller.nvic_initiator.socket.bind( nvic_target.socket);

  sc_start();

  std::cout << std::endl << std::endl << std::endl << std::endl;
  pmc_initiator.emit_enable();

  return 0;

}
