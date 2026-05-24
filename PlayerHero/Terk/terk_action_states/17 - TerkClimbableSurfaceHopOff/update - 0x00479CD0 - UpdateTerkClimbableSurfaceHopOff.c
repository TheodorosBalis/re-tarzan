/*
State 0x17 Update: CPlayerHero::UpdateTerkClimbableSurfaceHopOff
Address: 0x00479CD0
*/


void CPlayerHero__UpdateTerkClimbableSurfaceHopOff(void)

{
  undefined2 uVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = CPlayerHero__AdvanceAnimationScript();
  if (iVar3 == 8) {
    *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0x80;
    g_PlayerTargetMoveSpeed = 0x80;
    *(undefined4 *)(g_PlayerMotionState + 0x10) = 0x40;
    *(undefined4 *)(g_PlayerMotionState + 0x18) = 8;
    *(undefined4 *)(g_PlayerMotionState + 0x14) = 2;
    *(undefined4 *)(g_PlayerMotionState + 0x20) = 8;
    *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0xf0;
    *(undefined4 *)(g_PlayerMotionState + 0x24) = 8;
    *(undefined1 *)(g_PlayerMotionState + 0xd) = 0;
  }
  else if (((iVar3 == 0xe) && (g_PlayerLatchedInteractionCollisionSurface != 0)) &&
          ((*(uint *)(g_PlayerLatchedInteractionCollisionSurface + 0x14) & 0xc000) != 0)) {
    uVar4 = (uint)*(ushort *)(g_PlayerLatchedInteractionCollisionSurface + 0x18);
    iVar3 = *(int *)(g_CollisionSurfaceTable + 4 + uVar4 * 4) + 0x34 +
            ((uint)*(ushort *)(g_PlayerLatchedInteractionCollisionSurface + 0x1a) * 7 + uVar4) * 4 +
            g_CollisionSurfaceTable;
    *(uint *)(g_PlayerSceneEntry + 0x110) = uVar4;
    if ((*(uint *)(iVar3 + 0x14) & 0x2000) == 0) {
      *(undefined4 *)(g_PlayerSceneEntry + 0x10c) = *(undefined4 *)(iVar3 + 0xc);
    }
    else {
      *(int *)(g_PlayerSceneEntry + 0x10c) = *(int *)(iVar3 + 0xc) + -1;
    }
  }
  CPlayerHero__UpdateJumpArcVerticalMotion(0);
  CPlayerHero__UpdateRunInputAndMovement();
  cVar2 = CPlayerHero__TryResolveGroundContactSnap();
  uVar1 = g_PlayerActionState;
  if (cVar2 != '\0') {
    g_PlayerActionState = 0xc;
    g_PreviousPlayerActionState = uVar1;
                    /* WARNING: Could not recover jumptable at 0x00479dee. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_CPlayerHero__EnterTerkLandingRecovery_0050c1a8)();
    return;
  }
  return;
}


