#include "tarzan_ghidra_types.hpp"

// Address: 0x00427B20
// Label: ElephantHairDare::UpdateOneShotSoundCue
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ElephantHairDare::UpdateOneShotSoundCue(undefined4 entry)

{
  char resultFlag;
  
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

