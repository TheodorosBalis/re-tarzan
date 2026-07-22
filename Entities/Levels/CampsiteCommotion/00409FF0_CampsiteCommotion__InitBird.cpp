#include "tarzan_ghidra_types.hpp"

// Address: 0x00409FF0
// Label: CampsiteCommotion::InitBird
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CampsiteCommotion::InitBird(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  
  CampsiteCommotion::InitBirdCommon(entry);
  value = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
  if (value != 0) {
    *(undefined2 *)(value + 0x16) = 10;
    *(undefined2 *)(value + 0x10) = 0x28;
    *(undefined2 *)(value + 0x14) = 0x28;
    *(byte *)(entry + 0x4a) = *(byte *)(entry + 0x4a) | 1;
    value2 = RandomModulo(0xfa);
    *(int *)(entry + 0x4c) = value2 + 100;
    if ((*(byte *)(entry + 0x4a) & 0x20) != 0) {
      *(undefined2 *)(value + 0x16) = 0;
    }
    if ((*(byte *)(entry + 0x4b) & 2) != 0) {
      *(undefined4 *)(value + 0x24) = 10;
      *(undefined2 *)(value + 0x22) = 1000;
    }
    if ((entity->descriptor != 0) &&
       (*(int *)(*(int *)(entity->descriptor + 0x10) + 4) == 0x10)) {
      *(undefined2 *)(value + 0x10) = 0x32;
      *(undefined2 *)(value + 0x14) = 0x32;
    }
  }
  return;
}

