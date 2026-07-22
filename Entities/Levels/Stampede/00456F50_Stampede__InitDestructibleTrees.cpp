#include "tarzan_ghidra_types.hpp"

// Address: 0x00456F50
// Label: Stampede::InitDestructibleTrees
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void Stampede::InitDestructibleTrees(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  
  *(undefined2 *)(entity->sceneObjects + 0xa6) = 3;
  value = CEntities::CreateEntityAttachment(entry,0x500,0x10000000);
  if (value != 0) {
    *(int *)(entity->sceneObjects + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x30c0;
    if (entity->descriptor != 0) {
      switch(*(undefined4 *)(*(int *)(entity->descriptor + 0x10) + 4)) {
      case 0:
      case 2:
      case 4:
        *(undefined2 *)(entity->sceneObjects + 0xc) = 0x203e;
        break;
      case 1:
      case 3:
        *(undefined2 *)(entity->sceneObjects + 0xc) = 0x203e;
        break;
      case 5:
        *(undefined2 *)(entity->sceneObjects + 0xc) = 0x2039;
        break;
      case 6:
        *(undefined2 *)(entity->sceneObjects + 0xc) = 0x203a;
        break;
      case 7:
        *(undefined2 *)(entity->sceneObjects + 0xc) = 0x203b;
        break;
      case 8:
        *(undefined2 *)(entity->sceneObjects + 0xc) = 0x203c;
        break;
      case 9:
        *(undefined2 *)(entity->sceneObjects + 0xc) = 0x203d;
      }
    }
    *(undefined4 *)(entity->sceneObjects + 0x6c) = 0xffffffa0;
    *(undefined4 *)(value + 0xc) = 7;
    *(undefined4 *)(value + 0x10) = 0x18;
    *(undefined4 *)(value + 0x14) = 6;
    *(undefined4 *)(value + 0x18) = 0;
  }
  return;
}

