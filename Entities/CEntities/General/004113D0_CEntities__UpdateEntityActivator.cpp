#include "tarzan_ghidra_types.hpp"

// Address: 0x004113D0
// Label: CEntities::UpdateEntityActivator
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::UpdateEntityActivator(int entry)

{
  Entity *entity = (Entity *)entry;
  byte *value;
  int entry2;
  int entry3;
  
  entry3 = entity->sceneObjects;
  entry2 = CEntities::GetClaytonDistanceAheadOfPlayer(entry3);
  if (entry2 < 0x1381) {
    ((EntitySceneObject *)entry3)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x618;
    *(undefined2 *)(entry3 + 0xc) = 0;
    CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&DAT_004c0fc8);
    CEntities::SelectEntityAnimationAttachmentState(entry,1);
    ((EntitySceneObject *)entry3)->roll = 1;
    *(undefined1 *)(entry3 + 0x75) = 0xff;
    entry3 = CEntities::FindEntityAttachmentByFlags(entry,0x400);
    if (entry3 == 0) {
      CEntities::ReleaseEntityToFreeList((byte *)entry);
      return;
    }
    *(undefined2 *)(entry + 0x48) = 0x15;
    value = (byte *)(entity->sceneObjects + 0xf);
    *value = *value | 0x80;
    *(undefined2 *)(entry + 0x46) = 0x185;
    *(undefined4 *)(entry + 0x2c) = *(undefined4 *)(g_EntityTypeCallbackTable + 0xc28);
    *(undefined4 *)(entry + 0x30) = *(undefined4 *)(g_EntityTypeCallbackTable + 0xc2c);
  }
  return;
}

