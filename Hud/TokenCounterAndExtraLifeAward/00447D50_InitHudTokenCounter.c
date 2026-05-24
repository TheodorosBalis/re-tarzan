
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void InitHudTokenCounter(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined2 *puVar3;
  undefined4 *puVar4;
  
  iVar1 = g_WorldSceneEntryArrayBase + 0x68;
  g_HudTokenCounterScene = &DAT_00533834;
  _DAT_00533844 = &g_LanguageFontAssetSet;
  _DAT_00533840 = 0x2000;
  _DAT_0053386c = &DAT_005329a8;
  _DAT_00533842 = 0x8121;
  _DAT_00533888 = 0x1cc00;
  _DAT_0053388c = 0x2800;
  _DAT_00533850 = 0;
  _DAT_00533864 = 0x600;
  _DAT_005329b4 = 3;
  puVar4 = &DAT_004f0268;
  puVar3 = &DAT_005329ba;
  do {
    uVar2 = *puVar4;
    *(int *)(puVar3 + 1) = iVar1;
    *puVar3 = 0x8100;
    *(undefined4 *)(puVar3 + 3) = uVar2;
    *(undefined4 *)(puVar3 + 5) = 0;
    *(undefined4 *)(puVar3 + 7) = 0xffffffc4;
    puVar4 = puVar4 + 1;
    puVar3 = puVar3 + 0x14;
  } while ((int)puVar4 < 0x4f0274);
  g_HudTokenCounterSpinFrame = 0;
  _DAT_00533994 = 0;
  _g_HudTokenOnesDigitSprite = 0x200f;
  _g_HudTokenTensDigitSprite = 0x200f;
  _g_HudTokenHundredsDigitSprite = 0x200f;
  g_HudTokenCounterSlideTicks = 0x78;
  g_HudExtraLifeAwardScene = &DAT_00533978;
  _DAT_00533988 = &g_LanguageFontAssetSet;
  _DAT_00533984 = 0x2000;
  _DAT_00533986 = 0x100;
  _DAT_005339cc = 0x1cc00;
  _DAT_005339d0 = 0x2800;
  _DAT_005339a8 = 0x600;
  _DAT_005339e4 = 0xffffffc4;
  return;
}

