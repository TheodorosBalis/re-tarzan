#include "tarzan_ghidra_types.hpp"

// Address: 0x004874B0
// Label: TrashingTheCamp::UpdateGorillaOnBox
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TrashingTheCamp::UpdateGorillaOnBox(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  char resultFlag;
  short shortValue;
  uint value2;
  
  value = entity->sceneObjects;
  if (value != 0) {
    if (*(short *)(entry + 0x48) != 0) {
      CEntities::MoveEntitySceneObjectAndEaseFacingAngles(entry,*(short *)(entry + 0x48));
    }
    resultFlag = CEntities::CheckPlayerDamageContact(value);
    if (resultFlag != '\0') {
      QueuePlayerDamageEvent(entry,0x1006);
      g_PlayerDamageContactEntitySceneObject = value;
      value2 = CEntities::ComputeSignedPlayerFacingDistanceXZ(&((EntitySceneObject *)value)->x);
      if (*(byte *)(value + 0x75) != 0) {
        value2 = ~value2 + 1;
      }
      if ((int)value2 < 0) {
        *(byte *)(value + 0x75) = ~*(byte *)(value + 0x75);
      }
    }
    shortValue = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
    if (shortValue == 4) {
      *(undefined2 *)(entry + 0x48) = 0;
    }
    else if (shortValue == 5) {
      shortValue = RandomModulo(0x20);
      *(short *)(entry + 0x48) = shortValue + 0x20;
    }
  }
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

