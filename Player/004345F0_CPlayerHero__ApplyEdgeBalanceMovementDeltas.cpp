#include "tarzan_ghidra_types.hpp"

// Address: 0x004345F0
// Label: CPlayerHero::ApplyEdgeBalanceMovementDeltas
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::ApplyEdgeBalanceMovementDeltas(undefined4 arg1,int arg2)

{
  uint value;
  
  value = _g_PlayerCurrentCollisionMode & 0xffff;
  if ((value == 2) || ((4 < value && (value < 7)))) {
    ComputeEntitySceneObjectCollisionMoveDelta(arg1,0,g_PlayerEntitySceneObject);
    g_PlayerMoveHeadingAngle = *(ushort *)(g_PlayerEntitySceneObject + 0x132);
    *(int *)(g_PlayerEntitySceneObjectData + 8) =
         *(int *)(g_PlayerEntitySceneObjectData + 8) + *(int *)(g_PlayerEntitySceneObject + 0x54);
    *(int *)(g_PlayerEntitySceneObjectData + 0x10) =
         *(int *)(g_PlayerEntitySceneObjectData + 0x10) + *(int *)(g_PlayerEntitySceneObject + 0x5c)
    ;
    if (*(char *)(g_PlayerEntitySceneObject + 0x75) == '\0') {
      g_PlayerMoveHeadingAngle = g_PlayerMoveHeadingAngle ^ 0x800;
    }
    *(int *)(g_PlayerEntitySceneObjectData + 0xc) =
         *(int *)(g_PlayerEntitySceneObjectData + 0xc) + arg2;
  }
  return;
}

