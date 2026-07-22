#include "tarzan_ghidra_types.hpp"

// Address: 0x0040CE20
// Label: CampsiteCommotion::UpdateFallingCampDebris
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CampsiteCommotion::UpdateFallingCampDebris(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  char resultFlag;
  int value2;
  int value3;
  
  value = entity->sceneObjects;
  if (value != 0) {
    value2 = CEntities::FindEntityAttachmentByFlags(entry,0x800);
    if (value2 != 0) {
      value3 = *(int *)(value2 + 0x20) + *(int *)(value2 + 0x24);
      *(int *)(value2 + 0x20) = value3;
      if (*(int *)(value2 + 0x2c) < value3) {
        *(int *)(value2 + 0x20) = *(int *)(value2 + 0x2c);
      }
      ((EntitySceneObject *)value)->y = ((EntitySceneObject *)value)->y + *(int *)(value2 + 0x20);
    }
    ComputeEntitySceneObjectCollisionMoveDelta(0,0,value);
    value2 = ((EntitySceneObject *)value)->next;
    if (value2 != 0) {
      value3 = ((EntitySceneObject *)value)->y + *(int *)(value + 0x58);
      *(int *)(value2 + 0x18) = value3;
      value3 = (((EntitySceneObject *)value)->y - value3 >> 2) + 0x400;
      if (value3 < 0) {
        value3 = 0;
      }
      *(int *)(value2 + 0x30) = value3;
    }
    resultFlag = CEntities::CheckPlayerDamageContact(value);
    if (resultFlag != '\0') {
      QueuePlayerDamageEvent(entry,10);
      g_PlayerDamageContactEntitySceneObject = value;
    }
    resultFlag = CEntities::CheckEntitySceneObjectVerticalImpact(value);
    if (resultFlag != '\0') {
      CEntities::SpawnEntityByTypeAtPosition
                (((EntitySceneObject *)value)->x,((EntitySceneObject *)value)->y,
                 ((EntitySceneObject *)value)->z,0x11d,0x11);
      PlayAudioById(0x2d3,(int *)0,(undefined4 *)&((EntitySceneObject *)value)->x);
      value2 = 3;
      do {
        value3 = (int)*(short *)(&g_CampsiteCommotionFallingDebrisModelTable +
                               g_CampsiteCommotionFallingDebrisModelIndex * 2);
        if (value3 != -1) {
          if (value3 != 0) {
            CEntities::SpawnMappedEffectOnSurfaceWithScatterConfig
                      (value3,((EntitySceneObject *)value)->surfacePathIndex,((EntitySceneObject *)value)->surfaceIndex,
                       &g_CampsiteCommotionFallingDebrisImpactDesc);
          }
          g_CampsiteCommotionFallingDebrisModelIndex =
               g_CampsiteCommotionFallingDebrisModelIndex + 1;
        }
        value2 = value2 + -1;
      } while (value2 != 0);
      CEntities::ReleaseEntityToFreeList((byte *)entry);
    }
  }
  return;
}

