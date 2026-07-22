#include "tarzan_ghidra_types.hpp"

// Address: 0x00434680
// Label: CPlayerHero::TryClampJumpArcToSurfaceCeiling
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int CPlayerHero::TryClampJumpArcToSurfaceCeiling(int arg1)

{
  int value;
  
  if (((*(int *)(g_PlayerEntitySceneObject + 0x108) == 1) &&
      ((*(byte *)(*(int *)(g_PlayerEntitySceneObject + 0x114) + 0x14) & 0x10) == 0)) &&
     (*(int *)(g_PlayerEntitySceneObject + 300) != -0x7fffffff)) {
    arg1 = *(int *)(g_PlayerEntitySceneObject + 300) + arg1;
    if (*(int *)(g_PlayerEntitySceneObjectData + 0xc) < arg1) {
      value = *(int *)(g_PlayerEntitySceneObject + 0x58) +
              *(int *)(g_PlayerEntitySceneObjectData + 0xc);
      if (arg1 <= value) {
        return arg1;
      }
      return value;
    }
  }
  return 0;
}

