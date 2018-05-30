#define SC_INCLUDE_DYNAMIC_PROCESSES

#include "systemc"
using namespace sc_core;
using namespace sc_dt;
using namespace std;

#include "tlm.h"
#include "tlm_utils/simple_target_socket.h"

struct PMC_TARGET: sc_module
{
  tlm_utils::simple_target_socket<PMC_TARGET> socket;

  PMC_TARGET(sc_module_name nm, bool* enable):sc_module(nm), socket("socket")
  {
    socket.register_b_transport(this, &PMC_TARGET::b_transport);
  }

  virtual void b_transport( tlm::tlm_generic_payload& trans, sc_time& delay )
  {
    tlm::tlm_command cmd = trans.get_command();
    unsigned char*   ptr = trans.get_data_ptr();
    unsigned int     len = trans.get_data_length();

    if ( cmd == tlm::TLM_READ_COMMAND )
      memcpy(ptr, enable, len);
    else if ( cmd == tlm::TLM_WRITE_COMMAND )
      memcpy(enable, ptr, len);

    trans.set_response_status( tlm::TLM_OK_RESPONSE );
  }

};
