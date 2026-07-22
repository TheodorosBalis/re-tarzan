#include "tarzan_ghidra_types.hpp"

// Address: 0x00462470
// Label: TarzanToTheRescue::InitRhino
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TarzanToTheRescue::InitRhino(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  undefined4 value3;
  
  *(uint *)(entry + 0x28) = *(uint *)(entry + 0x28) | 0x200;
  value2 = CEntities::CreateEntityAttachment(entry,100,0x10000000);
  if (value2 != 0) {
    *(int *)(entity->sceneObjects + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x3878;
    *(undefined2 *)(entity->sceneObjects + 0xc) = 0x23;
    value3 = (int)CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&DAT_00506288);
    *(undefined4 *)(value2 + 0x2c) = value3;
    *(undefined2 *)(entity->sceneObjects + 0xa6) = 1;
    *(undefined2 *)(entity->sceneObjects + 0xa2) = 0x200;
    *(undefined4 *)(value2 + 0xc) = 1;
    *(undefined4 *)(value2 + 0x60) = 1;
    *(undefined4 *)(value2 + 0x3c) = 0x200;
    *(undefined4 *)(value2 + 0x1c) = 8;
    *(undefined4 *)(value2 + 0x10) = 0x3c;
    *(undefined4 *)(value2 + 0x14) = 2;
    *(undefined4 *)(value2 + 0x18) = 2;
    *(undefined4 *)(value2 + 0x30) = 0x39;
    *(undefined4 *)(value2 + 0x44) = 0;
    *(undefined4 *)(value2 + 0x4c) = 0x1e;
    value = entity->sceneObjects;
    *(undefined4 *)(value2 + 0x20) = ((EntitySceneObject *)value)->x;
    *(undefined4 *)(value2 + 0x24) = ((EntitySceneObject *)value)->y;
    value3 = ((EntitySceneObject *)value)->z;
    *(undefined4 *)(value2 + 0x34) = 0;
    *(undefined4 *)(value2 + 0x28) = value3;
    *(undefined4 *)(value2 + 0x40) = 0;
  }
  CEntities::LinkEntityIntoProcessingList(&g_ActiveEntityListHead,entry);
  return;
}

