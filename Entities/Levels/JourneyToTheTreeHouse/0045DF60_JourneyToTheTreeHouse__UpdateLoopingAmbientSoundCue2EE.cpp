#include "tarzan_ghidra_types.hpp"

// Address: 0x0045DF60
// Label: JourneyToTheTreeHouse::UpdateLoopingAmbientSoundCue2EE
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void JourneyToTheTreeHouse::UpdateLoopingAmbientSoundCue2EE(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  char resultFlag;
  
  value = entity->sceneObjects;
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    DetachEntitySoundHandle(&((EntitySceneObject *)value)->soundPosition);
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

