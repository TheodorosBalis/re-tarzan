#include "tarzan_ghidra_types.hpp"

// Address: 0x0044FE80
// Label: SaborAttacks::InitEagle
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void SaborAttacks::InitEagle(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  
  value = entity->sceneObjects;
  if (value != 0) {
    ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x958;
    ((EntitySceneObject *)value)->roll = 1;
    *(undefined2 *)(value + 0x140) = 0;
    CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&g_SaborAttacksEagleScriptDesc);
    value = CEntities::CreateEntityAttachment(entry,0x20,0x10000000);
    if (value != 0) {
      *(undefined4 *)(value + 0xc) = 0;
      ((EntitySceneObject *)value)->worldObject = 0;
      ((EntitySceneObject *)value)->z = 0xffffffff;
      *(undefined2 *)(entry + 0x48) = 10;
      *(undefined2 *)(entry + 0x4a) = 1;
      if (entity->descriptor == 0) {
        return;
      }
      if ((*(byte *)(*(int *)(entity->descriptor + 0x10) + 3) & 1) == 0) {
        return;
      }
      *(undefined2 *)(entry + 0x4a) = 0x201;
      return;
    }
  }
  CEntities::ReleaseEntityToFreeList((byte *)entry);
  return;
}

