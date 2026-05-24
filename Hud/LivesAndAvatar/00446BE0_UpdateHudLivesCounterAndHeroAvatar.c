
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void UpdateHudLivesCounterAndHeroAvatar(void)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  
  if (g_HudLivesCounterScene != 0) {
    _g_HudLivesOnesDigitSprite = (short)g_LevelTransitionContext._3_1_ % 10 + 0x200f;
    _g_HudLivesTensDigitSprite = (short)(((int)g_LevelTransitionContext._3_1_ / 10) % 10) + 0x200f;
    g_HudLivesTensDigitFlags = -(ushort)((int)g_LevelTransitionContext._3_1_ / 10 != 0) & 0x8100;
    if (-1 < g_HudLifeGainPortraitFrameIndex) {
      iVar2 = *(int *)(&g_HudLifeGainPortraitFrameScript + g_HudLifeGainPortraitFrameIndex * 4);
      if (iVar2 == 999) {
        iVar2 = 0;
        g_HudLifeGainPortraitFrameIndex = -1;
      }
      else {
        g_HudLifeGainPortraitFrameIndex = g_HudLifeGainPortraitFrameIndex + 1;
      }
      *(int *)(g_HudLivesCounterScene + 0x18) = iVar2;
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
      sVar1 = GetWrappedSignedAngleDelta12Bit(0,*(ushort *)(g_HudLivesAvatarScene + 0xa2) & 0x7ff);
      uVar3 = (int)sVar1 >> 0x1f;
      if (0x2f < (int)(((int)sVar1 ^ uVar3) - uVar3)) {
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

