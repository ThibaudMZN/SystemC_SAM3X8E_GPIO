/**
 *  @file    port.h
 *  @author Thibaud Marazano (ThibaudMZN)
 *  @date    29/05/2018
 *  @version 1.0
 *
 *  @section DESCRIPTION
 *
 *  Generic class for GPIO port
 *
 */


 #include "systemc.h"

 template<const int n = 32, const int addr = 0>
 SC_MODULE(port_n)                      // declare port sc_module
 {
   sc_in<bool> clk, rst;
   sc_out<int> gpio;                    // int is 32 bits
   int base_addr;

   void do_update_port()
   {
     if(clk) {
       if(rst) {

       } else {
         gpio.write(base_addr);
       }
     }
     //F.write(A.read() + B.read());
     // TODO : describe internal register behavior
   }

   void do_reset(){

   }

   SC_CTOR(port_n)                      // constructor for port_n
   {
     SC_METHOD(do_update_port);         // register do_update_port with kernel
     sensitive << clk << rst;               // sensitivity list
     base_addr = addr;
   }
 };
