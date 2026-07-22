#include "tarzan_ghidra_types.hpp"

// Address: 0x00436680
// Label: CPlayerHero::TryResolveGroundContactSnap
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint CPlayerHero::TryResolveGroundContactSnap(void)

{
  int value;
  int value2;
  uint value4;
  uint value5;
  uint value6;
  int value3;
  uint value7;
  uint value8;
  uint value9;
  
  value2 = g_PlayerGroundSnapOffset;
  value4 = *(int *)(g_PlayerEntitySceneObjectData + 0xc) - *(int *)(g_PlayerEntitySceneObject + 0x4c)
  ;
  value7 = (int)value4 >> 0x1f;
  value5 = *(int *)(g_PlayerEntitySceneObjectData + 8) - *(int *)(g_PlayerEntitySceneObject + 0x48);
  value8 = (int)value5 >> 0x1f;
  value6 = *(int *)(g_PlayerEntitySceneObjectData + 0x10) -
          *(int *)(g_PlayerEntitySceneObject + 0x50);
  value9 = (int)value6 >> 0x1f;
  g_PlayerGroundSnapOffset = CPlayerHero::FindGroundSnapOffset();
  value = g_PlayerGroundContactEntitySceneObject;
  value3 = g_PlayerEntitySceneObject;
  if (g_PlayerGroundSnapOffset == 0x7fffffff) {
LAB_00436829:
    return g_PlayerGroundSnapOffset & 0xffffff00;
  }
  if (g_PlayerGroundSnapOffset == 0) {
    if (g_PlayerGroundContactEntitySceneObject != 0) {
      if (*(int *)(g_PlayerEntitySceneObject + 0x60) != 0) {
        *(undefined4 *)(*(int *)(g_PlayerEntitySceneObject + 0x60) + 0x60) = 0;
        *(undefined4 *)(value3 + 0x60) = 0;
      }
      if (*(int *)(value + 0x60) != 0) {
        *(undefined4 *)(*(int *)(value + 0x60) + 0x60) = 0;
        *(undefined4 *)(value + 0x60) = 0;
      }
      *(int *)(value3 + 0x60) = value;
      *(int *)(value + 0x60) = value3;
    }
    value3 = *(int *)(g_PlayerEntitySceneObject + 0x108) + -1;
    if ((value3 == 0) && (value3 = 0, g_PlayerActiveSurfaceDefinition != 0)) {
      value = *(int *)(g_PlayerActiveSurfaceDefinition + 0x14);
      value3 = 0;
      if (value != 0) {
        g_PlayerCurrentCollisionMode = (short)value;
        return CONCAT31((int3)((uint)value >> 8),1);
      }
    }
  }
  else {
    if (-1 < (int)g_PlayerGroundSnapOffset) goto LAB_00436829;
    if (_g_PlayerCollisionSnapRange == 0x400) {
      *(int *)(g_PlayerEntitySceneObjectData + 0xc) =
           *(int *)(g_PlayerEntitySceneObjectData + 0xc) + g_PlayerGroundSnapOffset;
      CPlayerHero::ClampPositionWithinGroundContactRadius();
      value3 = *(int *)(g_PlayerEntitySceneObject + 0x108) + -1;
      if ((value3 == 0) && (value3 = 0, g_PlayerActiveSurfaceDefinition != 0)) {
        value = *(int *)(g_PlayerActiveSurfaceDefinition + 0x14);
        value3 = 0;
        if (value != 0) {
          g_PlayerCurrentCollisionMode = (short)value;
          return CONCAT31((int3)((uint)value >> 8),1);
        }
      }
    }
    else {
      if (((int)g_PlayerGroundSnapOffset <
           (int)(~((uint)_g_PlayerCollisionSnapRange + ((value6 ^ value9) - value9) +
                   ((value5 ^ value8) - value8) + ((value4 ^ value7) - value7)) + 1)) && (value2 < 0))
      goto LAB_00436829;
      *(uint *)(g_PlayerEntitySceneObjectData + 0xc) =
           *(int *)(g_PlayerEntitySceneObjectData + 0xc) + g_PlayerGroundSnapOffset;
      value = g_PlayerGroundContactEntitySceneObject;
      value3 = g_PlayerEntitySceneObject;
      if (g_PlayerGroundContactEntitySceneObject != 0) {
        if (*(int *)(g_PlayerEntitySceneObject + 0x60) != 0) {
          *(undefined4 *)(*(int *)(g_PlayerEntitySceneObject + 0x60) + 0x60) = 0;
          *(undefined4 *)(value3 + 0x60) = 0;
        }
        if (*(int *)(value + 0x60) != 0) {
          *(undefined4 *)(*(int *)(value + 0x60) + 0x60) = 0;
          *(undefined4 *)(value + 0x60) = 0;
        }
        *(int *)(value3 + 0x60) = value;
        *(int *)(value + 0x60) = value3;
      }
      CPlayerHero::ClampPositionWithinGroundContactRadius();
      value3 = *(int *)(g_PlayerEntitySceneObject + 0x108) + -1;
      if (((value3 == 0) && (value3 = 0, g_PlayerActiveSurfaceDefinition != 0)) &&
         (value3 = *(int *)(g_PlayerActiveSurfaceDefinition + 0x14), value3 != 0)) {
        g_PlayerCurrentCollisionMode = (undefined2)value3;
      }
    }
  }
  return CONCAT31((int3)((uint)value3 >> 8),1);
}

