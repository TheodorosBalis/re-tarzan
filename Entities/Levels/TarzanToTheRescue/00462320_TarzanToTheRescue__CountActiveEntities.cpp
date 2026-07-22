#include "tarzan_ghidra_types.hpp"

// Address: 0x00462320
// Label: TarzanToTheRescue::CountActiveEntities
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int TarzanToTheRescue::CountActiveEntities(void)

{
  int count;
  int count2;
  
  count2 = 0;
  for (count = g_ActiveEntityListHead; count != 0; count = *(int *)(count + 0x20)) {
    count2 = count2 + 1;
  }
  return count2;
}

