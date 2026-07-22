#include "tarzan_ghidra_types.hpp"

// Address: 0x00416ED0
// Label: ComingOfAge::InitBananaTree
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ComingOfAge::InitBananaTree(int entry)

{
  Entity *entity = (Entity *)entry;
  undefined2 value4;
  undefined4 value5;
  short *value6;
  int value;
  int value2;
  short *value7;
  undefined2 *dataCursor;
  int value3;
  undefined2 *dataCursor2;
  
  if (entity->descriptor != 0) {
    *(undefined4 *)(entry + 0x50) = *(undefined4 *)(*(int *)(entity->descriptor + 0x10) + 4)
    ;
  }
  *(undefined2 *)(entry + 0x48) = 1;
  value = CEntities::FindEntityAttachmentByFlags(entry,0x200);
  if (value != 0) {
    *(undefined ***)(value + 0x24) = &PTR_DAT_004c2e38;
    CEntities::ResetScriptAttachmentSequenceState(value,0);
    value3 = *(int *)(value + 0x18);
    if (value3 != 0) {
      value2 = CreateEntityEntitySceneObject((uint *)entry,1);
      if (value2 != 0) {
        *(undefined4 *)(value2 + 0x14) = *(undefined4 *)(value + 0xc);
        *(undefined4 *)(value2 + 0x18) = *(undefined4 *)(value + 0x10);
        value5 = *(undefined4 *)(value + 0x14);
        *(undefined2 *)(value2 + 0xe) = 0;
        *(undefined4 *)(value2 + 0x1c) = value5;
        *(int *)(value2 + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x3a8;
        value7 = (short *)CEntities::ResolveChildSceneObjectArrayFromRef(value3);
        if (((value7 != (short *)0x0) && (0 < *value7)) &&
           (value = CEntities::CreateChildEntitySceneObjectArrayAttachment(entry,1,(int)*value7),
           value != 0)) {
          value3 = 0;
          if (0 < *value7) {
            dataCursor2 = &DAT_004c2cfc;
            dataCursor = (undefined2 *)(value + 0x10);
            value6 = value7;
            do {
              *(int *)(dataCursor + 2) = g_WorldEntitySceneObjectArrayBase + 0x3a8;
              value4 = *dataCursor2;
              dataCursor[1] = dataCursor[1] | 0x8000;
              *dataCursor = value4;
              *(int *)(dataCursor + 4) = (int)value6[2];
              value3 = value3 + 1;
              *(int *)(dataCursor + 6) = (int)value6[3];
              dataCursor2 = dataCursor2 + 1;
              *(int *)(dataCursor + 8) = (int)value6[4];
              dataCursor = dataCursor + 0x14;
              value6 = value6 + 4;
            } while (value3 < *value7);
          }
        }
      }
      *(undefined1 *)(entry + 0x3d) = 0x50;
      CEntities::LinkEntityIntoProcessingList(&g_CollisionTriggerEntryListHead,entry);
    }
  }
  return;
}

