#include "tarzan_ghidra_types.hpp"

// Address: 0x0040B270
// Label: CampsiteCommotion::UpdateBarrelWorkerSpawner
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CampsiteCommotion::UpdateBarrelWorkerSpawner(undefined4 entry)

{
  char resultFlag;
  
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

