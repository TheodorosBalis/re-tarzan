#include "tarzan_ghidra_types.hpp"

// Address: 0x004ABFD0
// Label: TransitionToWorldOrMenu
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TransitionToWorldOrMenu(int menu)

{
  g_GameplayRuntimeFlags = g_GameplayRuntimeFlags & 0xfffffffb;
  bIsOnTransition = 1;
  if (menu != 1) {
    SetControlKeysOnlyMode(1);
    g_IsWorldModeActive = 0;
    LoadMenuOrAdvanceLevel(0);
    g_ActiveWorldOrMenuProcessFn = ProcessMainMenu;
    g_ActiveWorldOrMenuRenderFn = MainMenu::Render;
    return;
  }
  SetControlKeysOnlyMode(g_PendingTransitionPayload != 0);
  g_IsWorldModeActive = 1;
  LoadAndBuildWorldScene(0);
  g_ActiveWorldOrMenuProcessFn = CWorld::Process;
  g_ActiveWorldOrMenuRenderFn = CWorld::Render;
  if (g_PendingTransitionPayload == 0) {
    UpdateCFGFile((int)*( undefined1 *)((int)&g_LevelTransitionContext + 2),(int)*( undefined1 *)((int)&g_LevelTransitionContext + 1));
  }
  return;
}

