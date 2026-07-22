#include "tarzan_ghidra_types.hpp"

// Address: 0x00465A60
// Label: TarzanToTheRescue::UpdateFallingProjectileTrap
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TarzanToTheRescue::UpdateFallingProjectileTrap(int entry)

{
  Entity *entity = (Entity *)entry;
  short *value6;
  char resultFlag;
  short shortValue;
  int value2;
  int value3;
  int value4;
  int value5;
  short shortValue2;
  uint value7;
  int value;
  undefined1 localState2 [4];
  undefined4 localState5;
  int localState3;
  undefined4 localState4;
  undefined1 localState [16];
  
  value2 = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
  if (value2 != 0) {
    *(undefined2 *)(entity->sceneObjects + 0xa2) = *(undefined2 *)(value2 + 0x70);
    localState5 = *(undefined4 *)(g_PlayerEntitySceneObject + 0x14);
    localState3 = *(int *)(g_PlayerEntitySceneObject + 0x18) + -0x80;
    localState4 = *(undefined4 *)(g_PlayerEntitySceneObject + 0x1c);
    if ((*(int *)(value2 + 0x78) == 1) || (*(int *)(value2 + 0x78) == 2)) {
      value6 = (short *)(entity->sceneObjects + 0xa0);
      *value6 = *value6 + 0x80;
      resultFlag = CEntities::CheckAttachmentBoundsOverlapAndPushVector
                        (g_PlayerEntitySceneObject,0x200,entity->sceneObjects,0x200,
                         localState2,localState);
      if (resultFlag != '\0') {
        PlayAudioById(0x399,(int *)0,(undefined4 *)0);
        QueuePlayerDamageEvent(entry,0x200a);
        value3 = entity->sceneObjects;
        value3 = CEntities::SpawnEntityByTypeAtPosition
                          (((EntitySceneObject *)value3)->x,((EntitySceneObject *)value3)->y,
                           ((EntitySceneObject *)value3)->z + -0x20,0x14,0x11);
        if (value3 != 0) {
          *(undefined4 *)(*(int *)(value3 + 0x38) + 0xb4) = 1;
          *(undefined4 *)(*(int *)(value3 + 0x38) + 0xa8) = 6000;
          *(undefined4 *)(*(int *)(value3 + 0x38) + 0xac) = 6000;
          *(undefined4 *)(*(int *)(value3 + 0x38) + 0xb0) = 6000;
        }
        shortValue2 = 0;
        value7 = 0x200;
        do {
          value3 = entity->sceneObjects;
          value3 = CEntities::SpawnEntityByTypeAtPosition
                            (((EntitySceneObject *)value3)->x,((EntitySceneObject *)value3)->y,
                             ((EntitySceneObject *)value3)->z,0x160,0x11);
          if (value3 != 0) {
            if (*(int *)(value2 + 0x78) == 1) {
              *(undefined2 *)(*(int *)(value3 + 0x38) + 0xc) = 0x201c;
            }
            if (*(int *)(value2 + 0x78) == 2) {
              *(undefined2 *)(*(int *)(value3 + 0x38) + 0xc) = 0x202b;
            }
            value4 = CEntities::FindEntityAttachmentByFlags(value3,0x20000000);
            if (value4 != 0) {
              value5 = RandomModulo(0x1e);
              *(int *)(value4 + 0x40) =
                   (int)(short)(&g_SinCosTable12Bit)[value7 - 0x400 & 0xfff] * (value5 + 0x32) >> 0xc;
              *(int *)(value4 + 0x44) =
                   (int)(short)(&g_SinCosTable12Bit)[value7 & 0xfff] * (value5 + 0x32) >> 0xc;
              shortValue = RandomModulo(0x40);
              *(undefined2 *)(value4 + 0x56) = 0xff80;
              *(short *)(value4 + 0x54) = -0x60 - shortValue;
              *(undefined4 *)(value4 + 0x24) = *(undefined4 *)(entity->sceneObjects + 0x18);
              *(short *)(*(int *)(value3 + 0x38) + 0xa2) = shortValue2 * 0x400 + 0x200;
              *(undefined2 *)(*(int *)(value3 + 0x38) + 0xa0) = 0x400;
              value3 = RandomModulo(0x14);
              *(int *)(value4 + 0x18) = value3 + 0x32;
              *(undefined4 *)(value4 + 0x10) = 0;
            }
          }
          value7 = value7 + 0x400;
          shortValue2 = shortValue2 + 1;
        } while ((int)value7 < 0x1200);
        CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
        return;
      }
    }
    if (*(int *)(value2 + 0x78) == 0) {
      value3 = entity->sceneObjects;
      value = ((EntitySceneObject *)value3)->x - *(int *)(g_PlayerEntitySceneObject + 0x14);
      value4 = ((EntitySceneObject *)value3)->y - *(int *)(g_PlayerEntitySceneObject + 0x18);
      value5 = ((EntitySceneObject *)value3)->z - *(int *)(g_PlayerEntitySceneObject + 0x1c);
      value3 = TarzanToTheRescue::DoesEntryOverlapActiveAttachment200(entry);
      if (value3 != 0) {
        value2 = entity->sceneObjects;
        CEntities::SpawnEntityByTypeAtPosition
                  (((EntitySceneObject *)value2)->x,((EntitySceneObject *)value2)->y,
                   ((EntitySceneObject *)value2)->z,0x13,0x11);
        CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
        return;
      }
      if (value5 * value5 + value4 * value4 + value * value < 0x10000) {
        QueuePlayerDamageEvent(entry,0x200a);
        CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
        return;
      }
    }
    value3 = entity->sceneObjects + 0x14;
    value3 = CEntities::AdvanceEntitySceneObjectParabolicArc(value3,&localState5,&((EntitySceneObject *)value2)->worldObject,value3);
    if (value3 != 0) {
      if ((*(int *)(value2 + 0x78) == 1) || (*(int *)(value2 + 0x78) == 2)) {
        PlayAudioById(0x399,(int *)0,(undefined4 *)0);
        value3 = entity->sceneObjects;
        value3 = CEntities::SpawnEntityByTypeAtPosition
                          (((EntitySceneObject *)value3)->x,((EntitySceneObject *)value3)->y,
                           ((EntitySceneObject *)value3)->z + -0x20,0x14,0x11);
        if (value3 != 0) {
          *(undefined4 *)(*(int *)(value3 + 0x38) + 0xb4) = 1;
          *(undefined4 *)(*(int *)(value3 + 0x38) + 0xa8) = 6000;
          *(undefined4 *)(*(int *)(value3 + 0x38) + 0xac) = 6000;
          *(undefined4 *)(*(int *)(value3 + 0x38) + 0xb0) = 6000;
        }
        shortValue2 = 0;
        value7 = 0x200;
        do {
          value3 = entity->sceneObjects;
          value3 = CEntities::SpawnEntityByTypeAtPosition
                            (((EntitySceneObject *)value3)->x,((EntitySceneObject *)value3)->y,
                             ((EntitySceneObject *)value3)->z,0x160,0x11);
          if (value3 != 0) {
            if (*(int *)(value2 + 0x78) == 1) {
              *(undefined2 *)(*(int *)(value3 + 0x38) + 0xc) = 0x201c;
            }
            if (*(int *)(value2 + 0x78) == 2) {
              *(undefined2 *)(*(int *)(value3 + 0x38) + 0xc) = 0x202b;
            }
            value4 = CEntities::FindEntityAttachmentByFlags(value3,0x20000000);
            if (value4 != 0) {
              value5 = RandomModulo(0x1e);
              *(int *)(value4 + 0x40) =
                   (int)(short)(&g_SinCosTable12Bit)[value7 - 0x400 & 0xfff] * (value5 + 0x32) >> 0xc;
              *(int *)(value4 + 0x44) =
                   (int)(short)(&g_SinCosTable12Bit)[value7 & 0xfff] * (value5 + 0x32) >> 0xc;
              shortValue = RandomModulo(0x40);
              *(undefined2 *)(value4 + 0x56) = 0xff80;
              *(short *)(value4 + 0x54) = -0x60 - shortValue;
              *(short *)(*(int *)(value3 + 0x38) + 0xa2) = shortValue2 * 0x400 + 0x200;
              *(undefined2 *)(*(int *)(value3 + 0x38) + 0xa0) = 0x400;
              *(undefined4 *)(value4 + 0x24) = *(undefined4 *)(entity->sceneObjects + 0x18);
              value3 = RandomModulo(0x14);
              *(int *)(value4 + 0x18) = value3 + 0x32;
              *(undefined4 *)(value4 + 0x10) = 0;
            }
          }
          value7 = value7 + 0x400;
          shortValue2 = shortValue2 + 1;
        } while ((int)value7 < 0x1200);
      }
      CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
      return;
    }
  }
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

