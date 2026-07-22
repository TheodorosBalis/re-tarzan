#include "tarzan_ghidra_types.hpp"

// Address: 0x00408620
// Label: RockinTheBoat::UpdateIndestructibleShipAttackTarget
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void RockinTheBoat::UpdateIndestructibleShipAttackTarget(undefined4 entry)

{
  CEntities::CheckEntityHitByPlayerAttackOrThrowable(entry);
  return;
}

