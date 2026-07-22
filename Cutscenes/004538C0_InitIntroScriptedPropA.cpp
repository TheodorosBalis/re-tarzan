#include "tarzan_ghidra_types.hpp"

// Address: 0x004538C0
// Label: InitIntroScriptedPropA
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void InitIntroScriptedPropA(int arg1)

{
  Entity *entity = (Entity *)arg1;
  int value;
  int value2;
  
  if ((*(byte *)(arg1 + 0x43) & 0x80) == 0) {
    value2 = entity->sceneObjects;
    *(uint *)(arg1 + 0x28) = *(uint *)(arg1 + 0x28) | 4;
    value = g_WorldEntitySceneObjectArrayBase;
    if (value2 != 0) {
      *(byte *)(value2 + 0xf) = *(byte *)(value2 + 0xf) | 1;
      ((EntitySceneObject *)value2)->worldObject = value + 0xd0;
      *(undefined4 *)(value2 + 0xa8) = 0xc00;
      *(undefined4 *)(value2 + 0xac) = 0xc00;
      *(undefined4 *)(value2 + 0xb0) = 0xc00;
      *(undefined **)(value2 + 0x100) = &g_TransitionSceneAnchorSecondary;
      *(undefined4 *)(value2 + 0xb4) = 1;
      ((EntitySceneObject *)value2)->roll = 0;
      *(undefined4 *)(value2 + 0x54) = 0xd200;
      *(undefined4 *)(value2 + 0x58) = 0xd200;
      CEntities::SetEntitySceneObjectScriptAttachment(arg1,(uint *)&DAT_004f2340);
      value2 = CEntities::CreateMotionStateAttachmentAndFlagEntry(arg1);
      if (value2 != 0) {
        *(undefined4 *)(value2 + 0xc) = 0;
      }
    }
    value2 = CEntities::SpawnEntityByTypeAtPosition(0xaa,0,0,3,0x11);
    if (value2 != 0) {
      CEntities::AppendEntityToChildChain(arg1,value2);
    }
    if ((*(byte *)(arg1 + 0x44) & 1) != 0) {
      CEntities::ReleaseEntityToFreeList((byte *)arg1);
    }
  }
  else if (*(int *)(arg1 + 0x18) != 0) {
    CEntities::ReleaseEntityToFreeList(*(int *)(arg1 + 0x18));
    return;
  }
  return;
}

