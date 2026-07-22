#include "tarzan_ghidra_types.hpp"

// Address: 0x00437620
// Label: CPlayerHero::UpdateJaneRouteRelativeFacing
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateJaneRouteRelativeFacing(void)

{
  short *value2;
  int value;
  
  value = CEntities::FindEntityAttachmentByFlags(g_PlayerEntity,0x40000000);
  if (value != 0) {
    _g_JaneDesiredFacingAngle = -*(int *)(value + 0x1c) - 0x800U & 0xfff;
    if (((byte)g_PlayerInputHeldMask & 0x20) != 0) {
      _g_JaneDesiredFacingAngle = (-*(int *)(value + 0x1c) - 0x800U & 0xfff) - 0x1c2;
    }
    if (((byte)g_PlayerInputHeldMask & 0x80) != 0) {
      _g_JaneDesiredFacingAngle = (-*(int *)(value + 0x1c) - 0x800U & 0xfff) + 0x1c2;
    }
    value2 = (short *)(g_PlayerEntitySceneObject + 0xa2);
    value = GetWrappedSignedAngleDelta12Bit
                      ((int)*(short *)(g_PlayerEntitySceneObject + 0xa2),_g_JaneDesiredFacingAngle);
    *value2 = *value2 + (short)(value >> 2);
  }
  return;
}

