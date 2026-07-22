#include "tarzan_ghidra_types.hpp"

// Address: 0x00467290
// Label: TarzanToTheRescue::InitElephantRideTokenPickup
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TarzanToTheRescue::InitElephantRideTokenPickup(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  
  value = entity->sceneObjects;
  *(byte *)(value + 0xf) = *(byte *)(value + 0xf) | 0x10;
  *(undefined ***)(&((EntitySceneObject *)value)->worldObject) = &g_LanguageFontAssetSet;
  *(undefined4 *)(value + 0x6c) = 0xffffff80;
  value = CEntities::SetEntitySceneObjectScriptAttachment
                    (entry,&g_CollectibleIdleScriptAttachmentDesc);
  if (value != 0) {
    *(undefined2 *)(value + 0x16) = 0;
    CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
  }
  value = CEntities::CreateEntityAttachment(entry,0x60,0x20000000);
  if (value != 0) {
    *(undefined4 *)(value + 0xc) = 3;
    ((EntitySceneObject *)value)->y = 0x50;
    ((EntitySceneObject *)value)->x = 0x400;
    *(undefined4 *)(value + 0x2c) = 1;
    ((EntitySceneObject *)value)->worldObject = 0;
    *(undefined4 *)(value + 0x40) = 0;
    *(undefined4 *)(value + 0x44) = 0;
    *(int *)(value + 0x24) = *(int *)(entity->sceneObjects + 0x18) + 0x1000;
  }
  CEntities::AdvanceEntityBounceMotionAndReturnImpact(entry);
  *(undefined4 *)(entry + 0x4c) = 0;
  *(undefined4 *)(entry + 0x50) = 0;
  *(undefined2 *)(entry + 0x48) = 1;
  return;
}

