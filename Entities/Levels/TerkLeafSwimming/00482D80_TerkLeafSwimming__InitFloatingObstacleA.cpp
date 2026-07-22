#include "tarzan_ghidra_types.hpp"

// Address: 0x00482D80
// Label: TerkLeafSwimming::InitFloatingObstacleA
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TerkLeafSwimming::InitFloatingObstacleA(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  
  *(undefined2 *)(entity->sceneObjects + 0xa6) = 0;
  value = entity->sceneObjects;
  if (value != 0) {
    value2 = CEntities::CreateEntityAttachment(entry,0x4c,0x10000000);
    ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0xfd8;
    *(undefined4 *)(value2 + 0xc) = 7;
    *(undefined4 *)(value2 + 0x10) = 0;
    *(undefined4 *)(value2 + 0x14) = 0x600;
    *(undefined4 *)(value2 + 0x18) = 4000;
    *(int *)(entity->sceneObjects + 0x1c) =
         *(int *)(entity->sceneObjects + 0x1c) +
         (g_LevelEntityInitScratch_Field1388 * 0x600 >> 0xc);
    *(int *)(entity->sceneObjects + 0x14) =
         *(int *)(entity->sceneObjects + 0x14) +
         ((int)(short)(&g_SinCosTable12Bit)[*(uint *)(value2 + 0x10) & 0xfff] *
          *(int *)(value2 + 0x14) >> 0xc);
    *(undefined2 *)(entity->sceneObjects + 0xa2) = 0x400;
    CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&DAT_0050e3c8);
  }
  if ((*(byte *)(entry + 0x44) & 1) != 0) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

