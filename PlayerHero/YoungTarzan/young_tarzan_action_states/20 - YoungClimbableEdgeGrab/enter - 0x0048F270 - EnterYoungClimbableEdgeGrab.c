/*
State 0x20 Enter: CPlayerHero::EnterYoungClimbableEdgeGrab
Address: 0x0048F270
*/


void CPlayerHero__EnterYoungClimbableEdgeGrab(void)

{
  undefined2 uVar1;
  char cVar2;
  
  CPlayerHero__PlayAnimation(0x6a);
  DAT_0051cda0 = g_PlayerInteractionCollisionSurface;
  *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
  g_PlayerTargetMoveSpeed = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x24) = 0;
  DAT_0051ce80 = 0;
  *(undefined1 *)(g_PlayerMotionState + 0xd) = 0;
  CPlayerHero__UpdateMovementAndCollision(1);
  cVar2 = CPlayerHero__TrySnapToNearbyGround();
  uVar1 = g_PlayerActionState;
  if (cVar2 == '\0') {
    g_PlayerActionState = 7;
    g_PreviousPlayerActionState = uVar1;
    /* table enter state 0x07 -> CPlayerHero::EnterYoungTarzanFalling */
  CPlayerHero__EnterYoungTarzanFalling();
  }
  CPlayerHero__AdvanceAnimationScript();
  return;
}


