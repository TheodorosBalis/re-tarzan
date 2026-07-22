#include "tarzan_ghidra_types.hpp"

// Address: 0x00446BE0
// Label: UpdateHudLivesCounterAndHeroAvatar
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void UpdateHudLivesCounterAndHeroAvatar(void)

{
  short shortValue;
  int count;
  uint value;
  
  if (g_HudLivesCounterScene != 0) {
    _g_HudLivesOnesDigitSprite = (short)*( undefined1 *)((int)&g_LevelTransitionContext + 3) % 10 + 0x200f;
    _g_HudLivesTensDigitSprite = (short)(((int)*( undefined1 *)((int)&g_LevelTransitionContext + 3) / 10) % 10) + 0x200f;
    g_HudLivesTensDigitFlags = -(ushort)((int)*( undefined1 *)((int)&g_LevelTransitionContext + 3) / 10 != 0) & 0x8100;
    if (-1 < g_HudLifeGainPortraitFrameIndex) {
      count = *(int *)(&g_HudLifeGainPortraitFrameScript + g_HudLifeGainPortraitFrameIndex * 4);
      if (count == 999) {
        count = 0;
        g_HudLifeGainPortraitFrameIndex = -1;
      }
      else {
        g_HudLifeGainPortraitFrameIndex = g_HudLifeGainPortraitFrameIndex + 1;
      }
      *(int *)(g_HudLivesCounterScene + 0x18) = count;
    }
  }
  if (g_HudLivesAvatarScene != 0) {
    switch(_g_PlayerHeroMode) {
    case 2:
    case 8:
    case 9:
    case 0xb:
      g_HudHeroRewardSetIndex = 1;
      *(undefined2 *)(g_HudLivesAvatarScene + 0xc) = 0x2030;
      break;
    case 6:
    case 10:
    case 0xc:
      g_HudHeroRewardSetIndex = 2;
      *(undefined2 *)(g_HudLivesAvatarScene + 0xc) = 0x2017;
    }
    if (((byte)g_GameplayStateFlags & 1) != 0) {
      shortValue = GetWrappedSignedAngleDelta12Bit(0,*(ushort *)(g_HudLivesAvatarScene + 0xa2) & 0x7ff);
      value = (int)shortValue >> 0x1f;
      if (0x2f < (int)(((int)shortValue ^ value) - value)) {
        *(short *)(g_HudLivesAvatarScene + 0xa2) = *(short *)(g_HudLivesAvatarScene + 0xa2) + 0x30;
        *(ushort *)(g_HudLivesAvatarScene + 0xa2) =
             *(ushort *)(g_HudLivesAvatarScene + 0xa2) & 0xfff;
        return;
      }
      *(ushort *)(g_HudLivesAvatarScene + 0xa2) = *(ushort *)(g_HudLivesAvatarScene + 0xa2) & 0xf800
      ;
      *(ushort *)(g_HudLivesAvatarScene + 0xa2) = *(ushort *)(g_HudLivesAvatarScene + 0xa2) & 0xfff;
      return;
    }
    *(short *)(g_HudLivesAvatarScene + 0xa2) = *(short *)(g_HudLivesAvatarScene + 0xa2) + 0x30;
    *(ushort *)(g_HudLivesAvatarScene + 0xa2) = *(ushort *)(g_HudLivesAvatarScene + 0xa2) & 0xfff;
    return;
  }
  switch(_g_PlayerHeroMode) {
  case 2:
  case 8:
  case 9:
  case 0xb:
    g_HudHeroRewardSetIndex = 1;
    return;
  default:
    g_HudHeroRewardSetIndex = 0;
    return;
  case 6:
  case 10:
  case 0xc:
    g_HudHeroRewardSetIndex = 2;
    return;
  }
}

