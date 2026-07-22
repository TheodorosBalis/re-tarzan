#include "tarzan_ghidra_types.hpp"

// Address: 0x0044C9A0
// Label: PlaceSaborOnPlayerSurfaceAndMove
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void PlaceSaborOnPlayerSurfaceAndMove(int arg1,undefined4 arg2)

{
  ushort value2;
  int value;
  
  *(undefined4 *)(arg1 + 0x110) = *(undefined4 *)(g_PlayerEntitySceneObject + 0x110);
  *(undefined4 *)(arg1 + 0x10c) = *(undefined4 *)(g_PlayerEntitySceneObject + 0x10c);
  value = g_PlayerEntitySceneObject;
  *(undefined4 *)(arg1 + 0x10c) = *(undefined4 *)(g_PlayerEntitySceneObject + 0x10c);
  *(undefined4 *)(arg1 + 0x110) = *(undefined4 *)(value + 0x110);
  *(undefined4 *)(arg1 + 0x114) = *(undefined4 *)(g_PlayerEntitySceneObject + 0x114);
  *(undefined4 *)(arg1 + 0x108) = *(undefined4 *)(g_PlayerEntitySceneObject + 0x108);
  ComputeEntitySceneObjectCollisionMoveDelta(arg2,0,arg1);
  value = *(int *)(arg1 + 0x14) + *(int *)(arg1 + 0x54);
  *(int *)(arg1 + 0x14) = value;
  *(int *)(arg1 + 0x18) = *(int *)(arg1 + 0x18) + *(int *)(arg1 + 0x58);
  value2 = *(ushort *)(arg1 + 0x132) & 0xf7ff;
  *(int *)(arg1 + 0x1c) = *(int *)(arg1 + 0x1c) + *(int *)(arg1 + 0x5c);
  *(undefined1 *)(arg1 + 0x75) = 0xff;
  *(ushort *)(arg1 + 0xa2) = value2;
  if (value < *(int *)(*(int *)(g_PlayerEntity + 0x38) + 0x14)) {
    *(undefined1 *)(arg1 + 0x75) = 0;
    *(ushort *)(arg1 + 0xa2) = value2 ^ 0x800;
  }
  return;
}

