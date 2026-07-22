#include "tarzan_ghidra_types.hpp"

// Address: 0x004449A0
// Label: CEntities::UpdateSourceLinkedNoOpEntity
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::UpdateSourceLinkedNoOpEntity(undefined4 entry)

{
  char resultFlag;
  
  CEntities::FindEntityAttachmentByFlags(entry,0x200);
  resultFlag = IsEntitySourceRefOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

