#define SC_INCLUDE_DYNAMIC_PROCESSES

#include "systemc"
using namespace sc_core;
using namespace sc_dt;
using namespace std;

#include <vector>

#include "tlm.h"
#include "tlm_utils/simple_target_socket.h"

#include "PIO.h"
#include "initiator.h"

class PMC_TARGET: public sc_module
{
  bool* parent_enable;

  public:
    tlm_utils::simple_target_socket<PMC_TARGET> socket;

    PMC_TARGET(sc_module_name nm, bool* enable):sc_module(nm), socket("socket")
    {
      socket.register_b_transport(this, &PMC_TARGET::b_transport);
      parent_enable = enable;
    }

  virtual void b_transport( tlm::tlm_generic_payload& trans, sc_time& delay )
  {
    tlm::tlm_command cmd = trans.get_command();
    unsigned char*   ptr = trans.get_data_ptr();
    unsigned int     len = trans.get_data_length();

    if ( cmd == tlm::TLM_READ_COMMAND )
      memcpy(ptr, parent_enable, len);
    else if ( cmd == tlm::TLM_WRITE_COMMAND )
      memcpy(parent_enable, ptr, len);

    trans.set_response_status( tlm::TLM_OK_RESPONSE );
  }

};

class GPIO_TARGET: public sc_module
{
  uint32_t gpio_reg;
  uint8_t bit_offset;
  uint8_t ret;
  PIO* pio;

  std::vector<GPIO_INITIATOR*> peripheral_A;
  std::vector<GPIO_INITIATOR*> peripheral_B;

  public:
    tlm_utils::simple_target_socket<GPIO_TARGET> socket;

    GPIO_TARGET(sc_module_name nm, uint32_t reg_offset, uint8_t bit_addr, PIO* pio_master, std::vector<GPIO_INITIATOR*> periph_a, std::vector<GPIO_INITIATOR*> periph_b):sc_module(nm), socket("socket")
    {
      socket.register_b_transport(this, &GPIO_TARGET::b_transport);
      gpio_reg = reg_offset;
      bit_offset = bit_addr;
      pio = pio_master;
      peripheral_A = periph_a;
      peripheral_B = periph_b;
    }

  virtual void b_transport( tlm::tlm_generic_payload& trans, sc_time& delay )
  {
    tlm::tlm_command cmd = trans.get_command();
    unsigned char*   ptr = trans.get_data_ptr();

    if (cmd == tlm::TLM_WRITE_COMMAND)
    {
      //pio->write_bit_in_reg(gpio_offset/4, bit_offset, (bool*) ptr);
      ret = pio->select_peripheral(gpio_reg, bit_offset);
      if(ret == 1)
      {
        peripheral_A[bit_offset]->emit_value(ptr);
      } else if (ret == 2)
      {
        peripheral_B[bit_offset]->emit_value(ptr);
        // MUX B
      } else if (ret == 3)
      {
        // WRITE IN REG
        pio->write_bit_in_reg(gpio_reg/4, bit_offset, (bool*) ptr);
      }

      trans.set_response_status(tlm::TLM_OK_RESPONSE);
    }
  }

};
