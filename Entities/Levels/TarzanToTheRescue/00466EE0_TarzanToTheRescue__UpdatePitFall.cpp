#include "tarzan_ghidra_types.hpp"

// Address: 0x00466EE0
// Label: TarzanToTheRescue::UpdatePitFall
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TarzanToTheRescue::UpdatePitFall(int entry)

{
  Entity *entity = (Entity *)entry;
  ushort *dataCursor;
  char resultFlag;
  short shortValue;
  int value;
  int *intCursor;
  int value2;
  short shortValue2;
  int value3;
  uint value4;
  
  value = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
  if (value != 0) {
    if (*(int *)(value + 0xc) == 0) {
      value2 = *(int *)(entity->sceneObjects + 0x14) - *(int *)(g_PlayerEntitySceneObject + 0x14)
      ;
      value3 = *(int *)(entity->sceneObjects + 0x1c) - *(int *)(g_PlayerEntitySceneObject + 0x1c)
      ;
      if (value3 * value3 + value2 * value2 < 0x40000) {
        *(undefined4 *)(value + 0xc) = 1;
        dataCursor = (ushort *)(entity->sceneObjects + 0xe);
        *dataCursor = *dataCursor & 0x7fff;
        QueuePlayerDamageEvent(0,0x600);
        g_PlayerSequenceDelayTicks = 0;
        value = entity->sceneObjects;
        intCursor = (int *)CEntities::SpawnEntityByTypeAtPosition
                                  (((EntitySceneObject *)value)->x + -0x80,((EntitySceneObject *)value)->y + 0x80,
                                   ((EntitySceneObject *)value)->z,0x178,0x11);
        if ((intCursor != (int *)0x0) && (*intCursor != 0)) {
          *(undefined2 *)(intCursor[0xe] + 0xc) = 0x2017;
        }
        value = entity->sceneObjects;
        CEntities::SpawnEntityByTypeAtPosition
                  (((EntitySceneObject *)value)->x + 0x80,((EntitySceneObject *)value)->y,
                   ((EntitySceneObject *)value)->z,0x178,0x11);
        value = entity->sceneObjects;
        value = CEntities::SpawnEntityByTypeAtPosition
                          (((EntitySceneObject *)value)->x,((EntitySceneObject *)value)->y + 0x100,
                           ((EntitySceneObject *)value)->z + -0x20,0x14,0x11);
        if (value != 0) {
          *(undefined4 *)(*(int *)(value + 0x38) + 0xb4) = 1;
          *(undefined4 *)(*(int *)(value + 0x38) + 0xa8) = 11000;
          *(undefined4 *)(*(int *)(value + 0x38) + 0xac) = 11000;
          *(undefined4 *)(*(int *)(value + 0x38) + 0xb0) = 11000;
        }
        value = entity->sceneObjects;
        value = CEntities::SpawnEntityByTypeAtPosition
                          (((EntitySceneObject *)value)->x + 0x80,((EntitySceneObject *)value)->y + 0x56f0,
                           ((EntitySceneObject *)value)->z + -0x20,0x14,0x11);
        if (value != 0) {
          *(undefined4 *)(*(int *)(value + 0x38) + 0xb4) = 1;
          *(undefined4 *)(*(int *)(value + 0x38) + 0xa8) = 11000;
          *(undefined4 *)(*(int *)(value + 0x38) + 0xac) = 11000;
          *(undefined4 *)(*(int *)(value + 0x38) + 0xb0) = 11000;
        }
        shortValue2 = 0;
        value4 = 0x200;
        do {
          value2 = RandomModulo(0x200,*(undefined4 *)(entity->sceneObjects + 0x1c),0x160,0x11);
          value = *(int *)(entity->sceneObjects + 0x18);
          value3 = RandomModulo(0x200);
          value2 = RandomModulo(0x200,(value - value2) + 0x180 + value3);
          value = *(int *)(entity->sceneObjects + 0x14);
          value3 = RandomModulo(0x200);
          value = CEntities::SpawnEntityByTypeAtPosition((value - value2) + value3);
          if (value != 0) {
            value2 = CEntities::FindEntityAttachmentByFlags(value,0x20000000);
            if (value2 != 0) {
              value3 = RandomModulo(0x1e);
              *(int *)(value2 + 0x40) =
                   (int)(short)(&g_SinCosTable12Bit)[value4 - 0x400 & 0xfff] * (value3 + 0x32) >> 0xc;
              *(int *)(value2 + 0x44) =
                   (int)(short)(&g_SinCosTable12Bit)[value4 & 0xfff] * (value3 + 0x32) >> 0xc;
              shortValue = RandomModulo(0x40);
              *(short *)(value2 + 0x54) = -0x60 - shortValue;
              *(undefined2 *)(*(int *)(value + 0x38) + 0xc) = 0x201d;
              *(undefined2 *)(value2 + 0x56) = 0xff80;
              *(short *)(*(int *)(value + 0x38) + 0xa2) = (shortValue2 + 1) * 0x200;
              *(undefined2 *)(*(int *)(value + 0x38) + 0xa0) = 0x400;
              value = RandomModulo(0x32);
              *(int *)(value2 + 0x18) = value + 0x1e;
              *(undefined4 *)(value2 + 0x10) = 0;
            }
          }
          value4 = value4 + 0x200;
          shortValue2 = shortValue2 + 1;
        } while ((int)value4 < 0x1200);
      }
    }
    else if ((*(int *)(value + 0xc) == 1) && (g_PlayerActionState != 3)) {
      g_PreviousPlayerActionState = g_PlayerActionState;
      g_PlayerActionState = 3;
      (*(code *)g_AdultTarzanElephantEnterPitFallHandlerPtr)();
    }
  }
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

