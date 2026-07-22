#include "tarzan_ghidra_types.hpp"

// Address: 0x00429260
// Label: LoadAndBuildWorldScene
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void LoadAndBuildWorldScene(void)

{
  int entry;
  
  entry = GetLoadFontsOffset_Stub();
  LoadFonts((&g_LevelFontSetPointerTable)[*( undefined1 *)((int)&g_LevelTransitionContext + 2)],&DAT_00c4602c + entry);
  ResetInputStateForTransition();
  if (g_PendingTransitionPayload != 0) {
    g_ActiveTransitionPayload = LoadAssetPayload(g_PendingTransitionPayload);
    InitLoadedPayloadPlaybackState(g_ActiveTransitionPayload);
    *( undefined1 *)((int)&g_LevelTransitionContext + 3) = 3;
    gCurrentTokensCollected = 0;
  }
  SetActiveMenuContext(&g_MenuSceneContext);
  if (*( undefined1 *)((int)&g_LevelTransitionContext + 2) == '\x15') {
    entry = *(int *)(g_ActiveMenuContext + 0x1c) + 0x40;
  }
  else {
    entry = *(int *)(g_ActiveMenuContext + 0x1c);
  }
  InitSceneAnchorTransform(&g_CameraFocusX,entry);
  InitSceneAnchorTransform
            (&g_TransitionSceneAnchorSecondary,*(int *)(g_ActiveMenuContext + 0x1c) + 0x20);
  LegacyTransitionCallback_Stub(0,0,0);
  SelectLevelAudioProfile((int)*( undefined1 *)((int)&g_LevelTransitionContext + 2));
  InitializeLevelRuntimeAndLoadRequiredResources();
  if (*( undefined2 *)((int)&g_LevelTransitionRequestFlags + 2) != 0) {
    ResolveEntitySceneObjectPointers(&g_CurrentWorldSceneContext);
  }
  ResetLevelRuntimeState();
  FinalizeLevelTransitionAndInvokeHook();
  if (*( undefined1 *)((int)&g_LevelTransitionContext + 2) == '\x15') {
    SetActiveMenuContext(&g_MenuSceneContext);
    return;
  }
  SetActiveMenuContext(&g_MenuSceneContext);
  return;
}

