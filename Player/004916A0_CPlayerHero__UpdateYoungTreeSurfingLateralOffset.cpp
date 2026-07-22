#include "tarzan_ghidra_types.hpp"

// Address: 0x004916A0
// Label: CPlayerHero::UpdateYoungTreeSurfingLateralOffset
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::UpdateYoungTreeSurfingLateralOffset(void)

{
  if ((((byte)g_PlayerInputHeldMask & 0xa0) == 0) || (((byte)g_PlayerInputHeldMask & 0x40) != 0)) {
    if (g_PlayerLateralSurfaceOffset != 0) {
      if (g_PlayerLateralSurfaceOffset < 0) {
        g_PlayerLateralSurfaceOffset = g_PlayerLateralSurfaceOffset + 1;
        return;
      }
      g_PlayerLateralSurfaceOffset = g_PlayerLateralSurfaceOffset + -1;
    }
  }
  else if (((byte)g_PlayerInputHeldMask & 0x80) == 0) {
    g_PlayerLateralSurfaceOffset = g_PlayerLateralSurfaceOffset + 2;
    if (0xf < g_PlayerLateralSurfaceOffset) {
      g_PlayerLateralSurfaceOffset = 0xf;
      g_PlayerTreeSurfingLateralThresholdSide = 2;
      return;
    }
    if (4 < g_PlayerLateralSurfaceOffset) {
      g_PlayerTreeSurfingLateralThresholdSide = 2;
      return;
    }
  }
  else {
    g_PlayerLateralSurfaceOffset = g_PlayerLateralSurfaceOffset + -2;
    if (g_PlayerLateralSurfaceOffset < -0xf) {
      g_PlayerLateralSurfaceOffset = 0xfffffff1;
      g_PlayerTreeSurfingLateralThresholdSide = 1;
      return;
    }
    if (g_PlayerLateralSurfaceOffset < -4) {
      g_PlayerTreeSurfingLateralThresholdSide = 1;
      return;
    }
  }
  return;
}

