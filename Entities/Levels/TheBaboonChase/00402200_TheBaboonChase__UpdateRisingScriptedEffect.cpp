#include "tarzan_ghidra_types.hpp"

// Address: 0x00402200
// Label: TheBaboonChase::UpdateRisingScriptedEffect
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TheBaboonChase::UpdateRisingScriptedEffect(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  char resultFlag;
  
  value = entity->sceneObjects;
  if (value != 0) {
    CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
    if (*(short *)(entry + 0x48) == 2) {
      ((EntitySceneObject *)value)->y = ((EntitySceneObject *)value)->y + 0x90;
    }
    if (0x800 < ((EntitySceneObject *)value)->y) {
      CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
    }
  }
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

