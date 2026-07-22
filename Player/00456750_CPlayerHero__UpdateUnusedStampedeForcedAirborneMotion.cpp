#include "tarzan_ghidra_types.hpp"

// Address: 0x00456750
// Label: CPlayerHero::UpdateUnusedStampedeForcedAirborneMotion
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateUnusedStampedeForcedAirborneMotion(void)

{
  short *value2;
  int value;
  
  value = CEntities::FindEntityAttachmentByFlags(g_PlayerEntity,0x40000000);
  if (value != 0) {
    value2 = (short *)(g_PlayerEntitySceneObject + 0xa2);
    _g_UnusedStampedeForcedAirborneFacingTarget = -*(int *)(value + 0x1c) - 0x800U & 0xfff;
    value = GetWrappedSignedAngleDelta12Bit
                      ((int)*(short *)(g_PlayerEntitySceneObject + 0xa2),
                       _g_UnusedStampedeForcedAirborneFacingTarget);
    *value2 = *value2 + (short)(value >> 4);
    CPlayerHero::ApproachStampedeRecoilForwardSpeedAndMoveZ();
    CPlayerHero_UpdateAirborneVerticalMotion();
    RefreshEntitySceneObjectNatureTerrainVerticalDelta(g_PlayerEntitySceneObject);
    CPlayerHero::TrySnapToNearbyGround();
    CPlayerHero::AdvanceAnimationScript();
  }
  return;
}

