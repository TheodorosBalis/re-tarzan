#include "tarzan_ghidra_types.hpp"

// Address: 0x0044C8D0
// Label: SetSaborAnimationState
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SetSaborAnimationState(int arg1,undefined4 arg2)

{
  Entity *entity = (Entity *)arg1;
  int value;
  
  _g_PreviousSaborAnimationCategory = g_SaborAnimationCategory;
  switch(arg2) {
  case 1:
  case 2:
  case 9:
  case 0xb:
  case 0x13:
    g_SaborAnimationCategory = 2;
    break;
  case 3:
  case 7:
  case 0xc:
    g_SaborAnimationCategory = 1;
    break;
  default:
    g_SaborAnimationCategory = 0;
  }
  g_SaborAnimationState = arg2;
  CEntities::SelectEntityAnimationAttachmentState(arg1,arg2);
  if (g_SaborFlipFacingOnNextAnimationFlag != 0) {
    g_SaborFlipFacingOnNextAnimationFlag = 0;
    value = entity->sceneObjects;
    ((EntitySceneObject *)value)->yaw = ((EntitySceneObject *)value)->yaw ^ 0x800;
    *(byte *)(value + 0x75) = ~*(byte *)(value + 0x75);
  }
  return;
}

