#include "tarzan_ghidra_types.hpp"

// Address: 0x00456180
// Label: CPlayerHero::ApproachStampedeLateralRecoilSpeedAndMoveX
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::ApproachStampedeLateralRecoilSpeedAndMoveX(void)

{
  if (g_StampedeLateralRecoilSpeed != g_StampedeLateralRecoilTargetSpeed) {
    if (g_StampedeLateralRecoilTargetSpeed < g_StampedeLateralRecoilSpeed) {
      g_StampedeLateralRecoilSpeed =
           g_StampedeLateralRecoilSpeed - _g_StampedeLateralRecoilDeceleration;
      if (g_StampedeLateralRecoilTargetSpeed <= g_StampedeLateralRecoilSpeed) goto LAB_004561b8;
    }
    else {
      g_StampedeLateralRecoilSpeed =
           g_StampedeLateralRecoilSpeed + _g_StampedeLateralRecoilAcceleration;
      if (g_StampedeLateralRecoilSpeed <= g_StampedeLateralRecoilTargetSpeed) goto LAB_004561b8;
    }
    g_StampedeLateralRecoilSpeed = g_StampedeLateralRecoilTargetSpeed;
  }
LAB_004561b8:
  *(int *)(g_PlayerEntitySceneObject + 0x14) =
       *(int *)(g_PlayerEntitySceneObject + 0x14) + (g_StampedeLateralRecoilSpeed >> 8);
  return;
}

