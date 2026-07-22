#include "tarzan_ghidra_types.hpp"

// Address: 0x004830D0
// Label: TerkLeafSwimming::UpdateObstacleSpawner
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TerkLeafSwimming::UpdateObstacleSpawner(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  ushort value3;
  int value2;
  
  value2 = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
  if (value2 != 0) {
    *(int *)(entity->sceneObjects + 0x14) =
         (((int)(short)(&g_SinCosTable12Bit)[*(int *)(value2 + 0x2c) - 0x400U & 0xfff] << 8) >> 0xc)
         + (((int)(short)(&g_SinCosTable12Bit)[*(int *)(value2 + 0x30) - 0x400U & 0xfff] << 7) >> 0xc
           ) + *(int *)(value2 + 0x1c);
    *(int *)(entity->sceneObjects + 0x1c) =
         (((int)(short)(&g_SinCosTable12Bit)[*(uint *)(value2 + 0x2c) & 0xfff] << 10) >> 0xc) +
         *(int *)(value2 + 0x24);
    value = entity->sceneObjects;
    value3 = GetAngleFromXZVector12Bit
                      (-(((EntitySceneObject *)value)->x - *(int *)(value + 0x48)),
                       ((EntitySceneObject *)value)->z - *(int *)(value + 0x50));
    *(ushort *)(entity->sceneObjects + 0xa2) = -(value3 & 0xfff);
    *(uint *)(value2 + 0x2c) = *(int *)(value2 + 0x2c) + 8U & 0xfff;
    *(uint *)(value2 + 0x30) = *(int *)(value2 + 0x30) + 0x20U & 0xfff;
  }
  return;
}

