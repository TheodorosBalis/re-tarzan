#include "tarzan_ghidra_types.hpp"

// Address: 0x00421F40
// Label: CEntities::InitChargingGroundAnimalVariant
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::InitChargingGroundAnimalVariant(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  
  value = entity->sceneObjects;
  *(uint *)(entry + 0x28) = *(uint *)(entry + 0x28) | 0x1000;
  if (value != 0) {
    value2 = g_WorldEntitySceneObjectArrayBase + 0x3190;
    ((EntitySceneObject *)value)->roll = 1;
    ((EntitySceneObject *)value)->worldObject = value2;
    *(undefined2 *)(value + 0x140) = 0;
    CEntities::AcquireEntitySceneObjectResourceSet(value);
    CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&DAT_004c6878);
    value = entity->descriptor;
    *(undefined2 *)(entry + 0x48) = 0;
    *(undefined2 *)(entry + 0x4a) = 0;
    *(undefined2 *)(entry + 0x3e) = 0x200;
    if (value != 0) {
      if ((*(ushort *)(((EntitySceneObject *)value)->worldObject + 2) & 0x100) != 0) {
        *(undefined2 *)(entry + 0x4a) = 0x80;
      }
      if ((*(ushort *)(((EntitySceneObject *)value)->worldObject + 2) & 0x200) != 0) {
        *(ushort *)(entry + 0x4a) = *(ushort *)(entry + 0x4a) | 0x100;
      }
    }
  }
  CEntities::LinkEntityIntoProcessingList(&g_ActiveEntityListHead,entry);
  return;
}

