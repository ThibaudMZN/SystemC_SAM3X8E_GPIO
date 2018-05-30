#include "initiator.h"
#include "target.h"
#include "systemc.h"
#include "PIO.h"

template<const int base_addr = 0x00>
SC_MODULE(pio_controller)
{

  PIO pio;
  bool enable;
  PMC_TARGET pmc_target = PMC_TARGET("pmc_target", &enable);

  SC_CTOR(pio_controller)
  {

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
