#include "tarzan_ghidra_types.hpp"

// Address: 0x0048FD00
// Label: CPlayerHero::SteerYoungAirMoveHeadingFromHorizontalInput
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::SteerYoungAirMoveHeadingFromHorizontalInput(void)

{
  short shortValue;
  uint value;
  
  if (g_PlayerActionState == 0x28) {
    if ((_g_PlayerAirMovePitchAngle & 0x800) == 0) {
      value = _g_PlayerAirMovePitchAngle & 0x7ff;
    }
    else {
      value = _g_PlayerAirMovePitchAngle & 0xffff | 0xfffff800;
    }
    if ((int)value < 0) {
      value = ~value + 1;
    }
    shortValue = (short)((int)value >> 4) + 0x2d;
  }
  else {
    shortValue = 0x2d;
  }
  if (((byte)g_PlayerInputHeldMask & 0x80) != 0) {
    g_PlayerAirMoveHeadingAngle = g_PlayerAirMoveHeadingAngle - shortValue;
  }
  if (((byte)g_PlayerInputHeldMask & 0x20) != 0) {
    g_PlayerAirMoveHeadingAngle = g_PlayerAirMoveHeadingAngle + shortValue & 0xfff;
    return;
  }
  g_PlayerAirMoveHeadingAngle = g_PlayerAirMoveHeadingAngle & 0xfff;
  return;
}

