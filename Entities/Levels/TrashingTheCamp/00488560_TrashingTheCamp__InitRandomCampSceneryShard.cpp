#include "tarzan_ghidra_types.hpp"

// Address: 0x00488560
// Label: TrashingTheCamp::InitRandomCampSceneryShard
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TrashingTheCamp::InitRandomCampSceneryShard(int entry3)

{
  Entity *entity = (Entity *)entry3;
  int entry;
  undefined2 value;
  int entry2;
  
  entry = entity->sceneObjects;
  if (entry != 0) {
    ((EntitySceneObject *)entry)->roll = 1;
    value = RandomModulo(0x1000);
    *(undefined2 *)(entry + 0xa0) = value;
    value = RandomModulo(0x1000);
    ((EntitySceneObject *)entry)->yaw = value;
    value = RandomModulo(0x1000);
    ((EntitySceneObject *)entry)->pitch = value;
    ((EntitySceneObject *)entry)->worldObject = g_CurrentWorldSceneContext;
    entry2 = RandomModulo(0x10);
    *(undefined2 *)(entry + 0xc) =
         *(undefined2 *)(&g_TrashingTheCampRandomSceneryShardModelTable + entry2 * 2);
    *(uint *)(entry3 + 0x4c) =
         (uint)*(ushort *)(&g_TrashingTheCampRandomSceneryShardTypeTable + entry2 * 2);
  }
  if (*(short *)(entry3 + 0x44) != 0) {
    CEntities::ReleaseEntityToFreeList((byte *)entry3);
  }
  return;
}

