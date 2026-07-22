#include "tarzan_ghidra_types.hpp"

// Address: 0x00438010
// Label: CPlayerHero::ApproachJaneLateralRecoilSpeedAndMoveX
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::ApproachJaneLateralRecoilSpeedAndMoveX(void)

{
  if (_g_JaneLateralRecoilSpeed != _g_JaneLateralRecoilTargetSpeed) {
    if (_g_JaneLateralRecoilTargetSpeed < _g_JaneLateralRecoilSpeed) {
      _g_JaneLateralRecoilSpeed = _g_JaneLateralRecoilSpeed - _g_JaneLateralRecoilDeceleration;
      if (_g_JaneLateralRecoilTargetSpeed <= _g_JaneLateralRecoilSpeed) goto LAB_00438048;
    }
    else {
      _g_JaneLateralRecoilSpeed = _g_JaneLateralRecoilSpeed + _g_JaneLateralRecoilAcceleration;
      if (_g_JaneLateralRecoilSpeed <= _g_JaneLateralRecoilTargetSpeed) goto LAB_00438048;
    }
    _g_JaneLateralRecoilSpeed = _g_JaneLateralRecoilTargetSpeed;
  }
LAB_00438048:
  *(int *)(g_PlayerEntitySceneObject + 0x14) =
       *(int *)(g_PlayerEntitySceneObject + 0x14) + _g_JaneLateralRecoilSpeed;
  return;
}

