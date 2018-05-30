#include "systemc.h"
#include "PIO.h"

template<const int base_addr = 0x00>
SC_MODULE(pio_controller)
{
  // sc_out<bool> interrupt;

  // sc_in<uint32_t> in_peripheral_A;
  // sc_in<uint32_t> in_peripheral_B;
  //
  // sc_out<uint32_t> out_peripheral_A;
  // sc_out<uint32_t> out_peripheral_B;
  //
  // sc_in<uint32_t> in_pins;
  // sc_out<uint32_t> out_pins;

  PIO* pio;
  bool enable;


  /*void do_pio_control()
  {
    //F.write(A.read() + B.read());
    pio->write_in_reg(0, 1);
    pio->write_in_reg(1, 2);
  }

  SC_CTOR(pio_controller)
  {
    SC_METHOD(do_pio_control);
    sensitive << in_peripheral_A << in_peripheral_B << in_pins;
    pio = new PIO(base_addr);
  }*/
};
