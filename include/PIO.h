/**
 *  @file    PIO.h
 *  @author Thibaud Marazano (ThibaudMZN)
 *  @date    29/05/2018
 *  @version 1.0
 *
 *  @section DESCRIPTION
 *
 *  Class container for PIO
 *
 */

using namespace std;

#include "register.h"
#include "adr.h"


 class PIO
 {
 	uint32_t base_address;

 public:
 	 PIO(uint32_t base);
   // Pin
   Register PIO_PER = Register(base_address, PIO_PER_OFFSET, 0);
   Register PIO_PDR = Register(base_address, PIO_PDR_OFFSET, 0);
   Register PIO_PSR = Register(base_address, PIO_PSR_OFFSET, 0);
   // Pull Up
   Register PIO_PUER = Register(base_address, PIO_PUER_OFFSET, 0);
   Register PIO_PUDR = Register(base_address, PIO_PUDR_OFFSET, 0);
   Register PIO_PUSR = Register(base_address, PIO_PUSR_OFFSET, 0);
   // Output
   Register PIO_OER = Register(base_address, PIO_OER_OFFSET, 0);
   Register PIO_ODR = Register(base_address, PIO_ODR_OFFSET, 0);
   Register PIO_OSR = Register(base_address, PIO_OSR_OFFSET, 0);
   void update();
 };
