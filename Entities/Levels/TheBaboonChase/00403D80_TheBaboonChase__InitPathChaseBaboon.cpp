#include "tarzan_ghidra_types.hpp"

// Address: 0x00403D80
// Label: TheBaboonChase::InitPathChaseBaboon
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TheBaboonChase::InitPathChaseBaboon(int entry)

{
  Entity *entity = (Entity *)entry;
  ushort *dataCursor;
  int value;
  int value2;
  undefined4 value3;
  
  value2 = CEntities::CreateEntityAttachment(entry,0x7c,0x10000000);
  if (value2 != 0) {
    *(int *)(entity->sceneObjects + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x1e10;
    value3 = (int)CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&DAT_004bc5e8);
    *(undefined4 *)(value2 + 0x10) = value3;
    CEntities::AcquireEntitySceneObjectResourceSet(entity->sceneObjects);
    CEntities::SelectScriptAttachmentSequence(*(undefined4 *)(value2 + 0x10),0);
    *(undefined4 *)(value2 + 0xc) = 1;
    *(undefined2 *)(entity->sceneObjects + 0xa6) = 1;
    dataCursor = (ushort *)(entity->sceneObjects + 0xe);
    *dataCursor = *dataCursor & 0x7fff;
    *(undefined4 *)(value2 + 0x14) = 0;
    if (entity->descriptor != 0) {
      value = *(int *)(*(int *)(entity->descriptor + 0x10) + 4);
      if (value == 0) {
        *(undefined4 *)(value2 + 0x18) = 0;
        *(undefined4 *)(entity->sceneObjects + 0x6c) = 0xffffffc0;
        PlayAudioById(600,(int *)0,(undefined4 *)0);
      }
      else {
        if (value == 1) {
          *(undefined4 *)(value2 + 0x18) = 0xf;
          *(undefined4 *)(entity->sceneObjects + 0x6c) = 0xffffffe0;
          return;
        }
        if (value == 2) {
          *(undefined4 *)(value2 + 0x18) = 0xfffffff1;
          *(undefined4 *)(entity->sceneObjects + 0x6c) = 0xffffffa0;
          return;
        }
      }
    }
  }
  return;
}

