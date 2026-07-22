#include "tarzan_ghidra_types.hpp"

// Address: 0x00467860
// Label: TarzanToTheRescue::InitFallingBoulderDust
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TarzanToTheRescue::InitFallingBoulderDust(int entry)

{
  Entity *entity = (Entity *)entry;
  ushort *dataCursor;
  
  dataCursor = (ushort *)(entity->sceneObjects + 0xe);
  *dataCursor = *dataCursor | 0x1421;
  *(int *)(entity->sceneObjects + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x2630;
  *(undefined4 *)(entity->sceneObjects + 0xb4) = 1;
  *(undefined4 *)(entity->sceneObjects + 0x6c) = 0x20;
  *(undefined2 *)(entity->sceneObjects + 0xc) = 0x2021;
  *(undefined4 *)(entity->sceneObjects + 0x30) = 0x1000;
  return;
}

