#include "tarzan_ghidra_types.hpp"

// Address: 0x00431FC0
// Label: GoingApe::InitSmashableGroundOnTreeFinal
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void GoingApe::InitSmashableGroundOnTreeFinal(int entry)

{
  int value;
  
  value = CEntities::FindEntityAttachmentByFlags(entry,0x200);
  if (value != 0) {
    value = GetEncodedEntitySceneObjectIdFromSourceRef(*(undefined4 *)(value + 0x18));
    if (value == 0x5095) {
      *(undefined1 *)(entry + 0x3d) = 7;
      *(undefined4 *)(entry + 0x4c) = 2;
      CEntities::LinkEntityIntoProcessingList(&g_CollisionTriggerEntryListHead,entry);
    }
  }
  return;
}

