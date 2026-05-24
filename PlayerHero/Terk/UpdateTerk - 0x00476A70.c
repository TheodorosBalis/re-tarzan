/*
Terk action-state dispatcher: CPlayerHero::UpdateTerk
Address: 0x00476A70
Table: 0x0050C148 g_TerkActionStateHandlerTable
Update column: 0x0050C14C
*/


void CPlayerHero__UpdateTerk(void)

{
  char cVar1;
  
  if (g_PlayerActionState != 0x10) {
    if (DAT_0051ce60 < 0) {
      DAT_0051ce60 = DAT_0051ce60 + 1;
    }
    else if ((g_PlayerEdgeBalanceInputMask & g_PlayerInputHeldMask) != 0) {
      g_PreviousPlayerActionState = g_PlayerActionState;
      g_PlayerActionState = 0x10;
      (*(code *)PTR_CPlayerHero__EnterTerkEdgeBalance_0050c1c8)();
    }
  }
  if (g_PlayerCurrentCollisionMode == 2) {
    cVar1 = ShouldMirrorCameraFollowSideForActiveAnchor();
    if (cVar1 == '\0') {
      g_CameraRelativeTurnInputMask = 0x20;
      g_CameraFollowFlags = 0x80;
    }
    else {
      g_CameraRelativeTurnInputMask = 0x80;
      g_CameraFollowFlags = 0x20;
    }
  }
  else {
    g_CameraRelativeTurnInputMask = 0xa0;
    g_CameraFollowFlags = 0x10;
  }
  CPlayerHero__RefreshClimbableEdgeCollisionContext();
  g_InputPreviousMask = g_InputPreviousMask & ~(uint)g_CameraFollowFlags;
  (*(code *)(&PTR_CPlayerHero__UpdateTerkIdle_0050c14c)[(uint)g_PlayerActionState * 2])();
  CPlayerHero__UpdateSceneEntryFacingAngles();
  if (g_PlayerActionState == 0) {
    DAT_0051cdcc = DAT_0051cdcc + 1;
    return;
  }
  DAT_0051cdcc = 0;
  return;
}



