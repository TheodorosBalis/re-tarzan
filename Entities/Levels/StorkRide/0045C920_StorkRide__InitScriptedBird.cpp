#include "tarzan_ghidra_types.hpp"

// Address: 0x0045C920
// Label: StorkRide::InitScriptedBird
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void StorkRide::InitScriptedBird(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  
  *(undefined2 *)(entity->sceneObjects + 0xa6) = 0;
  value = entity->sceneObjects;
  if (value != 0) {
    value2 = CEntities::CreateEntityAttachment(entry,0x4c,0x10000000);
    ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0xf08;
    *(undefined4 *)(value2 + 0xc) = 7;
    *(undefined4 *)(value2 + 0x18) = 0;
    *(undefined4 *)(value2 + 0x1c) = 0;
    *(undefined4 *)(value2 + 0x20) = 0;
    *(undefined2 *)(entity->sceneObjects + 0xa2) = 0x400;
    CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&DAT_005040c0);
  }
  if ((*(byte *)(entry + 0x44) & 1) != 0) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

