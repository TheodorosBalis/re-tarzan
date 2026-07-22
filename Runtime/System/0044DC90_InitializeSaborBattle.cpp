#include "tarzan_ghidra_types.hpp"

// Address: 0x0044DC90
// Label: InitializeSaborBattle
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void InitializeSaborBattle(void)

{
  LoadSaborBattleResources();
  g_SavedCameraFollowModeBeforeSaborBattle = g_CameraFollowMode;
  g_CameraFollowMode = 0x10;
  g_SaborBattleCameraState = 0;
  SelectBackgroundMusicTrackForLevel(1);
  g_SaborFlipFacingOnNextAnimationFlag = 0;
  g_SaborAttackHitPlayerFlag = 0;
  g_SaborAttackCycleCount = 0;
  _g_SaborSuccessfulAttackCount = 0;
  InitOptionalHudMeter();
  g_SaborHitProcessedFlag = 0;
  return;
}

