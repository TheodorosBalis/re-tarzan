// 0x00432e60
void CPlayerHero_Update(void)

{
  short sVar1;
  int iVar2;
  
  if ((g_PlayerAnimationState != 0 && g_PlayerMotionState != 0) && g_PlayerSceneEntry != 0) {
    if ((_g_PlayerSequenceFlags & 0x8000) != 0) {
      if (g_PlayerSequenceDelayTicks == 0) {
        g_LoadTransitionFlags._0_2_ = 0x8040;
      }
      else {
        g_PlayerSequenceDelayTicks = g_PlayerSequenceDelayTicks + -1;
      }
    }
    if ((_g_PlayerSequenceFlags & 0xf000) == 0) {
      ProcessPlayerDamageAndDeath();
      g_PlayerSurfaceTriggerPacket = g_PlayerSurfaceTriggerPacket & 0xf000ffff;
      g_PendingPlayerDamage = 0;
      if ((DAT_00534010 & 0x80000000) != 0) {
        if (((byte)g_PlayerInputPressedMask & 1) != 0) {
          RespawnAndReinitializeGameplayWorld();
        }
        if (((DAT_00534010 & 0x10) != 0) && ((g_SecondaryInputHeldMask & 0x400) != 0)) {
          _g_PlayerSequenceFlags = _g_PlayerSequenceFlags | 0x8000;
          g_PlayerSequenceDelayTicks = 0;
        }
        if (((DAT_00534010 & 0x20) != 0) && ((g_SecondaryInputHeldMask & 0x800) != 0)) {
          _g_PlayerSequenceFlags = _g_PlayerSequenceFlags | 0x4000;
          g_LoadTransitionFlags._0_2_ = 0x8001;
        }
      }
    }
    else {
      g_PlayerInputHeldMask = g_PlayerInputHeldMask & 0xffff0000;
    }
    UpdateSelectedPowerFruitTypeFromInput();
    DAT_0051cd94 = 0;
    if (DAT_0051cdfc != 0) {
      *(undefined2 *)(DAT_0051cdfc + 0xe) = 0;
    }
    switch(_g_PlayerHeroMode) {
    case 1:
    case 3:
      CPlayerHero_UpdateAdultTarzan();
      break;
    case 2:
      CPlayerHero_UpdateYoungTarzan();
      break;
    case 4:
      CPlayerHero_UpdateJane();
      break;
    case 5:
      CPlayerHero_UpdateTarzanSurfingWithJane();
      break;
    case 6:
      CPlayerHero_UpdateTerk();
      break;
    case 7:
      CPlayerHero_UpdateAdultTarzanOnElephant();
      break;
    case 8:
      CPlayerHero_UpdateYoungTarzanOnStork();
      break;
    case 9:
      CPlayerHero_UpdateStampedeYoungTarzan();
      break;
    case 10:
      CPlayerHero_UpdateJaneElephantKerchakChase();
      break;
    case 0xb:
    case 0xc:
      CPlayerHero_UpdateYoungTarzanOrTerkLeafSwimming();
    }
    g_PlayerDamageContactSceneEntry = 0;
    g_PlayerSpecialAttachmentEntry = FindPlayerSpecialAttachmentEntry();
    UpdatePlayerSpecialAttachmentPosition();
    sVar1 = g_LastProcessedSurfaceTriggerPacket;
    if ((short)g_PlayerSurfaceTriggerPacket != g_LastProcessedSurfaceTriggerPacket) {
      if ((g_PlayerSurfaceTriggerPacket & 0xc000) != 0) {
        CPlayerHero_ApplySurfaceResourceTrigger(g_PlayerSurfaceTriggerPacket);
      }
      sVar1 = (short)g_PlayerSurfaceTriggerPacket;
      if ((g_PlayerSurfaceTriggerPacket & 0x2000) != 0) {
        SelectBackgroundMusicTrackForLevel(g_PlayerSurfaceTriggerPacket & 0xff);
        sVar1 = (short)g_PlayerSurfaceTriggerPacket;
      }
    }
    g_LastProcessedSurfaceTriggerPacket = sVar1;
    if ((_g_PlayerSequenceFlags & 0x2000) == 0) {
      iVar2 = GetSceneAttachmentWorldPositionByMask
                        (g_PlayerSceneEntry,0x80,&g_CameraOverrideTargetX);
      DAT_0051cd1c = 0;
      g_CameraOverrideTargetPtr = -(uint)(iVar2 != 0) & 0x51ce08;
    }
    if (DAT_0051ce62 == '\0') {
      iVar2 = GetSceneAttachmentWorldPositionByMask(g_PlayerSceneEntry,0x20,&DAT_0051ce18);
      DAT_0051ce58 = -(uint)(iVar2 != 0) & 0x51ce18;
    }
    else {
      DAT_0051ce58 = 0;
    }
    g_PlayerSurfaceTriggerPacket = g_PlayerSurfaceTriggerPacket & 0xf00ffff;
    DAT_0051ce5c = DAT_00531d3c;
    DAT_00531d3c = 0;
  }
  return;
}