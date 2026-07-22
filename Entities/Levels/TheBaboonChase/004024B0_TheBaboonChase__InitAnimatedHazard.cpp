#include "tarzan_ghidra_types.hpp"

// Address: 0x004024B0
// Label: TheBaboonChase::InitAnimatedHazard
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TheBaboonChase::InitAnimatedHazard(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  int value3;
  undefined4 value4;
  
  value = entity->sceneObjects;
  if (value != 0) {
    if (entity->descriptor == 0) {
      value3 = 0;
    }
    else {
      value2 = *(int *)(entity->descriptor + 0x10);
      value3 = *(int *)(value2 + 4);
      value2 = *(int *)(value2 + 8);
      *(int *)(entry + 0x50) = value2 * value2;
    }
    ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x1e10;
    ((EntitySceneObject *)value)->roll = 1;
    value2 = (int)CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&DAT_004bc5e8);
    CEntities::CreateRuntimeMotionStateAttachment(entry);
    if (value3 == 1) {
      *(undefined2 *)(entry + 0x48) = 0;
      *(undefined4 *)(entry + 0x4c) = 0;
      *(undefined1 *)(value + 0x75) = 0;
      if (value2 != 0) {
        CEntities::SelectScriptAttachmentSequence(value2,0x10);
      }
    }
    else {
      *(undefined2 *)(entry + 0x48) = 2;
      value3 = RandomModulo(0x20);
      *(int *)(entry + 0x4c) = value3 + -0x10;
      value4 = RandomModulo(2);
      *(undefined4 *)(entry + 0x50) = value4;
      *(undefined1 *)(value + 0x75) = 0xff;
    }
  }
  if (*(short *)(entry + 0x44) != 0) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

