#include "tarzan_ghidra_types.hpp"

// Address: 0x004820D0
// Label: CEntities::InitMovingWaterSplashDroplet
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::InitMovingWaterSplashDroplet(int entry)

{
  Entity *entity = (Entity *)entry;
  ushort *dataCursor;
  int value;
  int value2;
  int value3;
  
  value = CEntities::CreateEntityAttachment(entry,0x4c,0x10000000);
  if (value != 0) {
    *(undefined4 *)(value + 0xc) = 0;
    *(undefined4 *)(value + 0x10) = 0;
    *(int *)(entity->sceneObjects + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x2560;
    *(undefined2 *)(entity->sceneObjects + 0xc) = 0x2003;
    dataCursor = (ushort *)(entity->sceneObjects + 0xe);
    *dataCursor = *dataCursor | 0xc21;
    *(undefined2 *)(entity->sceneObjects + 0xa6) = 3;
    *(undefined4 *)(entity->sceneObjects + 0xb4) = 0;
    *(undefined4 *)(entity->sceneObjects + 0x30) = 0xfff;
  }
  value = CEntities::CreateEntityAttachment(entry,0x60,0x20000000);
  if (value != 0) {
    *(undefined4 *)(value + 0xc) = 4;
    *(undefined4 *)(value + 0x14) = 0x40;
    *(undefined4 *)(value + 0x10) = 0;
    *(undefined4 *)(value + 0x28) = 0;
    *(undefined4 *)(value + 0x2c) = 1;
    value2 = RandomModulo(0x1000);
    value3 = RandomModulo(0x1000);
    *(int *)(value + 0x30) = value2 - value3;
    value2 = RandomModulo(0x1000);
    value3 = RandomModulo(0x1000);
    *(int *)(value + 0x34) = value2 - value3;
  }
  return;
}

