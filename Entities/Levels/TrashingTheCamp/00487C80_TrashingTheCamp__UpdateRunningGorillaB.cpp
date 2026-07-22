#include "tarzan_ghidra_types.hpp"

// Address: 0x00487C80
// Label: TrashingTheCamp::UpdateRunningGorillaB
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TrashingTheCamp::UpdateRunningGorillaB(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  char resultFlag;
  
  value = entity->sceneObjects;
  if (value != 0) {
    resultFlag = CEntities::CheckPlayerDamageContact(value);
    if (resultFlag != '\0') {
      QueuePlayerDamageEvent(entry,7);
      g_PlayerDamageContactEntitySceneObject = value;
      *(byte *)(value + 0x75) = ~*(byte *)(value + 0x75);
    }
    CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
    CEntities::MoveEntitySceneObjectAndEaseFacingAngles(entry,0x40);
  }
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

