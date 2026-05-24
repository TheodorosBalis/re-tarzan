
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void InitHudLivesCounterAndHeroAvatar(void)

{
  short sVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined2 *puVar5;
  short *psVar6;
  
  uVar4 = DAT_00533494;
  uVar3 = DAT_00533490;
  _DAT_00533700 = g_WorldSceneEntryArrayBase + 0x68;
  g_HudLivesCounterScene = &DAT_00533468;
  DAT_00533476 = 0x8100;
  _DAT_005334bc = 0x1d400;
  _DAT_005334c0 = 0xde00;
  _DAT_005334c4 = 0;
  _DAT_00533474 = 0x200c;
  _DAT_005334a0 = &DAT_005320e0;
  _DAT_005320ec = 3;
  psVar6 = &DAT_004f0276;
  puVar5 = &DAT_005320f2;
  _DAT_00533478 = _DAT_00533700;
  do {
    sVar1 = psVar6[-1];
    *(int *)(puVar5 + 1) = _DAT_00533700;
    *puVar5 = 0;
    uVar2 = DAT_00533488;
    *(int *)(puVar5 + 3) = (int)sVar1;
    *(int *)(puVar5 + 5) = (int)*psVar6;
    *(undefined4 *)(puVar5 + 7) = 0xffffffc4;
    psVar6 = psVar6 + 2;
    *(undefined4 *)(puVar5 + 9) = uVar2;
    *(undefined4 *)(puVar5 + 0xb) = DAT_0053348c;
    *(undefined4 *)(puVar5 + 0xd) = uVar3;
    *(undefined4 *)(puVar5 + 0xf) = uVar4;
    puVar5 = puVar5 + 0x14;
  } while ((int)psVar6 < 0x4f0282);
  _g_HudLivesOnesDigitSprite = g_LevelTransitionContext._3_1_ + 0x200f;
  _DAT_00533604 = 0xde00;
  _DAT_005335bc = g_WorldSceneEntryArrayBase + 0x3a8;
  _DAT_00533748 = 0xde00;
  g_HudHeroRewardSetIndex = 0;
  _DAT_0053374c = 0;
  DAT_005320f2 = 0x8100;
  _g_HudLivesTensDigitSprite = 0x200f;
  g_HudLivesAvatarScene = &DAT_005335ac;
  DAT_005335ba = 0x8100;
  _DAT_00533600 = 0x3000;
  _DAT_00533608 = 0xffffffc4;
  _DAT_005335b8 = 0x202a;
  _DAT_00533652 = 1;
  _DAT_00533618 = 0xffffffce;
  _g_HudLifeGainPortraitScene = &DAT_005336f0;
  _DAT_00533796 = 1;
  _DAT_005336fe = 0x8100;
  _DAT_00533744 = 0x3200;
  _DAT_0053375c = 0xffffffe2;
  _DAT_005336fc = 0x200b;
  g_HudLifeGainPortraitFrameIndex = 0xffffffff;
  return;
}

