#include "tarzan_ghidra_types.hpp"

// Address: 0x004312D0
// Label: ComputeEntityHorizontalDistanceSqToPlayer
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int ComputeEntityHorizontalDistanceSqToPlayer(int arg1)

{
  Entity *entity = (Entity *)arg1;
  int entry;
  int entry2;
  
  entry2 = *(int *)(entity->sceneObjects + 0x14) -
          *(int *)(*(int *)(g_PlayerEntity + 0x38) + 0x14);
  entry = *(int *)(entity->sceneObjects + 0x1c) -
          *(int *)(*(int *)(g_PlayerEntity + 0x38) + 0x1c);
  return entry * entry + entry2 * entry2;
}

