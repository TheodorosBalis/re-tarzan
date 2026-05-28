
void CEntities__UpdateTutorialPickup(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  char cVar4;
  int iVar5;
  
  iVar1 = *(int *)(param_1 + 0x38);
  if (iVar1 != 0) {
    if (g_PlayerInteractionLockFlags == 0) {
      *(ushort *)(iVar1 + 0xa2) = *(short *)(iVar1 + 0xa2) + 0x38U & 0xfff;
      cVar4 = CEntities__IsPlayerWithinPickupTriggerBounds
                        (iVar1,0xc0,(int)*(short *)(g_PlayerSceneEntry + 0x142),0);
      if ((cVar4 != '\0') && (cVar4 = CEntities__CanStartPickupCollection(param_1), cVar4 != '\0'))
      {
        g_PlayerDamageInvulnerabilityTicks = 0x3c;
        g_TutorialPickupSkipApproachFlag = 0;
        g_PlayerInteractionLockFlags = 0x8000;
        g_ActiveTutorialPickupRuntimeEntry = param_1;
        g_ActiveTutorialPickupId = *(int *)(param_1 + 0x4c);
        *(ushort *)(iVar1 + 0xe) = *(ushort *)(iVar1 + 0xe) ^ 0x8000;
        LoadEncodedResourceId(0x23);
        CEntities__SpawnRuntimeEntryByTypeAtPosition
                  (*(undefined4 *)(iVar1 + 0x14),*(undefined4 *)(iVar1 + 0x18),
                   *(undefined4 *)(iVar1 + 0x1c),0x14,0x11);
        PlayAudioById(0x22,0,g_PlayerSceneEntry + 0x14);
      }
    }
    else if (g_ActiveTutorialPickupId != *(int *)(param_1 + 0x4c)) {
      cVar4 = IsRuntimeEntryOutsideOuterActivationBounds(param_1);
      if (cVar4 == '\0') {
        return;
      }
      CEntities__ReleaseRuntimeEntryToFreeList(param_1);
      return;
    }
    switch(g_TutorialPickupSequencePhase) {
    case 1:
      g_TutorialPickupSequencePhase = 2;
      *(undefined4 *)(iVar1 + 0xa8) = 0x1000;
      *(undefined4 *)(iVar1 + 0xac) = 0x1000;
      *(undefined4 *)(iVar1 + 0xb0) = 0x1000;
      *(undefined4 *)(iVar1 + 0x14) = *(undefined4 *)(g_PlayerSceneEntryData + 4);
      *(undefined4 *)(iVar1 + 0x18) = *(undefined4 *)(g_PlayerSceneEntryData + 6);
      *(undefined4 *)(iVar1 + 0x1c) = *(undefined4 *)(g_PlayerSceneEntryData + 8);
      *(undefined2 *)(iVar1 + 0xe) = g_PlayerSceneEntryData[1];
      *(undefined4 *)(iVar1 + 0x6c) = *(undefined4 *)(g_PlayerSceneEntry + 0x6c);
      *(int *)(iVar1 + 0x10) = g_WorldSceneEntryArrayBase + 0x1a0;
      *(undefined2 *)(iVar1 + 0xc) = *g_PlayerSceneEntryData;
      *(undefined4 *)(iVar1 + 0x70) = *(undefined4 *)(g_PlayerSceneEntry + 0x70);
      *(undefined2 *)(iVar1 + 0xa0) = *(undefined2 *)(g_PlayerSceneEntry + 0xa0);
      *(undefined2 *)(iVar1 + 0xa2) = *(undefined2 *)(g_PlayerSceneEntry + 0xa2);
      *(undefined2 *)(iVar1 + 0xa4) = *(undefined2 *)(g_PlayerSceneEntry + 0xa4);
      *(undefined2 *)(iVar1 + 0xa6) = *(undefined2 *)(g_PlayerSceneEntry + 0xa6);
      *(undefined1 *)(iVar1 + 0x75) = *(undefined1 *)(g_PlayerSceneEntry + 0x75);
      iVar5 = g_PlayerSceneEntry;
      *(undefined4 *)(iVar1 + 0x10c) = *(undefined4 *)(g_PlayerSceneEntry + 0x10c);
      *(undefined4 *)(iVar1 + 0x110) = *(undefined4 *)(iVar5 + 0x110);
      *(undefined4 *)(iVar1 + 0x110) = *(undefined4 *)(g_PlayerSceneEntry + 0x110);
      *(undefined4 *)(iVar1 + 0x10c) = *(undefined4 *)(g_PlayerSceneEntry + 0x10c);
      *(undefined4 *)(iVar1 + 0x114) = *(undefined4 *)(g_PlayerSceneEntry + 0x114);
      *(undefined2 *)(iVar1 + 0x142) = *(undefined2 *)(g_PlayerSceneEntry + 0x142);
      iVar5 = g_PlayerSceneEntry;
      *(undefined4 *)(iVar1 + 0x14) = *(undefined4 *)(g_PlayerSceneEntry + 0x14);
      *(undefined4 *)(iVar1 + 0x18) = *(undefined4 *)(iVar5 + 0x18);
      *(undefined4 *)(iVar1 + 0x1c) = *(undefined4 *)(iVar5 + 0x1c);
      iVar5 = g_PlayerSceneEntry;
      *(undefined4 *)(iVar1 + 0x3c) = *(undefined4 *)(g_PlayerSceneEntry + 0x3c);
      *(undefined4 *)(iVar1 + 0x40) = *(undefined4 *)(iVar5 + 0x40);
      *(undefined4 *)(iVar1 + 0x44) = *(undefined4 *)(iVar5 + 0x44);
      iVar5 = g_PlayerSceneEntry;
      *(undefined4 *)(iVar1 + 0x48) = *(undefined4 *)(g_PlayerSceneEntry + 0x48);
      *(undefined4 *)(iVar1 + 0x4c) = *(undefined4 *)(iVar5 + 0x4c);
      *(undefined4 *)(iVar1 + 0x50) = *(undefined4 *)(iVar5 + 0x50);
      iVar5 = g_PlayerSceneEntry;
      *(undefined4 *)(iVar1 + 0x54) = *(undefined4 *)(g_PlayerSceneEntry + 0x54);
      *(undefined4 *)(iVar1 + 0x58) = *(undefined4 *)(iVar5 + 0x58);
      *(undefined4 *)(iVar1 + 0x5c) = *(undefined4 *)(iVar5 + 0x5c);
      g_ActiveCameraAnchorEntry =
           CEntities__SpawnRuntimeEntryByTypeAtPosition
                     (*(undefined4 *)(g_PlayerSceneEntryData + 4),
                      *(undefined4 *)(g_PlayerSceneEntryData + 6),
                      *(undefined4 *)(g_PlayerSceneEntryData + 8),0x2d,0x11);
      iVar5 = *(int *)(g_ActiveCameraAnchorEntry + 0x38);
      if (iVar5 == 0) {
        g_ActiveCameraAnchorEntry = param_1;
      }
      else {
        *(undefined4 *)(iVar5 + 0x14) = *(undefined4 *)(g_PlayerSceneEntryData + 4);
        *(undefined4 *)(iVar5 + 0x18) = *(undefined4 *)(g_PlayerSceneEntryData + 6);
        uVar2 = *(undefined4 *)(g_PlayerSceneEntryData + 8);
        *(ushort *)(iVar5 + 0xe) = *(ushort *)(iVar5 + 0xe) & 0x7fff;
        *(undefined4 *)(iVar5 + 0x1c) = uVar2;
        *(int *)(iVar5 + 0x10) = g_WorldSceneEntryArrayBase + 0x1a0;
        *(undefined2 *)(iVar5 + 0xc) = *g_PlayerSceneEntryData;
        *(undefined2 *)(iVar5 + 0xa0) = *(undefined2 *)(g_PlayerSceneEntry + 0xa0);
        *(undefined2 *)(iVar5 + 0xa2) = *(undefined2 *)(g_PlayerSceneEntry + 0xa2);
        *(undefined2 *)(iVar5 + 0xa4) = *(undefined2 *)(g_PlayerSceneEntry + 0xa4);
        *(undefined2 *)(iVar5 + 0xa6) = *(undefined2 *)(g_PlayerSceneEntry + 0xa6);
        iVar3 = g_PlayerSceneEntry;
        *(undefined4 *)(iVar5 + 0x10c) = *(undefined4 *)(g_PlayerSceneEntry + 0x10c);
        *(undefined4 *)(iVar5 + 0x110) = *(undefined4 *)(iVar3 + 0x110);
        *(undefined4 *)(iVar5 + 0x110) = *(undefined4 *)(g_PlayerSceneEntry + 0x110);
        *(undefined4 *)(iVar5 + 0x10c) = *(undefined4 *)(g_PlayerSceneEntry + 0x10c);
        *(undefined4 *)(iVar5 + 0x114) = *(undefined4 *)(g_PlayerSceneEntry + 0x114);
        *(undefined2 *)(iVar5 + 0x142) = *(undefined2 *)(g_PlayerSceneEntry + 0x142);
        iVar3 = g_PlayerSceneEntry;
        *(undefined4 *)(iVar5 + 0x14) = *(undefined4 *)(g_PlayerSceneEntry + 0x14);
        *(undefined4 *)(iVar5 + 0x18) = *(undefined4 *)(iVar3 + 0x18);
        *(undefined4 *)(iVar5 + 0x1c) = *(undefined4 *)(iVar3 + 0x1c);
        iVar3 = g_PlayerSceneEntry;
        *(undefined4 *)(iVar5 + 0x3c) = *(undefined4 *)(g_PlayerSceneEntry + 0x3c);
        *(undefined4 *)(iVar5 + 0x40) = *(undefined4 *)(iVar3 + 0x40);
        *(undefined4 *)(iVar5 + 0x44) = *(undefined4 *)(iVar3 + 0x44);
        iVar3 = g_PlayerSceneEntry;
        *(undefined4 *)(iVar5 + 0x48) = *(undefined4 *)(g_PlayerSceneEntry + 0x48);
        *(undefined4 *)(iVar5 + 0x4c) = *(undefined4 *)(iVar3 + 0x4c);
        *(undefined4 *)(iVar5 + 0x50) = *(undefined4 *)(iVar3 + 0x50);
        iVar3 = g_PlayerSceneEntry;
        *(undefined4 *)(iVar5 + 0x54) = *(undefined4 *)(g_PlayerSceneEntry + 0x54);
        *(undefined4 *)(iVar5 + 0x58) = *(undefined4 *)(iVar3 + 0x58);
        *(undefined4 *)(iVar5 + 0x5c) = *(undefined4 *)(iVar3 + 0x5c);
        iVar5 = g_ActiveTutorialPickupId * 0x30;
        g_TutorialPickupCameraMoveXStep = (int)*(short *)(&DAT_00515250 + iVar5);
        g_TutorialPickupCameraMoveYStep = (int)*(short *)(&DAT_00515252 + iVar5);
        g_TutorialPickupCameraMoveZStep = (int)*(short *)(&DAT_00515254 + iVar5);
        g_TutorialPickupCameraMoveXTicksRemaining = *(undefined4 *)(&DAT_00515258 + iVar5);
        g_TutorialPickupCameraMoveYTicksRemaining = *(undefined4 *)(&DAT_0051525c + iVar5);
        g_TutorialPickupCameraMoveZTicksRemaining = *(undefined4 *)(&DAT_00515260 + iVar5);
      }
      g_TutorialPickupGroundShadowSceneEntry = CreateRuntimeEntitySceneEntry(param_1,2);
      if (g_TutorialPickupGroundShadowSceneEntry != 0) {
        *(int *)(g_TutorialPickupGroundShadowSceneEntry + 0x10) = g_WorldSceneEntryArrayBase + 0x3a8
        ;
        *(undefined2 *)(g_TutorialPickupGroundShadowSceneEntry + 0xc) = 0x2010;
        iVar3 = g_TutorialPickupGroundShadowSceneEntry;
        iVar5 = g_PlayerSceneEntry;
        *(undefined4 *)(g_TutorialPickupGroundShadowSceneEntry + 0x14) =
             *(undefined4 *)(g_PlayerSceneEntry + 0x14);
        *(undefined4 *)(iVar3 + 0x18) = *(undefined4 *)(iVar5 + 0x18);
        *(undefined4 *)(iVar3 + 0x1c) = *(undefined4 *)(iVar5 + 0x1c);
        *(ushort *)(g_TutorialPickupGroundShadowSceneEntry + 0xe) =
             *(ushort *)(g_TutorialPickupGroundShadowSceneEntry + 0xe) | 0x441;
        *(undefined4 *)(g_TutorialPickupGroundShadowSceneEntry + 0x30) = 0x400;
        *(undefined4 *)(g_TutorialPickupGroundShadowSceneEntry + 0x6c) = 0xffffffec;
        *(undefined4 *)(iVar1 + 0x6c) = 0xffffffe2;
        *(undefined2 *)(iVar1 + 0xa6) = 1;
        *(undefined4 *)(g_TutorialPickupGroundShadowSceneEntry + 0x108) =
             *(undefined4 *)(g_PlayerSceneEntry + 0x108);
        *(undefined4 *)(g_TutorialPickupGroundShadowSceneEntry + 0x110) =
             *(undefined4 *)(g_PlayerSceneEntry + 0x110);
        *(undefined4 *)(g_TutorialPickupGroundShadowSceneEntry + 0x10c) =
             *(undefined4 *)(g_PlayerSceneEntry + 0x10c);
        *(ushort *)(g_PlayerGroundShadowProbeSceneEntry + 0xe) =
             *(ushort *)(g_PlayerGroundShadowProbeSceneEntry + 0xe) & 0x7fff;
      }
      FUN_004ac6b0(*(undefined4 *)(&DAT_0051524c + g_ActiveTutorialPickupId * 0x30));
      CEntities__SetSceneEntryScriptAttachment
                (param_1,&g_TutorialPickupTransformScriptAttachmentDesc);
    case 2:
    case 3:
      CEntities__UpdateScriptedSceneEntryAttachment(param_1);
      break;
    case 4:
      g_ActiveCameraAnchorEntry = g_RuntimeEntryPoolBase;
      g_TutorialPickupSequencePhase = 5;
      g_ActiveTutorialPickupId = 0;
      g_PreviousPlayerActionState = g_PlayerActionState;
      g_PlayerActionState = 0x3e;
      (*(code *)PTR_CPlayerHero__EnterYoungTutorialPickupReturnIdle_00514ac8)();
      UnloadEncodedResourceId(0x23);
      CEntities__ReleaseRuntimeEntryAndMarkDescriptorConsumed(param_1);
      g_ActiveTutorialPickupRuntimeEntry = 0;
      return;
    }
  }
  cVar4 = IsRuntimeEntryOutsideOuterActivationBounds(param_1);
  if (cVar4 != '\0') {
    CEntities__ReleaseRuntimeEntryToFreeList(param_1);
  }
  return;
}

