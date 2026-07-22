#include "tarzan_ghidra_types.hpp"

// Address: 0x0042DA50
// Label: CWorld::DoExitFromLevel
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CWorld::DoExitFromLevel(void)

{
  int value;
  int value2;
  undefined4 value3;
  
  if (((ushort)g_GameplayStateFlags & 0x10) != 0) {
    InitAudioLine__stub();
    *( undefined2 *)((int)&g_GameplayStateFlags + 0) = 0;
    SuspendAllSound();
    ResetEntitySoundSlotLists();
    Empty_stub();
    LoadFonts(&PTR_DAT_00502d48,&DAT_00c4602c);
    if (g_PendingTransitionPayload == 0) {
      value = (int)g_SelectedLevelIndex;
      value2 = value * 0x3c;
      if ((short)g_LevelTransitionRequestFlags == -0x7fff) {
        if (((byte)g_GameplayRuntimeFlags & 1) != 0) {
          g_CollectedTARZANLetterMask6 = 0x3f;
        }
        if ((g_CollectedTARZANLetterMask6 & 0x3f) == 0x3f) {
          *(byte *)((int)&g_RuntimeCompletionFlagsByLevel + (int)*( undefined1 *)((int)&g_LevelTransitionContext + 2)) =
               *(byte *)((int)&g_RuntimeCompletionFlagsByLevel + (int)*( undefined1 *)((int)&g_LevelTransitionContext + 2)
                        ) | '\x01' << (*( undefined1 *)((int)&g_LevelTransitionContext + 1) & 0x1f);
        }
        if ((&g_MenuLoadOrAdvanceLevelCallback)[value * 0xf] == -1) {
          PlayAudioById(*(undefined4 *)
                         (&g_LevelCompleteDifficultyAudioIdTable +
                         (char)*( undefined1 *)((int)&g_LevelTransitionContext + 1) * 4),0,0);
          ProcessMovieClipOrLogo(0x4004,0x78,0,0xffff);
        }
        ProcessMovieClipOrLogo(*(undefined4 *)(&DAT_004f2690 + value2),0x5a,0,0xffff);
        ProcessMovieClipOrLogo
                  (*(undefined4 *)(value2 + 0x4f2694 + (char)*( undefined1 *)((int)&g_LevelTransitionContext + 1) * 4),0x5a
                   ,0,0xffff);
        ProcessMovieClipOrLogo(*(undefined4 *)(&DAT_004f26a0 + value2),0x5a,0,0xffff);
        TransitionToWorldOrMenu(0);
        return;
      }
      if ((g_LevelTransitionRequestFlags & 0x8080) == 0x8080) {
        value = RandomModulo(2,0x5a,0,0xffff);
        ProcessMovieClipOrLogo(*(undefined4 *)(value2 + 0x4f2688 + value * 4));
        if (g_SelectedLevelIndex < '\f') {
          value2 = RandomModulo(5,0,0);
          value3 = *(undefined4 *)(&g_EarlyLevelExitRandomAudioIdTable + value2 * 4);
        }
        else {
          value2 = RandomModulo(5,0,0);
          value3 = *(undefined4 *)(&g_LateLevelExitRandomAudioIdTable + value2 * 4);
        }
        PlayAudioById(value3);
        SetActiveMenuContext(&g_MenuSceneContext);
        ProcessLevelLogo(&DAT_004e57e0);
        InitAudioLine_stub();
        TransitionToWorldOrMenu(0);
        return;
      }
    }
    SetActiveMenuContext(&g_MenuSceneContext);
    TransitionToWorldOrMenu(0);
  }
  return;
}

