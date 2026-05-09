/*
State 0x1D Update: CPlayerHero::UpdateYoungSwingToClimbableSurface
Address: 0x00492C00
*/


void CPlayerHero__UpdateYoungSwingToClimbableSurface(void)

{
  undefined2 uVar1;
  int iVar2;
  
  uVar1 = g_PlayerActionState;
  if ((g_PlayerInputHeldMask & 0x200000) != 0) {
    g_PlayerActionState = 7;
    g_PreviousPlayerActionState = uVar1;
    /* table enter state 0x07 -> CPlayerHero::EnterYoungTarzanFalling */
  CPlayerHero__EnterYoungTarzanFalling();
    return;
  }
  iVar2 = CPlayerHero__AdvanceAnimationScript();
  if (iVar2 == 8) {
    DAT_0051ce80 = DAT_0051ce80 + 1;
    CPlayerHero__SnapToCurrentJungleSurface();
    if ((g_PlayerCurrentCollisionSurface == 0) ||
       ((*(byte *)(g_PlayerCurrentCollisionSurface + 0x14) & 0x20) == 0)) goto LAB_00492d2b;
    if (2 < DAT_0051ce80) {
      if (DAT_0051ce40 == '\0') {
        CPlayerHero__PlayAnimation(0x55);
        CPlayerHero__UpdateMovementAndCollision(1);
        return;
      }
LAB_00492cf7:
      CPlayerHero__PlayAnimation(0x59);
      CPlayerHero__UpdateMovementAndCollision(1);
      return;
    }
  }
  else {
    if (iVar2 != 0xc) goto LAB_00492d2b;
    if ((g_PlayerInputHeldMask & g_CameraRelativeTurnInputMask) != 0) {
      if (DAT_0051ce40 == '\0') {
        CPlayerHero__PlayAnimation(0x5d);
        CPlayerHero__UpdateMovementAndCollision(1);
        return;
      }
      CPlayerHero__PlayAnimation(0x5e);
      CPlayerHero__UpdateMovementAndCollision(1);
      return;
    }
    if ((g_PlayerInputHeldMask & g_CameraFollowFlags) != 0) goto LAB_00492d2b;
    if (2 < DAT_0051ce80) {
      if (DAT_0051ce40 == '\0') {
        CPlayerHero__PlayAnimation(0x55);
        CPlayerHero__UpdateMovementAndCollision(1);
        return;
      }
      goto LAB_00492cf7;
    }
  }
  if (DAT_0051ce40 == '\0') {
    CPlayerHero__PlayAnimation(0x56);
    CPlayerHero__UpdateMovementAndCollision(1);
    return;
  }
  CPlayerHero__PlayAnimation(0x5a);
LAB_00492d2b:
  CPlayerHero__UpdateMovementAndCollision(1);
  return;
}


