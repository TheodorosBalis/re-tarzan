#include "tarzan_ghidra_types.hpp"

// Address: 0x00436210
// Label: CPlayerHero::MoveToAnimationAttachmentWithCollision
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::MoveToAnimationAttachmentWithCollision(void)

{
  int value;
  int value2;
  uint value3;
  
  value2 = GetSceneAttachmentWorldPositionByMask
                    (g_PlayerEntitySceneObject,0x40,&g_BranchBoostChildWorldPositionScratch);
  value = g_PlayerEntitySceneObject;
  if (value2 != 0) {
    *(undefined4 *)(g_PlayerEntitySceneObject + 0x14) = g_BranchBoostChildWorldPositionScratch;
    *(undefined4 *)(value + 0x18) = g_BranchBoostChildSceneObjectPtrScratch;
    *(undefined4 *)(value + 0x1c) = g_BranchBoostChildWorldPositionZScratch;
    value3 = (uint)*(short *)(value2 + 4);
    if (*(char *)(g_PlayerEntitySceneObject + 0x75) == '\0') {
      value3 = ~value3 + 1;
    }
    ComputeEntitySceneObjectCollisionMoveDelta(value3,0,g_PlayerEntitySceneObject);
  }
  return;
}

