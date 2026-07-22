#include "tarzan_ghidra_types.hpp"

// Address: 0x0044A350
// Label: CEntities::InitTokenPickup
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::InitTokenPickup(int entry)

{
  Entity *entity = (Entity *)entry;
  byte *value4;
  int value;
  int value2;
  uint value3;
  
  value = entity->sceneObjects;
  if (value != 0) {
    *(undefined ***)(&((EntitySceneObject *)value)->worldObject) = &g_LanguageFontAssetSet;
    ((EntitySceneObject *)value)->roll = 3;
    value4 = (byte *)(entity->sceneObjects + 0xf);
    *value4 = *value4 | 0x10;
    *(undefined2 *)(entry + 0x48) = 1;
    *(undefined2 *)(entry + 0x4a) = 0;
    value2 = CEntities::SetEntitySceneObjectScriptAttachment
                      (entry,&g_CollectibleIdleScriptAttachmentDesc);
    if (value2 != 0) {
      value3 = (int)((EntitySceneObject *)value)->x >> 0x1f;
      *(short *)(value2 + 0x16) = (short)((int)((((EntitySceneObject *)value)->x ^ value3) - value3) % 0x18);
      CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
    }
    if (entity->descriptor != 0) {
      value2 = *(int *)(entity->descriptor + 0x10);
      if (*(int *)(value2 + 4) != 0) {
        ((EntitySceneObject *)value)->y = ((EntitySceneObject *)value)->y - *(int *)(value2 + 4);
      }
      *(undefined4 *)(value + 0x6c) = *(undefined4 *)(value2 + 8);
      value3 = *(uint *)(value2 + 0x10);
      if (value3 != 0) {
        *(uint *)(entry + 0x50) = value3;
        *(undefined4 *)(value + 0xb4) = 1;
        value3 = (uint)*(ushort *)(&g_CollectibleInitialVariantFrameTable + (value3 & 0xf) * 2);
        *(uint *)(value + 0xb0) = value3;
        *(uint *)(value + 0xac) = value3;
        *(uint *)(value + 0xa8) = value3;
      }
    }
  }
  if ((*(byte *)(entry + 0x44) & 1) != 0) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

