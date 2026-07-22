#include "tarzan_ghidra_types.hpp"

// Address: 0x00459110
// Label: Stampede::InitCivetRhino
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void Stampede::InitCivetRhino(int entry)

{
  Entity *entity = (Entity *)entry;
  ushort *dataCursor;
  int value;
  int value2;
  int value3;
  
  value = CEntities::CreateEntityAttachment(entry,0x34,0x10000000);
  if (value != 0) {
    if (*( undefined1 *)((int)&g_LevelTransitionContext + 2) == '\x04') {
      dataCursor = (ushort *)(entity->sceneObjects + 0xe);
      *dataCursor = *dataCursor | 0x800;
    }
    *(undefined2 *)(entity->sceneObjects + 0xa6) = 1;
    *(undefined4 *)(value + 0xc) = 0;
    if (entity->descriptor != 0) {
      value3 = *(int *)(entity->descriptor + 0x10);
      if (*(int *)(value3 + 4) == 0) {
        *(int *)(entity->sceneObjects + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x410;
        CEntities::AcquireEntitySceneObjectResourceSet(entity->sceneObjects);
        *(undefined2 *)(entity->sceneObjects + 0xc) = 2;
        value2 = (int)CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&DAT_00503898);
        *(int *)(value + 0x18) = value2;
        if (value2 != 0) {
          CEntities::SelectScriptAttachmentSequence(value2,0);
        }
      }
      if (*(int *)(value3 + 4) == 1) {
        *(undefined4 *)(entity->sceneObjects + 0xb4) = 1;
        *(undefined4 *)(entity->sceneObjects + 0xa8) = 0x800;
        *(undefined4 *)(entity->sceneObjects + 0xac) = 0x800;
        *(undefined4 *)(entity->sceneObjects + 0xb0) = 0x800;
        *(int *)(entity->sceneObjects + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x410;
        CEntities::AcquireEntitySceneObjectResourceSet(entity->sceneObjects);
        *(undefined2 *)(entity->sceneObjects + 0xc) = 2;
        value2 = (int)CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&DAT_00503898);
        *(int *)(value + 0x18) = value2;
        if (value2 != 0) {
          CEntities::SelectScriptAttachmentSequence(value2,0);
        }
      }
      if (*(int *)(value3 + 4) == 2) {
        *(int *)(entity->sceneObjects + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x3878;
        value2 = (int)CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&DAT_00503898);
        *(int *)(value + 0x18) = value2;
        if (value2 != 0) {
          CEntities::SelectScriptAttachmentSequence(value2,2);
        }
        *(undefined4 *)(value + 0x30) = 0;
      }
      if (*(int *)(value3 + 4) == 3) {
        *(int *)(entity->sceneObjects + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x3190;
        CEntities::AcquireEntitySceneObjectResourceSet(entity->sceneObjects);
        value3 = (int)CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&DAT_00503898);
        *(int *)(value + 0x18) = value3;
        if (value3 != 0) {
          CEntities::SelectScriptAttachmentSequence(value3,3);
          *(undefined4 *)(value + 0xc) = 4;
          *(undefined4 *)(value + 0x30) = 1;
        }
      }
    }
    *(undefined1 *)(entity->sceneObjects + 0x75) = 0;
    *(undefined4 *)(value + 0x20) = 2;
    *(undefined4 *)(value + 0x24) = 2;
    *(undefined4 *)(value + 0x10) = 0;
    *(undefined4 *)(value + 0x28) = 10;
    *(undefined4 *)(value + 0x1c) = 0x14;
  }
  return;
}

