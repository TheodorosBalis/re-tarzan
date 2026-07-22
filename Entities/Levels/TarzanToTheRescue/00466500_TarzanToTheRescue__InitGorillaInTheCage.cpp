#include "tarzan_ghidra_types.hpp"

// Address: 0x00466500
// Label: TarzanToTheRescue::InitGorillaInTheCage
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TarzanToTheRescue::InitGorillaInTheCage(int entry)

{
  Entity *entity = (Entity *)entry;
  byte *value4;
  int value;
  int value2;
  undefined4 value3;
  
  value2 = CEntities::CreateEntityAttachment(entry,0x24,0x10000000);
  if (value2 != 0) {
    if (entity->descriptor != 0) {
      value = *(int *)(entity->descriptor + 0x10);
      if (*(int *)(value + 4) == 0) {
        *(undefined4 *)(value2 + 0x20) = 0;
        *(undefined2 *)(entity->sceneObjects + 0xc) = 0x200c;
        *(undefined4 *)(entity->sceneObjects + 0x110) = 0xf;
        *(undefined4 *)(entity->sceneObjects + 0x10c) = 0;
        *(undefined4 *)(entity->sceneObjects + 0x108) = 1;
        UpdateEntityEntitySceneObjectTransformFromPlacement(entity->sceneObjects);
        value3 = (int)CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&DAT_00507098);
        *(undefined4 *)(value2 + 0x10) = value3;
        *(int *)(entity->sceneObjects + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x2cb0;
        CEntities::AcquireEntitySceneObjectResourceSet(entity->sceneObjects);
      }
      if (*(int *)(value + 4) == 1) {
        *(undefined4 *)(value2 + 0x20) = 1;
        value4 = (byte *)(entity->sceneObjects + 0xf);
        *value4 = *value4 | 8;
        *(undefined2 *)(entity->sceneObjects + 0xc) = 0x200c;
        *(undefined4 *)(entity->sceneObjects + 0x110) = 0x12;
        *(undefined4 *)(entity->sceneObjects + 0x10c) = 0;
        *(undefined4 *)(entity->sceneObjects + 0x108) = 1;
        *(undefined2 *)(entity->sceneObjects + 0xa2) = 0xff00;
        UpdateEntityEntitySceneObjectTransformFromPlacement(entity->sceneObjects);
        value3 = (int)CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&DAT_00507098);
        *(undefined4 *)(value2 + 0x10) = value3;
        *(int *)(entity->sceneObjects + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x2b78;
        CEntities::AcquireEntitySceneObjectResourceSet(entity->sceneObjects);
      }
      if (*(int *)(value + 4) == 2) {
        *(undefined4 *)(value2 + 0x20) = 2;
        *(undefined2 *)(entity->sceneObjects + 0xc) = 0x200c;
        *(undefined4 *)(entity->sceneObjects + 0x110) = 0x13;
        *(undefined4 *)(entity->sceneObjects + 0x10c) = 0;
        *(undefined4 *)(entity->sceneObjects + 0x108) = 1;
        *(undefined2 *)(entity->sceneObjects + 0xa2) = 0x100;
        UpdateEntityEntitySceneObjectTransformFromPlacement(entity->sceneObjects);
        value3 = (int)CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&DAT_00507098);
        *(undefined4 *)(value2 + 0x10) = value3;
        *(int *)(entity->sceneObjects + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x2b10;
        CEntities::AcquireEntitySceneObjectResourceSet(entity->sceneObjects);
      }
    }
    *(undefined4 *)(value2 + 0x14) = 0x80;
    *(undefined4 *)(value2 + 0x18) = 0x30;
    value3 = RandomModulo(0x1000);
    *(undefined4 *)(value2 + 0x1c) = value3;
    *(undefined4 *)(value2 + 0xc) = 0;
    *(undefined2 *)(entity->sceneObjects + 0xa6) = 0;
  }
  return;
}

