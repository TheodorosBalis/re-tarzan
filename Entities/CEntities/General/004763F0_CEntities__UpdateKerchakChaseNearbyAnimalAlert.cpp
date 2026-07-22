#include "tarzan_ghidra_types.hpp"

// Address: 0x004763F0
// Label: CEntities::UpdateKerchakChaseNearbyAnimalAlert
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CEntities::UpdateKerchakChaseNearbyAnimalAlert(int entry)

{
  Entity *entity = (Entity *)entry;
  ushort *dataCursor;
  char resultFlag;
  short shortValue;
  int value;
  int value2;
  int value3;
  int value4;
  int *intCursor;
  short shortValue2;
  uint value5;
  undefined4 value6;
  
  value = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
  if (value == 0) goto LAB_004767c6;
  if (*(int *)(value + 0xc) == 0) {
    if ((g_KerchakChasePrimaryPursuerEntity != 0) &&
       (value4 = *(int *)(*(int *)(g_KerchakChasePrimaryPursuerEntity + 0x38) + 0x14) -
                *(int *)(entity->sceneObjects + 0x14),
       value2 = *(int *)(*(int *)(g_KerchakChasePrimaryPursuerEntity + 0x38) + 0x1c) -
               *(int *)(entity->sceneObjects + 0x1c), value2 * value2 + value4 * value4 < 0x90000))
    {
      *(undefined4 *)(value + 0xc) = 1;
      return;
    }
    value2 = *(int *)(*(int *)(g_PlayerEntity + 0x38) + 0x14) -
            *(int *)(entity->sceneObjects + 0x14);
    value4 = *(int *)(*(int *)(g_PlayerEntity + 0x38) + 0x1c) -
            *(int *)(entity->sceneObjects + 0x1c);
    value4 = value4 * value4 + value2 * value2;
    if ((0xd070f < value4) || (value4 < 1)) goto LAB_004767c6;
    *(undefined4 *)(value + 0xc) = 1;
    PlayAudioById(0x323,(int *)entity->sceneObjects + 0x104,(undefined4 *)entity->sceneObjects + 0x14);
    value4 = RandomModulo(3);
    if (value4 == 0) {
      value6 = 0x366;
LAB_00476510:
      PlayAudioById(value6,(int *)0,(undefined4 *)g_PlayerEntitySceneObject + 0x14);
    }
    else {
      if (value4 == 1) {
        value6 = 0x367;
        goto LAB_00476510;
      }
      if (value4 == 2) {
        value6 = 0x368;
        goto LAB_00476510;
      }
    }
    *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0xffffe200;
    dataCursor = (ushort *)(entity->sceneObjects + 0xe);
    *dataCursor = *dataCursor & 0x7fff;
  }
  else if (*(int *)(value + 0xc) != 1) goto LAB_004767c6;
  dataCursor = (ushort *)(entity->sceneObjects + 0xe);
  *dataCursor = *dataCursor & 0x7fff;
  _g_CampBoxCameraShakeTimer = 0x20;
  _g_CampBoxCameraShakeAmplitude = 0x10;
  PlayForceFeedbackEffect_Stub(0,2,0xf);
  PlayForceFeedbackEffect_Stub(0,8,8);
  shortValue2 = 0;
  value5 = 0x200;
  do {
    value2 = RandomModulo(0x100,0x160,0x11);
    value4 = *(int *)(entity->sceneObjects + 0x1c);
    value3 = RandomModulo(0x100);
    value2 = RandomModulo(0x100,(value4 - value2) + value3);
    value4 = *(int *)(entity->sceneObjects + 0x18);
    value3 = RandomModulo(0x100);
    value2 = RandomModulo(0x100,(value4 - value2) + 0x100 + value3);
    value4 = *(int *)(entity->sceneObjects + 0x14);
    value3 = RandomModulo(0x100);
    value4 = CEntities::SpawnEntityByTypeAtPosition((value4 - value2) + value3);
    if (value4 != 0) {
      *(undefined4 *)(*(int *)(value4 + 0x38) + 0x10) = g_CurrentWorldSceneContext;
      *(undefined2 *)(*(int *)(value4 + 0x38) + 0xc) = 0x200d;
      value2 = CEntities::FindEntityAttachmentByFlags(value4,0x20000000);
      if (value2 != 0) {
        value3 = RandomModulo(0x1e);
        *(int *)(value2 + 0x40) =
             (int)(short)(&g_SinCosTable12Bit)[value5 - 0x400 & 0xfff] * (value3 + 0x32) >> 0xc;
        *(int *)(value2 + 0x44) =
             (int)(short)(&g_SinCosTable12Bit)[value5 & 0xfff] * (value3 + 0x32) >> 0xc;
        shortValue = RandomModulo(0x100);
        *(short *)(value2 + 0x54) = shortValue + 0x7f;
        shortValue = RandomModulo(0x100);
        *(short *)(value2 + 0x56) = shortValue + 0x80;
        *(short *)(*(int *)(value4 + 0x38) + 0xa2) = (shortValue2 + 1) * 0x200;
        *(undefined2 *)(*(int *)(value4 + 0x38) + 0xa0) = 0x400;
        *(int *)(value2 + 0x24) = *(int *)(entity->sceneObjects + 0x18) + 0x100;
        value4 = RandomModulo(0x32);
        *(int *)(value2 + 0x18) = value4 + 0x1e;
        *(undefined4 *)(value2 + 0x10) = 0;
      }
    }
    value5 = value5 + 0x200;
    shortValue2 = shortValue2 + 1;
  } while ((int)value5 < 0x1a00);
  value4 = entity->sceneObjects;
  value4 = CEntities::SpawnEntityByTypeAtPosition
                    (((EntitySceneObject *)value4)->x,((EntitySceneObject *)value4)->y + 0x100,
                     ((EntitySceneObject *)value4)->z,0x15e,0x11);
  if (value4 != 0) {
    *(undefined4 *)(*(int *)(value4 + 0x38) + 0xb4) = 1;
    *(undefined4 *)(*(int *)(value4 + 0x38) + 0xa8) = 19000;
    *(undefined4 *)(*(int *)(value4 + 0x38) + 0xac) = 19000;
    *(undefined4 *)(*(int *)(value4 + 0x38) + 0xb0) = 19000;
    *(undefined4 *)(*(int *)(value4 + 0x38) + 0x6c) = 0xffffff00;
    *(undefined4 *)(*(int *)(value4 + 0x38) + 0x30) = 0xc00;
  }
  value4 = entity->sceneObjects;
  intCursor = (int *)CEntities::SpawnEntityByTypeAtPosition
                            (((EntitySceneObject *)value4)->x,((EntitySceneObject *)value4)->y + 0x100,
                             ((EntitySceneObject *)value4)->z,0x178,0x11);
  if ((intCursor != (int *)0x0) && (*intCursor != 0)) {
    *(int *)(intCursor[0xe] + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x2ff0;
    *(undefined2 *)(intCursor[0xe] + 0xc) = 0x2035;
    value4 = CEntities::FindEntityAttachmentByFlags(intCursor,0x10000000);
    if (value4 != 0) {
      value2 = *(int *)(entity->sceneObjects + 0x18);
      *(undefined4 *)(value4 + 0x524) = 0x180;
      ((EntitySceneObject *)value4)->next = value2 + 0x100;
    }
  }
  *(undefined4 *)(value + 0xc) = 2;
LAB_004767c6:
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

