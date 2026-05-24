
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int UpdateHudPowerFruitSelector(void)

{
  ushort uVar1;
  int iVar2;
  short sVar3;
  uint uVar4;
  short sVar5;
  int iVar6;
  short sVar7;
  ushort uVar8;
  ushort local_4;
  
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
    uVar8 = g_SelectedPowerFruitType << 10;
    if (g_SelectedPowerFruitType != 0) goto LAB_0044709a;
  }
  else {
    g_PowerFruitPickupFlashTicks = g_PowerFruitPickupFlashTicks + -1;
    uVar8 = (ushort)(g_PowerFruitPickupFlashType << 10);
LAB_0044709a:
    g_HudPowerFruitSelectorSlideTicks = 0x1e;
  }
  uVar1 = *(ushort *)(g_HudPowerFruitSelectorScene + 0xa2);
  if (uVar1 != uVar8) {
    sVar3 = GetWrappedSignedAngleDelta12Bit((int)(short)uVar8,(int)(short)uVar1);
    sVar3 = sVar3 >> 2;
    if (sVar3 != 0) {
      if (sVar3 < -0x80) {
        uVar8 = uVar1 + 0x80;
      }
      else {
        if (0x80 < sVar3) {
          sVar3 = 0x80;
        }
        uVar8 = uVar1 - sVar3;
      }
    }
    *(ushort *)(g_HudPowerFruitSelectorScene + 0xa2) = uVar8 & 0xfff;
  }
  *(undefined4 *)(g_HudPowerFruitSelectorBackScene + 0x18) =
       *(undefined4 *)(g_HudPowerFruitSelectorScene + 0x18);
  iVar6 = g_HudPowerFruitSelectorBackScene;
  *(undefined2 *)(g_HudPowerFruitSelectorBackScene + 0xa2) =
       *(undefined2 *)(g_HudPowerFruitSelectorScene + 0xa2);
  uVar4 = CONCAT22((short)((uint)iVar6 >> 0x10),*(undefined2 *)(g_HudPowerFruitSelectorScene + 0xa2)
                  ) + 0x200 >> 10 & 3;
  uVar8 = (&g_HudPowerFruitSelectorPoseXBySlot)[uVar4 * 3];
  if (g_HudPowerFruitSelectorPoseX != uVar8) {
    iVar6 = (int)((_g_HudPowerFruitSelectorPoseX & 0xffff) - (uint)uVar8) >> 2;
    if (iVar6 == 0) {
      _g_HudPowerFruitSelectorPoseX = CONCAT22(_g_HudPowerFruitSelectorPoseY,uVar8);
    }
    else {
      g_HudPowerFruitSelectorPoseX = g_HudPowerFruitSelectorPoseX - (short)iVar6;
    }
  }
  uVar8 = (&g_HudPowerFruitSelectorPoseYBySlot)[uVar4 * 3];
  if (_g_HudPowerFruitSelectorPoseY != uVar8) {
    iVar6 = (int)((uint)_g_HudPowerFruitSelectorPoseY - (uint)uVar8) >> 2;
    if (iVar6 == 0) {
      _g_HudPowerFruitSelectorPoseX = CONCAT22(uVar8,g_HudPowerFruitSelectorPoseX);
    }
    else {
      _g_HudPowerFruitSelectorPoseX =
           CONCAT22(_g_HudPowerFruitSelectorPoseY - (short)iVar6,g_HudPowerFruitSelectorPoseX);
    }
  }
  uVar8 = (&g_HudPowerFruitSelectorPoseZBySlot)[uVar4 * 3];
  if ((ushort)g_HudPowerFruitSelectorPoseZ != uVar8) {
    iVar6 = (int)((g_HudPowerFruitSelectorPoseZ & 0xffff) - (uint)uVar8) >> 2;
    if (iVar6 == 0) {
      g_HudPowerFruitSelectorPoseZ = CONCAT22(g_HudPowerFruitSelectorPoseZ._2_2_,uVar8);
    }
    else {
      g_HudPowerFruitSelectorPoseZ._0_2_ = (ushort)g_HudPowerFruitSelectorPoseZ - (short)iVar6;
    }
  }
  *(uint *)(g_HudPowerFruitSelectorScene + 0x20) = _g_HudPowerFruitSelectorPoseX & 0xffff;
  *(uint *)(g_HudPowerFruitSelectorScene + 0x24) = _g_HudPowerFruitSelectorPoseX >> 0x10;
  *(uint *)(g_HudPowerFruitSelectorScene + 0x28) = g_HudPowerFruitSelectorPoseZ & 0xffff;
  sVar5 = *(short *)(g_HudPowerFruitSelectorScene + 0xa2);
  uVar4 = 0xffffffff;
  sVar3 = sVar5;
  if (sVar5 < 0x401) {
    local_4 = 0xffff;
    sVar7 = -0x400;
    uVar4 = (uint)g_PowerFruitAmmoType1;
LAB_0044728b:
    sVar7 = sVar5 + sVar7;
    if (0x800 < sVar5) goto LAB_00447291;
LAB_004472af:
    if (sVar5 < 0xc01) goto LAB_004472be;
  }
  else {
    sVar7 = sVar5;
    if (sVar5 < 0x801) {
      sVar3 = sVar5 + -0x400;
      sVar7 = -0x800;
      uVar4 = g_PowerFruitAmmoType2 & 0xffff;
      local_4 = g_PowerFruitAmmoType1;
      goto LAB_0044728b;
    }
LAB_00447291:
    if (sVar5 < 0xc01) {
      sVar3 = sVar3 + -0x800;
      sVar7 = sVar7 + 0x400;
      uVar4 = (uint)g_PowerFruitAmmoType2._2_2_;
      local_4 = (ushort)g_PowerFruitAmmoType2;
      goto LAB_004472af;
    }
  }
  sVar3 = sVar3 + 0x400;
  local_4 = g_PowerFruitAmmoType2._2_2_;
LAB_004472be:
  if (g_HudPowerFruitLeftAmmoDigitsScene != 0) {
    *(undefined4 *)(g_HudPowerFruitLeftAmmoDigitsScene + 0x58) =
         *(undefined4 *)(g_HudPowerFruitSelectorScene + 0x58);
    *(undefined4 *)(g_HudPowerFruitLeftAmmoDigitsScene + 0x18) =
         *(undefined4 *)(g_HudPowerFruitSelectorScene + 0x18);
    *(short *)(g_HudPowerFruitLeftAmmoDigitsScene + 0xa2) = sVar3;
    if ((short)local_4 < 0) {
      g_HudPowerFruitLeftAmmoOnesDigitFlags = 0;
      g_HudPowerFruitLeftAmmoTensDigitFlags = 0;
      _g_HudPowerFruitLeftAmmoHundredsDigitFlags = 0;
    }
    else {
      g_HudPowerFruitLeftAmmoOnesDigitFlags = 0x8100;
      _g_HudPowerFruitLeftAmmoOnesDigitSprite = (short)local_4 % 10 + 0x200f;
      sVar5 = (short)local_4 / 10;
      if (sVar5 == 0) {
        g_HudPowerFruitLeftAmmoTensDigitFlags = 0;
      }
      else {
        g_HudPowerFruitLeftAmmoTensDigitFlags = 0x8100;
        _g_HudPowerFruitLeftAmmoTensDigitSprite = sVar5 % 10 + 0x200f;
      }
      if (sVar5 / 10 == 0) {
        _g_HudPowerFruitLeftAmmoHundredsDigitFlags = 0;
      }
      else {
        _g_HudPowerFruitLeftAmmoHundredsDigitFlags = 0x8100;
        _g_HudPowerFruitLeftAmmoHundredsDigitSprite = (sVar5 / 10) % 10 + 0x200f;
      }
    }
  }
  iVar6 = g_HudPowerFruitRightAmmoDigitsScene;
  if (g_HudPowerFruitRightAmmoDigitsScene != 0) {
    *(undefined4 *)(g_HudPowerFruitRightAmmoDigitsScene + 0x18) =
         *(undefined4 *)(g_HudPowerFruitSelectorScene + 0x18);
    iVar6 = g_HudPowerFruitRightAmmoDigitsScene;
    *(short *)(g_HudPowerFruitRightAmmoDigitsScene + 0xa2) = sVar7;
    *(short *)(g_HudPowerFruitLeftAmmoDigitsScene + 0xa2) = sVar3;
    if ((int)uVar4 < 0) {
      g_HudPowerFruitRightAmmoOnesDigitFlags = 0;
      g_HudPowerFruitRightAmmoTensDigitFlags = 0;
    }
    else {
      g_HudPowerFruitRightAmmoOnesDigitFlags = 0x8100;
      _g_HudPowerFruitRightAmmoOnesDigitSprite = (short)((int)uVar4 % 10) + 0x200f;
      iVar2 = (int)uVar4 / 10;
      if (iVar2 == 0) {
        g_HudPowerFruitRightAmmoTensDigitFlags = 0;
      }
      else {
        g_HudPowerFruitRightAmmoTensDigitFlags = 0x8100;
        _g_HudPowerFruitRightAmmoTensDigitSprite = (short)(iVar2 % 10) + 0x200f;
      }
      iVar6 = iVar2 * 0x66666667;
      iVar2 = iVar2 / 10;
      if (iVar2 != 0) {
        _g_HudPowerFruitRightAmmoHundredsDigitFlags = 0x8100;
        _g_HudPowerFruitRightAmmoHundredsDigitSprite = (short)(iVar2 % 10) + 0x200f;
        return iVar2 / 10;
      }
    }
    _g_HudPowerFruitRightAmmoHundredsDigitFlags = 0;
  }
  return iVar6;
}

