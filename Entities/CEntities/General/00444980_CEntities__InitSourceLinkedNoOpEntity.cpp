#include "tarzan_ghidra_types.hpp"

// Address: 0x00444980
// Label: CEntities::InitSourceLinkedNoOpEntity
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::InitSourceLinkedNoOpEntity(undefined4 entry)

{
  CEntities::FindEntityAttachmentByFlags(entry,0x200);
  return;
}

