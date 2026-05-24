/*
State 0x04 Update: CPlayerHero::UpdateTerkAirborneMovement
Address: 0x004784B0
*/


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint CPlayerHero__UpdateTerkAirborneMovement(void)

{
  ushort *puVar1;
  short sVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  ushort uVar8;
  ushort uVar9;
  undefined4 *puVar10;
  
  uVar6 = TryStartPlayerAttachmentInteraction();
  if ((char)uVar6 != '\0') {
    return uVar6;
  }
  CPlayerHero__UpdateRunInputAndMovement();
  CPlayerHero__TrySnapDownToGround();
  if (g_PlayerFacingCurrentCollisionSurface != '\0') {
    if (((ram0x0051cdca & 0x2000) == 0) && (g_PlayerActionState != 8)) {
      g_PreviousPlayerActionState = g_PlayerActionState;
      g_PlayerActionState = 8;
      (*(code *)PTR_CPlayerHero__EnterTerkAirborneDamage_0050c188)();
    }
    if (g_PlayerDamageInvulnerabilityTicks == 0) {
      g_PlayerDamageInvulnerabilityTicks = 0x3c;
      g_PlayerDamageFlashTicks = 0x3c;
    }
  }
  if (g_PlayerJumpArcActive != '\0') {
    iVar7 = CPlayerHero__TryClampJumpArcToSurfaceCeiling(0x14e);
    if (iVar7 != 0) {
      *(int *)(g_PlayerSceneEntryData + 6) = iVar7;
      g_PreviousPlayerActionState = g_PlayerActionState;
      g_PlayerActionState = 10;
      (*(code *)PTR_CPlayerHero__EnterTerkFalling_0050c198)();
      g_PlayerJumpArcActive = '\0';
    }
    CPlayerHero__UpdateJumpArcVerticalMotion(g_PlayerActionState != 7);
  }
  uVar6 = 0;
  *(short *)(g_PlayerAnimationState + 0x14) = *(short *)(g_PlayerAnimationState + 0x14) + -1;
  if (*(short *)(g_PlayerAnimationState + 0x14) < 0) {
    if ((*(byte *)(g_PlayerAnimationState + 0x1f) & 1) == 0) {
      do {
        *(short *)(g_PlayerAnimationState + 0x16) = *(short *)(g_PlayerAnimationState + 0x16) + 1;
        iVar5 = g_PlayerSceneEntry;
        iVar4 = (int)*(short *)(g_PlayerAnimationState + 0x16);
        iVar7 = *(int *)(g_PlayerAnimationState + 0xc);
        uVar8 = *(ushort *)(iVar7 + iVar4 * 4);
        uVar9 = uVar8 & 0x8000;
        if (uVar9 == 0) break;
        switch(uVar8) {
        case 0x8000:
          *(short *)(g_PlayerAnimationState + 0x16) = *(short *)(iVar7 + 2 + iVar4 * 4) + -1;
          if (uVar6 == 0) {
            uVar6 = 2;
          }
          break;
        case 0x8001:
          *(int *)(g_PlayerAnimationState + 0xc) = iVar7 + 4 + iVar4 * 4;
          *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
          break;
        case 0x8002:
          return (uint)*(ushort *)
                        (*(int *)(g_PlayerAnimationState + 0xc) + 2 +
                        *(short *)(g_PlayerAnimationState + 0x16) * 4);
        case 0x8003:
          uVar6 = (uint)*(ushort *)(iVar7 + 2 + iVar4 * 4);
          break;
        case 0x8004:
          SetPlayerActionState
                    (*(undefined2 *)
                      (*(int *)(g_PlayerAnimationState + 0xc) + 2 +
                      *(short *)(g_PlayerAnimationState + 0x16) * 4));
          return uVar6;
        case 0x8005:
          uVar6 = CPlayerHero__PlayHeroModeAnimation
                            (*(undefined2 *)
                              (*(int *)(g_PlayerAnimationState + 0xc) + 2 +
                              *(short *)(g_PlayerAnimationState + 0x16) * 4));
          return uVar6;
        case 0x8006:
          uVar3 = *(ushort *)(iVar7 + 2 + iVar4 * 4);
          if (uVar3 == 0x8000) {
            *(undefined4 *)(g_PlayerSceneEntryData + 2) = g_CurrentWorldSceneContext;
          }
          else {
            *(uint *)(g_PlayerSceneEntryData + 2) = g_WorldSceneEntryArrayBase + (uint)uVar3 * 0x68;
          }
          break;
        case 0x8007:
          g_PlayerJumpArcActive = '\x01';
          if (*(int *)(g_PlayerSceneEntry + 0x60) != 0) {
            *(undefined4 *)(*(int *)(g_PlayerSceneEntry + 0x60) + 0x60) = 0;
          }
          *(undefined4 *)(iVar5 + 0x60) = 0;
          break;
        case 0x8008:
          g_PlayerTiltControlEnabled = *(short *)(iVar7 + 2 + iVar4 * 4) != 0;
          break;
        case 0x8009:
          iVar5 = g_PlayerSceneEntry + 0x14;
          goto LAB_0043370c;
        case 0x800a:
          PlayAudioById(*(undefined2 *)(iVar7 + 2 + iVar4 * 4),g_PlayerSceneEntry + 0x104,
                        g_PlayerSceneEntry + 0x14);
          break;
        case 0x800b:
          iVar5 = g_PlayerSceneEntry + 0x14;
          puVar10 = &g_PlayerLoopingSoundHandle;
          goto LAB_0043370d;
        case 0x800c:
          DetachEntitySoundHandle(&g_PlayerLoopingSoundHandle);
          break;
        case 0x800d:
          iVar5 = 0;
LAB_0043370c:
          puVar10 = (undefined4 *)0x0;
LAB_0043370d:
          PlayAudioById(*(undefined2 *)(iVar7 + 2 + iVar4 * 4),puVar10,iVar5);
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
            *(undefined2 *)(g_PlayerSceneEntry + 0x76) = *(undefined2 *)(iVar7 + 2 + iVar4 * 4);
          }
          else {
            *g_PlayerSceneEntryData = *(ushort *)(iVar7 + 2 + iVar4 * 4);
          }
          *(undefined2 *)(g_PlayerSceneEntry + 0x78) = 0;
          *(byte *)(g_PlayerAnimationState + 0x1e) = *(byte *)(g_PlayerAnimationState + 0x1e) | 1;
          break;
        case 0x8011:
          *(undefined2 *)(g_PlayerSceneEntry + 0x78) = *(undefined2 *)(iVar7 + 2 + iVar4 * 4);
          break;
        case 0x8012:
          if ((*(byte *)(g_PlayerAnimationState + 0x1e) & 4) == 0) {
            *(undefined2 *)(g_PlayerSceneEntry + 0x76) = *(undefined2 *)(iVar7 + 2 + iVar4 * 4);
          }
          else {
            *g_PlayerSceneEntryData = *(ushort *)(iVar7 + 2 + iVar4 * 4);
          }
          *(undefined2 *)(g_PlayerSceneEntry + 0x78) = 0;
          *(byte *)(g_PlayerAnimationState + 0x1e) = *(byte *)(g_PlayerAnimationState + 0x1e) | 0x82
          ;
          break;
        case 0x8013:
          *(short *)(g_PlayerAnimationState + 0x1c) =
               (short)(0x100 / (ulonglong)(longlong)(int)(*(ushort *)(iVar7 + 2 + iVar4 * 4) + 1));
          *(undefined2 *)(g_PlayerSceneEntry + 0x78) = 0;
          *(byte *)(g_PlayerAnimationState + 0x1e) = *(byte *)(g_PlayerAnimationState + 0x1e) | 2;
          break;
        case 0x8014:
          *(undefined2 *)(g_PlayerSceneEntry + 0x78) = 0;
          *(undefined2 *)(g_PlayerAnimationState + 0x1e) = 0;
          break;
        case 0x8015:
          CPlayerHero__MoveToAnimationAttachmentWithCollision();
          if (uVar6 == 0) {
            uVar6 = 0xe;
          }
          break;
        case 0x8016:
          uVar3 = *(ushort *)(iVar7 + 2 + iVar4 * 4);
          *(undefined2 *)(g_PlayerAnimationState + 0x1e) = 6;
          *(ushort *)(g_PlayerSceneEntry + 0x76) = *g_PlayerSceneEntryData;
          *(undefined2 *)(g_PlayerSceneEntry + 0x78) = 0;
          *(short *)(g_PlayerAnimationState + 0x1c) =
               (short)(0x100 / (ulonglong)(longlong)(int)(uVar3 + 1));
          break;
        case 0x8017:
          DAT_0051ce40 = *(undefined1 *)(iVar7 + 2 + iVar4 * 4);
          break;
        case 0x8018:
          uVar6 = 0xf;
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
            *puVar1 = *puVar1 | *(ushort *)(iVar7 + 2 + iVar4 * 4);
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
          *(uint *)(g_PlayerSceneEntry + 0x70) = (uint)*(ushort *)(iVar7 + 2 + iVar4 * 4);
          break;
        case 0x801f:
          CPlayerHero__RefreshPowerFruitDrawWindow();
          break;
        case 0x8020:
          CPlayerHero__ClearPowerFruitDrawWindow();
          break;
        case 0x8021:
          iVar5 = (uint)*(ushort *)(iVar7 + 2 + iVar4 * 4) * 4;
          PlayForceFeedbackEffect_Stub
                    (0,*(undefined2 *)(&DAT_004ec5cc + iVar5),
                     CONCAT31((int3)((uint)iVar7 >> 8),(&DAT_004ec5ce)[iVar5]));
          break;
        case 0x8022:
          CPlayerHero__UpdateAnimationEffectSceneEntry
                    (CONCAT22(*(short *)(g_PlayerAnimationState + 0x16) >> 0xf,
                              *(undefined2 *)(iVar7 + 2 + iVar4 * 4)));
          break;
        case 0x8023:
          QueuePlayerDamageEvent(0,0x200);
        }
      } while (uVar9 != 0);
      if ((*(byte *)(g_PlayerAnimationState + 0x1e) & 4) == 0) {
        *g_PlayerSceneEntryData = uVar8;
      }
      else {
        *(ushort *)(g_PlayerSceneEntry + 0x76) = uVar8;
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
        uVar8 = *(ushort *)(*(int *)(g_PlayerAnimationState + 0xc) + sVar2 * 4);
        if ((uVar8 & 0x8000) == 0) {
          *g_PlayerSceneEntryData = uVar8;
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
      uVar6 = 0x10;
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
  return uVar6;
}


