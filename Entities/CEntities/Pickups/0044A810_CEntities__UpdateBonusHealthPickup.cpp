#include "tarzan_ghidra_types.hpp"

// Address: 0x0044A810
// Label: CEntities::UpdateBonusHealthPickup
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::UpdateBonusHealthPickup(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  char resultFlag;
  
  value = entity->sceneObjects;
  if (value != 0) {
    ((EntitySceneObject *)value)->yaw = ((EntitySceneObject *)value)->yaw + 0x38U & 0xfff;
    resultFlag = CEntities::IsPlayerWithinPickupTriggerBounds
                      (value,g_PlayerPickupTriggerRadius,
                       (int)*(short *)(g_PlayerEntitySceneObject + 0x142),0);
    if ((resultFlag != '\0') && (resultFlag = CEntities::CanStartPickupCollection(entry), resultFlag != '\0')) {
      g_PlayerMaxHealth = g_PlayerMaxHealth + 0x20;
      PlayAudioById(0xbd,(int *)0,(undefined4 *)0);
      if (0x180 < g_PlayerMaxHealth) {
        g_PlayerMaxHealth = 0x180;
      }
      CEntities::SpawnEntityByTypeAtPosition
                (((EntitySceneObject *)value)->x,((EntitySceneObject *)value)->y,
                 ((EntitySceneObject *)value)->z,0x14,0x11);
      CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
      return;
    }
  }
  resultFlag = CEntities::UpdateBouncingPickupMotionAndLifetime(entry);
  if ((resultFlag != '\0') || (resultFlag = IsEntityOutsideOuterActivationBounds(entry), resultFlag != '\0')) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

