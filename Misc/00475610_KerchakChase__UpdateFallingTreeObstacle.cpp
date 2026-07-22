#include "tarzan_ghidra_types.hpp"

// Address: 0x00475610
// Label: KerchakChase::UpdateFallingTreeObstacle
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void KerchakChase::UpdateFallingTreeObstacle(int entry)

{
  Entity *entity = (Entity *)entry;
  ushort *dataCursor;
  short *value6;
  char resultFlag;
  short shortValue;
  int value;
  int value2;
  int value3;
  int *intCursor;
  short shortValue2;
  uint value4;
  undefined4 value5;
  
  value = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
  if (value == 0) goto LAB_004759dc;
  if (*(int *)(value + 0xc) == 0) {
    value2 = *(int *)(*(int *)(g_PlayerEntity + 0x38) + 0x1c) -
            *(int *)(entity->sceneObjects + 0x1c);
    value3 = *(int *)(*(int *)(g_PlayerEntity + 0x38) + 0x14) -
            *(int *)(entity->sceneObjects + 0x14);
    if (value2 * value2 + value3 * value3 < 64000000) {
      *(undefined4 *)(value + 0xc) = 1;
      PlayAudioById(0x325,(int *)entity->sceneObjects + 0x104,(undefined4 *)entity->sceneObjects + 0x14);
    }
    goto LAB_004759dc;
  }
  if (*(int *)(value + 0xc) != 1) goto LAB_004759dc;
  CEntities::MoveEntityForwardAndEaseFacingYaw(entry,0x30);
  value3 = entity->sceneObjects;
  value2 = CEntities::GetEntitySceneObjectVerticalCollisionDelta(value3);
  ((EntitySceneObject *)value3)->y = ((EntitySceneObject *)value3)->y + value2;
  *(int *)(entity->sceneObjects + 0x18) = *(int *)(entity->sceneObjects + 0x18) + -0x24c;
  value6 = (short *)(entity->sceneObjects + 0xa4);
  *value6 = *value6 + -0x60;
  resultFlag = CEntities::DoEntitySceneObjectSphereAttachmentsOverlapByFlags
                    (entity->sceneObjects,0x200,g_PlayerEntitySceneObject,0x200);
  if (resultFlag == '\0') goto LAB_004759dc;
  value3 = RandomModulo(3);
  *(undefined4 *)(value + 0xc) = 2;
  dataCursor = (ushort *)(entity->sceneObjects + 0xe);
  *dataCursor = *dataCursor & 0x7fff;
  PlayAudioById(0x323,(int *)0,(undefined4 *)entity->sceneObjects + 0x14);
  _g_CampBoxCameraShakeTimer = 0x20;
  _g_CampBoxCameraShakeAmplitude = 0x10;
  PlayForceFeedbackEffect_Stub(0,2,0xf);
  PlayForceFeedbackEffect_Stub(0,8,8);
  if (value3 == 0) {
    value5 = 0x366;
LAB_00475721:
    PlayAudioById(value5,(int *)0,(undefined4 *)0);
  }
  else {
    if (value3 == 1) {
      value5 = 0x367;
      goto LAB_00475721;
    }
    if (value3 == 2) {
      value5 = 0x368;
      goto LAB_00475721;
    }
  }
  shortValue2 = 0;
  value4 = 0x200;
  do {
    value3 = RandomModulo(0x100,0x160,0x11);
    value = *(int *)(entity->sceneObjects + 0x1c);
    value2 = RandomModulo(0x100);
    value3 = RandomModulo(0x200,(value - value3) + value2);
    value = *(int *)(entity->sceneObjects + 0x18);
    value2 = RandomModulo(0x200);
    value3 = RandomModulo(0x100,(value - value3) + 0x100 + value2);
    value = *(int *)(entity->sceneObjects + 0x14);
    value2 = RandomModulo(0x100);
    value = CEntities::SpawnEntityByTypeAtPosition((value - value3) + value2);
    if (value != 0) {
      *(undefined4 *)(*(int *)(value + 0x38) + 0x10) = g_CurrentWorldSceneContext;
      *(undefined2 *)(*(int *)(value + 0x38) + 0xc) = 0x200d;
      value3 = CEntities::FindEntityAttachmentByFlags(value,0x20000000);
      if (value3 != 0) {
        value2 = RandomModulo(0x1e);
        *(int *)(value3 + 0x40) =
             (int)(short)(&g_SinCosTable12Bit)[value4 - 0x400 & 0xfff] * (value2 + 0x32) >> 0xc;
        *(int *)(value3 + 0x44) =
             (int)(short)(&g_SinCosTable12Bit)[value4 & 0xfff] * (value2 + 0x32) >> 0xc;
        shortValue = RandomModulo(0x100);
        *(short *)(value3 + 0x54) = shortValue + 0x7f;
        shortValue = RandomModulo(0x100);
        *(short *)(value3 + 0x56) = shortValue + 0x80;
        *(short *)(*(int *)(value + 0x38) + 0xa2) = (shortValue2 + 1) * 0x200;
        *(undefined2 *)(*(int *)(value + 0x38) + 0xa0) = 0x400;
        *(int *)(value3 + 0x24) = *(int *)(entity->sceneObjects + 0x18) + 0x100;
        value = RandomModulo(0x32);
        ((EntitySceneObject *)value3)->y = value + 0x1e;
        ((EntitySceneObject *)value3)->worldObject = 0;
      }
    }
    value4 = value4 + 0x200;
    shortValue2 = shortValue2 + 1;
  } while ((int)value4 < 0x1a00);
  value = entity->sceneObjects;
  value = CEntities::SpawnEntityByTypeAtPosition
                    (((EntitySceneObject *)value)->x,((EntitySceneObject *)value)->y + 0x100,
                     ((EntitySceneObject *)value)->z,0x15e,0x11);
  if (value != 0) {
    *(undefined4 *)(*(int *)(value + 0x38) + 0xb4) = 1;
    *(undefined4 *)(*(int *)(value + 0x38) + 0xa8) = 19000;
    *(undefined4 *)(*(int *)(value + 0x38) + 0xac) = 19000;
    *(undefined4 *)(*(int *)(value + 0x38) + 0xb0) = 19000;
    *(undefined4 *)(*(int *)(value + 0x38) + 0x6c) = 0xffffff00;
    *(undefined4 *)(*(int *)(value + 0x38) + 0x30) = 0xc00;
  }
  value = entity->sceneObjects;
  intCursor = (int *)CEntities::SpawnEntityByTypeAtPosition
                            (((EntitySceneObject *)value)->x,((EntitySceneObject *)value)->y + 0x100,
                             ((EntitySceneObject *)value)->z,0x178,0x11);
  if ((intCursor != (int *)0x0) && (*intCursor != 0)) {
    *(int *)(intCursor[0xe] + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x2ff0;
    *(undefined2 *)(intCursor[0xe] + 0xc) = 0x2035;
    value = CEntities::FindEntityAttachmentByFlags(intCursor,0x10000000);
    if (value != 0) {
      value5 = *(undefined4 *)(g_PlayerEntitySceneObject + 0x18);
      *(undefined4 *)(value + 0x524) = 0x100;
      ((EntitySceneObject *)value)->next = value5;
    }
  }
LAB_004759dc:
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

