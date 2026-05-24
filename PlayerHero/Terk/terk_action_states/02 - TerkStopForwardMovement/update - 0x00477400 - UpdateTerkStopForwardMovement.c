/*
State 0x02 Update: CPlayerHero::UpdateTerkStopForwardMovement
Address: 0x00477400
*/


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint CPlayerHero__UpdateTerkStopForwardMovement(void)

{
  ushort *puVar1;
  short sVar2;
  ushort uVar3;
  int iVar4;
  undefined2 uVar5;
  char cVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  ushort uVar10;
  ushort uVar11;
  undefined4 *puVar12;
  
  CPlayerHero__UpdateMovementAndCollision(1);
  uVar5 = g_PlayerActionState;
  g_InputPreviousMask = g_InputPreviousMask & 0xffefffff;
  if (g_PlayerFacingCurrentCollisionSurface != '\0') {
    if ((ram0x0051cdca & 0x1000) != 0) {
      g_PlayerActionState = 8;
      g_PreviousPlayerActionState = uVar5;
      uVar9 = (*(code *)PTR_CPlayerHero__EnterTerkAirborneDamage_0050c188)();
      if (g_PlayerDamageInvulnerabilityTicks == 0) {
        uVar9 = 0x3c;
        g_PlayerDamageInvulnerabilityTicks = 0x3c;
        g_PlayerDamageFlashTicks = 0x3c;
      }
      return uVar9;
    }
    if (g_PlayerDamageInvulnerabilityTicks == 0) {
      CPlayerHero__ApplyDamageContactPushback();
      g_PreviousPlayerActionState = g_PlayerActionState;
      g_PlayerActionState = 0xf;
                    /* WARNING: Could not recover jumptable at 0x0047748c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar9 = (*(code *)PTR_CPlayerHero__EnterTerkGroundDamage_0050c1c0)();
      return uVar9;
    }
    g_PlayerCollisionFacingFlags = '\x01';
    CPlayerHero__ApplyDamageContactPushback();
  }
  cVar6 = CPlayerHero__TrySnapToNearbyGround();
  uVar5 = g_PlayerActionState;
  if (cVar6 == '\0') {
    g_PlayerActionState = 10;
    g_PreviousPlayerActionState = uVar5;
    (*(code *)PTR_CPlayerHero__EnterTerkFalling_0050c198)();
  }
  if (((((_g_PlayerSequenceFlags & 0xf000) == 0) && (g_PlayerCurrentCollisionMode == 2)) &&
      (cVar6 = CPlayerHero__IsFacingCurrentCollisionSurface(), uVar5 = g_PlayerActionState,
      cVar6 == '\0')) &&
     (((g_CameraFollowFlags & g_PlayerInputHeldMask) != 0 && (g_PlayerCollisionFacingFlags == '\0'))
     )) {
    g_PlayerActionState = 1;
    g_PreviousPlayerActionState = uVar5;
    (*(code *)PTR_CPlayerHero__EnterTerkMoveForward_0050c150)();
  }
  uVar5 = g_PlayerActionState;
  if (((_g_PlayerSequenceFlags & 0xf000) == 0) && ((g_PlayerInputPressedMask & 0x200000) != 0)) {
    g_PlayerActionState = 6;
    g_PreviousPlayerActionState = uVar5;
                    /* WARNING: Could not recover jumptable at 0x0047754b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar9 = (*(code *)PTR_CPlayerHero__EnterTerkStandingJump_0050c178)();
    return uVar9;
  }
  if ((((_g_PlayerSequenceFlags & 0xf000) == 0) &&
      ((g_PlayerInputHeldMask & g_CameraRelativeTurnInputMask) != 0)) &&
     (g_PlayerCurrentCollisionMode == 2)) {
    g_PlayerActionState = 3;
    g_PreviousPlayerActionState = uVar5;
    (*(code *)PTR_CPlayerHero__EnterTerkTurnAround_0050c160)();
  }
  uVar9 = 0;
  *(short *)(g_PlayerAnimationState + 0x14) = *(short *)(g_PlayerAnimationState + 0x14) + -1;
  if (*(short *)(g_PlayerAnimationState + 0x14) < 0) {
    if ((*(byte *)(g_PlayerAnimationState + 0x1f) & 1) == 0) {
      do {
        *(short *)(g_PlayerAnimationState + 0x16) = *(short *)(g_PlayerAnimationState + 0x16) + 1;
        iVar8 = g_PlayerSceneEntry;
        iVar7 = (int)*(short *)(g_PlayerAnimationState + 0x16);
        iVar4 = *(int *)(g_PlayerAnimationState + 0xc);
        uVar10 = *(ushort *)(iVar4 + iVar7 * 4);
        uVar11 = uVar10 & 0x8000;
        if (uVar11 == 0) break;
        switch(uVar10) {
        case 0x8000:
          *(short *)(g_PlayerAnimationState + 0x16) = *(short *)(iVar4 + 2 + iVar7 * 4) + -1;
          if (uVar9 == 0) {
            uVar9 = 2;
          }
          break;
        case 0x8001:
          *(int *)(g_PlayerAnimationState + 0xc) = iVar4 + 4 + iVar7 * 4;
          *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
          break;
        case 0x8002:
          return (uint)*(ushort *)
                        (*(int *)(g_PlayerAnimationState + 0xc) + 2 +
                        *(short *)(g_PlayerAnimationState + 0x16) * 4);
        case 0x8003:
          uVar9 = (uint)*(ushort *)(iVar4 + 2 + iVar7 * 4);
          break;
        case 0x8004:
          SetPlayerActionState
                    (*(undefined2 *)
                      (*(int *)(g_PlayerAnimationState + 0xc) + 2 +
                      *(short *)(g_PlayerAnimationState + 0x16) * 4));
          return uVar9;
        case 0x8005:
          uVar9 = CPlayerHero__PlayHeroModeAnimation
                            (*(undefined2 *)
                              (*(int *)(g_PlayerAnimationState + 0xc) + 2 +
                              *(short *)(g_PlayerAnimationState + 0x16) * 4));
          return uVar9;
        case 0x8006:
          uVar3 = *(ushort *)(iVar4 + 2 + iVar7 * 4);
          if (uVar3 == 0x8000) {
            *(undefined4 *)(g_PlayerSceneEntryData + 2) = g_CurrentWorldSceneContext;
          }
          else {
            *(uint *)(g_PlayerSceneEntryData + 2) = g_WorldSceneEntryArrayBase + (uint)uVar3 * 0x68;
          }
          break;
        case 0x8007:
          g_PlayerJumpArcActive = 1;
          if (*(int *)(g_PlayerSceneEntry + 0x60) != 0) {
            *(undefined4 *)(*(int *)(g_PlayerSceneEntry + 0x60) + 0x60) = 0;
          }
          *(undefined4 *)(iVar8 + 0x60) = 0;
          break;
        case 0x8008:
          g_PlayerTiltControlEnabled = *(short *)(iVar4 + 2 + iVar7 * 4) != 0;
          break;
        case 0x8009:
          iVar8 = g_PlayerSceneEntry + 0x14;
          goto LAB_0043370c;
        case 0x800a:
          PlayAudioById(*(undefined2 *)(iVar4 + 2 + iVar7 * 4),g_PlayerSceneEntry + 0x104,
                        g_PlayerSceneEntry + 0x14);
          break;
        case 0x800b:
          iVar8 = g_PlayerSceneEntry + 0x14;
          puVar12 = &g_PlayerLoopingSoundHandle;
          goto LAB_0043370d;
        case 0x800c:
          DetachEntitySoundHandle(&g_PlayerLoopingSoundHandle);
          break;
        case 0x800d:
          iVar8 = 0;
LAB_0043370c:
          puVar12 = (undefined4 *)0x0;
LAB_0043370d:
          PlayAudioById(*(undefined2 *)(iVar4 + 2 + iVar7 * 4),puVar12,iVar8);
          break;
        case 0x800e:
          *(byte *)(g_PlayerSceneEntry + 0x75) = ~*(byte *)(g_PlayerSceneEntry + 0x75);
          *(ushort *)(g_PlayerSceneEntry + 0xa2) = *(ushort *)(g_PlayerSceneEntry + 0xa2) ^ 0x800;
          break;
        case 0x800f:
          *(byte *)(g_PlayerAnimationState + 0x1e) = *(byte *)(g_PlayerAnimationState + 0x1e) | 4;
          break;
        case 0x8010:
          if ((*(byte *)(g_PlayerAnimationState + 0x1e) & 4) == 0) {
            *(undefined2 *)(g_PlayerSceneEntry + 0x76) = *(undefined2 *)(iVar4 + 2 + iVar7 * 4);
          }
          else {
            *g_PlayerSceneEntryData = *(ushort *)(iVar4 + 2 + iVar7 * 4);
          }
          *(undefined2 *)(g_PlayerSceneEntry + 0x78) = 0;
          *(byte *)(g_PlayerAnimationState + 0x1e) = *(byte *)(g_PlayerAnimationState + 0x1e) | 1;
          break;
        case 0x8011:
          *(undefined2 *)(g_PlayerSceneEntry + 0x78) = *(undefined2 *)(iVar4 + 2 + iVar7 * 4);
          break;
        case 0x8012:
          if ((*(byte *)(g_PlayerAnimationState + 0x1e) & 4) == 0) {
            *(undefined2 *)(g_PlayerSceneEntry + 0x76) = *(undefined2 *)(iVar4 + 2 + iVar7 * 4);
          }
          else {
            *g_PlayerSceneEntryData = *(ushort *)(iVar4 + 2 + iVar7 * 4);
          }
          *(undefined2 *)(g_PlayerSceneEntry + 0x78) = 0;
          *(byte *)(g_PlayerAnimationState + 0x1e) = *(byte *)(g_PlayerAnimationState + 0x1e) | 0x82
          ;
          break;
        case 0x8013:
          *(short *)(g_PlayerAnimationState + 0x1c) =
               (short)(0x100 / (ulonglong)(longlong)(int)(*(ushort *)(iVar4 + 2 + iVar7 * 4) + 1));
          *(undefined2 *)(g_PlayerSceneEntry + 0x78) = 0;
          *(byte *)(g_PlayerAnimationState + 0x1e) = *(byte *)(g_PlayerAnimationState + 0x1e) | 2;
          break;
        case 0x8014:
          *(undefined2 *)(g_PlayerSceneEntry + 0x78) = 0;
          *(undefined2 *)(g_PlayerAnimationState + 0x1e) = 0;
          break;
        case 0x8015:
          CPlayerHero__MoveToAnimationAttachmentWithCollision();
          if (uVar9 == 0) {
            uVar9 = 0xe;
          }
          break;
        case 0x8016:
          uVar3 = *(ushort *)(iVar4 + 2 + iVar7 * 4);
          *(undefined2 *)(g_PlayerAnimationState + 0x1e) = 6;
          *(ushort *)(g_PlayerSceneEntry + 0x76) = *g_PlayerSceneEntryData;
          *(undefined2 *)(g_PlayerSceneEntry + 0x78) = 0;
          *(short *)(g_PlayerAnimationState + 0x1c) =
               (short)(0x100 / (ulonglong)(longlong)(int)(uVar3 + 1));
          break;
        case 0x8017:
          DAT_0051ce40 = *(undefined1 *)(iVar4 + 2 + iVar7 * 4);
          break;
        case 0x8018:
          uVar9 = 0xf;
          *(byte *)(g_PlayerAnimationState + 0x1f) = *(byte *)(g_PlayerAnimationState + 0x1f) | 1;
          break;
        case 0x8019:
          g_PlayerSceneEntryData[1] = g_PlayerSceneEntryData[1] ^ 2;
          break;
        case 0x801a:
          g_PlayerSceneEntryData[1] = g_PlayerSceneEntryData[1] ^ 4;
          break;
        case 0x801b:
          g_PlayerSceneEntryData[1] = g_PlayerSceneEntryData[1] ^ 8;
          break;
        case 0x801c:
          g_PlayerSceneEntryData[1] = g_PlayerSceneEntryData[1] & 0xfff1;
          break;
        case 0x801d:
          if (*(int *)(g_PlayerSceneEntry + 0x60) != 0) {
            puVar1 = (ushort *)(*(int *)(*(int *)(g_PlayerSceneEntry + 0x60) + -4) + 0x42);
            *puVar1 = *puVar1 | *(ushort *)(iVar4 + 2 + iVar7 * 4);
          }
          if (g_PlayerTriggeredCollisionEntry != 0) {
            *(ushort *)(g_PlayerTriggeredCollisionEntry + 0x42) =
                 *(ushort *)(g_PlayerTriggeredCollisionEntry + 0x42) |
                 *(ushort *)
                  (*(int *)(g_PlayerAnimationState + 0xc) + 2 +
                  *(short *)(g_PlayerAnimationState + 0x16) * 4);
          }
          break;
        case 0x801e:
          *(uint *)(g_PlayerSceneEntry + 0x70) = (uint)*(ushort *)(iVar4 + 2 + iVar7 * 4);
          break;
        case 0x801f:
          CPlayerHero__RefreshPowerFruitDrawWindow();
          break;
        case 0x8020:
          CPlayerHero__ClearPowerFruitDrawWindow();
          break;
        case 0x8021:
          iVar8 = (uint)*(ushort *)(iVar4 + 2 + iVar7 * 4) * 4;
          PlayForceFeedbackEffect_Stub
                    (0,*(undefined2 *)(&DAT_004ec5cc + iVar8),
                     CONCAT31((int3)((uint)iVar4 >> 8),(&DAT_004ec5ce)[iVar8]));
          break;
        case 0x8022:
          CPlayerHero__UpdateAnimationEffectSceneEntry
                    (CONCAT22(*(short *)(g_PlayerAnimationState + 0x16) >> 0xf,
                              *(undefined2 *)(iVar4 + 2 + iVar7 * 4)));
          break;
        case 0x8023:
          QueuePlayerDamageEvent(0,0x200);
        }
      } while (uVar11 != 0);
      if ((*(byte *)(g_PlayerAnimationState + 0x1e) & 4) == 0) {
        *g_PlayerSceneEntryData = uVar10;
      }
      else {
        *(ushort *)(g_PlayerSceneEntry + 0x76) = uVar10;
      }
      *(undefined2 *)(g_PlayerAnimationState + 0x14) =
           *(undefined2 *)
            (*(int *)(g_PlayerAnimationState + 0xc) + 2 +
            *(short *)(g_PlayerAnimationState + 0x16) * 4);
      if ((*(byte *)(g_PlayerAnimationState + 0x1e) & 0x80) != 0) {
        *(short *)(g_PlayerAnimationState + 0x1c) =
             (short)(0x100 / (longlong)(*(short *)(g_PlayerAnimationState + 0x14) + 2));
      }
    }
    else {
      *(short *)(g_PlayerAnimationState + 0x16) = *(short *)(g_PlayerAnimationState + 0x16) + -1;
      sVar2 = *(short *)(g_PlayerAnimationState + 0x16);
      while (-1 < sVar2) {
        uVar10 = *(ushort *)(*(int *)(g_PlayerAnimationState + 0xc) + sVar2 * 4);
        if ((uVar10 & 0x8000) == 0) {
          *g_PlayerSceneEntryData = uVar10;
          *(undefined2 *)(g_PlayerAnimationState + 0x14) =
               *(undefined2 *)
                (*(int *)(g_PlayerAnimationState + 0xc) + 2 +
                *(short *)(g_PlayerAnimationState + 0x16) * 4);
          goto LAB_00433a9e;
        }
        *(short *)(g_PlayerAnimationState + 0x16) = *(short *)(g_PlayerAnimationState + 0x16) + -1;
        sVar2 = *(short *)(g_PlayerAnimationState + 0x16);
      }
      *(ushort *)(g_PlayerAnimationState + 0x1e) =
           *(ushort *)(g_PlayerAnimationState + 0x1e) & 0xfeff;
      uVar9 = 0x10;
    }
  }
LAB_00433a9e:
  if ((*(byte *)(g_PlayerAnimationState + 0x1e) & 2) != 0) {
    *(short *)(g_PlayerSceneEntry + 0x78) =
         *(short *)(g_PlayerSceneEntry + 0x78) + *(short *)(g_PlayerAnimationState + 0x1c);
  }
  if (0xff < *(short *)(g_PlayerSceneEntry + 0x78)) {
    *(undefined2 *)(g_PlayerSceneEntry + 0x78) = 0;
    *(undefined2 *)(g_PlayerAnimationState + 0x1e) = 0;
    *g_PlayerSceneEntryData = *(ushort *)(g_PlayerSceneEntry + 0x76);
  }
  return uVar9;
}


