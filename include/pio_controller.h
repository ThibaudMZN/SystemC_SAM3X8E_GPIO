#include "initiator.h"
#include "target.h"
#include "systemc.h"
#include "PIO.h"
#include "adr.h"
#include <vector>
#include <string>

template<const uint32_t base_addr = 0x00>
SC_MODULE(pio_controller)
{
  bool enable;

  PIO pio;
  PMC_TARGET pmc_target;
  NVIC_INITIATOR nvic_initiator;

  std::vector<GPIO_INITIATOR*> peripheral_A;
  std::vector<GPIO_INITIATOR*> peripheral_B;

  std::vector<GPIO_TARGET*> pins;

  SC_CTOR(pio_controller) :
  pio(base_addr),
  pmc_target("pmc_target", &enable),
  nvic_initiator("nvic_target")
  {
    for(int i = 0; i < 32; i++)
    {
      peripheral_A.push_back(new GPIO_INITIATOR("peripheral_A"));
      peripheral_B.push_back(new GPIO_INITIATOR("peripheral_B"));
      pins.push_back(new GPIO_TARGET("pin", PIO_PDSR_OFFSET, i, &pio, peripheral_A, peripheral_B));
    }
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
