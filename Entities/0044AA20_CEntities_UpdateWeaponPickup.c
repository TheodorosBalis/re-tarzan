
/* WARNING: Removing unreachable block (ram,0x0044ac72) */
/* WARNING: Removing unreachable block (ram,0x0044acab) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CEntities__UpdateWeaponPickup(int param_1)

{
  ushort uVar1;
  int iVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iStack_c;
  byte bStack_7;
  
  iVar2 = *(int *)(param_1 + 0x38);
  if (iVar2 == 0) {
LAB_0044ad72:
    cVar3 = CEntities__UpdateBouncingPickupMotionAndLifetime(param_1);
    if ((cVar3 != '\0') ||
       (cVar3 = IsRuntimeEntryOutsideOuterActivationBounds(param_1), cVar3 != '\0')) {
      CEntities__ReleaseRuntimeEntryToFreeList(param_1);
    }
    return;
  }
  *(ushort *)(iVar2 + 0xa2) = *(short *)(iVar2 + 0xa2) + 0x38U & 0xfff;
  cVar3 = CEntities__IsPlayerWithinPickupTriggerBounds
                    (iVar2,g_PlayerPickupTriggerRadius,(int)*(short *)(g_PlayerSceneEntry + 0x142),0
                    );
  if ((cVar3 == '\0') || (cVar3 = CEntities__CanStartPickupCollection(param_1), cVar3 == '\0'))
  goto LAB_0044ad72;
  switch(*(undefined4 *)(param_1 + 0x4c)) {
  case 0:
    _g_PlayerPowerFruitInventoryFlags = _g_PlayerPowerFruitInventoryFlags | 4;
    g_PowerFruitAmmoType2._2_2_ = g_PowerFruitAmmoType2._2_2_ + 5;
    g_PowerFruitPickupFlashType = 3;
    g_PowerFruitPickupFlashTicks = 0x3c;
    if (_g_PlayerHeroMode != 2) {
      PlayAudioById(0x68,0,0);
      goto switchD_0044aa9e_caseD_3;
    }
    break;
  case 1:
    g_PowerFruitAmmoType2._0_2_ = (short)g_PowerFruitAmmoType2 + 5;
    _g_PlayerPowerFruitInventoryFlags = _g_PlayerPowerFruitInventoryFlags | 2;
    g_PowerFruitPickupFlashType = 2;
    g_PowerFruitPickupFlashTicks = 0x3c;
    if ((_g_PlayerHeroMode != 2) && (_g_PlayerHeroMode != 9)) {
      PlayAudioById(0x68,0,0);
      goto switchD_0044aa9e_caseD_3;
    }
    break;
  case 2:
    _g_PlayerPowerFruitInventoryFlags = _g_PlayerPowerFruitInventoryFlags | 1;
    g_PowerFruitAmmoType1 = g_PowerFruitAmmoType1 + 1;
    g_PowerFruitPickupFlashType = 1;
    g_PowerFruitPickupFlashTicks = 0x3c;
    if (_g_PlayerHeroMode != 2) {
      PlayAudioById(0x68,0,0);
      goto switchD_0044aa9e_caseD_3;
    }
    break;
  default:
    goto switchD_0044aa9e_caseD_3;
  case 10:
    _g_PlayerPowerFruitInventoryFlags = _g_PlayerPowerFruitInventoryFlags | 0x10;
    if (_g_PlayerHeroMode == 2) {
      PlayAudioById(0x25,0,0);
    }
    else {
      PlayAudioById(0x67,0,0);
    }
    goto switchD_0044aa9e_caseD_3;
  case 0x14:
    PlayAudioById(0x44a,0,0);
    uVar1 = *(ushort *)(&DAT_004f05b4 + g_LevelTransitionContext._1_1_ * 2);
    uVar6 = (uint)(char)((uint)g_HudCountdownBcdTime >> 8);
    uVar7 = uVar6 & 0x8000000f;
    if ((int)uVar7 < 0) {
      uVar7 = (uVar7 - 1 | 0xfffffff0) + 1;
    }
    uVar4 = (uint)(char)((uint)g_HudCountdownBcdTime >> 0x10);
    iStack_c = uVar7 + ((int)(uVar6 + ((int)uVar6 >> 0x1f & 0xfU)) >> 4) * 10;
    uVar6 = uVar4 & 0x8000000f;
    if ((int)uVar6 < 0) {
      uVar6 = (uVar6 - 1 | 0xfffffff0) + 1;
    }
    iVar5 = uVar6 + ((int)(uVar4 + ((int)uVar4 >> 0x1f & 0xfU)) >> 4) * 10;
    uVar6 = (uint)(char)g_HudCountdownBcdTime;
    uVar7 = uVar6 & 0x8000000f;
    if ((int)uVar7 < 0) {
      uVar7 = (uVar7 - 1 | 0xfffffff0) + 1;
    }
    iVar8 = uVar7 + (((uVar1 & 0xff) >> 4) + ((int)(uVar6 + ((int)uVar6 >> 0x1f & 0xfU)) >> 4)) * 10
            + (uVar1 & 0xf);
    if (DAT_00533fee < iVar8) {
      iStack_c = iStack_c + 1;
      iVar8 = iVar8 - DAT_00533fee;
    }
    bStack_7 = (byte)(uVar1 >> 8);
    iVar9 = (bStack_7 & 0x8000000f) + iStack_c + (uint)(bStack_7 >> 4) * 10;
    if (0x3b < iVar9) {
      iVar5 = iVar5 + 1;
      iVar9 = iVar9 + -0x3c;
    }
    if (0x3b < iVar5) {
      iVar5 = iVar5 + -0x3c;
    }
    g_HudCountdownBcdTime =
         ((char)((((char)(iVar5 / 10) + (char)(iVar5 >> 0x1f)) -
                 (char)((longlong)iVar5 * 0x66666667 >> 0x3f)) * '\x10' + (char)(iVar5 % 10)) *
          0x100 + (int)(char)((((char)(iVar9 / 10) + (char)(iVar9 >> 0x1f)) -
                              (char)((longlong)iVar9 * 0x66666667 >> 0x3f)) * '\x10' +
                             (char)(iVar9 % 10))) * 0x100 +
         (int)(char)((((char)(iVar8 / 10) + (char)(iVar8 >> 0x1f)) -
                     (char)((longlong)iVar8 * 0x66666667 >> 0x3f)) * '\x10' + (char)(iVar8 % 10));
    goto switchD_0044aa9e_caseD_3;
  }
  g_PowerFruitPickupFlashTicks = 0x3c;
  PlayAudioById(0x26,0,0);
switchD_0044aa9e_caseD_3:
  CEntities__SpawnRuntimeEntryByTypeAtPosition
            (*(undefined4 *)(iVar2 + 0x14),*(undefined4 *)(iVar2 + 0x18),
             *(undefined4 *)(iVar2 + 0x1c),0x14,0x11);
  CEntities__ReleaseRuntimeEntryAndMarkDescriptorConsumed(param_1);
  return;
}

