/*
State 0x14 Enter: CPlayerHero::EnterTerkClimbableSurfaceGrab
Address: 0x00479870
*/


void CPlayerHero__EnterTerkClimbableSurfaceGrab(void)

{
  undefined2 uVar1;
  char cVar2;
  
  g_PlayerCurrentAnimationId = 0x2f;
  *(undefined **)(g_PlayerAnimationState + 0xc) = PTR_DAT_0050c2fc;
  *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
  *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  CPlayerHero__AdvanceAnimationScript();
  g_PlayerLatchedInteractionCollisionSurface = g_PlayerInteractionCollisionSurface;
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
    g_PlayerActionState = 10;
    g_PreviousPlayerActionState = uVar1;
    (*(code *)PTR_CPlayerHero__EnterTerkFalling_0050c198)();
  }
  CPlayerHero__AdvanceAnimationScript();
  return;
}


