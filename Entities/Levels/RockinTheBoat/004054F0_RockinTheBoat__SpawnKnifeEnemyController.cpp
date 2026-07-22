#include "tarzan_ghidra_types.hpp"

// Address: 0x004054F0
// Label: RockinTheBoat::SpawnKnifeEnemyController
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void RockinTheBoat::SpawnKnifeEnemyController(void)

{
  g_RockinTheBoatKnifeEnemyControllerEntry =
       CEntities::SpawnEntityByTypeAtPosition(0,0,0,0x153,0x11);
  return;
}

