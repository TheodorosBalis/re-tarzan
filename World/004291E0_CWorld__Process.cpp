#include "tarzan_ghidra_types.hpp"

// Address: 0x004291E0
// Label: CWorld::Process
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 CWorld::Process(void)

{
  char resultFlag;
  
  resultFlag = CWorld::ShouldRunGameplayTick();
  if (resultFlag == '\0') {
    CWorld::UpdateHudPhase_stub();
    CWorld::DoExitFromLevel();
    g_CameraYaw = g_CameraYaw & 0xfff;
    return 1;
  }
  if (*( undefined2 *)((int)&g_LevelTransitionRequestFlags + 2) != 0) {
    CWorld::UpdateNatureTerrain(&g_CurrentWorldSceneContext,&g_CameraFocusX);
  }
  if (*( undefined1 *)((int)&g_LevelTransitionContext + 2) == '\v') {
    CWorld::ProcessGameplayTick_stub();
    CWorld::DoExitFromLevel();
    g_CameraYaw = g_CameraYaw & 0xfff;
    return 1;
  }
  CWorld::ProcessGameplayTick();
  CWorld::DoExitFromLevel();
  g_CameraYaw = g_CameraYaw & 0xfff;
  return 1;
}

