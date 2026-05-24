/*
State 0x14 Update: CPlayerHero::UpdateTerkClimbableSurfaceGrab
Address: 0x00479920
*/


void CPlayerHero__UpdateTerkClimbableSurfaceGrab(void)

{
  undefined2 uVar1;
  char cVar2;
  
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


