#define SC_INCLUDE_DYNAMIC_PROCESSES

#include "systemc"
using namespace sc_core;
using namespace sc_dt;
using namespace std;

#include "tlm.h"
#include "tlm_utils/simple_target_socket.h"

#include "PIO.h"

class PMC_TARGET: public sc_module
{
  tlm_utils::simple_target_socket<PMC_TARGET> socket;
  bool* parent_enable;

  public:
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
  tlm_utils::simple_target_socket<GPIO_TARGET> socket;
  uint32_t gpio_offset;
  uint32_t bit_offset;
  PIO* pio;

  public:
    GPIO_TARGET(sc_module_name nm, uint32_t reg_offset, uint32_t bit_addr, PIO* pio_master):sc_module(nm), socket("socket")
    {
      socket.register_b_transport(this, &GPIO_TARGET::b_transport);
      gpio_offset = reg_offset;
      bit_offset = bit_addr;
      pio = pio_master;
    }

  virtual void b_transport( tlm::tlm_generic_payload& trans, sc_time& delay )
  {
    tlm::tlm_command cmd = trans.get_command();
    unsigned char*   ptr = trans.get_data_ptr();

    if (cmd == tlm::TLM_WRITE_COMMAND)
<<<<<<< HEAD
=======
    {
>>>>>>> 24ff0f5535a1265974af567d38bcb51c842d7180
      pio->write_bit_in_reg(gpio_offset/4, bit_offset, (bool*) ptr);
      trans.set_response_status(tlm::TLM_OK_RESPONSE);
    }
  }

};
