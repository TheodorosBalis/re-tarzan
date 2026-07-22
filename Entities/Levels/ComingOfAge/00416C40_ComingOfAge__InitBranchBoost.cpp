#include "tarzan_ghidra_types.hpp"

// Address: 0x00416C40
// Label: ComingOfAge::InitBranchBoost
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ComingOfAge::InitBranchBoost(int entry)

{
  int value;
  
  value = CEntities::FindEntityAttachmentByFlags(entry,0x200);
  if (value != 0) {
    *(undefined1 *)(entry + 0x3d) = 99;
    CEntities::LinkEntityIntoProcessingList(&g_CollisionTriggerEntryListHead,entry);
    *(undefined2 *)(entry + 0x48) = 2;
    *(undefined **)(value + 0x20) = &g_ComingOfAgeBranchBoostScriptAttachmentDesc;
  }
  if (*(short *)(entry + 0x44) != 0) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

