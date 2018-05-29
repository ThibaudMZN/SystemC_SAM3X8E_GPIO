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

 template<const int n = 8>
 SC_MODULE(stim)
 {
   sc_out<bool> clk, rst;
   sc_out<sc_bigint<128>> 
   PIO_PER,
   PIO_PDR,
   PIO_OER,
   PIO_ODR,
   PIO_IFER,
   PIO_IFDR,
   PIO_SODR,
   PIO_CODR,
   PIO_IER,
   PIO_IDR,
   PIO_MDER,
   PIO_MDDR,
   PIO_PUDR,
   PIO_PUER,
   PIO_ABSR,
   PIO_OWER,
   PIO_OWDR;

   void StimGen()
   {
    PIO_PER.write(0x0000FFFF); // 0x0000FFFF
   PIO_PDR.write(0xFFFF0000); // 0xFFFF0000
   PIO_OER.write(0x000000FF); // 0x000000FF
   PIO_ODR.write(0xFFFFFF00);
   PIO_IFER.write();
   PIO_IFDR.write();
   PIO_SODR.write();
   PIO_CODR.write();
   PIO_IER.write();
   PIO_IDR.write();
   PIO_MDER.write();
   PIO_MDDR.write();
   PIO_PUDR.write();
   PIO_PUER.write();
   PIO_ABSR.write();
   PIO_OWER.write();
   PIO_OWDR.write();


     cout << "Done" << endl;

     sc_stop();
   }

   SC_CTOR(stim)
   {
     SC_THREAD(StimGen);
   }

 };
