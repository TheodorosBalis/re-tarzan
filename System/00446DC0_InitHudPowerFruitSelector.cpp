#include "tarzan_ghidra_types.hpp"

// Address: 0x00446DC0
// Label: InitHudPowerFruitSelector
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void InitHudPowerFruitSelector(void)

{
  int value;
  undefined4 value2;
  undefined2 *dataCursor;
  undefined4 *dataCursor2;
  
  value = g_WorldEntitySceneObjectArrayBase + 0x68;
  _g_HudPowerFruitSelectorIconScene_Field54 = 0x3000;
  _g_HudPowerFruitSelectorBackScene_Field54 = 0x3000;
  _g_HudPowerFruitLeftAmmoDigitsScene_Field54 = 0x3000;
  g_HudPowerFruitSelectorScene = &DAT_00532f58;
  _g_HudPowerFruitSelectorIconScene_Field0E = 0x8500;
  _g_HudPowerFruitSelectorIconScene_Field58 = 0x1500;
  _g_HudPowerFruitSelectorIconScene_Field5C = 0;
  _g_HudPowerFruitSelectorIconScene_FieldA6 = 1;
  _g_HudPowerFruitSelectorIconScene_Field0C = 0x200a;
  _g_HudPowerFruitSelectorIconScene_Field30 = 0x200;
  g_HudPowerFruitSelectorBackScene = &DAT_0053309c;
  _g_HudPowerFruitSelectorBackScene_Field0E = 0x8100;
  _g_HudPowerFruitSelectorBackScene_Field58 = 0x1500;
  _g_HudPowerFruitSelectorBackScene_Field5C = 0;
  _g_HudPowerFruitSelectorBackScene_FieldA6 = 1;
  _g_HudPowerFruitSelectorBackScene_Field0C = 0x200d;
  g_HudPowerFruitLeftAmmoDigitsScene = &DAT_005331e0;
  _g_HudPowerFruitLeftAmmoDigitsScene_Field10 = &g_LanguageFontAssetSet;
  _g_HudPowerFruitLeftAmmoDigitsScene_Field0C = 0x2000;
  _g_HudPowerFruitLeftAmmoDigitsScene_Field38 = &DAT_00532058;
  _g_HudPowerFruitLeftAmmoDigitsScene_FieldA6 = 1;
  _g_HudPowerFruitLeftAmmoDigitsScene_Field0E = 0x100;
  _g_HudPowerFruitLeftAmmoDigitsScene_Field58 = 0x1500;
  _g_HudPowerFruitLeftAmmoDigitsScene_Field5C = 0;
  _g_HudPowerFruitLeftAmmoDigitList_Field0C = 3;
  dataCursor2 = &DAT_004f0268;
  dataCursor = &g_HudPowerFruitLeftAmmoOnesDigitFlags;
  _g_HudPowerFruitSelectorIconScene_Field10 = value;
  _g_HudPowerFruitSelectorBackScene_Field10 = value;
  do {
    value2 = *dataCursor2;
    *(int *)(dataCursor + 1) = value;
    *dataCursor = 0x8100;
    *(undefined4 *)(dataCursor + 3) = value2;
    *(undefined4 *)(dataCursor + 5) = 0x6c;
    *(undefined4 *)(dataCursor + 7) = 0xffffff90;
    dataCursor2 = dataCursor2 + 1;
    dataCursor = dataCursor + 0x14;
  } while ((int)dataCursor2 < 0x4f0274);
  g_HudPowerFruitRightAmmoDigitsScene = &DAT_00533324;
  _g_HudPowerFruitLeftAmmoOnesDigitSprite = 0x200f;
  _g_HudPowerFruitLeftAmmoTensDigitSprite = 0x200f;
  _g_HudPowerFruitLeftAmmoHundredsDigitSprite = 0x200f;
  _g_HudPowerFruitRightAmmoDigitsScene_Field10 = &g_LanguageFontAssetSet;
  _g_HudPowerFruitRightAmmoDigitsScene_Field0C = 0x2000;
  _g_HudPowerFruitRightAmmoDigitsScene_Field38 = &DAT_00531fd0;
  _g_HudPowerFruitRightAmmoDigitsScene_Field0E = 0x100;
  _g_HudPowerFruitRightAmmoDigitsScene_FieldA6 = 1;
  _g_HudPowerFruitRightAmmoDigitsScene_Field54 = 0x3000;
  _g_HudPowerFruitRightAmmoDigitsScene_Field58 = 0x1500;
  _g_HudPowerFruitRightAmmoDigitsScene_Field5C = 0;
  _g_HudPowerFruitRightAmmoDigitList_Field0C = 3;
  dataCursor2 = &DAT_004f0268;
  dataCursor = &g_HudPowerFruitRightAmmoOnesDigitFlags;
  do {
    value2 = *dataCursor2;
    *(int *)(dataCursor + 1) = value;
    *dataCursor = 0x8100;
    *(undefined4 *)(dataCursor + 3) = value2;
    *(undefined4 *)(dataCursor + 5) = 0x6c;
    *(undefined4 *)(dataCursor + 7) = 0xffffff90;
    dataCursor2 = dataCursor2 + 1;
    dataCursor = dataCursor + 0x14;
  } while ((int)dataCursor2 < 0x4f0274);
  _g_HudPowerFruitRightAmmoOnesDigitSprite = 0x200f;
  _g_HudPowerFruitRightAmmoTensDigitSprite = 0x200f;
  _g_HudPowerFruitRightAmmoHundredsDigitSprite = 0x200f;
  g_HudPowerFruitSelectorSlideTicks = 0x78;
  g_HudPowerFruitSelectorPoseX = g_HudPowerFruitSelectorPoseXBySlot;
  _g_HudPowerFruitSelectorPoseY = g_HudPowerFruitSelectorPoseYBySlot;
  *( undefined2 *)((int)&g_HudPowerFruitSelectorPoseZ + 0) = g_HudPowerFruitSelectorPoseZBySlot;
  return;
}

