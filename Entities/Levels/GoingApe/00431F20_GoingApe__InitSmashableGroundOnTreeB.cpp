#include "tarzan_ghidra_types.hpp"

// Address: 0x00431F20
// Label: GoingApe::InitSmashableGroundOnTreeB
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void GoingApe::InitSmashableGroundOnTreeB(int entry)

{
  int value;
  
  value = CEntities::FindEntityAttachmentByFlags(entry,0x200);
  if (value != 0) {
    value = GetEncodedEntitySceneObjectIdFromSourceRef(*(undefined4 *)(value + 0x18));
    if (value == 0x5094) {
      *(undefined1 *)(entry + 0x3d) = 4;
      *(undefined4 *)(entry + 0x4c) = 2;
      CEntities::LinkEntityIntoProcessingList(&g_CollisionTriggerEntryListHead,entry);
    }
  }
  return;
}

