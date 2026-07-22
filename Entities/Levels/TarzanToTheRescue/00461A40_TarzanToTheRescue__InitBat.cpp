#include "tarzan_ghidra_types.hpp"

// Address: 0x00461A40
// Label: TarzanToTheRescue::InitBat
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TarzanToTheRescue::InitBat(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  int value3;
  undefined4 value4;
  
  *(undefined4 *)(entity->sceneObjects + 0x6c) = 0xffffffc0;
  value3 = CEntities::CreateEntityAttachment(entry,0x4c,0x10000000);
  if ((value3 != 0) && (value = entity->sceneObjects, value != 0)) {
    if (entity->descriptor != 0) {
      value2 = *(int *)(entity->descriptor + 0x10);
      if (*(int *)(value2 + 4) == 0) {
        CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&PTR_DAT_00506000);
        ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x2768;
        *(undefined4 *)(value3 + 0x3c) = 0x200;
        *(undefined4 *)(value3 + 0x40) = 0x3c;
        *(undefined4 *)(value3 + 0x44) = 0x300;
        *(undefined4 *)(value3 + 0x48) = 0;
        *(undefined2 *)(entry + 0x3e) = 0x100;
      }
      if (*(int *)(value2 + 4) == 1) {
        CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&PTR_DAT_00506010);
        ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x958;
        *(undefined4 *)(value3 + 0x3c) = 0x400;
        *(undefined4 *)(value3 + 0x40) = 0x28;
        *(undefined4 *)(value3 + 0x44) = 0x63c;
        *(undefined4 *)(value3 + 0x48) = 1;
        *(undefined2 *)(entry + 0x3e) = 0x180;
      }
    }
    ((EntitySceneObject *)value)->roll = 1;
    *(undefined2 *)(value + 0x140) = 0;
    CEntities::AcquireEntitySceneObjectResourceSet(value);
    value = entity->sceneObjects;
    *(undefined4 *)(value3 + 0x10) = ((EntitySceneObject *)value)->x;
    *(undefined4 *)(value3 + 0x14) = ((EntitySceneObject *)value)->y;
    *(undefined4 *)(value3 + 0x18) = ((EntitySceneObject *)value)->z;
    value4 = RandomModulo(0x1000);
    *(undefined4 *)(value3 + 0x1c) = value4;
    *(undefined4 *)(value3 + 0xc) = 0;
    *(undefined4 *)(value3 + 0x34) = 4;
    *(undefined4 *)(value3 + 0x38) = 0;
  }
  CEntities::LinkEntityIntoProcessingList(&g_ScriptedEnemyEntityListHead,entry);
  return;
}

