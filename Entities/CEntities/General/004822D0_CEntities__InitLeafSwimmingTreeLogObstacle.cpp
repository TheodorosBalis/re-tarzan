#include "tarzan_ghidra_types.hpp"

// Address: 0x004822D0
// Label: CEntities::InitLeafSwimmingTreeLogObstacle
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::InitLeafSwimmingTreeLogObstacle(int entry)

{
  Entity *entity = (Entity *)entry;
  *(undefined2 *)(entity->sceneObjects + 0xa6) = 0;
  *(int *)(entity->sceneObjects + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x2560;
  *(undefined2 *)(entity->sceneObjects + 0xc) = 0x2004;
  return;
}

