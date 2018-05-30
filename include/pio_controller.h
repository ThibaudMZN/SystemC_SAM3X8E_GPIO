#include "initiator.h"
#include "target.h"
#include "systemc.h"
#include "PIO.h"

template<const int base_addr = 0x00>
SC_MODULE(pio_controller)
{

  PIO* pio; // déclaration d'un PIO CONTROLLER
  bool enable; // envoyé par PMC
};


SC_MODULE(Top)
{
  Initiator *initiator;
  Memory    *memory;

  SC_CTOR(Top)
  {
    // Instantiate components
    initiator = new Initiator("initiator");
    memory    = new Memory   ("memory");

    // One initiator is bound directly to one target with no intervening bus

    // Bind initiator socket to target socket
    initiator->socket.bind( memory->socket );
  }
};
