#include "tarzan_ghidra_types.hpp"

// Address: 0x00446FD0
// Label: UpdateHudPowerFruitSelector
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int UpdateHudPowerFruitSelector(void)

{
  ushort value3;
  int value;
  short shortValue;
  uint value4;
  short shortValue2;
  int value2;
  short shortValue3;
  ushort value5;
  ushort localState;
  
  if (g_HudPowerFruitSelectorScene == 0) {
    return 0;
  }
  *(ushort *)(g_HudPowerFruitSelectorScene + 0xe) =
       *(ushort *)(g_HudPowerFruitSelectorScene + 0xe) | 0x8000;
  *(ushort *)(g_HudPowerFruitSelectorBackScene + 0xe) =
       *(ushort *)(g_HudPowerFruitSelectorBackScene + 0xe) | 0x8000;
  if (((byte)g_GameplayStateFlags & 1) == 0) {
    if (g_HudPowerFruitSelectorSlideTicks < 0) {
      if (*(int *)(g_HudPowerFruitSelectorScene + 0x18) < -0x10f) {
        *(ushort *)(g_HudPowerFruitSelectorScene + 0xe) =
             *(ushort *)(g_HudPowerFruitSelectorScene + 0xe) & 0x7fff;
        *(ushort *)(g_HudPowerFruitSelectorBackScene + 0xe) =
             *(ushort *)(g_HudPowerFruitSelectorBackScene + 0xe) & 0x7fff;
      }
      else {
        *(int *)(g_HudPowerFruitSelectorScene + 0x18) =
             *(int *)(g_HudPowerFruitSelectorScene + 0x18) + -0x30;
      }
    }
    else {
      if (*(int *)(g_HudPowerFruitSelectorScene + 0x18) < 0) {
        *(int *)(g_HudPowerFruitSelectorScene + 0x18) =
             *(int *)(g_HudPowerFruitSelectorScene + 0x18) + 0x30;
      }
      else {
        *(undefined4 *)(g_HudPowerFruitSelectorScene + 0x18) = 0;
      }
      g_HudPowerFruitSelectorSlideTicks = g_HudPowerFruitSelectorSlideTicks + -1;
    }
  }
  else if (*(int *)(g_HudPowerFruitSelectorScene + 0x18) < 0) {
    *(int *)(g_HudPowerFruitSelectorScene + 0x18) =
         *(int *)(g_HudPowerFruitSelectorScene + 0x18) + 0x30;
  }
  else {
    *(undefined4 *)(g_HudPowerFruitSelectorScene + 0x18) = 0;
  }
  if (g_PowerFruitPickupFlashTicks == 0) {
    value5 = g_SelectedPowerFruitType << 10;
    if (g_SelectedPowerFruitType != 0) goto LAB_0044709a;
  }
  else {
    g_PowerFruitPickupFlashTicks = g_PowerFruitPickupFlashTicks + -1;
    value5 = (ushort)(g_PowerFruitPickupFlashType << 10);
LAB_0044709a:
    g_HudPowerFruitSelectorSlideTicks = 0x1e;
  }
  value3 = *(ushort *)(g_HudPowerFruitSelectorScene + 0xa2);
  if (value3 != value5) {
    shortValue = GetWrappedSignedAngleDelta12Bit((int)(short)value5,(int)(short)value3);
    shortValue = shortValue >> 2;
    if (shortValue != 0) {
      if (shortValue < -0x80) {
        value5 = value3 + 0x80;
      }
      else {
        if (0x80 < shortValue) {
          shortValue = 0x80;
        }
        value5 = value3 - shortValue;
      }
    }
    *(ushort *)(g_HudPowerFruitSelectorScene + 0xa2) = value5 & 0xfff;
  }
  *(undefined4 *)(g_HudPowerFruitSelectorBackScene + 0x18) =
       *(undefined4 *)(g_HudPowerFruitSelectorScene + 0x18);
  value2 = g_HudPowerFruitSelectorBackScene;
  *(undefined2 *)(g_HudPowerFruitSelectorBackScene + 0xa2) =
       *(undefined2 *)(g_HudPowerFruitSelectorScene + 0xa2);
  value4 = CONCAT22((short)((uint)value2 >> 0x10),*(undefined2 *)(g_HudPowerFruitSelectorScene + 0xa2)
                  ) + 0x200 >> 10 & 3;
  value5 = (&g_HudPowerFruitSelectorPoseXBySlot)[value4 * 3];
  if (g_HudPowerFruitSelectorPoseX != value5) {
    value2 = (int)((_g_HudPowerFruitSelectorPoseX & 0xffff) - (uint)value5) >> 2;
    if (value2 == 0) {
      _g_HudPowerFruitSelectorPoseX = CONCAT22(_g_HudPowerFruitSelectorPoseY,value5);
    }
    else {
      g_HudPowerFruitSelectorPoseX = g_HudPowerFruitSelectorPoseX - (short)value2;
    }
  }
  value5 = (&g_HudPowerFruitSelectorPoseYBySlot)[value4 * 3];
  if (_g_HudPowerFruitSelectorPoseY != value5) {
    value2 = (int)((uint)_g_HudPowerFruitSelectorPoseY - (uint)value5) >> 2;
    if (value2 == 0) {
      _g_HudPowerFruitSelectorPoseX = CONCAT22(value5,g_HudPowerFruitSelectorPoseX);
    }
    else {
      _g_HudPowerFruitSelectorPoseX =
           CONCAT22(_g_HudPowerFruitSelectorPoseY - (short)value2,g_HudPowerFruitSelectorPoseX);
    }
  }
  value5 = (&g_HudPowerFruitSelectorPoseZBySlot)[value4 * 3];
  if ((ushort)g_HudPowerFruitSelectorPoseZ != value5) {
    value2 = (int)((g_HudPowerFruitSelectorPoseZ & 0xffff) - (uint)value5) >> 2;
    if (value2 == 0) {
      g_HudPowerFruitSelectorPoseZ = CONCAT22(*( undefined2 *)((int)&g_HudPowerFruitSelectorPoseZ + 2),value5);
    }
    else {
      *( undefined2 *)((int)&g_HudPowerFruitSelectorPoseZ + 0) = (ushort)g_HudPowerFruitSelectorPoseZ - (short)value2;
    }
  }
  *(uint *)(g_HudPowerFruitSelectorScene + 0x20) = _g_HudPowerFruitSelectorPoseX & 0xffff;
  *(uint *)(g_HudPowerFruitSelectorScene + 0x24) = _g_HudPowerFruitSelectorPoseX >> 0x10;
  *(uint *)(g_HudPowerFruitSelectorScene + 0x28) = g_HudPowerFruitSelectorPoseZ & 0xffff;
  shortValue2 = *(short *)(g_HudPowerFruitSelectorScene + 0xa2);
  value4 = 0xffffffff;
  shortValue = shortValue2;
  if (shortValue2 < 0x401) {
    localState = 0xffff;
    shortValue3 = -0x400;
    value4 = (uint)g_PowerFruitAmmoType1;
LAB_0044728b:
    shortValue3 = shortValue2 + shortValue3;
    if (0x800 < shortValue2) goto LAB_00447291;
LAB_004472af:
    if (shortValue2 < 0xc01) goto LAB_004472be;
  }
  else {
    shortValue3 = shortValue2;
    if (shortValue2 < 0x801) {
      shortValue = shortValue2 + -0x400;
      shortValue3 = -0x800;
      value4 = g_PowerFruitAmmoType2 & 0xffff;
      localState = g_PowerFruitAmmoType1;
      goto LAB_0044728b;
    }
LAB_00447291:
    if (shortValue2 < 0xc01) {
      shortValue = shortValue + -0x800;
      shortValue3 = shortValue3 + 0x400;
      value4 = (uint)*( undefined2 *)((int)&g_PowerFruitAmmoType2 + 2);
      localState = (ushort)g_PowerFruitAmmoType2;
      goto LAB_004472af;
    }
  }
  shortValue = shortValue + 0x400;
  localState = *( undefined2 *)((int)&g_PowerFruitAmmoType2 + 2);
LAB_004472be:
  if (g_HudPowerFruitLeftAmmoDigitsScene != 0) {
    *(undefined4 *)(g_HudPowerFruitLeftAmmoDigitsScene + 0x58) =
         *(undefined4 *)(g_HudPowerFruitSelectorScene + 0x58);
    *(undefined4 *)(g_HudPowerFruitLeftAmmoDigitsScene + 0x18) =
         *(undefined4 *)(g_HudPowerFruitSelectorScene + 0x18);
    *(short *)(g_HudPowerFruitLeftAmmoDigitsScene + 0xa2) = shortValue;
    if ((short)localState < 0) {
      g_HudPowerFruitLeftAmmoOnesDigitFlags = 0;
      g_HudPowerFruitLeftAmmoTensDigitFlags = 0;
      _g_HudPowerFruitLeftAmmoHundredsDigitFlags = 0;
    }
    else {
      g_HudPowerFruitLeftAmmoOnesDigitFlags = 0x8100;
      _g_HudPowerFruitLeftAmmoOnesDigitSprite = (short)localState % 10 + 0x200f;
      shortValue2 = (short)localState / 10;
      if (shortValue2 == 0) {
        g_HudPowerFruitLeftAmmoTensDigitFlags = 0;
      }
      else {
        g_HudPowerFruitLeftAmmoTensDigitFlags = 0x8100;
        _g_HudPowerFruitLeftAmmoTensDigitSprite = shortValue2 % 10 + 0x200f;
      }
      if (shortValue2 / 10 == 0) {
        _g_HudPowerFruitLeftAmmoHundredsDigitFlags = 0;
      }
      else {
        _g_HudPowerFruitLeftAmmoHundredsDigitFlags = 0x8100;
        _g_HudPowerFruitLeftAmmoHundredsDigitSprite = (shortValue2 / 10) % 10 + 0x200f;
      }
    }
  }
  value2 = g_HudPowerFruitRightAmmoDigitsScene;
  if (g_HudPowerFruitRightAmmoDigitsScene != 0) {
    *(undefined4 *)(g_HudPowerFruitRightAmmoDigitsScene + 0x18) =
         *(undefined4 *)(g_HudPowerFruitSelectorScene + 0x18);
    value2 = g_HudPowerFruitRightAmmoDigitsScene;
    *(short *)(g_HudPowerFruitRightAmmoDigitsScene + 0xa2) = shortValue3;
    *(short *)(g_HudPowerFruitLeftAmmoDigitsScene + 0xa2) = shortValue;
    if ((int)value4 < 0) {
      g_HudPowerFruitRightAmmoOnesDigitFlags = 0;
      g_HudPowerFruitRightAmmoTensDigitFlags = 0;
    }
    else {
      g_HudPowerFruitRightAmmoOnesDigitFlags = 0x8100;
      _g_HudPowerFruitRightAmmoOnesDigitSprite = (short)((int)value4 % 10) + 0x200f;
      value = (int)value4 / 10;
      if (value == 0) {
        g_HudPowerFruitRightAmmoTensDigitFlags = 0;
      }
      else {
        g_HudPowerFruitRightAmmoTensDigitFlags = 0x8100;
        _g_HudPowerFruitRightAmmoTensDigitSprite = (short)(value % 10) + 0x200f;
      }
      value2 = value * 0x66666667;
      value = value / 10;
      if (value != 0) {
        _g_HudPowerFruitRightAmmoHundredsDigitFlags = 0x8100;
        _g_HudPowerFruitRightAmmoHundredsDigitSprite = (short)(value % 10) + 0x200f;
        return value / 10;
      }
    }
    _g_HudPowerFruitRightAmmoHundredsDigitFlags = 0;
  }
  return value2;
}

