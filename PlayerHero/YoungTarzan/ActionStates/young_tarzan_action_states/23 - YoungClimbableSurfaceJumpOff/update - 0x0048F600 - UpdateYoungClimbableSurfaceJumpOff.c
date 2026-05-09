/*
State 0x23 Update: CPlayerHero::UpdateYoungClimbableSurfaceJumpOff
Address: 0x0048F600
Source: C:\Users\Proxi\TarzanREVERSEDCodex\ghidra_export\young_state_forced_all_decomp\0048F600_CPlayerHero__UpdateYoungClimbableSurfaceJumpOff.c
*/


void CPlayerHero__UpdateYoungClimbableSurfaceJumpOff(void)

{
  undefined2 uVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = CPlayerHero__AdvanceAnimationScript();
  if (iVar3 == 8) {
    *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0x30;
    g_PlayerTargetMoveSpeed = 0x30;
    *(undefined4 *)(g_PlayerMotionState + 0x10) = 0x18;
    *(undefined4 *)(g_PlayerMotionState + 0x18) = 4;
    *(undefined4 *)(g_PlayerMotionState + 0x14) = 2;
    *(undefined4 *)(g_PlayerMotionState + 0x20) = 0x10;
    *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0x60;
    *(undefined4 *)(g_PlayerMotionState + 0x24) = 4;
    *(undefined1 *)(g_PlayerMotionState + 0xd) = 0;
  }
  else if (((iVar3 == 0xe) && (DAT_0051cda0 != 0)) &&
          ((*(uint *)(DAT_0051cda0 + 0x14) & 0xc000) != 0)) {
    uVar4 = (uint)*(ushort *)(DAT_0051cda0 + 0x18);
    iVar3 = *(int *)(g_CollisionSurfaceTable + 4 + uVar4 * 4) + 0x34 +
            ((uint)*(ushort *)(DAT_0051cda0 + 0x1a) * 7 + uVar4) * 4 + g_CollisionSurfaceTable;
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
    g_PlayerActionState = 9;
    g_PreviousPlayerActionState = uVar1;
    /* table enter state 0x09 -> CPlayerHero::EnterYoungLandingRecovery */
  CPlayerHero__EnterYoungLandingRecovery();
    return;
  }
  return;
}


