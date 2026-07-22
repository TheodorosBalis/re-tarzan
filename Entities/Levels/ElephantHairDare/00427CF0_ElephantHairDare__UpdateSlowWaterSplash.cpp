#include "tarzan_ghidra_types.hpp"

// Address: 0x00427CF0
// Label: ElephantHairDare::UpdateSlowWaterSplash
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ElephantHairDare::UpdateSlowWaterSplash(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  
  value2 = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
  if (value2 != 0) {
    *(short *)(value2 + 0xc) = *(short *)(value2 + 0xc) + *(short *)(value2 + 0xe);
    if (*(short *)(value2 + 0x10) < *(short *)(value2 + 0xc)) {
      *(short *)(value2 + 0xc) = *(short *)(value2 + 0x10);
    }
    *(int *)(entity->sceneObjects + 0xa8) = *(short *)(value2 + 0xc) + 0x1000;
    *(int *)(entity->sceneObjects + 0xac) = *(short *)(value2 + 0xc) + 0x1000;
    *(int *)(entity->sceneObjects + 0xb0) = *(short *)(value2 + 0xc) + 0x1000;
    value = *(int *)(entity->sceneObjects + 0x30);
    if (value < 1) {
      CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
      return;
    }
    *(int *)(entity->sceneObjects + 0x30) = value - *(short *)(value2 + 0x12);
  }
  return;
}

