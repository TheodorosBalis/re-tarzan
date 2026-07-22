#include "tarzan_ghidra_types.hpp"

// Address: 0x00487E00
// Label: TrashingTheCamp::UpdateCivetCub
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TrashingTheCamp::UpdateCivetCub(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  char resultFlag;
  short shortValue;
  
  value = entity->sceneObjects;
  if (value != 0) {
    shortValue = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
    if (shortValue == 7) {
      ((EntitySceneObject *)value)->yaw = ((EntitySceneObject *)value)->yaw ^ 0x800;
      *(byte *)(value + 0x75) = ~*(byte *)(value + 0x75);
    }
    CEntities::MoveEntitySceneObjectAndEaseFacingAngles(entry,0);
  }
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

