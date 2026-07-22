#include "tarzan_ghidra_types.hpp"

// Address: 0x00463180
// Label: TarzanToTheRescue::InitBoxDebrisPiece
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TarzanToTheRescue::InitBoxDebrisPiece(int entry)

{
  Entity *entity = (Entity *)entry;
  ushort *dataCursor;
  int value;
  
  value = CEntities::CreateEntityAttachment(entry,0x1c,0x10000000);
  if (value != 0) {
    *(int *)(entity->sceneObjects + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x2630;
    *(undefined2 *)(entity->sceneObjects + 0xc) = 0x2013;
    dataCursor = (ushort *)(entity->sceneObjects + 0xe);
    *dataCursor = *dataCursor | 0xc21;
    *(undefined4 *)(entity->sceneObjects + 0xb4) = 1;
    *(undefined2 *)(entity->sceneObjects + 0xa6) = 0;
    *(undefined4 *)(value + 0xc) = 0;
    *(undefined4 *)(value + 0x14) = 6;
    *(undefined4 *)(entity->sceneObjects + 0x30) = 0;
  }
  return;
}

