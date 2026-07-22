#include "tarzan_ghidra_types.hpp"

// Address: 0x004321B0
// Label: GoingApe::InitSmashableGroundWithTreeB
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void GoingApe::InitSmashableGroundWithTreeB(int entry)

{
  int value;
  int value2;
  
  value = CEntities::FindEntityAttachmentByFlags(entry,0x200);
  if (value != 0) {
    value2 = GetEncodedEntitySceneObjectIdFromSourceRef(*(undefined4 *)(value + 0x18));
    if (value2 == 0x5096) {
      *(undefined1 *)(entry + 0x3d) = 8;
      *(undefined4 *)(entry + 0x4c) = 4;
      CEntities::LinkEntityIntoProcessingList(&g_CollisionTriggerEntryListHead,entry);
      CreateEntityEntitySceneObjectFromSourceRef(value);
      return;
    }
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

