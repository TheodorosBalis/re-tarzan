#include "tarzan_ghidra_types.hpp"

// Address: 0x00482380
// Label: CEntities::InitLeafSwimmingToken
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::InitLeafSwimmingToken(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  int value3;
  uint value4;
  
  value = entity->sceneObjects;
  *(byte *)(value + 0xf) = *(byte *)(value + 0xf) | 0x10;
  *(undefined ***)(&((EntitySceneObject *)value)->worldObject) = &g_LanguageFontAssetSet;
  value2 = CEntities::SetEntitySceneObjectScriptAttachment
                    (entry,&g_CollectibleIdleScriptAttachmentDesc);
  if (value2 == 0) {
    CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
  }
  else {
    value4 = (int)((EntitySceneObject *)value)->x >> 0x1f;
    *(short *)(value2 + 0x16) = (short)((int)((((EntitySceneObject *)value)->x ^ value4) - value4) % 0x18);
    CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
  }
  value2 = CEntities::CreateEntityAttachment(entry,0x60,0x20000000);
  if (value2 != 0) {
    *(undefined4 *)(value2 + 0xc) = 2;
    value3 = RandomModulo(0x40);
    *(int *)(value2 + 0x14) = value3 + 0x80;
    *(undefined4 *)(value2 + 0x10) = 0;
    *(undefined4 *)(value2 + 0x28) = 0;
    *(undefined4 *)(value2 + 0x2c) = 0;
    *(undefined4 *)(value2 + 0x30) = 0;
    *(undefined4 *)(value2 + 0x34) = 0;
    *(undefined4 *)(value2 + 0x24) = *(undefined4 *)(entity->sceneObjects + 0x18);
  }
  g_ActiveLeafSwimmingTokenCount = g_ActiveLeafSwimmingTokenCount + 1;
  *(undefined4 *)(value + 0xb4) = 1;
  *(undefined4 *)(value + 0xa8) = 0xc00;
  *(undefined4 *)(value + 0xac) = 0xc00;
  *(undefined4 *)(value + 0xb0) = 0xc00;
  *(undefined2 *)(entry + 0x4a) = 0;
  return;
}

