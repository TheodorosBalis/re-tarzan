#include "tarzan_ghidra_types.hpp"

// Address: 0x00427B60
// Label: ElephantHairDare::InitFastWaterSplash
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ElephantHairDare::InitFastWaterSplash(int entry)

{
  Entity *entity = (Entity *)entry;
  ushort *dataCursor;
  int value;
  
  value = CEntities::CreateEntityAttachment(entry,0x14,0x10000000);
  if (value != 0) {
    *(undefined2 *)(value + 0xc) = 0;
    *(undefined2 *)(value + 0xe) = 0x480;
    *(undefined2 *)(value + 0x10) = 0x4000;
    *(undefined2 *)(value + 0x12) = 0xf0;
    *(int *)(entity->sceneObjects + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x1450;
    *(undefined2 *)(entity->sceneObjects + 0xc) = 0x2002;
    dataCursor = (ushort *)(entity->sceneObjects + 0xe);
    *dataCursor = *dataCursor | 0xc21;
    *(undefined2 *)(entity->sceneObjects + 0xa6) = 3;
    *(undefined4 *)(entity->sceneObjects + 0xb4) = 1;
    *(undefined4 *)(entity->sceneObjects + 0x30) = 0xfff;
  }
  return;
}

