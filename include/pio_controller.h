#include "initiator.h"
#include "target.h"
#include "systemc.h"
#include "PIO.h"
#include "adr.h"

template<const uint32_t base_addr = 0x00>
SC_MODULE(pio_controller)
{
  bool enable;

  PIO pio;
  PMC_TARGET pmc_target;
  NVIC_INITIATOR nvic_initiator;
  GPIO_TARGET URXD;
  GPIO_INITIATOR UTXD;

  SC_CTOR(pio_controller) :
  pio(base_addr),
  pmc_target("pmc_target", &enable),
  nvic_initiator("nvic_target"),
<<<<<<< HEAD
  URXD("urxd", PIO_PDSR_OFFSET, (uint8_t) 8, &pio_master)
  UTXD("utxd")
=======
  URXD("urxd", PIO_PDSR_OFFSET, (uint8_t) 8, &pio)
>>>>>>> 24ff0f5535a1265974af567d38bcb51c842d7180
  {
    //nvic_initiator.emit_interrupt();
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
