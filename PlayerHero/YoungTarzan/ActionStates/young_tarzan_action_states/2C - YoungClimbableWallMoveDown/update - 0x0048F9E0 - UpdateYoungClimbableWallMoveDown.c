/*
State 0x2C Update: CPlayerHero::UpdateYoungClimbableWallMoveDown
Address: 0x0048F9E0
Source: C:\Users\Proxi\TarzanREVERSEDCodex\ghidra_export\young_state_forced_all_decomp\0048F9E0_CPlayerHero__UpdateYoungClimbableWallMoveDown.c
*/


void CPlayerHero__UpdateYoungClimbableWallMoveDown(void)

{
  undefined2 uVar1;
  int iVar2;
  
  CPlayerHero__UpdateMovementAndCollision(1);
  iVar2 = CPlayerHero__AdvanceAnimationScript();
  if (iVar2 == 8) {
    *(int *)(g_PlayerSceneEntryData + 0xc) = *(int *)(g_PlayerSceneEntryData + 0xc) + -0x70;
    uVar1 = g_PlayerActionState;
    if (*(int *)(g_PlayerSceneEntryData + 0xc) - g_PlayerInteractionCollisionBaseY < 0x38) {
      *(int *)(g_PlayerSceneEntryData + 0xc) = g_PlayerInteractionCollisionBaseY;
      g_PreviousPlayerActionState = g_PlayerActionState;
      if ((*(byte *)(DAT_0051cda0 + 0x14) & 0x20) != 0) {
        g_PlayerActionState = 0x2b;
        /* table enter state 0x2B -> CPlayerHero::EnterYoungClimbableWallIdle */
  CPlayerHero__EnterYoungClimbableWallIdle();
        return;
      }
      g_PlayerActionState = 0x20;
      /* table enter state 0x20 -> CPlayerHero::EnterYoungClimbableEdgeGrab */
  CPlayerHero__EnterYoungClimbableEdgeGrab();
      return;
    }
    if (((byte)g_PlayerInputHeldMask & 0x10) == 0) {
      g_PlayerActionState = 0x2b;
      g_PreviousPlayerActionState = uVar1;
      /* table enter state 0x2B -> CPlayerHero::EnterYoungClimbableWallIdle */
  CPlayerHero__EnterYoungClimbableWallIdle();
      return;
    }
  }
  return;
}


