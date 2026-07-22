#include "tarzan_ghidra_types.hpp"

// Address: 0x00436480
// Label: CPlayerHero::TrySnapToNearbyGround
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 CPlayerHero::TrySnapToNearbyGround(void)

{
  uint value3;
  int value;
  int value2;
  uint value4;
  
  value3 = *(int *)(g_PlayerEntitySceneObjectData + 8) - *(int *)(g_PlayerEntitySceneObject + 0x48);
  value4 = (int)value3 >> 0x1f;
  value2 = (value3 ^ value4) - value4;
  if (value2 < 0x10) {
    value2 = value2 + 0x10;
  }
  else {
    value2 = value2 + 8;
  }
  value3 = *(int *)(g_PlayerEntitySceneObjectData + 0x10) -
          *(int *)(g_PlayerEntitySceneObject + 0x50);
  value4 = (int)value3 >> 0x1f;
  value3 = (uint)_g_PlayerCollisionSnapRange + value2 + ((value3 ^ value4) - value4);
  value = CPlayerHero::FindGroundSnapOffset();
  value2 = g_PlayerEntitySceneObject;
  if (value == 0x7fffffff) {
    *(undefined4 *)(g_PlayerEntitySceneObject + 0x14) =
         *(undefined4 *)(g_PlayerEntitySceneObject + 0x48);
    *(undefined4 *)(value2 + 0x18) = *(undefined4 *)(value2 + 0x4c);
    *(undefined4 *)(value2 + 0x1c) = *(undefined4 *)(value2 + 0x50);
    return 1;
  }
  if ((g_PlayerCurrentCollisionSurfaceFlags & 0x400) != 0) {
    g_PlayerCollisionFacingFlags = 1;
  }
  if (value < 0) {
    if (value < (int)(~value3 + 1)) {
      return 0;
    }
    *(int *)(g_PlayerEntitySceneObjectData + 0xc) =
         *(int *)(g_PlayerEntitySceneObjectData + 0xc) + value;
    if ((g_PlayerTriggeredCollisionEntry != 0) &&
       ((*(ushort *)(g_PlayerTriggeredCollisionEntry + 0x42) & 0x40) != 0)) {
      *(ushort *)(g_PlayerTriggeredCollisionEntry + 0x42) =
           *(ushort *)(g_PlayerTriggeredCollisionEntry + 0x42) | 0x80;
    }
    value = g_PlayerGroundContactEntitySceneObject;
    value2 = g_PlayerEntitySceneObject;
    if (g_PlayerGroundContactEntitySceneObject == 0) {
      return 1;
    }
    if (*(int *)(g_PlayerEntitySceneObject + 0x60) != 0) {
      *(undefined4 *)(*(int *)(g_PlayerEntitySceneObject + 0x60) + 0x60) = 0;
      *(undefined4 *)(value2 + 0x60) = 0;
    }
    if (*(int *)(value + 0x60) != 0) {
      *(undefined4 *)(*(int *)(value + 0x60) + 0x60) = 0;
      *(undefined4 *)(value + 0x60) = 0;
      *(int *)(value2 + 0x60) = value;
      *(int *)(value + 0x60) = value2;
      return 1;
    }
  }
  else {
    if ((int)value3 < value) {
      return 0;
    }
    *(int *)(g_PlayerEntitySceneObjectData + 0xc) =
         *(int *)(g_PlayerEntitySceneObjectData + 0xc) + value;
    if ((g_PlayerTriggeredCollisionEntry != 0) &&
       ((*(ushort *)(g_PlayerTriggeredCollisionEntry + 0x42) & 0x40) != 0)) {
      *(ushort *)(g_PlayerTriggeredCollisionEntry + 0x42) =
           *(ushort *)(g_PlayerTriggeredCollisionEntry + 0x42) | 0x80;
    }
    value = g_PlayerGroundContactEntitySceneObject;
    value2 = g_PlayerEntitySceneObject;
    if (g_PlayerGroundContactEntitySceneObject == 0) {
      return 1;
    }
    if (*(int *)(g_PlayerEntitySceneObject + 0x60) != 0) {
      *(undefined4 *)(*(int *)(g_PlayerEntitySceneObject + 0x60) + 0x60) = 0;
      *(undefined4 *)(value2 + 0x60) = 0;
    }
    if (*(int *)(value + 0x60) != 0) {
      *(undefined4 *)(*(int *)(value + 0x60) + 0x60) = 0;
      *(undefined4 *)(value + 0x60) = 0;
    }
  }
  *(int *)(value2 + 0x60) = value;
  *(int *)(value + 0x60) = value2;
  return 1;
}

