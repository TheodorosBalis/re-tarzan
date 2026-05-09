/*
State 0x22 Update: CPlayerHero::UpdateYoungClimbableEdgePullUp
Address: 0x0048F480
*/


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero__UpdateYoungClimbableEdgePullUp(void)

{
  undefined2 uVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  
  CPlayerHero_UpdateMovementAndCollision(1);
  cVar2 = CPlayerHero_TrySnapToNearbyGround();
  uVar1 = g_PlayerActionState;
  if (cVar2 == '\0') {
    g_PlayerActionState = 7;
    g_PreviousPlayerActionState = uVar1;
    /* table enter state 0x07 -> CPlayerHero::EnterYoungTarzanFalling */
    CPlayerHero__EnterYoungTarzanFalling();
  }
  iVar3 = CPlayerHero_AdvanceAnimationScript();
  uVar1 = g_PlayerActionState;
  if (iVar3 == 7) {
    if ((_g_PlayerSequenceFlags & 0xf000) == 0) {
      if (g_PlayerCurrentCollisionMode != 0) {
        if (g_PlayerCurrentCollisionMode < 3) {
          cVar2 = CPlayerHero_IsFacingCurrentCollisionSurface();
          uVar1 = g_PlayerActionState;
          if (((cVar2 == '\0') && ((g_CameraFollowFlags & g_PlayerInputHeldMask) != 0)) &&
             (g_PlayerCollisionFacingFlags == '\0')) {
            g_PlayerActionState = 1;
            g_PreviousPlayerActionState = uVar1;
            /* table enter state 0x01 -> CPlayerHero::EnterYoungTarzanMoveForward */
            CPlayerHero__EnterYoungTarzanMoveForward();
            return;
          }
        }
        else if ((g_PlayerCurrentCollisionMode == 5) && (g_PlayerCollisionFacingFlags == '\0')) {
          g_PlayerActionState = 0xe;
          g_PreviousPlayerActionState = uVar1;
          /* table enter state 0x0E -> CPlayerHero::EnterYoungTouchSurfaceOnSurfing */
          CPlayerHero__EnterYoungTouchSurfaceOnSurfing();
          return;
        }
      }
    }
  }
  else if (iVar3 == 8) {
    iVar3 = *(int *)(g_PlayerSceneEntry + 0x110) * 4 + 4;
    uVar4 = ProjectWorldPositionToJungleSurfaceCoord
                      (g_PlayerSceneEntry + 0x14,
                       *(int *)(iVar3 + g_JungleSurfaceTableBase) + iVar3 + g_JungleSurfaceTableBase
                      );
    *(undefined4 *)(g_PlayerSceneEntry + 0x10c) = uVar4;
    MoveSceneEntryWithCollision(0,0,g_PlayerSceneEntry);
    *(int *)(g_PlayerSceneEntryData + 8) =
         *(int *)(g_PlayerSceneEntryData + 8) + *(int *)(g_PlayerSceneEntry + 0x54);
    *(int *)(g_PlayerSceneEntryData + 0xc) =
         *(int *)(g_PlayerSceneEntryData + 0xc) + *(int *)(g_PlayerSceneEntry + 0x58);
    *(int *)(g_PlayerSceneEntryData + 0x10) =
         *(int *)(g_PlayerSceneEntryData + 0x10) + *(int *)(g_PlayerSceneEntry + 0x5c);
  }
  return;
}

