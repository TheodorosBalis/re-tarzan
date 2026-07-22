#include "tarzan_ghidra_types.hpp"

// Address: 0x0044A1A0
// Label: CEntities::InitSketchPickup
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::InitSketchPickup(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  uint value3;
  
  value2 = g_WorldEntitySceneObjectArrayBase;
  value = entity->sceneObjects;
  if (value != 0) {
    *(byte *)(value + 0xf) = *(byte *)(value + 0xf) | 0x10;
    ((EntitySceneObject *)value)->worldObject = value2 + 0x3a8;
    CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&g_SketchPickupScriptAttachmentDesc);
    ComputeEntitySceneObjectCollisionMoveDelta(0,0,value);
    if (entity->descriptor != 0) {
      value2 = *(int *)(entity->descriptor + 0x10);
      *(int *)(entry + 0x4c) = *(int *)(value2 + 4) + -1;
      *(undefined4 *)(value + 0x6c) = *(undefined4 *)(value2 + 8);
      value2 = *(int *)(value2 + 0x10);
      if (value2 != 0) {
        *(undefined4 *)(value + 0xb4) = 1;
        value3 = (uint)*(ushort *)(&g_CollectibleInitialVariantFrameTable + value2 * 2);
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

