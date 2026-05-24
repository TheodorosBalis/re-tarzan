
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void InitHudPowerFruitSelector(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined2 *puVar3;
  undefined4 *puVar4;
  
  iVar1 = g_WorldSceneEntryArrayBase + 0x68;
  _DAT_00532fac = 0x3000;
  _DAT_005330f0 = 0x3000;
  _DAT_00533234 = 0x3000;
  g_HudPowerFruitSelectorScene = &DAT_00532f58;
  _DAT_00532f66 = 0x8500;
  _DAT_00532fb0 = 0x1500;
  _DAT_00532fb4 = 0;
  _DAT_00532ffe = 1;
  _DAT_00532f64 = 0x200a;
  _DAT_00532f88 = 0x200;
  g_HudPowerFruitSelectorBackScene = &DAT_0053309c;
  _DAT_005330aa = 0x8100;
  _DAT_005330f4 = 0x1500;
  _DAT_005330f8 = 0;
  _DAT_00533142 = 1;
  _DAT_005330a8 = 0x200d;
  g_HudPowerFruitLeftAmmoDigitsScene = &DAT_005331e0;
  _DAT_005331f0 = &g_LanguageFontAssetSet;
  _DAT_005331ec = 0x2000;
  _DAT_00533218 = &DAT_00532058;
  _DAT_00533286 = 1;
  _DAT_005331ee = 0x100;
  _DAT_00533238 = 0x1500;
  _DAT_0053323c = 0;
  _DAT_00532064 = 3;
  puVar4 = &DAT_004f0268;
  puVar3 = &g_HudPowerFruitLeftAmmoOnesDigitFlags;
  _DAT_00532f68 = iVar1;
  _DAT_005330ac = iVar1;
  do {
    uVar2 = *puVar4;
    *(int *)(puVar3 + 1) = iVar1;
    *puVar3 = 0x8100;
    *(undefined4 *)(puVar3 + 3) = uVar2;
    *(undefined4 *)(puVar3 + 5) = 0x6c;
    *(undefined4 *)(puVar3 + 7) = 0xffffff90;
    puVar4 = puVar4 + 1;
    puVar3 = puVar3 + 0x14;
  } while ((int)puVar4 < 0x4f0274);
  g_HudPowerFruitRightAmmoDigitsScene = &DAT_00533324;
  _g_HudPowerFruitLeftAmmoOnesDigitSprite = 0x200f;
  _g_HudPowerFruitLeftAmmoTensDigitSprite = 0x200f;
  _g_HudPowerFruitLeftAmmoHundredsDigitSprite = 0x200f;
  _DAT_00533334 = &g_LanguageFontAssetSet;
  _DAT_00533330 = 0x2000;
  _DAT_0053335c = &DAT_00531fd0;
  _DAT_00533332 = 0x100;
  _DAT_005333ca = 1;
  _DAT_00533378 = 0x3000;
  _DAT_0053337c = 0x1500;
  _DAT_00533380 = 0;
  _DAT_00531fdc = 3;
  puVar4 = &DAT_004f0268;
  puVar3 = &g_HudPowerFruitRightAmmoOnesDigitFlags;
  do {
    uVar2 = *puVar4;
    *(int *)(puVar3 + 1) = iVar1;
    *puVar3 = 0x8100;
    *(undefined4 *)(puVar3 + 3) = uVar2;
    *(undefined4 *)(puVar3 + 5) = 0x6c;
    *(undefined4 *)(puVar3 + 7) = 0xffffff90;
    puVar4 = puVar4 + 1;
    puVar3 = puVar3 + 0x14;
  } while ((int)puVar4 < 0x4f0274);
  _g_HudPowerFruitRightAmmoOnesDigitSprite = 0x200f;
  _g_HudPowerFruitRightAmmoTensDigitSprite = 0x200f;
  _g_HudPowerFruitRightAmmoHundredsDigitSprite = 0x200f;
  g_HudPowerFruitSelectorSlideTicks = 0x78;
  g_HudPowerFruitSelectorPoseX = g_HudPowerFruitSelectorPoseXBySlot;
  _g_HudPowerFruitSelectorPoseY = g_HudPowerFruitSelectorPoseYBySlot;
  g_HudPowerFruitSelectorPoseZ._0_2_ = g_HudPowerFruitSelectorPoseZBySlot;
  return;
}

