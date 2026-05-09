/*
State 0x37 Update: CPlayerHero::UpdateYoungTarzanAndTerkTutorialPickupSequence
Address: 0x00490780
Source: C:\Users\Proxi\TarzanREVERSEDCodex\ghidra_export\young_state_forced_all_decomp\00490780_CPlayerHero__UpdateYoungTarzanAndTerkTutorialPickupSequence.c
*/


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero__UpdateYoungTarzanAndTerkTutorialPickupSequence(void)

{
  ushort uVar1;
  undefined2 uVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  
  uVar2 = g_PlayerActionState;
  g_PlayerDamageInvulnerabilityTicks = 0x3c;
  if (DAT_0053a2e8 == 5) {
    g_PlayerActionState = 0x3e;
    g_PreviousPlayerActionState = uVar2;
    /* table enter state 0x3E -> CPlayerHero::EnterYoungTutorialPickupReturnIdle */
  CPlayerHero__EnterYoungTutorialPickupReturnIdle();
    *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0;
    *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
    CPlayerHero__UpdateMovementAndCollision(1);
    return;
  }
  switch(g_PlayerActionState) {
  case 0x37:
    goto LAB_00490865;
  case 0x38:
    *(byte *)(g_PlayerGroundShadowProbeSceneEntry + 0xf) =
         *(byte *)(g_PlayerGroundShadowProbeSceneEntry + 0xf) | 0x80;
    if (DAT_0053a2a8 != 0) {
      g_PlayerActionState = 0x39;
      CPlayerHero__PlayAnimation(0xa1);
      return;
    }
    *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0x20;
    *(undefined4 *)(g_PlayerMotionState + 0x10) = 0x20;
    CPlayerHero__UpdateMovementAndCollision(1);
    uVar2 = g_PlayerActionState;
    if (g_PlayerCollisionFacingFlags != '\x01') goto LAB_00490d30;
    g_PlayerActionState = 0x3a;
    g_PreviousPlayerActionState = uVar2;
    /* table enter state 0x3A -> CPlayerHero::EnterYoungTutorialPickupFinalPose */
  CPlayerHero__EnterYoungTutorialPickupFinalPose();
LAB_00490865:
    *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0;
    *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
    break;
  case 0x39:
    if (DAT_0051cdf0 == 0xa1) {
      *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0;
      *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
    }
    else {
      *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0x20;
      *(undefined4 *)(g_PlayerMotionState + 0x10) = 0x20;
    }
    CPlayerHero__UpdateMovementAndCollision(1);
    if (g_PlayerCollisionFacingFlags == '\x01') {
      DAT_0053a2e8 = 4;
      iVar5 = *(int *)(DAT_0053a2b4 + 0x38);
      *(undefined4 *)(g_PlayerSceneEntryData + 4) = *(undefined4 *)(iVar5 + 0x14);
      *(undefined4 *)(g_PlayerSceneEntryData + 6) = *(undefined4 *)(iVar5 + 0x18);
      *(undefined4 *)(g_PlayerSceneEntryData + 8) = *(undefined4 *)(iVar5 + 0x1c);
      g_PlayerSceneEntryData[1] = *(undefined2 *)(iVar5 + 0xe);
      *(undefined4 *)(g_PlayerSceneEntry + 0x6c) = *(undefined4 *)(iVar5 + 0x6c);
      *(undefined2 *)(g_PlayerSceneEntry + 0xa0) = *(undefined2 *)(iVar5 + 0xa0);
      _g_PlayerMoveTiltAngle = *(undefined2 *)(g_PlayerSceneEntry + 0xa0);
      *(undefined2 *)(g_PlayerSceneEntry + 0xa2) = *(undefined2 *)(iVar5 + 0xa2);
      g_PlayerMoveHeadingAngle = *(undefined2 *)(g_PlayerSceneEntry + 0xa2);
      *(undefined2 *)(g_PlayerSceneEntry + 0xa4) = *(undefined2 *)(iVar5 + 0xa4);
      *(undefined2 *)(g_PlayerSceneEntry + 0xa6) = *(undefined2 *)(iVar5 + 0xa6);
      *(undefined4 *)(g_PlayerSceneEntry + 0x10c) = *(undefined4 *)(iVar5 + 0x10c);
      *(undefined4 *)(g_PlayerSceneEntry + 0x110) = *(undefined4 *)(iVar5 + 0x110);
      *(undefined4 *)(g_PlayerSceneEntry + 0x110) = *(undefined4 *)(iVar5 + 0x110);
      *(undefined4 *)(g_PlayerSceneEntry + 0x10c) = *(undefined4 *)(iVar5 + 0x10c);
      *(undefined4 *)(g_PlayerSceneEntry + 0x114) = *(undefined4 *)(iVar5 + 0x114);
      *(undefined2 *)(g_PlayerSceneEntry + 0x142) = *(undefined2 *)(iVar5 + 0x142);
      iVar4 = g_PlayerSceneEntry;
      *(undefined4 *)(g_PlayerSceneEntry + 0x14) = *(undefined4 *)(iVar5 + 0x14);
      *(undefined4 *)(iVar4 + 0x18) = *(undefined4 *)(iVar5 + 0x18);
      *(undefined4 *)(iVar4 + 0x1c) = *(undefined4 *)(iVar5 + 0x1c);
      iVar4 = g_PlayerSceneEntry;
      *(undefined4 *)(g_PlayerSceneEntry + 0x3c) = *(undefined4 *)(iVar5 + 0x3c);
      *(undefined4 *)(iVar4 + 0x40) = *(undefined4 *)(iVar5 + 0x40);
      *(undefined4 *)(iVar4 + 0x44) = *(undefined4 *)(iVar5 + 0x44);
      iVar4 = g_PlayerSceneEntry;
      *(undefined4 *)(g_PlayerSceneEntry + 0x48) = *(undefined4 *)(iVar5 + 0x48);
      *(undefined4 *)(iVar4 + 0x4c) = *(undefined4 *)(iVar5 + 0x4c);
      *(undefined4 *)(iVar4 + 0x50) = *(undefined4 *)(iVar5 + 0x50);
      iVar4 = g_PlayerSceneEntry;
      *(undefined4 *)(g_PlayerSceneEntry + 0x54) = *(undefined4 *)(iVar5 + 0x54);
      *(undefined4 *)(iVar4 + 0x58) = *(undefined4 *)(iVar5 + 0x58);
      *(undefined4 *)(iVar4 + 0x5c) = *(undefined4 *)(iVar5 + 0x5c);
      *(int *)(g_PlayerSceneEntryData + 2) = DAT_0051c6cc + 0x1a0;
      *g_PlayerSceneEntryData = 0x9d;
      *(undefined4 *)(g_PlayerSceneEntry + 0x70) = *(undefined4 *)(iVar5 + 0x70);
      *(undefined4 *)(g_PlayerSceneEntry + 0xb4) = 1;
      *(undefined4 *)(g_PlayerSceneEntry + 0xa8) = 0x1000;
      *(undefined4 *)(g_PlayerSceneEntry + 0xac) = 0x1000;
      *(undefined4 *)(g_PlayerSceneEntry + 0xb0) = 0x1000;
      *(undefined1 *)(g_PlayerSceneEntry + 0x75) = *(undefined1 *)(iVar5 + 0x75);
      *(undefined2 *)(g_PlayerSceneEntry + 0x140) = 0x80;
      if (g_PlayerGroundShadowProbeSceneEntry != 0) {
        *(int *)(g_PlayerGroundShadowProbeSceneEntry + 0x10) = DAT_0051c6cc + 0x3a8;
        *(undefined2 *)(g_PlayerGroundShadowProbeSceneEntry + 0xc) = 0x2010;
        iVar4 = g_PlayerGroundShadowProbeSceneEntry;
        iVar5 = g_PlayerSceneEntry;
        *(undefined4 *)(g_PlayerGroundShadowProbeSceneEntry + 0x14) =
             *(undefined4 *)(g_PlayerSceneEntry + 0x14);
        *(undefined4 *)(iVar4 + 0x18) = *(undefined4 *)(iVar5 + 0x18);
        *(undefined4 *)(iVar4 + 0x1c) = *(undefined4 *)(iVar5 + 0x1c);
        *(ushort *)(g_PlayerGroundShadowProbeSceneEntry + 0xe) =
             *(ushort *)(g_PlayerGroundShadowProbeSceneEntry + 0xe) | 0x441;
        *(undefined4 *)(g_PlayerGroundShadowProbeSceneEntry + 0x30) = 0x400;
        *(undefined4 *)(g_PlayerGroundShadowProbeSceneEntry + 0x6c) = 0xffffffec;
        *(undefined4 *)(g_PlayerSceneEntry + 0x6c) = 0xffffffe2;
        *(undefined2 *)(g_PlayerSceneEntry + 0xa6) = 1;
        *(undefined4 *)(g_PlayerGroundShadowProbeSceneEntry + 0x108) =
             *(undefined4 *)(g_PlayerSceneEntry + 0x108);
        *(undefined4 *)(g_PlayerGroundShadowProbeSceneEntry + 0x110) =
             *(undefined4 *)(g_PlayerSceneEntry + 0x110);
        *(undefined4 *)(g_PlayerGroundShadowProbeSceneEntry + 0x10c) =
             *(undefined4 *)(g_PlayerSceneEntry + 0x10c);
      }
    }
    goto LAB_00490d30;
  case 0x3a:
    *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0;
    *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
    CPlayerHero__UpdateMovementAndCollision(1);
    if (DAT_0053a2a8 != 0) {
      DAT_0053a2d0 = DAT_0053a2e4;
      InitAudioLine_stub();
    }
    DAT_0053a2d0 = DAT_0053a2d0 + 1;
    iVar5 = DAT_0053a2dc;
    if (DAT_0053a2e4 < DAT_0053a2d0) {
      g_PlayerActionState = 0x39;
      g_PlayerCurrentCollisionMode =
           FUN_00434380(g_PlayerSceneEntry,(&PTR_DAT_00515268)[DAT_0053a2dc * 0xc]);
      CPlayerHero__PlayAnimation(*(undefined4 *)(&DAT_0051526c + DAT_0053a2dc * 0x30));
      iVar5 = DAT_0053a2dc;
      iVar4 = DAT_0053a2dc * 0x30;
      uVar1 = *(ushort *)(&DAT_00515250 + iVar4);
      *(ushort *)(&DAT_00515250 + iVar4) = ~uVar1 + 1;
      DAT_0053a2ec = (int)(short)(~uVar1 + 1);
      uVar1 = *(ushort *)(&DAT_00515252 + iVar4);
      *(ushort *)(&DAT_00515252 + iVar4) = ~uVar1 + 1;
      DAT_0053a2e0 = (int)(short)(~uVar1 + 1);
      uVar1 = *(ushort *)(&DAT_00515254 + iVar4);
      *(ushort *)(&DAT_00515254 + iVar4) = ~uVar1 + 1;
      DAT_0053a2d8 = (int)(short)(~uVar1 + 1);
      DAT_0053a2c8 = *(undefined4 *)(&DAT_00515258 + iVar4);
      DAT_0053a2b8 = *(undefined4 *)(&DAT_0051525c + iVar4);
      DAT_0053a2d4 = *(undefined4 *)(&DAT_00515260 + iVar4);
    }
    if (DAT_0053a2d0 == DAT_0053a2cc) {
      PlayAudioById(*(undefined4 *)(&DAT_0051524c + iVar5 * 0x30),0,0);
    }
    *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0;
    *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
    break;
  default:
    *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0;
    *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
  }
  CPlayerHero__UpdateMovementAndCollision(1);
LAB_00490d30:
  cVar3 = CPlayerHero__TrySnapToNearbyGround();
  uVar2 = g_PlayerActionState;
  if (cVar3 == '\0') {
    g_PlayerActionState = 7;
    g_PreviousPlayerActionState = uVar2;
    /* table enter state 0x07 -> CPlayerHero::EnterYoungTarzanFalling */
  CPlayerHero__EnterYoungTarzanFalling();
    return;
  }
  iVar5 = CPlayerHero__AdvanceAnimationScript();
  if (iVar5 == 6) {
    *(byte *)(g_PlayerSceneEntry + 0x75) = ~*(byte *)(g_PlayerSceneEntry + 0x75);
    *(ushort *)(g_PlayerSceneEntry + 0xa2) = *(ushort *)(g_PlayerSceneEntry + 0xa2) ^ 0x800;
    _g_PlayerMoveTiltAngle = *(undefined2 *)(g_PlayerSceneEntry + 0xa0);
    g_PlayerMoveHeadingAngle = *(undefined2 *)(g_PlayerSceneEntry + 0xa2);
  }
  else if (iVar5 == 8) {
    CPlayerHero__PlayAnimation(0x94);
    return;
  }
  return;
}


