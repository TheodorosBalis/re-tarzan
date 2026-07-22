#include "tarzan_ghidra_types.hpp"

// Address: 0x00488BC0
// Label: TrashingTheCamp::UpdateCampSoundCue
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TrashingTheCamp::UpdateCampSoundCue(undefined4 entry)

{
  char resultFlag;
  
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

