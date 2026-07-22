#include "tarzan_ghidra_types.hpp"

// Address: 0x00487FA0
// Label: TrashingTheCamp::UpdateHog
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TrashingTheCamp::UpdateHog(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  char resultFlag;
  int value3;
  int value4;
  undefined4 value5;
  
  value = entity->sceneObjects;
  if (value != 0) {
    value4 = ((EntitySceneObject *)value)->surface;
    value2 = *(int *)(value4 + 0xc);
    if ((((*(uint *)(value4 + 0x14) & 0x8000) != 0) && ((*(uint *)(value4 + 0x14) & 1) != 0)) &&
       (value3 = RandomModulo(7), value3 == 0)) {
      ((EntitySceneObject *)value)->surfacePathIndex = (uint)*(ushort *)(value4 + 0x18);
      ((EntitySceneObject *)value)->surfaceIndex = ((EntitySceneObject *)value)->surfaceIndex - value2;
    }
    if (*(int *)(entry + 0x50) == 0) {
      value4 = RandomModulo(0x28);
      if (value4 == 0) {
        value5 = RandomModulo(5);
        switch(value5) {
        case 1:
          value5 = 0x2a6;
          break;
        case 2:
          value5 = 0x2a7;
          break;
        case 3:
          value5 = 0x2a8;
          break;
        case 4:
          value5 = 0x2a9;
          break;
        default:
          value5 = 0x2a5;
        }
        PlayAudioById(value5,(int *)0,(undefined4 *)&((EntitySceneObject *)value)->x);
        *(undefined4 *)(entry + 0x50) = 0x28;
      }
    }
    else {
      *(int *)(entry + 0x50) = *(int *)(entry + 0x50) + -1;
    }
    CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
    CEntities::MoveEntitySceneObjectAndEaseFacingAngles(entry,0x40);
    resultFlag = CEntities::CheckPlayerDamageContact(value);
    if (resultFlag != '\0') {
      QueuePlayerDamageEvent(entry,7);
      g_PlayerDamageContactEntitySceneObject = value;
    }
    if ((*(byte *)(value + 0x13c) & 2) != 0) goto LAB_004880b2;
  }
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag == '\0') {
    return;
  }
LAB_004880b2:
  CEntities::ReleaseEntityToFreeList((byte *)entry);
  return;
}

