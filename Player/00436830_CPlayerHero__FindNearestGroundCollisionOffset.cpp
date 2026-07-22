#include "tarzan_ghidra_types.hpp"

// Address: 0x00436830
// Label: CPlayerHero::FindNearestGroundCollisionOffset
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

uint CPlayerHero::FindNearestGroundCollisionOffset(uint arg1)

{
  int foundIndex;
  int foundIndex2;
  int foundIndex3;
  uint value;
  int foundIndex4;
  uint value2;
  int localState;
  
  foundIndex4 = 0;
  g_PlayerCollisionContactFlags = g_PlayerCollisionContactFlags & 0xffff;
  g_PlayerGroundContactEntitySceneObject = 0;
  value2 = arg1;
  for (foundIndex2 = g_ActiveEntityListHead; foundIndex2 != 0; foundIndex2 = *(int *)(foundIndex2 + 0x20)) {
    for (foundIndex = *(int *)(foundIndex2 + 0x38); foundIndex != 0; foundIndex = *(int *)(foundIndex + 0x34)) {
      localState = GetEntitySceneObjectAttachmentList(foundIndex,&arg1);
      if ((localState != 0) && (0 < localState)) {
        do {
          if (((*(byte *)(arg1 + 0xc) & 0x10) != 0) &&
             ((foundIndex3 = GetGroundAttachmentContactY(arg1,foundIndex,g_PlayerEntitySceneObject),
              foundIndex3 != -0x80000000 &&
              (value = foundIndex3 - *(int *)(g_PlayerEntitySceneObjectData + 0xc),
              (int)((value ^ (int)value >> 0x1f) - ((int)value >> 0x1f)) <
              (int)((value2 ^ (int)value2 >> 0x1f) - ((int)value2 >> 0x1f)))))) {
            foundIndex4 = *(int *)(arg1 + 0xc);
            value2 = value;
            g_PlayerGroundContactEntitySceneObject = foundIndex;
          }
          arg1 = arg1 + 0x10;
          localState = localState + -1;
        } while (localState != 0);
      }
    }
  }
  g_PlayerCollisionContactFlags = g_PlayerCollisionContactFlags | foundIndex4 << 0x10;
  return value2;
}

