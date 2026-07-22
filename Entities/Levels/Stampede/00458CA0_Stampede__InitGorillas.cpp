#include "tarzan_ghidra_types.hpp"

// Address: 0x00458CA0
// Label: Stampede::InitGorillas
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void Stampede::InitGorillas(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  undefined4 value3;
  int value2;
  
  value = CEntities::CreateEntityAttachment(entry,0x30,0x10000000);
  if (value != 0) {
    value2 = 0;
    if (entity->descriptor != 0) {
      value2 = *(int *)(entity->descriptor + 0x10);
      if (*(int *)(value2 + 4) == 0) {
        *(undefined4 *)(value + 0x28) = 0;
        *(int *)(entity->sceneObjects + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x2b10;
        *(undefined4 *)(value + 0x2c) = 0;
        *(undefined4 *)(value + 0xc) = 0;
        CEntities::AcquireEntitySceneObjectResourceSet(entity->sceneObjects);
      }
      if (*(int *)(value2 + 4) == 1) {
        *(undefined4 *)(value + 0x28) = 1;
        *(int *)(entity->sceneObjects + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x31f8;
        *(undefined4 *)(value + 0x2c) = 3;
        *(undefined4 *)(value + 0xc) = 2;
        CEntities::AcquireEntitySceneObjectResourceSet(entity->sceneObjects);
        CEntities::MoveEntitySceneObjectAndEaseFacingAngles(entry,1);
      }
    }
    if (*(int *)(value2 + 4) == 2) {
      *(undefined4 *)(value + 0x28) = 2;
      *(int *)(entity->sceneObjects + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x2b78;
      *(undefined4 *)(value + 0x2c) = 5;
      *(undefined4 *)(value + 0xc) = 0;
      CEntities::AcquireEntitySceneObjectResourceSet(entity->sceneObjects);
      CEntities::MoveEntitySceneObjectAndEaseFacingAngles(entry,1);
    }
    if (*(int *)(value2 + 4) == 3) {
      *(undefined4 *)(value + 0x28) = 3;
      *(int *)(entity->sceneObjects + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x2cb0;
      *(undefined4 *)(value + 0x2c) = 7;
      *(undefined4 *)(value + 0xc) = 0;
      CEntities::AcquireEntitySceneObjectResourceSet(entity->sceneObjects);
      CEntities::MoveEntitySceneObjectAndEaseFacingAngles(entry,1);
    }
  }
  *(undefined2 *)(entity->sceneObjects + 0xa6) = 0;
  value3 = (int)CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&DAT_005037b8);
  *(undefined4 *)(value + 0x10) = value3;
  CEntities::SelectScriptAttachmentSequence(value3,*(undefined4 *)(value + 0x2c));
  *(undefined4 *)(value + 0x24) = 0;
  *(undefined4 *)(value + 0x18) = 0x3c;
  *(undefined4 *)(value + 0x1c) = 2;
  *(undefined4 *)(value + 0x20) = 2;
  *(int *)(entity->sceneObjects + 0x6c) = *(int *)(entity->sceneObjects + 0x6c) + -0x40;
  return;
}

