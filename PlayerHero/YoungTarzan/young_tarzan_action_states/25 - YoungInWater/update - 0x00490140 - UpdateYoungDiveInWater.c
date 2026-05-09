/*
State 0x25 Update: CPlayerHero::UpdateYoungDiveInWater
Address: 0x00490140
*/


void CPlayerHero__UpdateYoungDiveInWater(void)

{
  int iVar1;
  undefined4 uStack_c;
  uint uStack_8;
  undefined4 uStack_4;
  
  if (g_PlayerAirMovePitchAngle != 0) {
    uStack_4 = 0xfffffe00;
    uStack_8 = (uint)g_PlayerAirMovePitchAngle;
    uStack_c = 0x49015b;
    iVar1 = GetWrappedSignedAngleDelta12Bit();
    if ((iVar1 >> 4 ^ iVar1 >> 0x1f) - (iVar1 >> 0x1f) < 2) {
      g_PlayerAirMovePitchAngle = 0;
    }
    else {
      g_PlayerAirMovePitchAngle = g_PlayerAirMovePitchAngle + (short)(iVar1 >> 4);
    }
  }
  uStack_4 = 1;
  uStack_8 = 0x490188;
  CPlayerHero_UpdateMovementAndCollision();
  uStack_4 = 0x490190;
  CPlayerHero_AdvanceAnimationScript();
  iVar1 = GetSceneAttachmentWorldPositionByMask(g_PlayerSceneEntry,0x100,&uStack_c);
  if (iVar1 != 0) {
    InstantiateRuntimeEntryByTypeAtPosition
              (uStack_c,*(undefined4 *)(g_PlayerSceneEntryData + 0xc),uStack_4,0x7d,0x11);
    InstantiateRuntimeEntryByTypeAtPosition
              (uStack_c,*(undefined4 *)(g_PlayerSceneEntryData + 0xc),uStack_4,0x7e,0x11);
  }
  iVar1 = GetSceneAttachmentWorldPositionByMask(g_PlayerSceneEntry,0x200,&uStack_c);
  if (iVar1 != 0) {
    InstantiateRuntimeEntryByTypeAtPosition
              (uStack_c,*(undefined4 *)(g_PlayerSceneEntryData + 0xc),uStack_4,0x7d,0x11);
    InstantiateRuntimeEntryByTypeAtPosition
              (uStack_c,*(undefined4 *)(g_PlayerSceneEntryData + 0xc),uStack_4,0x7e,0x11);
  }
  iVar1 = GetSceneAttachmentWorldPositionByMask(g_PlayerSceneEntry,0x400,&uStack_c);
  if (iVar1 != 0) {
    InstantiateRuntimeEntryByTypeAtPosition
              (uStack_c,*(undefined4 *)(g_PlayerSceneEntryData + 0xc),uStack_4,0x7d,0x11);
    InstantiateRuntimeEntryByTypeAtPosition
              (uStack_c,*(undefined4 *)(g_PlayerSceneEntryData + 0xc),uStack_4,0x7e,0x11);
  }
  iVar1 = GetSceneAttachmentWorldPositionByMask(g_PlayerSceneEntry,0x800,&uStack_c);
  if (iVar1 != 0) {
    InstantiateRuntimeEntryByTypeAtPosition
              (uStack_c,*(undefined4 *)(g_PlayerSceneEntryData + 0xc),uStack_4,0x7d,0x11);
    InstantiateRuntimeEntryByTypeAtPosition
              (uStack_c,*(undefined4 *)(g_PlayerSceneEntryData + 0xc),uStack_4,0x7e,0x11);
  }
  return;
}

