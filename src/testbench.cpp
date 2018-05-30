#include "pio_controller.h"
#include "testbench_class.h"

int sc_main(int argc, char* argv[])
{
  pio_controller pio_controller("top_pio_controller");
  NVIC_TARGET nvic_target("nvic_target_tb");
  PMC_INITIATOR pmc_initiator("pmc_target_tb");

  sc_start();
  return 0;
}
