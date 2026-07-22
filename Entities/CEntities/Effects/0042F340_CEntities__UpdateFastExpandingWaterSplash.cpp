#include "tarzan_ghidra_types.hpp"

// Address: 0x0042F340
// Label: CEntities::UpdateFastExpandingWaterSplash
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::UpdateFastExpandingWaterSplash(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  
  value = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
  if (value != 0) {
    *(short *)(value + 0xc) = *(short *)(value + 0xc) + *(short *)(value + 0xe);
    if (*(short *)(value + 0x10) < *(short *)(value + 0xc)) {
      *(short *)(value + 0xc) = *(short *)(value + 0x10);
    }
    *(int *)(entity->sceneObjects + 0xa8) = *(short *)(value + 0xc) + 0x1000;
    *(int *)(entity->sceneObjects + 0xac) = *(short *)(value + 0xc) + 0x1000;
    *(int *)(entity->sceneObjects + 0xb0) = *(short *)(value + 0xc) + 0x1000;
    *(int *)(entity->sceneObjects + 0x30) =
         *(int *)(entity->sceneObjects + 0x30) - (int)*(short *)(value + 0x12);
    if (*(int *)(entity->sceneObjects + 0x30) < 1) {
      CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
    }
  }
  return;
}

