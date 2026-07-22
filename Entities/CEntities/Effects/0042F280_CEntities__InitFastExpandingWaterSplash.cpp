#include "tarzan_ghidra_types.hpp"

// Address: 0x0042F280
// Label: CEntities::InitFastExpandingWaterSplash
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::InitFastExpandingWaterSplash(int entry)

{
  Entity *entity = (Entity *)entry;
  ushort *dataCursor;
  int value;
  
  value = CEntities::CreateEntityAttachment(entry,0x14,0x10000000);
  if (value != 0) {
    *(undefined2 *)(value + 0xc) = 0;
    *(undefined2 *)(value + 0xe) = 0x480;
    *(undefined2 *)(value + 0x10) = 0x4000;
    *(undefined2 *)(value + 0x12) = 0xf0;
    if (*( undefined1 *)((int)&g_LevelTransitionContext + 2) == '\x0f') {
      *(int *)(entity->sceneObjects + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x2560;
    }
    if (*( undefined1 *)((int)&g_LevelTransitionContext + 2) == '\f') {
      *(int *)(entity->sceneObjects + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x2630;
    }
    if (*( undefined1 *)((int)&g_LevelTransitionContext + 2) == '\x0f') {
      *(undefined2 *)(entity->sceneObjects + 0xc) = 0x2002;
    }
    if (*( undefined1 *)((int)&g_LevelTransitionContext + 2) == '\f') {
      *(undefined2 *)(entity->sceneObjects + 0xc) = 0x2022;
    }
    dataCursor = (ushort *)(entity->sceneObjects + 0xe);
    *dataCursor = *dataCursor | 0x421;
    *(undefined2 *)(entity->sceneObjects + 0xa6) = 3;
    *(undefined4 *)(entity->sceneObjects + 0xb4) = 1;
    *(undefined4 *)(entity->sceneObjects + 0x30) = 0xfff;
  }
  return;
}

