#include "tarzan_ghidra_types.hpp"

// Address: 0x0045DEA0
// Label: JourneyToTheTreeHouse::UpdateAmbientSoundEmitterC9
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void JourneyToTheTreeHouse::UpdateAmbientSoundEmitterC9(int entry)

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

