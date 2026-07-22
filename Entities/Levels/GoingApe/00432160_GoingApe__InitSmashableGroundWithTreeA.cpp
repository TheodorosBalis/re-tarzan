#include "tarzan_ghidra_types.hpp"

// Address: 0x00432160
// Label: GoingApe::InitSmashableGroundWithTreeA
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void GoingApe::InitSmashableGroundWithTreeA(int entry)

{
  int value;
  int value2;
  
  value = CEntities::FindEntityAttachmentByFlags(entry,0x200);
  if (value != 0) {
    value2 = GetEncodedEntitySceneObjectIdFromSourceRef(*(undefined4 *)(value + 0x18));
    if (value2 == 0x5093) {
      *(undefined1 *)(entry + 0x3d) = 6;
      *(undefined4 *)(entry + 0x4c) = 4;
      CEntities::LinkEntityIntoProcessingList(&g_CollisionTriggerEntryListHead,entry);
      CreateEntityEntitySceneObjectFromSourceRef(value);
    }
  }
  return;
}

