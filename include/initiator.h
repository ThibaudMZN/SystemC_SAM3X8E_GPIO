#include "systemc"
using namespace sc_core;
using namespace sc_dt;
using namespace std;

#include "tlm.h"
#include "tlm_utils/simple_initiator_socket.h"

class NVIC_INITIATOR: sc_module
{
  tlm_utils::simple_initiator_socket<NVIC_INITIATOR> socket;
  bool Val;

  public:
    NVIC_INITIATOR(sc_module_name nm) :sc_module(nm), socket("socket")
    {
      Val = true;
    }

    void emit_interrupt()
    {
      tlm::tlm_generic_payload* trans = new tlm::tlm_generic_payload;
      sc_time delay = SC_ZERO_TIME;
      tlm::tlm_command cmd = tlm::TLM_WRITE_COMMAND;

      trans->set_command(cmd);
      trans->set_address(0);
      trans->set_data_ptr(reinterpret_cast<unsigned char*> (&Val));
      trans->set_data_length(1);
      trans->set_response_status(tlm::TLM_INCOMPLETE_RESPONSE);

      socket->b_transport(*trans, delay);

        if (trans->is_response_error())
          SC_REPORT_ERROR("TLM-2", "Response error from b_transport on NVIC_IITIATOR");
      }
};
