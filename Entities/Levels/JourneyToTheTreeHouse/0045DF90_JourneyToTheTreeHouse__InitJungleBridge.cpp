#include "tarzan_ghidra_types.hpp"

// Address: 0x0045DF90
// Label: JourneyToTheTreeHouse::InitJungleBridge
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void JourneyToTheTreeHouse::InitJungleBridge(int entry)

{
  Entity *entity = (Entity *)entry;
  *(undefined2 *)(entity->sceneObjects + 0xe) = 0;
  *(undefined2 *)(entry + 0x48) = 0;
  return;
}

