#include "tarzan_ghidra_types.hpp"

// Address: 0x00487600
// Label: TrashingTheCamp::UpdateYoungGorilla
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TrashingTheCamp::UpdateYoungGorilla(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  char resultFlag;
  short shortValue;
  int value2;
  int value3;
  
  value = entity->sceneObjects;
  if (value != 0) {
    value2 = CEntities::FindEntityAttachmentByFlags(entry,0x400);
    if (value2 != 0) {
      if (*(short *)(entry + 0x48) != 0) {
        CEntities::MoveEntitySceneObjectAndEaseFacingAngles(entry,*(undefined4 *)(entry + 0x4c))
        ;
      }
      resultFlag = CEntities::CheckPlayerDamageContact(value);
      if (resultFlag != '\0') {
        QueuePlayerDamageEvent(entry,7);
        g_PlayerDamageContactEntitySceneObject = value;
        *(byte *)(value + 0x75) = ~*(byte *)(value + 0x75);
      }
      shortValue = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
      if (shortValue == 5) {
        value2 = RandomModulo(10);
        *(int *)(entry + 0x50) = value2 + 5;
        *(undefined2 *)(entry + 0x48) = 1;
      }
    }
    value2 = ((EntitySceneObject *)value)->next;
    if (value2 != 0) {
      value3 = GetSceneAttachmentWorldPositionByMask(value,1,value2 + 0x14);
      if (value3 != 0) {
        *(undefined2 *)(value2 + 0xa2) = ((EntitySceneObject *)value)->yaw;
        *(short *)(value2 + 0xa0) = *(short *)(value2 + 0xa0) + *(short *)(entry + 0x4c) * 2;
      }
    }
  }
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

