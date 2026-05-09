// 0x0048cb00

void CPlayerHero_UpdateYoungTarzan(void)

{
  char cVar1;
  
  if ((DAT_0051ce7c & 0x4000) != 0) {
    DAT_0053a2a8 = g_PlayerInputPressedMask & 0x4000;
    if ((g_PlayerInputPressedMask & 0x80) != 0) {
      g_InputPreviousMask = g_InputPreviousMask & 0xffffff7f;
    }
    if ((g_PlayerInputPressedMask & 0x20) != 0) {
      g_InputPreviousMask = g_InputPreviousMask & 0xffffffdf;
    }
  }
  if (g_PlayerActionState != 0xd) {
    if (DAT_0051ce60 < 0) {
      DAT_0051ce60 = DAT_0051ce60 + 1;
    }
    else if (((g_PlayerInputHeldMask & g_PlayerPowerFruitActionInputMask) != 0) &&
            (DAT_0051ce7c == 0)) {
      g_PreviousPlayerActionState = g_PlayerActionState;
      g_PlayerActionState = 0xd;
      (*(code *)PTR_CPlayerHero_EnterYoungEdgeBalance_00514940)();
    }
  }
  switch(g_PlayerCurrentCollisionMode) {
  case 0:
    goto switchD_0048cb94_caseD_0;
  case 1:
    CPlayerHero_BuildCameraRelativeInputMasks();
    break;
  case 2:
    cVar1 = ShouldMirrorCameraFollowSideForActiveAnchor();
    if (cVar1 == '\0') {
      g_CameraRelativeTurnInputMask = 0x20;
      g_CameraFollowFlags = 0x90;
    }
    else {
      g_CameraRelativeTurnInputMask = 0x80;
      g_CameraFollowFlags = 0x30;
    }
    break;
  default:
    g_CameraRelativeTurnInputMask = 0xa0;
    g_CameraFollowFlags = 0x10;
  }
  CPlayerHero_RefreshClimbableEdgeCollisionContext();
switchD_0048cb94_caseD_0:
  (**(code **)(&g_YoungTarzanActionStateUpdateColumn + (uint)g_PlayerActionState * 8))();
  CPlayerHero_UpdateSceneEntryFacingAngles();
  return;
}