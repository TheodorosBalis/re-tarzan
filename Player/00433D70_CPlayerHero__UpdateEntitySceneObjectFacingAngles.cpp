#include "tarzan_ghidra_types.hpp"

// Address: 0x00433D70
// Label: CPlayerHero::UpdateEntitySceneObjectFacingAngles
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateEntitySceneObjectFacingAngles(void)

{
  uint value;
  int entry;
  uint value2;
  
  value = _g_PlayerCurrentCollisionMode & 0xffff;
  if (value == 1) {
    if ((int)*(short *)(g_PlayerEntitySceneObject + 0xa2) != (_g_PlayerMoveHeadingAngle & 0xffff)) {
      _g_PlayerFacingAngleTarget = 0;
      entry = GetWrappedSignedAngleDelta12Bit
                        ((int)*(short *)(g_PlayerEntitySceneObject + 0xa2),
                         _g_PlayerMoveHeadingAngle & 0xfff);
      if ((entry >> 2 ^ entry >> 0x1f) - (entry >> 0x1f) < 2) {
        *(undefined2 *)(g_PlayerEntitySceneObject + 0xa2) = g_PlayerMoveHeadingAngle;
      }
      else if (((byte)g_PlayerInputHeldMask & 0xf0) != 0) {
        *(short *)(g_PlayerEntitySceneObject + 0xa2) =
             *(short *)(g_PlayerEntitySceneObject + 0xa2) + (short)(entry >> 2);
        _g_PlayerFacingAngleTarget = 1;
      }
      *(ushort *)(g_PlayerEntitySceneObject + 0xa2) =
           *(ushort *)(g_PlayerEntitySceneObject + 0xa2) & 0xfff;
    }
    if (g_PlayerTiltControlEnabled == '\0') {
      _g_PlayerMoveHeadingAngle = _g_PlayerMoveHeadingAngle & 0xffff;
    }
    if ((int)*(short *)(g_PlayerEntitySceneObject + 0xa0) == _g_PlayerMoveHeadingAngle >> 0x10) {
      return;
    }
    entry = GetWrappedSignedAngleDelta12Bit
                      ((int)*(short *)(g_PlayerEntitySceneObject + 0xa0),
                       _g_PlayerMoveHeadingAngle >> 0x10);
    value = entry >> 2;
    if ((int)((value ^ entry >> 0x1f) - (entry >> 0x1f)) < 2) {
      *(undefined2 *)(g_PlayerEntitySceneObject + 0xa0) = _g_PlayerMoveTiltAngle;
      *(ushort *)(g_PlayerEntitySceneObject + 0xa0) =
           *(ushort *)(g_PlayerEntitySceneObject + 0xa0) & 0xfff;
      return;
    }
  }
  else {
    if (value == 3) {
      if ((int)*(short *)(g_PlayerEntitySceneObject + 0xa0) == (_g_PlayerAirMovePitchAngle & 0xffff)
         ) {
        return;
      }
      entry = GetWrappedSignedAngleDelta12Bit
                        ((int)*(short *)(g_PlayerEntitySceneObject + 0xa0),
                         _g_PlayerAirMovePitchAngle & 0xffff);
      if (1 < (entry >> 2 ^ entry >> 0x1f) - (entry >> 0x1f)) {
        *(short *)(g_PlayerEntitySceneObject + 0xa0) =
             *(short *)(g_PlayerEntitySceneObject + 0xa0) + (short)(entry >> 2);
        *(ushort *)(g_PlayerEntitySceneObject + 0xa0) =
             *(ushort *)(g_PlayerEntitySceneObject + 0xa0) & 0xfff;
        return;
      }
      *(undefined2 *)(g_PlayerEntitySceneObject + 0xa0) = g_PlayerAirMovePitchAngle;
      *(ushort *)(g_PlayerEntitySceneObject + 0xa0) =
           *(ushort *)(g_PlayerEntitySceneObject + 0xa0) & 0xfff;
      return;
    }
    value2 = (uint)*(short *)(g_PlayerEntitySceneObject + 0xa2);
    if (value == 4) {
      if (value2 != g_PlayerAirMoveHeadingAngle) {
        entry = GetWrappedSignedAngleDelta12Bit(value2,(uint)g_PlayerAirMoveHeadingAngle);
        if ((entry >> 2 ^ entry >> 0x1f) - (entry >> 0x1f) < 2) {
          *(ushort *)(g_PlayerEntitySceneObject + 0xa2) = g_PlayerAirMoveHeadingAngle;
        }
        else {
          *(short *)(g_PlayerEntitySceneObject + 0xa2) =
               *(short *)(g_PlayerEntitySceneObject + 0xa2) + (short)(entry >> 2);
        }
        *(ushort *)(g_PlayerEntitySceneObject + 0xa2) =
             *(ushort *)(g_PlayerEntitySceneObject + 0xa2) & 0xfff;
      }
      if (g_PlayerTiltControlEnabled == '\0') {
        _g_PlayerAirMovePitchAngle = _g_PlayerAirMovePitchAngle & 0xffff0000;
      }
      if ((int)*(short *)(g_PlayerEntitySceneObject + 0xa0) == (_g_PlayerAirMovePitchAngle & 0xffff)
         ) {
        return;
      }
      entry = GetWrappedSignedAngleDelta12Bit
                        ((int)*(short *)(g_PlayerEntitySceneObject + 0xa0),
                         _g_PlayerAirMovePitchAngle & 0xffff);
      value = entry >> 2;
      if ((int)((value ^ entry >> 0x1f) - (entry >> 0x1f)) < 2) {
        *(undefined2 *)(g_PlayerEntitySceneObject + 0xa0) = g_PlayerAirMovePitchAngle;
        *(ushort *)(g_PlayerEntitySceneObject + 0xa0) =
             *(ushort *)(g_PlayerEntitySceneObject + 0xa0) & 0xfff;
        return;
      }
    }
    else {
      if (value2 != (_g_PlayerMoveHeadingAngle & 0xffff)) {
        entry = GetWrappedSignedAngleDelta12Bit(value2,_g_PlayerMoveHeadingAngle & 0xfff);
        if ((entry >> 2 ^ entry >> 0x1f) - (entry >> 0x1f) < 2) {
          *(undefined2 *)(g_PlayerEntitySceneObject + 0xa2) = g_PlayerMoveHeadingAngle;
        }
        else {
          *(short *)(g_PlayerEntitySceneObject + 0xa2) =
               *(short *)(g_PlayerEntitySceneObject + 0xa2) + (short)(entry >> 2);
        }
        *(ushort *)(g_PlayerEntitySceneObject + 0xa2) =
             *(ushort *)(g_PlayerEntitySceneObject + 0xa2) & 0xfff;
      }
      if (g_PlayerTiltControlEnabled == '\0') {
        _g_PlayerMoveHeadingAngle = _g_PlayerMoveHeadingAngle & 0xffff;
      }
      if ((int)*(short *)(g_PlayerEntitySceneObject + 0xa0) == _g_PlayerMoveHeadingAngle >> 0x10) {
        return;
      }
      entry = GetWrappedSignedAngleDelta12Bit
                        ((int)*(short *)(g_PlayerEntitySceneObject + 0xa0),
                         _g_PlayerMoveHeadingAngle >> 0x10);
      value = entry >> 2;
      if ((int)((value ^ entry >> 0x1f) - (entry >> 0x1f)) < 2) {
        *(undefined2 *)(g_PlayerEntitySceneObject + 0xa0) = _g_PlayerMoveTiltAngle;
        *(ushort *)(g_PlayerEntitySceneObject + 0xa0) =
             *(ushort *)(g_PlayerEntitySceneObject + 0xa0) & 0xfff;
        return;
      }
    }
  }
  *(short *)(g_PlayerEntitySceneObject + 0xa0) =
       *(short *)(g_PlayerEntitySceneObject + 0xa0) + (short)value;
  *(ushort *)(g_PlayerEntitySceneObject + 0xa0) =
       *(ushort *)(g_PlayerEntitySceneObject + 0xa0) & 0xfff;
  return;
}

