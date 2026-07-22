#include "tarzan_ghidra_types.hpp"

// Address: 0x00473EE0
// Label: CPlayerHero::UpdateJaneElephantKerchakChaseRiding
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateJaneElephantKerchakChaseRiding(void)

{
  short *value4;
  undefined2 value3;
  char resultFlag;
  int value;
  int value2;
  
  value = CEntities::FindEntityAttachmentByFlags(g_PlayerEntity,0x40000000);
  if (value != 0) {
    RefreshEntitySceneObjectNatureTerrainVerticalDelta(g_PlayerEntitySceneObject);
    resultFlag = CPlayerHero::TrySnapToNearbyGround();
    value3 = g_PlayerActionState;
    if (resultFlag == '\0') {
      g_PlayerActionState = 1;
      g_PreviousPlayerActionState = value3;
      (*_g_JaneElephantKerchakChaseEnterFallingHandlerPtr)();
    }
    *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0xffffba00;
    _g_KerchakChaseDesiredFacingAngle = -*(int *)(value + 0x1c) - 0x800U & 0xfff;
    value2 = CEntities::FindEntityAttachmentByFlags(g_PlayerEntity,0x10000018);
    if (value2 != 0) {
      if (((byte)g_PlayerInputHeldMask & 0x20) != 0) {
        _g_KerchakChaseDesiredFacingAngle = (-*(int *)(value + 0x1c) - 0x800U & 0xfff) - 0x1c2;
      }
      if (((byte)g_PlayerInputHeldMask & 0x80) != 0) {
        _g_KerchakChaseDesiredFacingAngle = (-*(int *)(value + 0x1c) - 0x800U & 0xfff) + 0x1c2;
      }
    }
    value4 = (short *)(g_PlayerEntitySceneObject + 0xa2);
    value = GetWrappedSignedAngleDelta12Bit
                      ((int)*(short *)(g_PlayerEntitySceneObject + 0xa2),
                       _g_KerchakChaseDesiredFacingAngle);
    *value4 = *value4 + (short)(value >> 3);
    CPlayerHero::ApproachKerchakChaseForwardSpeed();
    CPlayerHero::ApplyKerchakChaseForwardMotionXZ();
    CPlayerHero::AdvanceAnimationScript();
  }
  return;
}

