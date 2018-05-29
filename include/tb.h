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
   PIO_IFER.write(0x00000F00);
   PIO_IFDR.write(0xFFFFF0FF);
   PIO_SODR.write(0x00000000);
   PIO_CODR.write(0x0FFFFFFF);
   PIO_IER.write(0x0F000F00);
   PIO_IDR.write(0xF0FFF0FF);
   PIO_MDER.write(0x0000000F);
   PIO_MDDR.write(0xFFFFFFF0);
   PIO_PUDR.write(0xF0F000F0);
   PIO_PUER.write(0X0F0FFF0F);
   PIO_ABSR.write(0x00F00000);
   PIO_OWER.write(0x0000000F);
   PIO_OWDR.write(0x0FFFFFF0);


     cout << "Done" << endl;

     sc_stop();
   }

   SC_CTOR(stim)
   {
     SC_THREAD(StimGen);
   }

 };
