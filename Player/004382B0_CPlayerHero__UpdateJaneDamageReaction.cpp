#include "tarzan_ghidra_types.hpp"

// Address: 0x004382B0
// Label: CPlayerHero::UpdateJaneDamageReaction
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateJaneDamageReaction(void)

{
  short *value3;
  undefined2 value2;
  int value;
  
  value = CEntities::FindEntityAttachmentByFlags(g_PlayerEntity,0x40000000);
  if (value != 0) {
    value3 = (short *)(g_PlayerEntitySceneObject + 0xa2);
    value = GetWrappedSignedAngleDelta12Bit
                      ((int)*(short *)(g_PlayerEntitySceneObject + 0xa2),
                       -*(int *)(value + 0x1c) - 0x800U & 0xfff);
    *value3 = *value3 + (short)(value >> 3);
    if ((g_JaneDamageReactionType == 0) || (g_JaneDamageReactionType == 1)) {
      CPlayerHero::ApproachJaneLateralRecoilSpeedAndMoveX();
      CPlayerHero::ApproachJaneForwardRecoilSpeedAndMoveZ();
    }
    value2 = g_PlayerActionState;
    if (g_JaneDamageReactionType == 2) {
      if ((g_PlayerInputPressedMask & 0x200000) != 0) {
        g_PlayerActionState = 3;
        g_PreviousPlayerActionState = value2;
        (*_g_JaneEnterJumpHandlerPtr)();
        return;
      }
      CPlayerHero::ApproachJaneForwardSpeed();
      CPlayerHero::ApplyJaneForwardMotionXZ();
    }
    value2 = g_PlayerActionState;
    if (g_JaneDamageReactionType == 3) {
      if ((g_PlayerInputPressedMask & 0x200000) != 0) {
        g_PlayerActionState = 3;
        g_PreviousPlayerActionState = value2;
        (*_g_JaneEnterJumpHandlerPtr)();
        return;
      }
      CPlayerHero::ApproachJaneForwardSpeed();
      CPlayerHero::ApplyJaneForwardMotionXZ();
    }
    CPlayerHero::UpdateJumpArcVerticalMotion(0);
    RefreshEntitySceneObjectNatureTerrainVerticalDelta(g_PlayerEntitySceneObject);
    CPlayerHero::TrySnapToNearbyGround();
  }
  value = CPlayerHero::AdvanceAnimationScript();
  value2 = g_PlayerActionState;
  if (value != 0) {
    g_PlayerActionState = 1;
    g_PreviousPlayerActionState = value2;
    (*(code *)g_JaneEnterIdleHandlerPtr)();
  }
  return;
}

