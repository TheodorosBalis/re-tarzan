#include "tarzan_ghidra_types.hpp"

// Address: 0x004400C0
// Label: CEntities::ReleaseEntityAndMarkDescriptorConsumed
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int CEntities::ReleaseEntityAndMarkDescriptorConsumed(int entry)

{
  Entity *entity = (Entity *)entry;
  byte *value;
  
  if (entity->descriptor != 0) {
    value = (byte *)(entity->descriptor + 0x1b);
    *value = *value | 0x80;
  }
  CEntities::ReleaseEntityToFreeList((byte *)entry);
  return 0;
}

