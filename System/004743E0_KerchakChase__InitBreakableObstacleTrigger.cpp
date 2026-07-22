#include "tarzan_ghidra_types.hpp"

// Address: 0x004743E0
// Label: KerchakChase::InitBreakableObstacleTrigger
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void KerchakChase::InitBreakableObstacleTrigger(undefined4 entry)

{
  int value;
  int value2;
  
  value = CEntities::CreateEntityAttachment(entry,0x1c,0x10000000);
  if (value != 0) {
    *(undefined4 *)(value + 0xc) = 0;
    value = CEntities::FindEntityAttachmentByFlags(entry,0x200);
    if (value != 0) {
      value2 = GetEncodedEntitySceneObjectIdFromSourceRef(*(undefined4 *)(value + 0x18));
      if (value2 == 0x2006) {
        DecodeEncodedEntitySceneObjectIdToSourceRef(*(undefined4 *)(value + 0x18),0x5021);
      }
    }
  }
  return;
}

