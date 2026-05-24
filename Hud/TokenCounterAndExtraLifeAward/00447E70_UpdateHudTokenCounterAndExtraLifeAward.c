
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void UpdateHudTokenCounterAndExtraLifeAward(void)

{
  uint uVar1;
  
  if (g_HudTokenCounterScene == 0) {
    return;
  }
  *(ushort *)(g_HudTokenCounterScene + 0xe) = *(ushort *)(g_HudTokenCounterScene + 0xe) | 0x8000;
  if (((byte)g_GameplayStateFlags & 1) == 0) {
    if (g_HudTokenCounterSlideTicks < 0) {
      if (*(int *)(g_HudTokenCounterScene + 0x18) < -0x1bf) {
        *(ushort *)(g_HudTokenCounterScene + 0xe) =
             *(ushort *)(g_HudTokenCounterScene + 0xe) & 0x7fff;
      }
      else {
        *(int *)(g_HudTokenCounterScene + 0x18) = *(int *)(g_HudTokenCounterScene + 0x18) + -0x30;
      }
    }
    else {
      if (*(int *)(g_HudTokenCounterScene + 0x18) < 0) {
        *(int *)(g_HudTokenCounterScene + 0x18) = *(int *)(g_HudTokenCounterScene + 0x18) + 0x30;
      }
      else {
        *(undefined4 *)(g_HudTokenCounterScene + 0x18) = 0;
      }
      g_HudTokenCounterSlideTicks = g_HudTokenCounterSlideTicks + -1;
    }
joined_r0x00447f22:
    g_HudTokenCounterSpinFrame = g_HudTokenCounterSpinFrame + 1;
    if (0x17 < g_HudTokenCounterSpinFrame) {
      g_HudTokenCounterSpinFrame = 0;
    }
  }
  else {
    if (*(int *)(g_HudTokenCounterScene + 0x18) < 0) {
      *(int *)(g_HudTokenCounterScene + 0x18) = *(int *)(g_HudTokenCounterScene + 0x18) + 0x30;
    }
    else {
      *(undefined4 *)(g_HudTokenCounterScene + 0x18) = 0;
    }
    if (g_HudTokenCounterSpinFrame != 0) goto joined_r0x00447f22;
  }
  *(ushort *)(g_HudTokenCounterScene + 0xc) = g_HudTokenCounterSpinFrame + 0x2000;
  _g_HudTokenOnesDigitSprite = (short)((ulonglong)(uint)gCurrentTokensCollected % 10) + 0x200f;
  uVar1 = gCurrentTokensCollected / 10;
  if (uVar1 == 0) {
    g_HudTokenTensDigitFlags = g_HudTokenTensDigitFlags & 0x7fff;
  }
  else {
    _g_HudTokenTensDigitSprite = (short)(uVar1 % 10) + 0x200f;
    g_HudTokenTensDigitFlags = g_HudTokenTensDigitFlags | 0x8000;
  }
  if (uVar1 / 10 == 0) {
    _g_HudTokenHundredsDigitFlags = _g_HudTokenHundredsDigitFlags & 0x7fff;
  }
  else {
    _g_HudTokenHundredsDigitSprite = (short)((uVar1 / 10) % 10) + 0x200f;
    _g_HudTokenHundredsDigitFlags = _g_HudTokenHundredsDigitFlags | 0x8000;
  }
  if (g_HudExtraLifeAwardScene == 0) {
LAB_0044815f:
    g_ExtraLifeAwardState = 0;
  }
  else {
    *(ushort *)(g_HudExtraLifeAwardScene + 0xc) = g_HudTokenCounterSpinFrame + 0x2000;
    switch(g_ExtraLifeAwardState) {
    case 1:
      g_HudTokenCounterSlideTicks = 0x78;
      *(undefined4 *)(g_HudExtraLifeAwardScene + 0x18) = 0;
      g_HudExtraLifeAwardVelocity = 0;
      if (*(int *)(g_HudTokenCounterScene + 0x18) == 0) {
        g_ExtraLifeAwardState = 2;
        PlayAudioById(0xbe,0,0);
        return;
      }
      break;
    case 2:
      *(ushort *)(g_HudExtraLifeAwardScene + 0xe) =
           *(ushort *)(g_HudExtraLifeAwardScene + 0xe) | 0x8000;
      *(ushort *)(g_HudTokenCounterScene + 0xe) = *(ushort *)(g_HudTokenCounterScene + 0xe) & 0x7fff
      ;
      g_HudExtraLifeAwardVelocity = g_HudExtraLifeAwardVelocity + 4;
      if (0x50 < g_HudExtraLifeAwardVelocity) {
        g_HudExtraLifeAwardVelocity = 0x50;
      }
      *(int *)(g_HudExtraLifeAwardScene + 0x18) =
           *(int *)(g_HudExtraLifeAwardScene + 0x18) + g_HudExtraLifeAwardVelocity;
      if (0x400 < *(int *)(g_HudExtraLifeAwardScene + 0x18)) {
        g_ExtraLifeAwardState = 3;
        g_LevelTransitionContext._3_1_ = g_LevelTransitionContext._3_1_ + '\x01';
        if ('c' < g_LevelTransitionContext._3_1_) {
          g_LevelTransitionContext._3_1_ = 'c';
        }
        g_HudLifeGainPortraitFrameIndex = 0;
        return;
      }
      break;
    case 3:
      *(ushort *)(g_HudExtraLifeAwardScene + 0xe) =
           *(ushort *)(g_HudExtraLifeAwardScene + 0xe) | 0x8000;
      *(ushort *)(g_HudTokenCounterScene + 0xe) = *(ushort *)(g_HudTokenCounterScene + 0xe) & 0x7fff
      ;
      g_HudExtraLifeAwardVelocity = g_HudExtraLifeAwardVelocity + -4;
      if (g_HudExtraLifeAwardVelocity < 0) {
        g_HudExtraLifeAwardVelocity = 0;
        g_ExtraLifeAwardState = 4;
      }
      *(int *)(g_HudExtraLifeAwardScene + 0x18) =
           *(int *)(g_HudExtraLifeAwardScene + 0x18) - g_HudExtraLifeAwardVelocity;
      return;
    case 4:
      *(ushort *)(g_HudExtraLifeAwardScene + 0xe) =
           *(ushort *)(g_HudExtraLifeAwardScene + 0xe) | 0x8000;
      *(ushort *)(g_HudTokenCounterScene + 0xe) = *(ushort *)(g_HudTokenCounterScene + 0xe) & 0x7fff
      ;
      g_HudExtraLifeAwardVelocity = g_HudExtraLifeAwardVelocity + 4;
      if (0x50 < g_HudExtraLifeAwardVelocity) {
        g_HudExtraLifeAwardVelocity = 0x50;
      }
      *(int *)(g_HudExtraLifeAwardScene + 0x18) =
           *(int *)(g_HudExtraLifeAwardScene + 0x18) + g_HudExtraLifeAwardVelocity;
      if (*(int *)(g_HudExtraLifeAwardScene + 0x18) < 0x501) {
        return;
      }
      *(ushort *)(g_HudExtraLifeAwardScene + 0xe) =
           *(ushort *)(g_HudExtraLifeAwardScene + 0xe) & 0x7fff;
      *(ushort *)(g_HudTokenCounterScene + 0xe) = *(ushort *)(g_HudTokenCounterScene + 0xe) | 0x8000
      ;
      goto LAB_0044815f;
    }
  }
  return;
}

