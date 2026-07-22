#include "tarzan_ghidra_types.hpp"

// Address: 0x00405DC0
// Label: RockinTheBoat::CountActiveKnifeEnemies
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int RockinTheBoat::CountActiveKnifeEnemies(int arg1)

{
  int count;
  int count2;
  
  count2 = 0;
  for (count = *(int *)(arg1 + 0x18); count != 0; count = *(int *)(count + 0x18)) {
    if (*(short *)(count + 0x46) == 0x150) {
      count2 = count2 + 1;
    }
  }
  return count2;
}

