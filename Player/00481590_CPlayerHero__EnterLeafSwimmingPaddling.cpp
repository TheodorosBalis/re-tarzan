#include "tarzan_ghidra_types.hpp"

// Address: 0x00481590
// Label: CPlayerHero::EnterLeafSwimmingPaddling
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterLeafSwimmingPaddling(void)

{
  undefined *dataCursor;
  
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 0x200;
  *(undefined4 *)(g_PlayerMotionState + 0x18) = 0x180;
  g_LeafSwimmingMidStageMotionTable = 0;
  dataCursor = g_LeafSwimmingEarlyStageAnimationScript;
  if (1 < g_CurrentCheckpointId) {
    dataCursor = g_LeafSwimmingLateStageAnimationScript;
  }
  g_PlayerCurrentAnimationId = (ushort)(1 < g_CurrentCheckpointId);
  *(undefined **)(g_PlayerAnimationState + 0xc) = dataCursor;
  *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
  *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  CPlayerHero::AdvanceAnimationScript();
  g_LeafSwimmingCameraTargetDistance = g_LeafSwimmingLateStageMotionTable;
  g_LeafSwimmingCameraTargetDistanceScale = g_LeafSwimmingDefaultCameraDistanceScale;
  return;
}

