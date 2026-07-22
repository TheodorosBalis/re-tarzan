#include "tarzan_ghidra_types.hpp"

// Address: 0x00440590
// Label: CEntities::CreateMotionStateAttachmentAndFlagEntry
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int CEntities::CreateMotionStateAttachmentAndFlagEntry(uint *entry)

{
  int value;
  
  value = CEntities::AllocEntityAttachment(entry,0x2c,0x20000,0);
  if (value != 0) {
    *entry = *entry | 0x20000;
  }
  return 0;
}

