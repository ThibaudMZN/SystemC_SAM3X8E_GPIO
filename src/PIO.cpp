/**
 *  @file    PIO.cpp
 *  @author Thibaud Marazano (ThibaudMZN)
 *  @date    29/05/2018
 *  @version 1.0
 *
 *  @section DESCRIPTION
 *
 *  Instanciate all registers and register logic for PIO
 *
 */

 #include <stdint.h>
 #include "PIO.h"

 PIO::PIO (uint32_t base)
 {
   base_address = base;
 }

 void PIO::update()
 {

   PIO_PSR.write(PIO_PER.value & ~PIO_PDR.value);
   PIO_PUSR.write(PIO_PUER.value & ~PIO_PUDR.value);
 }
