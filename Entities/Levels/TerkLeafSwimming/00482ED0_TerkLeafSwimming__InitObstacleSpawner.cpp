#include "tarzan_ghidra_types.hpp"

// Address: 0x00482ED0
// Label: TerkLeafSwimming::InitObstacleSpawner
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TerkLeafSwimming::InitObstacleSpawner(uint entry)

{
  Entity *entity = (Entity *)entry;
  short shortValue;
  undefined4 value4;
  int value;
  int value2;
  int value3;
  uint value5;
  int localState;
  
  value = entry;
  *(undefined2 *)(entity->sceneObjects + 0xa6) = 0;
  value2 = CEntities::CreateEntityAttachment(entry,0x60,0x10000000);
  if (value2 != 0) {
    *(undefined2 *)(entity->sceneObjects + 0xa2) = 0;
    *(int *)(entity->sceneObjects + 0x18) = *(int *)(g_PlayerEntitySceneObjectData + 0xc) + 0x80
    ;
    *(undefined4 *)(value2 + 0xc) = 0;
    *(undefined4 *)(value2 + 0x38) = 0;
    *(undefined4 *)(value2 + 0x2c) = 0;
    *(undefined4 *)(value2 + 0x30) = 0;
    value3 = entity->sceneObjects;
    *(int *)(value2 + 0x1c) = ((EntitySceneObject *)value3)->x;
    *(undefined4 *)(value2 + 0x20) = ((EntitySceneObject *)value3)->y;
    *(undefined4 *)(value2 + 0x24) = ((EntitySceneObject *)value3)->z;
    *(undefined4 *)(entity->sceneObjects + 0xb4) = 1;
    *(undefined4 *)(entity->sceneObjects + 0xa8) = 0x400;
    *(undefined4 *)(entity->sceneObjects + 0xac) = 0x400;
    *(undefined4 *)(entity->sceneObjects + 0xb0) = 0x400;
    *(int *)(entity->sceneObjects + 0x14) =
         (((int)(short)(&g_SinCosTable12Bit)[*(int *)(value2 + 0x2c) - 0x400U & 0xfff] << 8) >> 0xc)
         + (((int)(short)(&g_SinCosTable12Bit)[*(int *)(value2 + 0x30) - 0x400U & 0xfff] << 7) >> 0xc
           ) + *(int *)(value2 + 0x1c);
    *(int *)(entity->sceneObjects + 0x1c) =
         (((int)(short)(&g_SinCosTable12Bit)[*(uint *)(value2 + 0x2c) & 0xfff] << 10) >> 0xc) +
         *(int *)(value2 + 0x24);
    value2 = RandomModulo(0x200);
    shortValue = *(short *)(entity->sceneObjects + 0xa2);
    value3 = RandomModulo(0x200);
    value5 = (shortValue - value2) + value3;
    localState = 0;
    entry = value5 - 0x400;
    do {
      value3 = RandomModulo(0x80);
      value3 = value3 + 0x40;
      value2 = *(int *)(value + 0x38);
      value2 = CEntities::SpawnEntityByTypeAtPosition
                        (((short)(&g_SinCosTable12Bit)[entry & 0xfff] * value3 >> 0xc) +
                         *(int *)(value2 + 0x14),*(undefined4 *)(value2 + 0x18),
                         ((short)(&g_SinCosTable12Bit)[value5 & 0xfff] * value3 >> 0xc) +
                         *(int *)(value2 + 0x1c),0x19d,0x11);
      if (value2 != 0) {
        value2 = CEntities::FindEntityAttachmentByFlags(value2,0x10000000);
        if (value2 != 0) {
          value4 = *(undefined4 *)(value + 0x38);
          *(int *)(value2 + 0x28) = value3;
          *(undefined4 *)(value2 + 0xc) = value4;
          *(uint *)(value2 + 0x2c) = value5;
          value3 = *(int *)(value + 0x38);
          *(undefined4 *)(value2 + 0x10) = ((EntitySceneObject *)value3)->x;
          *(undefined4 *)(value2 + 0x14) = ((EntitySceneObject *)value3)->y;
          *(undefined4 *)(value2 + 0x18) = ((EntitySceneObject *)value3)->z;
          *(int *)(value2 + 0x48) = localState;
        }
        value5 = value5 + 0x200;
        entry = entry + 0x200;
      }
      localState = localState + 1;
    } while (localState < 8);
  }
  return;
}

