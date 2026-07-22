#include "tarzan_ghidra_types.hpp"

// Address: 0x0041D060
// Label: ComingOfAge::InitLemurVariantB
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ComingOfAge::InitLemurVariantB(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  byte flagByte;
  int value2;
  
  value = entity->sceneObjects;
  *(uint *)(entry + 0x28) = *(uint *)(entry + 0x28) | 0x1000;
  if (value != 0) {
    value2 = g_WorldEntitySceneObjectArrayBase + 0x478;
    ((EntitySceneObject *)value)->roll = 1;
    ((EntitySceneObject *)value)->worldObject = value2;
    *(undefined2 *)(value + 0x140) = 0;
    CEntities::AcquireEntitySceneObjectResourceSet(value);
    CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&DAT_004c4ba0);
    value2 = entity->descriptor;
    *(undefined2 *)(entry + 0x48) = 0;
    *(undefined2 *)(entry + 0x4a) = 0;
    if (value2 != 0) {
      if ((*(byte *)(*(int *)(value2 + 0x10) + 3) & 1) != 0) {
        *(undefined2 *)(entry + 0x4a) = 0x80;
      }
      flagByte = *(byte *)(*(int *)(value2 + 0x10) + 4);
      if (*(int *)(*(int *)(value2 + 0x10) + 4) == 99) {
        flagByte = RandomModulo(8);
      }
      if ((flagByte & 1) != 0) {
        *(byte *)(value + 0xf) = *(byte *)(value + 0xf) | 2;
        *(undefined4 *)(value + 0x70) = 1;
      }
    }
  }
  CEntities::LinkEntityIntoProcessingList(&g_ActiveEntityListHead,entry);
  return;
}

