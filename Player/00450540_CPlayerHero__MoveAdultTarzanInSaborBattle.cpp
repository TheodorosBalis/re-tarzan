#include "tarzan_ghidra_types.hpp"

// Address: 0x00450540
// Label: CPlayerHero::MoveAdultTarzanInSaborBattle
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::MoveAdultTarzanInSaborBattle(undefined4 arg1)

{
  int value;
  uint value2;
  
  if ((int)*(short *)(g_PlayerEntitySceneObject + 0xa2) != (uint)g_PlayerMoveHeadingAngle) {
    value = GetWrappedSignedAngleDelta12Bit
                      ((int)*(short *)(g_PlayerEntitySceneObject + 0xa2),
                       g_PlayerMoveHeadingAngle & 0xfff);
    if ((value >> 2 ^ value >> 0x1f) - (value >> 0x1f) < 2) {
      *(ushort *)(g_PlayerEntitySceneObject + 0xa2) = g_PlayerMoveHeadingAngle;
    }
    else {
      *(short *)(g_PlayerEntitySceneObject + 0xa2) =
           *(short *)(g_PlayerEntitySceneObject + 0xa2) + (short)(value >> 2);
    }
    *(ushort *)(g_PlayerEntitySceneObject + 0xa2) =
         *(ushort *)(g_PlayerEntitySceneObject + 0xa2) & 0xfff;
  }
  if (g_PlayerContactSurfaceThisFrame != 0) {
    g_PlayerCollisionContactFlags =
         g_PlayerCollisionContactFlags | *(uint *)(g_PlayerContactSurfaceThisFrame + 0x14) & 0xffff;
  }
  g_PlayerMoveHeadingAngle = *(ushort *)(g_PlayerEntitySceneObject + 0x132);
  if (*(char *)(g_PlayerEntitySceneObject + 0x75) == '\0') {
    g_PlayerMoveHeadingAngle = g_PlayerMoveHeadingAngle ^ 0x800;
    _g_PlayerMoveTiltAngle = 0x400 - *(short *)(g_PlayerEntitySceneObject + 0x130);
  }
  else {
    _g_PlayerMoveTiltAngle = *(short *)(g_PlayerEntitySceneObject + 0x130) - 0x400;
  }
  _g_PlayerMoveTiltAngle = _g_PlayerMoveTiltAngle & 0xfff;
  g_PlayerCollisionFacingFlags = (byte)(*(uint *)(g_PlayerEntitySceneObject + 0x13c) >> 1) & 1;
  value = (g_PlayerLateralSurfaceOffset * g_PlayerSurfaceLeanScale) / 0xf;
  value2 = *(ushort *)(g_PlayerEntitySceneObject + 0xa2) + 0x400 & 0xfff;
  *(int *)(g_PlayerEntitySceneObject + 0x3c) =
       -((short)(&g_SinCosTable12Bit)[value2 - 0x400 & 0xfff] * value) >> 0xc;
  *(int *)(g_PlayerEntitySceneObject + 0x44) = -((short)(&g_SinCosTable12Bit)[value2] * value) >> 0xc
  ;
  value = value + value / 2;
  value2 = -value & 0xfff;
  *(int *)(g_PlayerEntitySceneObject + 0x40) =
       -((short)(&g_SinCosTable12Bit)[value2 - 0x400 & 0xfff] * value) >> 0xc;
  *(short *)(g_PlayerEntitySceneObject + 0xa4) = (short)value2;
  ComputeEntitySceneObjectCollisionMoveDelta
            (arg1,g_PlayerMoveHeadingAngle,g_PlayerEntitySceneObject);
  *(int *)(g_PlayerEntitySceneObjectData + 8) =
       *(int *)(g_PlayerEntitySceneObjectData + 8) + *(int *)(g_PlayerEntitySceneObject + 0x54);
  CPlayerHero::UpdateGroundShadowOnCurrentSurface();
  return;
}

