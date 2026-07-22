#include "tarzan_ghidra_types.hpp"

// Address: 0x0042FDE0
// Label: CEntities::InitBonusTimePickup
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::InitBonusTimePickup(int entry)

{
  Entity *entity = (Entity *)entry;
  *(int *)(entity->sceneObjects + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x3a8;
  *(undefined2 *)(entity->sceneObjects + 0xc) = 0x2029;
  *(undefined2 *)(entity->sceneObjects + 0xa6) = 0;
  return;
}

