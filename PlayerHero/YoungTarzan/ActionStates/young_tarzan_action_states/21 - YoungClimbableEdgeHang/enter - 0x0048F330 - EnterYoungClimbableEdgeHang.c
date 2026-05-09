/*
State 0x21 Enter: CPlayerHero::EnterYoungClimbableEdgeHang
Address: 0x0048F330
Source: C:\Users\Proxi\TarzanREVERSEDCodex\ghidra_export\young_state_forced_all_decomp\0048F330_CPlayerHero__EnterYoungClimbableEdgeHang.c
*/


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero__EnterYoungClimbableEdgeHang(void)

{
  undefined2 uVar1;
  
  uVar1 = g_PlayerActionState;
  if (((_g_PlayerSequenceFlags & 0xf000) == 0) &&
     (((g_CameraFollowFlags | 0x10) & g_PlayerInputHeldMask) != 0)) {
    g_PlayerActionState = 0x22;
    g_PreviousPlayerActionState = uVar1;
    /* table enter state 0x22 -> CPlayerHero::EnterYoungClimbableEdgePullUp */
  CPlayerHero__EnterYoungClimbableEdgePullUp();
    return;
  }
  if (*(char *)(g_PlayerSceneEntry + 0x75) == '\0') {
    CPlayerHero__PlayAnimation(0x6f);
    return;
  }
  CPlayerHero__PlayAnimation(0x6b);
  return;
}


