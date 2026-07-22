#include "tarzan_ghidra_types.hpp"

// Address: 0x004311A0
// Label: CEntities::UpdateSmashableFlyingDebris
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::UpdateSmashableFlyingDebris(int entry)

{
  Entity *entity = (Entity *)entry;
  short *value3;
  int value;
  int value2;
  
  value = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
  if (value != 0) {
    value2 = CEntities::AdvanceEntitySceneObjectParabolicArc
                      (value + 0x18,value + 0xc,value + 0x24,entity->sceneObjects + 0x14);
    if (value2 != 0) {
      CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
    }
    value3 = (short *)(entity->sceneObjects + 0xa0);
    *value3 = *value3 + *(short *)(value + 0x78);
    value3 = (short *)(entity->sceneObjects + 0xa4);
    *value3 = *value3 + *(short *)(value + 0x7a);
  }
  return;
}

