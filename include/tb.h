/**
 *  @file    tb.h
 *  @author Pacôme Lebeau (Pakish)
 *  @date    29/05/2018
 *  @version 1.0
 *
 *  @section DESCRIPTION
 *
 *  TestBench for main.cpp, containing simulation
 *
 */

 #include "systemc.h"
 #include <iostream>

 using namespace std;

 SC_MODULE(stim)
 {
   sc_out<bool> clk, rst;

   void StimGen()
   {
     clk.write(false);
     rst.write(false);

     cout << "Done" << endl;

     sc_stop();
   }

   SC_CTOR(stim)
   {
     SC_THREAD(StimGen);
   }

 };
