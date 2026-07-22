#include "tarzan_ghidra_types.hpp"

// Address: 0x004281D0
// Label: ElephantHairDare::InitGroundCollapseTriggerPhase1
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ElephantHairDare::InitGroundCollapseTriggerPhase1(int entry)

{
  int value;
  
  value = CEntities::FindEntityAttachmentByFlags(entry,0x200);
  if (value != 0) {
    value = GetEncodedEntitySceneObjectIdFromSourceRef(*(undefined4 *)(value + 0x18));
    if (value == 0x507b) {
      *(undefined1 *)(entry + 0x3d) = 1;
      *(undefined4 *)(entry + 0x4c) = 4;
      CEntities::LinkEntityIntoProcessingList(&g_CollisionTriggerEntryListHead,entry);
    }
  }
  return;
}

