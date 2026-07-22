#include "tarzan_ghidra_types.hpp"

// Address: 0x00434380
// Label: CPlayerHero::ApplyPlacementDescriptorToEntitySceneObject
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 CPlayerHero::ApplyPlacementDescriptorToEntitySceneObject(int arg1,(int)int arg2)

{
  undefined4 value;
  int entry;
  int entry2;
  undefined4 value2;
  
  value2 = 0;
  g_CameraFollowMode = *(undefined2 *)(arg2 + 0x1c);
  value = *(undefined4 *)(arg2 + 0x10);
  _g_PlayerHeroMode = *(undefined2 *)(arg2 + 0x18);
  switch(value) {
  case 0:
  case 8:
  case 9:
    goto switchD_004343b1_caseD_0;
  case 1:
  case 4:
  case 7:
    *(undefined4 *)(arg1 + 0x14) = *(undefined4 *)(arg2 + 4);
    *(undefined4 *)(arg1 + 0x18) = *(undefined4 *)(arg2 + 8);
    *(undefined4 *)(arg1 + 0x1c) = *(undefined4 *)(arg2 + 0xc);
    *(undefined2 *)(arg1 + 0xa2) = *(undefined2 *)(arg2 + 0x14);
    *(undefined1 *)(arg1 + 0x75) = 0;
    *(undefined4 *)(arg1 + 0x108) = 0;
    UpdateEntityEntitySceneObjectTransformFromPlacement(arg1);
    g_PlayerPreviousCollisionMode = *(undefined4 *)(g_PlayerEntitySceneObject + 0x108);
    return value;
  case 2:
  case 5:
  case 6:
    entry2 = *(int *)(arg2 + 4);
    if (entry2 == 0xffff) {
      entry = FindCollisionSurfaceIndexByCoordRef(*(undefined4 *)(arg2 + 8));
      entry2 = 0;
      if (entry != -1) {
        entry2 = g_CollisionSurfaceTable[entry + 1] + entry * 4 + 4;
        value2 = *(undefined4 *)
                 ((int)g_CollisionSurfaceTable +
                 *(int *)(entry2 + 0x10 + (int)g_CollisionSurfaceTable) * 0x1c + entry2 + 0x3c);
        entry2 = entry;
      }
    }
    else {
      value2 = *(undefined4 *)(arg2 + 8);
    }
    if (entry2 <= *g_CollisionSurfaceTable) {
      *(undefined4 *)(arg1 + 0x1c) = 0;
      *(undefined4 *)(arg1 + 0x18) = 0;
      *(undefined4 *)(arg1 + 0x14) = 0;
      *(undefined1 *)(arg1 + 0x75) = *(undefined1 *)(arg2 + 0x14);
      *(undefined4 *)(arg1 + 0x108) = 1;
      *(int *)(arg1 + 0x110) = entry2;
      *(undefined4 *)(arg1 + 0x10c) = value2;
      UpdateEntityEntitySceneObjectTransformFromPlacement(arg1);
      *(ushort *)(arg1 + 0xa2) = *(ushort *)(arg1 + 0x132);
      if (*(char *)(arg1 + 0x75) == '\0') {
        *(ushort *)(arg1 + 0xa2) = *(ushort *)(arg1 + 0x132) ^ 0x800;
        *(ushort *)(arg1 + 0xa0) = 0x400U - *(short *)(arg1 + 0x130) & 0xfff;
      }
      else {
        *(ushort *)(arg1 + 0xa0) = *(short *)(arg1 + 0x130) - 0x400U & 0xfff;
      }
      *(int *)(arg1 + 0x14) = *(int *)(arg1 + 0x14) + *(int *)(arg1 + 0x54);
      *(int *)(arg1 + 0x18) = *(int *)(arg1 + 0x18) + *(int *)(arg1 + 0x58);
      *(int *)(arg1 + 0x1c) = *(int *)(arg1 + 0x1c) + *(int *)(arg1 + 0x5c);
      g_PlayerActiveSurfaceDefinition = 0;
      g_PlayerPreviousCollisionMode = *(undefined4 *)(g_PlayerEntitySceneObject + 0x108);
      return value;
    }
switchD_004343b1_caseD_0:
    *(undefined4 *)(arg1 + 0x14) = *(undefined4 *)(arg2 + 4);
    *(undefined4 *)(arg1 + 0x18) = *(undefined4 *)(arg2 + 8);
    *(undefined4 *)(arg1 + 0x1c) = *(undefined4 *)(arg2 + 0xc);
    *(undefined2 *)(arg1 + 0xa2) = *(undefined2 *)(arg2 + 0x14);
    *(undefined1 *)(arg1 + 0x75) = 0;
    *(undefined4 *)(arg1 + 0x108) = 0;
    UpdateEntityEntitySceneObjectTransformFromPlacement(arg1);
    g_PlayerPreviousCollisionMode = *(undefined4 *)(g_PlayerEntitySceneObject + 0x108);
    return value;
  default:
    *(undefined4 *)(arg1 + 0x14) = *(undefined4 *)(arg2 + 4);
    *(undefined4 *)(arg1 + 0x18) = *(undefined4 *)(arg2 + 8);
    *(undefined4 *)(arg1 + 0x1c) = *(undefined4 *)(arg2 + 0xc);
    *(undefined2 *)(arg1 + 0xa2) = *(undefined2 *)(arg2 + 0x14);
    *(undefined1 *)(arg1 + 0x75) = 0;
    *(undefined4 *)(arg1 + 0x108) = 0;
    UpdateEntityEntitySceneObjectTransformFromPlacement(arg1);
    g_PlayerPreviousCollisionMode = *(undefined4 *)(g_PlayerEntitySceneObject + 0x108);
    return 1;
  }
}

