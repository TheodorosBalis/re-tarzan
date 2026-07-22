#include "tarzan_ghidra_types.hpp"

// Address: 0x00415F20
// Label: ComingOfAge::InitBreakableGround
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ComingOfAge::InitBreakableGround(int entry)

{
  int value;
  
  value = CEntities::FindEntityAttachmentByFlags(entry,0x200);
  if (value != 0) {
    value = GetEncodedEntitySceneObjectIdFromSourceRef(*(undefined4 *)(value + 0x18));
    if (value == 0x509b) {
      *(undefined1 *)(entry + 0x3d) = 1;
      *(undefined4 *)(entry + 0x4c) = 4;
      CEntities::LinkEntityIntoProcessingList(&g_CollisionTriggerEntryListHead,entry);
    }
  }
  return;
}

