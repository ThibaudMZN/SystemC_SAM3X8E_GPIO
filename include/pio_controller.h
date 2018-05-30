#include "initiator.h"
#include "target.h"
#include "systemc.h"
#include "PIO.h"

template<const uint32_t base_addr = 0x00>
SC_MODULE(pio_controller)
{
  bool enable;

  PIO pio;
  PMC_TARGET pmc_target;
  NVIC_INITIATOR nvic_initiator;

  SC_CTOR(pio_controller) :
  pio(base_addr),
  pmc_target("pmc_target", &enable),
  nvic_initiator("nvic_target")
  {
    nvic_initiator.emit_interrupt();
  }
};


/*SC_MODULE(Top)
{
  PMC_INITIATOR *initiator;
  PIO_TARGET    *memory;

  SC_CTOR(Top)
  {
    // Instantiate components
    initiator = new PMC_INITIATOR("initiator");
    memory    = new PIO_TARGET   ("memory");

    // One initiator is bound directly to one target with no intervening bus

    // Bind initiator socket to target socket
    initiator->socket.bind( memory->socket );
  }
};*/
