
#define SC_INCLUDE_DYNAMIC_PROCESSES
#include "systemc"
using namespace sc_core;
using namespace sc_dt;
using namespace std;

#include "tlm.h"
#include <iostream>
#include "tlm_utils/simple_target_socket.h"



class PMC_INITIATOR: sc_module
{
  tlm_utils::simple_initiator_socket<NVIC_INITIATOR> socket;
  bool enable;

  public:
    PMC_INITIATOR(sc_module_name nm):sc_module(nm), socket("socket")
    {
      enable = true;
    }

    void emit_enable()
    {
      tlm::tlm_generic_payload* trans = new tlm::tlm_generic_payload;
      sc_time delay = SC_ZERO_TIME;
      tlm::tlm_command cmd = tlm::TLM_WRITE_COMMAND;

      trans->set_command(cmd);
      trans->set_address(0);
      trans->set_data_ptr(reinterpret_cast<unsigned char*> (&enable));
      trans->set_data_length(1);
      trans->set_response_status(tlm::TLM_INCOMPLETE_RESPONSE);

      socket->b_transport(*trans, delay);
      cout << "send enable to PIO controller..." << endl;
        if (trans->is_response_error())
          cout << "unable to send to PIO controller..." << endl;
      }
};


class NVIC_TARGET: public sc_module
{
  tlm_utils::simple_target_socket<NVIC_TARGET> socket;

  public:
    NVIC_TARGET(sc_module_name nm):sc_module(nm), socket("socket")
    {
      socket.register_b_transport(this, &NVIC_TARGET::b_transport);
    }

  virtual void b_transport( tlm::tlm_generic_payload& trans, sc_time& delay )
  {
    tlm::tlm_command cmd = trans.get_command();
    unsigned char*   ptr = trans.get_data_ptr();
    unsigned int     len = trans.get_data_length();

    if ( cmd == tlm::TLM_READ_COMMAND )
      cout << "cannot read a target" << endl;
    else if ( cmd == tlm::TLM_WRITE_COMMAND && ptr=true)
      cout<<"Interrupt detected" << endl;

    trans.set_response_status( tlm::TLM_OK_RESPONSE );
  }

};
