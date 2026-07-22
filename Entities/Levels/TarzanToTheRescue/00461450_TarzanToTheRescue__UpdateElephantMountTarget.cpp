#include "tarzan_ghidra_types.hpp"

// Address: 0x00461450
// Label: TarzanToTheRescue::UpdateElephantMountTarget
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TarzanToTheRescue::UpdateElephantMountTarget(undefined4 entry)

{
  char resultFlag;
  
  CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

