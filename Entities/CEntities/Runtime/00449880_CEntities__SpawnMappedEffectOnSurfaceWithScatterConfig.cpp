#include "tarzan_ghidra_types.hpp"

// Address: 0x00449880
// Label: CEntities::SpawnMappedEffectOnSurfaceWithScatterConfig
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::SpawnMappedEffectOnSurfaceWithScatterConfig
               (undefined4 entry,undefined4 sceneObject,undefined4 attachment,short *flags)

{
  short shortValue;
  short shortValue2;
  short shortValue3;
  int value;
  int value2;
  int value3;
  
  value = CEntities::SpawnEntityByTypeAtPosition(0,0,0,entry,0x11);
  if ((value != 0) && (value2 = *(int *)(value + 0x38), value2 != 0)) {
    *(undefined4 *)(value2 + 0x108) = 1;
    *(undefined4 *)(value2 + 0x110) = sceneObject;
    *(undefined4 *)(value2 + 0x10c) = attachment;
    UpdateEntityEntitySceneObjectTransformFromPlacement(value2);
    *(int *)(value2 + 0x14) = *(int *)(value2 + 0x14) + *(int *)(value2 + 0x54);
    value3 = *(int *)(value2 + 0x18) + *(int *)(value2 + 0x58);
    *(int *)(value2 + 0x1c) = *(int *)(value2 + 0x1c) + *(int *)(value2 + 0x5c);
    *(int *)(value2 + 0x18) = value3;
    *(int *)(value2 + 0x18) = *(int *)(flags + 0xc) + value3;
    value2 = CEntities::CreateEntityAttachment(value,0x20,0x40000063);
    if (value2 != 0) {
      shortValue2 = RandomModulo(*(int *)(flags + 6) - *(int *)(flags + 4));
      shortValue = flags[4];
      *(undefined2 *)(value2 + 0x12) = 0xfff8;
      *(short *)(value2 + 0x10) = shortValue2 + shortValue;
      shortValue = flags[2];
      shortValue2 = *flags;
      shortValue3 = RandomModulo((int)(short)(shortValue - shortValue2) << 1);
      shortValue3 = (shortValue - shortValue2) - shortValue3;
      if (shortValue3 < 0) {
        shortValue = -*flags;
      }
      else {
        shortValue = *flags;
      }
      *(short *)(value2 + 0xc) = shortValue3 + shortValue;
      shortValue = flags[10];
      shortValue2 = flags[8];
      shortValue3 = RandomModulo((int)(short)(shortValue - shortValue2) << 1);
      shortValue3 = (shortValue - shortValue2) - shortValue3;
      if (shortValue3 < 0) {
        shortValue = -flags[8];
      }
      else {
        shortValue = flags[8];
      }
      *(short *)(value2 + 0x14) = shortValue3 + shortValue;
      *(undefined2 *)(value2 + 0xe) = 0;
      *(undefined2 *)(value2 + 0x16) = 0;
      *(undefined2 *)(value2 + 0x18) = 0;
      *(undefined2 *)(value2 + 0x1a) = 0;
      *(undefined1 *)(value2 + 0x1e) = 0x85;
      *(undefined2 *)(value2 + 0x1c) = 100;
      *(undefined1 *)(value2 + 0x1f) = 3;
    }
  }
  if (*(short *)(value + 0x44) != 0) {
    CEntities::ReleaseEntityToFreeList((byte *)value);
  }
  return;
}

