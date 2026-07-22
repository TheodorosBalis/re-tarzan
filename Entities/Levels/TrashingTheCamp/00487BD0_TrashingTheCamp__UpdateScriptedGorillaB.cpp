#include "tarzan_ghidra_types.hpp"

// Address: 0x00487BD0
// Label: TrashingTheCamp::UpdateScriptedGorillaB
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TrashingTheCamp::UpdateScriptedGorillaB(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  
  value = entity->sceneObjects;
  if (value != 0) {
    CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
    CEntities::MoveEntitySceneObjectAndEaseFacingAngles
              (entry,*(int *)(g_PlayerMotionState + 0x10) + 0x24);
    ((EntitySceneObject *)value)->y = ((EntitySceneObject *)value)->y + *(int *)(value + 0x58);
    if ((*(byte *)(value + 0x13c) & 2) != 0) {
      CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
    }
  }
  return;
}

