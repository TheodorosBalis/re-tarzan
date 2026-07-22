#include "tarzan_ghidra_types.hpp"

// Address: 0x00431250
// Label: StorkRide::UpdateFinishLine
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void StorkRide::UpdateFinishLine(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  
  if (entity->sceneObjects != 0) {
    value = CEntities::ComputeSceneObjectDataXZDistanceScaled64
                      (entity->sceneObjects + 0xc,g_PlayerEntitySceneObjectData);
    if (value < *(int *)(entry + 0x4c)) {
      *( undefined2 *)((int)&g_LevelTransitionRequestFlags + 0) = 0x8001;
    }
  }
  return;
}

