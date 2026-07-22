#include "tarzan_ghidra_types.hpp"

// Address: 0x004113C0
// Label: CEntities::InitEntityActivator
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::InitEntityActivator(int entry)

{
  Entity *entity = (Entity *)entry;
  *(undefined2 *)(entity->sceneObjects + 0xe) = 0;
  return;
}

