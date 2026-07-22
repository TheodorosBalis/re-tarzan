#include "tarzan_ghidra_types.hpp"

// Address: 0x00431300
// Label: CEntities::ComputeEntityDistanceSqToPlayer3D
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int CEntities::ComputeEntityDistanceSqToPlayer3D(int entry)

{
  Entity *entity = (Entity *)entry;
  int entry2;
  int entry3;
  
  entry3 = *(int *)(entity->sceneObjects + 0x18) - *(int *)(g_PlayerEntitySceneObjectData + 0xc);
  entry2 = ComputeEntityHorizontalDistanceSqToPlayer(entry);
  return entry2 + entry3 * entry3;
}

