#include "tarzan_ghidra_types.hpp"

// Address: 0x0044E5F0
// Label: SaborAttacks::InitFirstEncounterTrigger
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void SaborAttacks::InitFirstEncounterTrigger(int entry)

{
  int count;
  
  count = CEntities::FindEntityAttachmentByFlags(entry,0x200);
  if (count != 0) {
    count = GetEncodedEntitySceneObjectIdFromSourceRef(*(undefined4 *)(count + 0x18));
    if (count == 0x507c) {
      *(undefined1 *)(entry + 0x3d) = 1;
      *(undefined4 *)(entry + 0x4c) = 4;
      CEntities::LinkEntityIntoProcessingList(&g_CollisionTriggerEntryListHead,entry);
    }
  }
  return;
}

