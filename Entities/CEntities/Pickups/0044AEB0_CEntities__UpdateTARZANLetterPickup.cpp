#include "tarzan_ghidra_types.hpp"

// Address: 0x0044AEB0
// Label: CEntities::UpdateTARZANLetterPickup
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CEntities::UpdateTARZANLetterPickup(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  char resultFlag;
  undefined4 value2;
  
  value = entity->sceneObjects;
  if (value == 0) {
LAB_0044afa2:
    resultFlag = IsEntityOutsideOuterActivationBounds(entry);
    if (resultFlag != '\0') {
      CEntities::ReleaseEntityToFreeList((byte *)entry);
    }
    return;
  }
  ((EntitySceneObject *)value)->yaw = ((EntitySceneObject *)value)->yaw + 0x38U & 0xfff;
  resultFlag = CEntities::IsPlayerWithinPickupTriggerBounds
                    (value,g_PlayerPickupTriggerRadius,
                     (int)*(short *)(g_PlayerEntitySceneObject + 0x142),0);
  if ((resultFlag == '\0') || (resultFlag = CEntities::CanStartPickupCollection(entry), resultFlag == '\0'))
  goto LAB_0044afa2;
  PlayAudioById(0xb6,0,(undefined4 *)(&((EntitySceneObject *)value)->x));
  switch(_g_PlayerHeroMode) {
  case 1:
  case 7:
    value2 = 0x5d;
    break;
  case 2:
  case 9:
    value2 = 0x1e;
    break;
  default:
    goto switchD_0044af35_caseD_3;
  case 4:
  case 5:
    value2 = 0x22e;
    break;
  case 6:
    value2 = 0x4c1;
  }
  PlayAudioById(value2,(int *)0,(undefined4 *)0);
switchD_0044af35_caseD_3:
  g_CollectedTARZANLetterMask6 = g_CollectedTARZANLetterMask6 | *(byte *)(entry + 0x4c);
  g_HudCollectedTARZANslotSlideTicks = 0x5a;
  CEntities::SpawnEntityByTypeAtPosition
            (((EntitySceneObject *)value)->x,((EntitySceneObject *)value)->y,
             ((EntitySceneObject *)value)->z,0x14,0x11);
  CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
  return;
}

