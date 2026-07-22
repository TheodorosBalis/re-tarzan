#include "tarzan_ghidra_types.hpp"

// Address: 0x00402190
// Label: TheBaboonChase::InitRisingScriptedEffect
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TheBaboonChase::InitRisingScriptedEffect(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  
  value = entity->sceneObjects;
  if (value != 0) {
    ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x8f0;
    *(undefined2 *)(value + 0xc) = 0x15;
    *(undefined4 *)(value + 0xb4) = 1;
    ((EntitySceneObject *)value)->roll = 1;
    CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&PTR_DAT_004bc5f8);
  }
  CEntities::LinkEntityIntoProcessingList(&DAT_0051c2c8,entry);
  if (*(short *)(entry + 0x44) != 0) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

