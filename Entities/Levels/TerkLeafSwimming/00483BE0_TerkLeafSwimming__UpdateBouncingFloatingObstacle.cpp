#include "tarzan_ghidra_types.hpp"

// Address: 0x00483BE0
// Label: TerkLeafSwimming::UpdateBouncingFloatingObstacle
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TerkLeafSwimming::UpdateBouncingFloatingObstacle(int entry)

{
  Entity *entity = (Entity *)entry;
  int *intCursor;
  short *value4;
  char resultFlag;
  short shortValue;
  int value;
  int value2;
  int value3;
  
  value = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
  if (value != 0) {
    switch(*(undefined4 *)(value + 0xc)) {
    case 0:
      value3 = *(int *)(entity->sceneObjects + 0x14) - *(int *)(g_PlayerEntitySceneObject + 0x14)
      ;
      value2 = *(int *)(entity->sceneObjects + 0x1c) - *(int *)(g_PlayerEntitySceneObject + 0x1c)
      ;
      if (value2 * value2 + value3 * value3 < 0x400000) {
        *(undefined4 *)(value + 0xc) = 1;
      }
      break;
    case 1:
      value3 = CEntities::FindEntityAttachmentByFlags(entry,0x20000000);
      if (value3 != 0) {
        CEntities::AdvanceEntityBounceMotionAndReturnImpact(entry);
        if ((((EntitySceneObject *)value)->x == 0) &&
           (shortValue = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry), shortValue == 1)) {
          ((EntitySceneObject *)value)->x = 1;
        }
        if (*(int *)(value3 + 0x20) < 0) {
          *(undefined4 *)(value + 0xc) = 2;
        }
      }
      break;
    case 2:
      value3 = entity->sceneObjects;
      value2 = GetWrappedSignedAngleDelta12Bit((int)*(short *)(value3 + 0xa0),0x5dc);
      value4 = (short *)(value3 + 0xa0);
      *value4 = *value4 + (short)(value2 >> 4);
      CEntities::AdvanceEntityBounceMotionAndReturnImpact(entry);
      value3 = entity->sceneObjects;
      if (((EntitySceneObject *)value)->worldObject + -0x40 < ((EntitySceneObject *)value3)->y) {
        CEntities::SpawnLeafSwimmingWhirlpoolSplashEffects
                  (((EntitySceneObject *)value3)->x,((EntitySceneObject *)value3)->y,
                   ((EntitySceneObject *)value3)->z,0);
        *(undefined4 *)(value + 0xc) = 3;
      }
      break;
    case 3:
      value3 = *(int *)(entity->sceneObjects + 0x30);
      *(int *)(entity->sceneObjects + 0x30) = value3 - (value3 + -0x100 >> 4);
      value3 = CEntities::AdvanceEntityBounceMotionAndReturnImpact(entry);
      if (value3 != 0) {
        *(undefined4 *)(value + 0xc) = 4;
      }
      break;
    case 4:
      value = CEntities::FindEntityAttachmentByFlags(entry,0x20000000);
      if (value != 0) {
        *(int *)(entity->sceneObjects + 0x14) =
             *(int *)(entity->sceneObjects + 0x14) + *(int *)(value + 0x40);
        *(int *)(entity->sceneObjects + 0x14) =
             *(int *)(entity->sceneObjects + 0x14) + *(int *)(value + 0x40);
        intCursor = (int *)(entity->sceneObjects + 0x18);
        *intCursor = *intCursor + 0x10;
      }
      value = entity->sceneObjects;
      value3 = GetWrappedSignedAngleDelta12Bit((int)*(short *)(value + 0xa0),0);
      value4 = (short *)(value + 0xa0);
      *value4 = *value4 + (short)(value3 >> 4);
    }
  }
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

