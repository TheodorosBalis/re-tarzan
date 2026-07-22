#include "tarzan_ghidra_types.hpp"

// Address: 0x00475C50
// Label: KerchakChase::InitChaseFinishTrigger
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void KerchakChase::InitChaseFinishTrigger(undefined4 entry)

{
  int value;
  int value2;
  int value3;
  
  value = CEntities::CreateEntityAttachment(entry,0x1c,0x10000000);
  if (value != 0) {
    *(undefined4 *)(value + 0xc) = 0;
    value2 = CEntities::FindEntityAttachmentByFlags(entry,0x200);
    if (value2 != 0) {
      *(undefined4 *)(value + 0xc) = 0;
      value3 = *(int *)(value2 + 0x18);
      *(undefined4 *)(value + 0x10) = *(undefined4 *)(value3 + 0x20);
      *(undefined4 *)(value + 0x14) = *(undefined4 *)(value3 + 0x24);
      *(undefined4 *)(value + 0x18) = *(undefined4 *)(value3 + 0x28);
      value3 = GetEncodedEntitySceneObjectIdFromSourceRef(*(undefined4 *)(value2 + 0x18));
      if ((value3 == 0x2010) || (value3 == 0x200f)) {
        DecodeEncodedEntitySceneObjectIdToSourceRef(*(undefined4 *)(value2 + 0x18),0x200a);
      }
      if ((value3 == 0x2008) || (value3 == 0x2009)) {
        DecodeEncodedEntitySceneObjectIdToSourceRef(*(undefined4 *)(value2 + 0x18),0x2007);
      }
      CEntities::GetChildSceneAttachmentWorldPositionByMask
                (*(undefined4 *)(value2 + 0x18),1,(undefined4 *)(value + 0x10));
      CEntities::LinkEntityIntoProcessingList(&g_CollisionTriggerEntryListHead,entry);
    }
  }
  return;
}

