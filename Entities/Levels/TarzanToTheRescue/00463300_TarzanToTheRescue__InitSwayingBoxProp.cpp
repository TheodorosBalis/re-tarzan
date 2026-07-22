#include "tarzan_ghidra_types.hpp"

// Address: 0x00463300
// Label: TarzanToTheRescue::InitSwayingBoxProp
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TarzanToTheRescue::InitSwayingBoxProp(int entry)

{
  Entity *entity = (Entity *)entry;
  if (entity->descriptor != 0) {
    *(undefined4 *)(entry + 0x50) = *(undefined4 *)(*(int *)(entity->descriptor + 0x10) + 4)
    ;
  }
  *(int *)(entity->sceneObjects + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x2630;
  *(undefined2 *)(entity->sceneObjects + 0xc) = 0x2006;
  *(undefined2 *)(entity->sceneObjects + 0xa6) = 0;
  *(undefined4 *)(entry + 0x4c) = 0;
  return;
}

