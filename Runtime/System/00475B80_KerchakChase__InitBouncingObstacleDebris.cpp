#include "tarzan_ghidra_types.hpp"

// Address: 0x00475B80
// Label: KerchakChase::InitBouncingObstacleDebris
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void KerchakChase::InitBouncingObstacleDebris(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  
  value = CEntities::CreateEntityAttachment(entry,0x70,0x10000000);
  if (value != 0) {
    *(int *)(entity->sceneObjects + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x3a8;
    *(undefined2 *)(entity->sceneObjects + 0xc) = 0x200f;
    *(undefined4 *)(value + 0xc) = 0;
    *(undefined4 *)(value + 0x50) = 0;
    *(undefined4 *)(value + 0x54) = 0;
    *(undefined4 *)(value + 0x1c) = 3;
    *(undefined4 *)(value + 0x20) = 0;
    *(undefined4 *)(value + 0x3c) = 1;
    *(undefined4 *)(value + 0x28) = 0xffffffe8;
    RefreshEntitySceneObjectNatureTerrainVerticalDelta(entity->sceneObjects);
    *(int *)(value + 0x34) =
         (*(int *)(entity->sceneObjects + 0x18) - *(int *)(entity->sceneObjects + 0x58)) +
         -0x40;
  }
  return;
}

