#include "tarzan_ghidra_types.hpp"

// Address: 0x0044A5D0
// Label: CEntities::UpdateBananaPickup
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CEntities::UpdateBananaPickup(int entry)

{
  Entity *entity = (Entity *)entry;
  short shortValue;
  int value;
  char resultFlag;
  undefined4 value2;
  
  value = entity->sceneObjects;
  if (value != 0) {
    ((EntitySceneObject *)value)->yaw = ((EntitySceneObject *)value)->yaw + 0x38U & 0xfff;
    resultFlag = CEntities::IsPlayerWithinPickupTriggerBounds
                      (value,g_PlayerPickupTriggerRadius,
                       (int)*(short *)(g_PlayerEntitySceneObject + 0x142),0);
    if ((resultFlag != '\0') && (resultFlag = CEntities::CanStartPickupCollection(entry), resultFlag != '\0')) {
      switch(_g_PlayerHeroMode) {
      default:
        value2 = 0x5c;
        break;
      case 2:
      case 9:
        value2 = 0x1d;
        break;
      case 4:
      case 5:
        value2 = 0x22d;
        break;
      case 6:
        value2 = 0x4c0;
      }
      PlayAudioById(value2,(int *)0,(undefined4 *)0);
      if (*(short *)(entry + 0x4a) == 0) {
        shortValue = *(short *)(&g_SingleBananaHealthGainByDifficulty +
                          *( undefined1 *)((int)&g_LevelTransitionContext + 1) * 2);
      }
      else {
        shortValue = *(short *)((int)&g_BananaBunchHealthGainByDifficulty +
                          *( undefined1 *)((int)&g_LevelTransitionContext + 1) * 2);
      }
      g_PlayerHealth = g_PlayerHealth + shortValue;
      if ((int)(uint)g_PlayerMaxHealth < (int)(short)g_PlayerHealth) {
        g_PlayerHealth = g_PlayerMaxHealth;
      }
      CEntities::SpawnEntityByTypeAtPosition
                (((EntitySceneObject *)value)->x,((EntitySceneObject *)value)->y + -0xb4,
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

