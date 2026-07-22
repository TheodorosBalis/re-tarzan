#include "tarzan_ghidra_types.hpp"

// Address: 0x004361B0
// Label: CPlayerHero::SnapPlayerToAttachmentSurfaceCoord
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::SnapPlayerToAttachmentSurfaceCoord
               (undefined4 *arg1,undefined4 arg2,char arg3)

{
  int value;
  
  *(undefined4 *)(g_PlayerEntitySceneObject + 0x110) = arg2;
  value = arg1[3];
  if ((arg1[5] & 0x2000) != 0) {
    value = value + -1;
  }
  *(int *)(g_PlayerEntitySceneObject + 0x10c) = value;
  *(undefined4 *)(g_PlayerEntitySceneObjectData + 8) = *arg1;
  *(undefined4 *)(g_PlayerEntitySceneObjectData + 0x10) = arg1[2];
  if (arg3 != '\0') {
    *(undefined4 *)(g_PlayerEntitySceneObjectData + 0xc) = arg1[1];
  }
  return;
}

