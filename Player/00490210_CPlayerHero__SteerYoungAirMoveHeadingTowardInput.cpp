#include "tarzan_ghidra_types.hpp"

// Address: 0x00490210
// Label: CPlayerHero::SteerYoungAirMoveHeadingTowardInput
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int CPlayerHero::SteerYoungAirMoveHeadingTowardInput(void)

{
  short shortValue;
  uint value2;
  int value;
  
  value = -1;
  if (g_PlayerActionState == 0x28) {
    if ((_g_PlayerAirMovePitchAngle & 0x800) == 0) {
      value2 = _g_PlayerAirMovePitchAngle & 0x7ff;
    }
    else {
      value2 = _g_PlayerAirMovePitchAngle & 0xffff | 0xfffff800;
    }
    if ((int)value2 < 0) {
      value2 = ~value2 + 1;
    }
    shortValue = (short)((int)value2 >> 4) + 0x2d;
  }
  else {
    shortValue = 0x2d;
  }
  if (((byte)g_PlayerInputHeldMask & 0x10) != 0) {
    value = 0;
    if (((byte)g_PlayerInputHeldMask & 0x20) != 0) {
      value = 0x200;
    }
    if (((byte)g_PlayerInputHeldMask & 0x80) != 0) {
      value = 0xe00;
      goto LAB_004902b4;
    }
    if (value != -1) goto LAB_004902b4;
  }
  if (((byte)g_PlayerInputHeldMask & 0x40) != 0) {
    value = 0x800;
    if (((byte)g_PlayerInputHeldMask & 0x20) != 0) {
      value = 0x600;
    }
    if (((byte)g_PlayerInputHeldMask & 0x80) != 0) {
      value = 0xa00;
      goto LAB_004902b4;
    }
    if (value != -1) goto LAB_004902b4;
  }
  if (((byte)g_PlayerInputHeldMask & 0x20) == 0) {
    if (((byte)g_PlayerInputHeldMask & 0x80) != 0) {
      value = 0xc00;
    }
  }
  else {
    value = 0x400;
  }
LAB_004902b4:
  value = (uint)g_PlayerAirMoveHeadingAngle - value;
  if (value < 0) {
    value = value + 0x1000;
  }
  if (0x2f < value) {
    if (0x7ff < value) {
      g_PlayerAirMoveHeadingAngle = g_PlayerAirMoveHeadingAngle + shortValue & 0xfff;
      return 0;
    }
    g_PlayerAirMoveHeadingAngle = g_PlayerAirMoveHeadingAngle - shortValue & 0xfff;
  }
  return 0;
}

