#include "tarzan_ghidra_types.hpp"

// Address: 0x0040D0E0
// Label: CampsiteCommotion::InitCampCollapseEmitter
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CampsiteCommotion::InitCampCollapseEmitter(int entry)

{
  Entity *entity = (Entity *)entry;
  short shortValue;
  int value;
  int value2;
  undefined4 *dataCursor;
  short shortValue2;
  undefined2 upperWord;
  int value3;
  uint value5;
  int value4;
  
  value4 = entity->sceneObjects;
  if (value4 != 0) {
    *(ushort *)(value4 + 0xe) = *(ushort *)(value4 + 0xe) & 0x6fff | 0x1000;
    ((EntitySceneObject *)value4)->roll = 3;
    ((EntitySceneObject *)value4)->worldObject = g_CurrentWorldSceneContext;
    *(undefined2 *)(value4 + 0xc) = 0x200e;
    *(undefined4 *)(value4 + 0xb4) = 1;
    ((EntitySceneObject *)value4)->roll = 3;
    value = CEntities::CreateEntityAttachment(entry,0x53c,0x10000000);
    if (value != 0) {
      *(undefined4 *)(value + 0x10) = 0x10;
      value2 = CEntities::CreateChildEntitySceneObjectArrayAttachment
                        (entry,1,CONCAT22(upperWord,*(undefined2 *)(value + 0x10)));
      if (value2 != 0) {
        *(int *)(value + 0x2c) = value2;
        *(undefined4 *)(value + 0x14) = 4;
        *(undefined4 *)(value + 0x18) = 1;
        *(undefined4 *)(value + 0x1c) = 0;
        *(undefined4 *)(value + 0x40) = 8;
        *(undefined4 *)(value + 0x524) = 0x100;
        *(undefined4 *)(value + 0x34) = ((EntitySceneObject *)value4)->y;
        *(undefined4 *)(value + 0x24) = 0x400;
        *(undefined4 *)(value + 0x3c) = 0x400;
        value2 = 0;
        *(undefined4 *)(value + 0x20) = 0x5a;
        *(undefined4 *)(value + 0x28) = 0x14;
        *(undefined4 *)(value + 0x38) = 0x40;
        *(undefined4 *)(value + 0x52c) = 0;
        if (0 < *(int *)(value + 0x10)) {
          value3 = 0;
          dataCursor = (undefined4 *)(value + 0x50);
          do {
            *dataCursor = 0;
            value2 = value2 + 1;
            dataCursor = dataCursor + 0xd;
            *(undefined2 *)(*(int *)(value + 0x2c) + 0x12 + value3) = 0;
            value3 = value3 + 0x28;
          } while (value2 < *(int *)(value + 0x10));
        }
      }
    }
    shortValue2 = 0;
    value5 = 0x200;
    do {
      value = CEntities::SpawnEntityByTypeAtPosition
                        (((EntitySceneObject *)value4)->x,((EntitySceneObject *)value4)->y + -0x80,
                         ((EntitySceneObject *)value4)->z,0x160,0x11);
      if ((value != 0) && (value4 = *(int *)(value + 0x38), value4 != 0)) {
        ((EntitySceneObject *)value4)->worldObject = g_CurrentWorldSceneContext;
        *(undefined2 *)(value4 + 0xc) = 0x200f;
        value2 = CEntities::FindEntityAttachmentByFlags(value,0x20000000);
        if (value2 != 0) {
          value3 = RandomModulo(0x1e);
          *(int *)(value2 + 0x40) =
               (int)(short)(&g_SinCosTable12Bit)[value5 - 0x400 & 0xfff] * (value3 + 0x32) >> 0xc;
          *(int *)(value2 + 0x44) =
               (int)(short)(&g_SinCosTable12Bit)[value5 & 0xfff] * (value3 + 0x32) >> 0xc;
          shortValue = RandomModulo(0x40);
          *(undefined2 *)(value2 + 0x56) = 0xff80;
          *(short *)(value2 + 0x54) = -0x60 - shortValue;
          *(short *)(*(int *)(value + 0x38) + 0xa2) = shortValue2 * 0x400 + 0x200;
          *(undefined2 *)(*(int *)(value + 0x38) + 0xa0) = 0x400;
          value = RandomModulo(0x14);
          *(int *)(value2 + 0x18) = value + 0x32;
          *(undefined4 *)(value2 + 0x10) = 0;
        }
      }
      value5 = value5 + 0x400;
      shortValue2 = shortValue2 + 1;
    } while ((int)value5 < 0x1200);
  }
  return;
}

