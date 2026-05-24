/*
State 0x16 Update: CPlayerHero::UpdateTerkClimbableSurfacePullUp
Address: 0x00479B80
*/


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero__UpdateTerkClimbableSurfacePullUp(void)

{
  undefined2 uVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  
  CPlayerHero__UpdateMovementAndCollision(1);
  cVar2 = CPlayerHero__TrySnapToNearbyGround();
  uVar1 = g_PlayerActionState;
  if (cVar2 == '\0') {
    g_PlayerActionState = 10;
    g_PreviousPlayerActionState = uVar1;
    (*(code *)PTR_CPlayerHero__EnterTerkFalling_0050c198)();
  }
  iVar3 = CPlayerHero__AdvanceAnimationScript();
  if (iVar3 == 7) {
    if (((_g_PlayerSequenceFlags & 0xf000) == 0) && (g_PlayerCurrentCollisionMode == 2)) {
      cVar2 = CPlayerHero__IsFacingCurrentCollisionSurface();
      uVar1 = g_PlayerActionState;
      if ((cVar2 == '\0') &&
         (((g_CameraFollowFlags & g_PlayerInputHeldMask) != 0 &&
          (g_PlayerCollisionFacingFlags == '\0')))) {
        g_PlayerActionState = 1;
        g_PreviousPlayerActionState = uVar1;
                    /* WARNING: Could not recover jumptable at 0x00479c47. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)PTR_CPlayerHero__EnterTerkMoveForward_0050c150)();
        return;
      }
    }
  }
  else if (iVar3 == 8) {
    iVar3 = *(int *)(g_PlayerSceneEntry + 0x110) * 4 + 4;
    uVar4 = ProjectWorldPositionToJungleSurfaceCoord
                      (g_PlayerSceneEntry + 0x14,
                       *(int *)(iVar3 + g_CollisionSurfaceTable) + iVar3 + g_CollisionSurfaceTable);
    *(undefined4 *)(g_PlayerSceneEntry + 0x10c) = uVar4;
  }
  return;
}


