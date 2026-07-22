#include "tarzan_ghidra_types.hpp"

// Address: 0x0042D8F0
// Label: CWorld::ReInitOnDeath
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CWorld::ReInitOnDeath(void)

{
  switch(_g_DeathRespawnFadeState) {
  case 8:
    if ((g_LevelTransitionRequestFlags & 0x8000) != 0) {
      ResetBackgroundMusicPlaybackStateThunk(&DAT_00c46070);
      InitiateFade(2,0xb4);
      *( undefined1 *)((int)&g_GameplayStateFlags + 0) = (byte)g_GameplayStateFlags | 8;
      _g_DeathRespawnFadeState = 10;
      return;
    }
    break;
  case 9:
    if ((ram0x00534026 & 0x8000) == 0) {
      _g_DeathRespawnFadeState = 8;
      return;
    }
    break;
  case 10:
    if ((FadeBrightness == 0) && (3 < FadeStatus)) {
      if ((short)g_LevelTransitionRequestFlags == -0x7ffe) {
        *( undefined1 *)((int)&g_GameplayStateFlags + 0) = (byte)g_GameplayStateFlags | 0x10;
        return;
      }
      if ((short)g_LevelTransitionRequestFlags != -0x7fff) {
        if (((g_GameplayRuntimeFlags & 0x100) == 0) &&
           (*( undefined1 *)((int)&g_LevelTransitionContext + 3) = *( undefined1 *)((int)&g_LevelTransitionContext + 3) + -1,
           *( undefined1 *)((int)&g_LevelTransitionContext + 3) < '\0')) {
          g_LevelTransitionRequestFlags = CONCAT22(*( undefined2 *)((int)&g_LevelTransitionRequestFlags + 2),0x8080);
        }
        g_DeathRespawnBlackScreenDelayTicks = 0x1e;
        _g_DeathRespawnFadeState = 0x10;
        return;
      }
      if ((g_GameplayRuntimeFlags & 2) != 0) {
        g_CollectedSketchPieceMask4 = g_CollectedSketchPieceMask4 | 0xf;
      }
      *( undefined1 *)((int)&g_GameplayStateFlags + 0) = (byte)g_GameplayStateFlags | 0x10;
      return;
    }
    break;
  case 0x10:
    if (g_DeathRespawnBlackScreenDelayTicks != 0) {
      g_DeathRespawnBlackScreenDelayTicks = g_DeathRespawnBlackScreenDelayTicks + -1;
      return;
    }
    if ((short)g_LevelTransitionRequestFlags == -0x7f80) {
      *( undefined1 *)((int)&g_GameplayStateFlags + 0) = (byte)g_GameplayStateFlags | 0x10;
      return;
    }
    RespawnAndReinitializeGameplayWorld();
    InitiateFade(1,0xb4);
    g_LevelTransitionRequestFlags = g_LevelTransitionRequestFlags & 0xffff0000;
    _g_DeathRespawnFadeState = 9;
  }
  return;
}

