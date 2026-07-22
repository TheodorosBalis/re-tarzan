#include "tarzan_ghidra_types.hpp"

// Address: 0x00453A80
// Label: InitIntroScriptedPropB
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void InitIntroScriptedPropB(int arg1)

{
  Entity *entity = (Entity *)arg1;
  int value;
  int value2;
  
  value2 = g_WorldEntitySceneObjectArrayBase;
  value = entity->sceneObjects;
  if (value != 0) {
    *(byte *)(value + 0xf) = *(byte *)(value + 0xf) | 1;
    ((EntitySceneObject *)value)->worldObject = value2 + 0x68;
    *(undefined4 *)(value + 0xa8) = 0xc00;
    *(undefined4 *)(value + 0xac) = 0xc00;
    *(undefined4 *)(value + 0xb0) = 0xc00;
    *(undefined **)(value + 0x100) = &g_TransitionSceneAnchorSecondary;
    ((EntitySceneObject *)value)->yaw = 0xfe00;
    ((EntitySceneObject *)value)->roll = 0;
    *(undefined4 *)(value + 0xb4) = 1;
    *(undefined4 *)(value + 0x54) = 0xd200;
    *(undefined4 *)(value + 0x58) = 0xd200;
    CEntities::SetEntitySceneObjectScriptAttachment(arg1,(uint *)&DAT_004f2498);
  }
  if ((*(byte *)(arg1 + 0x44) & 1) != 0) {
    CEntities::ReleaseEntityToFreeList((byte *)arg1);
  }
  return;
}

