/*
State 0x2B Update: CPlayerHero::UpdateYoungClimbableWallIdle
Address: 0x0048F8E0
*/


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero__UpdateYoungClimbableWallIdle(void)

{
  undefined2 uVar1;
  
  CPlayerHero_UpdateMovementAndCollision(1);
  CPlayerHero_AdvanceAnimationScript();
  uVar1 = g_PlayerActionState;
  if ((_g_PlayerSequenceFlags & 0xf000) == 0) {
    if ((g_PlayerInputPressedMask & 0x200000) != 0) {
      g_PlayerActionState = 0x2e;
      g_PreviousPlayerActionState = uVar1;
      /* table enter state 0x2E -> CPlayerHero::EnterYoungClimbableSurfaceJumpOff */
      CPlayerHero__EnterYoungClimbableSurfaceJumpOff();
      return;
    }
    if (((byte)g_PlayerInputHeldMask & 0x10) == 0) {
      if (((byte)g_PlayerInputHeldMask & 0x40) != 0) {
        g_PlayerActionState = 0x2d;
        g_PreviousPlayerActionState = uVar1;
        /* table enter state 0x2D -> CPlayerHero::EnterYoungClimbableWallMoveUp */
        CPlayerHero__EnterYoungClimbableWallMoveUp();
        return;
      }
    }
    else {
      if (0x37 < *(int *)(g_PlayerSceneEntryData + 0xc) - g_PlayerInteractionCollisionBaseY) {
        g_PlayerActionState = 0x2c;
        g_PreviousPlayerActionState = uVar1;
        /* table enter state 0x2C -> CPlayerHero::EnterYoungClimbableWallMoveDown */
        CPlayerHero__EnterYoungClimbableWallMoveDown();
        return;
      }
      *(int *)(g_PlayerSceneEntryData + 0xc) = g_PlayerInteractionCollisionBaseY;
      uVar1 = g_PlayerActionState;
      if ((*(byte *)(g_PlayerLatchedInteractionCollisionSurface + 0x14) & 0x20) != 0) {
        g_PlayerActionState = 0x2b;
        g_PreviousPlayerActionState = uVar1;
        /* table enter state 0x2B -> CPlayerHero::EnterYoungClimbableWallIdle */
        CPlayerHero__EnterYoungClimbableWallIdle();
        return;
      }
    }
  }
  return;
}

