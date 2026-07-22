#include "tarzan_ghidra_types.hpp"

// Address: 0x0042DEA0
// Label: CEntities::AdvanceBounceMotionAndReturnImpact
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 CEntities::AdvanceBounceMotionAndReturnImpact(int entry,int sceneObject)

{
  Entity *entity2 = (Entity *)sceneObject;
  short shortValue;
  uint value3;
  int value;
  uint value4;
  int value2;
  
  if (entity2->next == 0) {
    entity2->next = 1;
    *(undefined4 *)(sceneObject + 0x20) = *(undefined4 *)(sceneObject + 0x18);
    *(undefined4 *)(sceneObject + 0x48) = 0;
    *(undefined4 *)(sceneObject + 0x5c) = 0;
  }
  *(undefined4 *)(sceneObject + 0x48) = 0;
  *(int *)(entry + 0x18) = *(int *)(entry + 0x18) - *(int *)(sceneObject + 0x20);
  *(int *)(sceneObject + 0x20) = *(int *)(sceneObject + 0x20) - entity2->previous;
  *(int *)(entry + 0x14) = *(int *)(entry + 0x14) + *(int *)(sceneObject + 0x40);
  *(int *)(entry + 0x1c) = *(int *)(entry + 0x1c) + *(int *)(sceneObject + 0x44);
  *(int *)(sceneObject + 0x5c) = *(int *)(sceneObject + 0x5c) + 1;
  value = *(int *)(entry + 0x18);
  if (*(int *)(sceneObject + 0x24) <= value) {
    value3 = value - *(int *)(sceneObject + 0x24);
    value4 = (int)value3 >> 0x1f;
    *(uint *)(entry + 0x18) = value - ((value3 ^ value4) - value4);
    value = *(int *)(sceneObject + 0x2c);
    if (value == 0) {
      *(int *)(sceneObject + 0x20) = -*(int *)(sceneObject + 0x20) >> 1;
    }
    else {
      if (value == 1) {
        *(int *)(sceneObject + 0x20) = -*(int *)(sceneObject + 0x20) >> 1;
        *(int *)(sceneObject + 0x40) = (*(int *)(sceneObject + 0x40) << 7) >> 8;
        *(int *)(sceneObject + 0x44) = (*(int *)(sceneObject + 0x44) << 7) >> 8;
      }
      if (value == 2) {
        value3 = RandomModulo(0x1000);
        *(int *)(sceneObject + 0x20) = -(*(int *)(sceneObject + 0x20) * 0x96 >> 8);
        value = (int)(short)(&g_SinCosTable12Bit)[value3 - 0x400 & 0xfff] * *(int *)(sceneObject + 0x40)
                >> 0xc;
        *(int *)(sceneObject + 0x40) = value;
        shortValue = (&g_SinCosTable12Bit)[value3 & 0xfff];
        *(undefined4 *)(sceneObject + 0x48) = 1;
        value2 = shortValue * value >> 0xc;
        *(int *)(sceneObject + 0x40) = value * 0xe6 >> 8;
        *(int *)(sceneObject + 0x44) = value2;
        *(int *)(sceneObject + 0x44) = value2 * 0xe6 >> 8;
        return *(undefined4 *)(sceneObject + 0x48);
      }
    }
    *(undefined4 *)(sceneObject + 0x48) = 1;
  }
  return *(undefined4 *)(sceneObject + 0x48);
}

