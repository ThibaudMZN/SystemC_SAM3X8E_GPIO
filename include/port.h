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

 template<const int n = 32>
 SC_MODULE(port_n)                      // declare port sc_module
 {
   // sc_in<sc_uint<n> > A, B;          // input signal ports
   // sc_out<sc_uint<n+1> > F;          // output signal ports

   void do_update_port()
   {
     //F.write(A.read() + B.read());
     // TODO : describe internal register behavior
   }

   SC_CTOR(port_n)                      // constructor for port_n
   {
     SC_METHOD(do_update_port);         // register do_update_port with kernel
     //sensitive << A << B;               // sensitivity list
   }
 };
