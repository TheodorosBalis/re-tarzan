#include "tarzan_ghidra_types.hpp"

// Address: 0x0044EE40
// Label: SaborAttacks::UpdateOneShotSoundCue
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void SaborAttacks::UpdateOneShotSoundCue(undefined4 entry)

{
  char resultFlag;
  
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

