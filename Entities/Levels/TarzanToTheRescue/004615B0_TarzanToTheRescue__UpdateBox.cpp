#include "tarzan_ghidra_types.hpp"

// Address: 0x004615B0
// Label: TarzanToTheRescue::UpdateBox
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void TarzanToTheRescue::UpdateBox(int entry)

{
  Entity *entity = (Entity *)entry;
  char resultFlag;
  short shortValue;
  int value;
  int value2;
  int value3;
  short shortValue2;
  int value4;
  uint value5;
  
  CEntities::CheckEntityHitByPlayerAttackOrThrowable(entry);
  value = CEntities::FindEntityAttachmentByFlags(entry,0x10000016);
  if (value == 0) goto switchD_0046160d_caseD_8;
  if ((*(int *)(entity->sceneObjects + 0x60) != 0) && (*(int *)(value + 0xc) != 0xc)) {
    *(undefined4 *)(value + 0xc) = 0x12;
  }
  switch(*(undefined4 *)(value + 0xc)) {
  case 7:
    if (-1 < ((EntitySceneObject *)value)->x) {
      *(short *)(entity->sceneObjects + 0xa0) =
           (short)((int)(short)(&g_SinCosTable12Bit)[((EntitySceneObject *)value)->y - 0x400U & 0xfff] *
                   ((EntitySceneObject *)value)->x >> 0xc);
      *(short *)(entity->sceneObjects + 0xa4) =
           (short)((int)(short)(&g_SinCosTable12Bit)[((EntitySceneObject *)value)->y & 0xfff] *
                   ((EntitySceneObject *)value)->x >> 0xc);
    }
    ((EntitySceneObject *)value)->x = ((EntitySceneObject *)value)->x - ((EntitySceneObject *)value)->z;
    ((EntitySceneObject *)value)->y = ((EntitySceneObject *)value)->y + 0x80;
  default:
    goto switchD_0046160d_caseD_8;
  case 0xb:
    ((EntitySceneObject *)value)->x = 0x80;
    break;
  case 0xc:
    _g_CampBoxCameraShakeTimer = 8;
    _g_CampBoxCameraShakeAmplitude = 0xc;
    PlayForceFeedbackEffect_Stub(0,2,0xf);
    PlayAudioById(0x389,(int *)0,(undefined4 *)entity->sceneObjects + 0x14);
    value4 = entity->sceneObjects;
    if (*(int *)(value + 0x30) == 0) {
      CEntities::SpawnEntityByTypeAtPosition
                (((EntitySceneObject *)value4)->x,((EntitySceneObject *)value4)->y + -0x80,
                 ((EntitySceneObject *)value4)->z,0x178,0x11);
    }
    else {
      value4 = CEntities::SpawnEntityByTypeAtPosition
                        (((EntitySceneObject *)value4)->x,((EntitySceneObject *)value4)->y,
                         ((EntitySceneObject *)value4)->z,0x178,0x11);
      if ((value4 != 0) &&
         (*(undefined2 *)(*(int *)(value4 + 0x38) + 0xc) = 0x2001, *(int *)(value + 0x30) == 3)) {
        *(undefined2 *)(*(int *)(value4 + 0x38) + 0xc) = 0x2029;
      }
    }
    PlayForceFeedbackEffect_Stub(0,8,8);
    shortValue2 = 0;
    value5 = 0x200;
    do {
      value4 = entity->sceneObjects;
      value4 = CEntities::SpawnEntityByTypeAtPosition
                        (((EntitySceneObject *)value4)->x,((EntitySceneObject *)value4)->y + -0x80,
                         ((EntitySceneObject *)value4)->z,0x160,0x11);
      if (value4 != 0) {
        if (*(int *)(value + 0x30) != 0) {
          *(undefined2 *)(*(int *)(value4 + 0x38) + 0xc) = 0x2001;
        }
        if (*(int *)(value + 0x30) == 3) {
          *(undefined2 *)(*(int *)(value4 + 0x38) + 0xc) = 0x202b;
        }
        *(undefined4 *)(*(int *)(value4 + 0x38) + 0xa8) = 6000;
        *(undefined4 *)(*(int *)(value4 + 0x38) + 0xac) = 6000;
        *(undefined4 *)(*(int *)(value4 + 0x38) + 0xb0) = 6000;
        value2 = CEntities::FindEntityAttachmentByFlags(value4,0x20000000);
        if (value2 != 0) {
          value3 = RandomModulo(0x1e);
          *(int *)(value2 + 0x40) =
               (int)(short)(&g_SinCosTable12Bit)[value5 - 0x400 & 0xfff] * (value3 + 0x32) >> 0xc;
          *(int *)(value2 + 0x44) =
               (int)(short)(&g_SinCosTable12Bit)[value5 & 0xfff] * (value3 + 0x32) >> 0xc;
          shortValue = RandomModulo(0x40);
          *(undefined2 *)(value2 + 0x56) = 0xff80;
          *(short *)(value2 + 0x54) = -0x60 - shortValue;
          *(short *)(*(int *)(value4 + 0x38) + 0xa2) = shortValue2 * 0x400 + 0x200;
          *(undefined2 *)(*(int *)(value4 + 0x38) + 0xa0) = 0x400;
          *(undefined4 *)(value2 + 0x24) = *(undefined4 *)(entity->sceneObjects + 0x18);
          value4 = RandomModulo(0x14);
          *(int *)(value2 + 0x18) = value4 + 0x32;
          *(undefined4 *)(value2 + 0x10) = 0;
        }
      }
      value5 = value5 + 0x400;
      shortValue2 = shortValue2 + 1;
    } while ((int)value5 < 0x1200);
    if (*(short *)(entry + 0x48) == 0) {
      value = entity->sceneObjects;
      CEntities::SpawnEntityByTypeAtPosition
                (((EntitySceneObject *)value)->x,((EntitySceneObject *)value)->y + 0x80,
                 ((EntitySceneObject *)value)->z,0x171,0x11);
    }
    if (*(short *)(entry + 0x48) == 1) {
      value = entity->sceneObjects;
      CEntities::SpawnMappedPickupOrEffectAtPosition
                (((EntitySceneObject *)value)->x,((EntitySceneObject *)value)->y,
                 ((EntitySceneObject *)value)->z,5,0,0);
    }
    if (*(short *)(entry + 0x48) == 4) {
      value = entity->sceneObjects;
      CEntities::SpawnEntityByTypeAtPosition
                (((EntitySceneObject *)value)->x,((EntitySceneObject *)value)->y,
                 ((EntitySceneObject *)value)->z,0x176,0x11);
    }
    if (*(short *)(entry + 0x48) == 3) {
      value = entity->sceneObjects;
      CEntities::SpawnMappedPickupOrEffectAtPosition
                (((EntitySceneObject *)value)->x,((EntitySceneObject *)value)->y,
                 ((EntitySceneObject *)value)->z,5,10,0);
    }
    if (*(short *)(entry + 0x48) == 2) {
      value = entity->sceneObjects;
      CEntities::SpawnMappedPickupOrEffectAtPosition
                (((EntitySceneObject *)value)->x,((EntitySceneObject *)value)->y,
                 ((EntitySceneObject *)value)->z,4,0,0);
    }
    CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
    return;
  case 0x12:
    *(undefined2 *)(entity->sceneObjects + 0xa0) = *(undefined2 *)(value + 0x20);
    *(undefined2 *)(entity->sceneObjects + 0xa4) = *(undefined2 *)(value + 0x28);
    *(undefined2 *)(entity->sceneObjects + 0xa2) = *(undefined2 *)(value + 0x24);
    ((EntitySceneObject *)value)->y = 0;
    ((EntitySceneObject *)value)->x = 0;
    if (g_PlayerActionState == 0x2c) {
      value4 = ((EntitySceneObject *)value)->worldObject + 1;
      ((EntitySceneObject *)value)->worldObject = value4;
      if ((((value4 == 0x10) || (value4 == 0x20)) || (value4 == 0x30)) || (value4 == 0x40)) {
        value4 = entity->sceneObjects;
        value4 = CEntities::SpawnEntityByTypeAtPosition
                          (((EntitySceneObject *)value4)->x,((EntitySceneObject *)value4)->y + -0x100,
                           ((EntitySceneObject *)value4)->z + -0x80,0x14,0x11);
        if (value4 != 0) {
          *(undefined4 *)(*(int *)(value4 + 0x38) + 0xb4) = 1;
          *(undefined4 *)(*(int *)(value4 + 0x38) + 0xa8) = 6000;
          *(undefined4 *)(*(int *)(value4 + 0x38) + 0xac) = 6000;
          *(undefined4 *)(*(int *)(value4 + 0x38) + 0xb0) = 6000;
          *(undefined4 *)(*(int *)(value4 + 0x38) + 0x6c) = 0xffffff80;
        }
      }
      if (0x40 < ((EntitySceneObject *)value)->worldObject) {
        *(undefined4 *)(value + 0xc) = 0xc;
      }
    }
    if (*(int *)(entity->sceneObjects + 0x60) != 0) goto switchD_0046160d_caseD_8;
  }
  *(undefined4 *)(value + 0xc) = 7;
switchD_0046160d_caseD_8:
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

