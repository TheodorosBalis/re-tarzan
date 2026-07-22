#include "tarzan_ghidra_types.hpp"

// Address: 0x0044E040
// Label: SaborAttacks::InitScenerySabor
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void SaborAttacks::InitScenerySabor(int entry4)

{
  Entity *entity = (Entity *)entry4;
  int entry;
  undefined4 value;
  int entry2;
  int entry3;
  
  if ((*(byte *)(entry4 + 0x44) & 1) == 0) {
    entry2 = CEntities::CreateEntityAttachment(entry4,0x14,0x10000001);
    entry3 = CEntities::CreateRuntimeMotionStateAttachment(entry4);
    entry = entity->sceneObjects;
    if (((entry != 0) && (entry2 != 0)) && (entry3 != 0)) {
      *(undefined4 *)(entry2 + 0xc) = 0;
      ((EntitySceneObject *)entry)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x11e0;
      *(undefined2 *)(entry + 0xc) = 0x91;
      *(undefined1 *)(entry + 0x75) = 0;
      CEntities::AcquireEntitySceneObjectResourceSet(entry);
      CEntities::SetEntitySceneObjectScriptAttachment(entry4,(uint *)&g_SaborScriptAttachmentConfig);
      SetSaborAnimationState(entry4,6);
      ((EntitySceneObject *)entry)->roll = 1;
      *(undefined2 *)(entry + 0x140) = 0;
      value = *(undefined4 *)(*(int *)(entity->descriptor + 0x10) + 4);
      *(undefined4 *)(entry4 + 0x50) = 0;
      *(undefined4 *)(entry4 + 0x4c) = value;
      *(undefined2 *)(entry4 + 0x48) = 0;
      return;
    }
  }
  CEntities::ReleaseEntityToFreeList((byte *)entry4);
  return;
}

