
void WelcomeToTheJungle__UpdateCivetCub(int param_1)

{
  short sVar1;
  char cVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  
  iVar5 = *(int *)(param_1 + 0x38);
  if ((iVar5 == 0) || (iVar4 = FindRuntimeEntityAttachmentByFlags(param_1,0x400), iVar4 == 0))
  goto switchD_0043cbf6_caseD_2;
  sVar3 = CEntities__UpdateScriptedSceneEntryAttachment(param_1);
  sVar1 = *(short *)(iVar4 + 0x18);
  CEntities__MoveAnimalFromRuntimeFlagsAndCheckCollision(param_1,iVar5,0x10,10);
  sVar3 = CEntities__HandleAnimalScriptEvent(param_1,iVar5,(int)sVar3);
  iVar9 = *(int *)(*(int *)(g_CollisionSurfaceTable + 4 + *(int *)(iVar5 + 0x110) * 4) + 8 +
                   *(int *)(iVar5 + 0x110) * 4 + g_CollisionSurfaceTable);
  iVar8 = *(int *)(iVar5 + 0x10c);
  cVar2 = CEntities__CheckPlayerDamageContact(iVar5);
  if (cVar2 != '\0') {
    g_PlayerDamageContactSceneEntry = iVar5;
    if ((*(byte *)(param_1 + 0x4b) & 2) == 0) {
      QueuePlayerDamageEvent(param_1,7);
      switch(*(undefined2 *)(param_1 + 0x48)) {
      case 3:
      case 4:
      case 7:
      case 8:
        *(ushort *)(param_1 + 0x4a) = *(ushort *)(param_1 + 0x4a) & 0xfffc;
        *(undefined2 *)(param_1 + 0x48) = 0;
      }
    }
    else {
      QueuePlayerDamageEvent(param_1,0x1007);
    }
  }
  cVar2 = CEntities__CheckEntityHitByPlayerAttackOrThrowable(param_1);
  if (cVar2 != '\0') {
    PlayAudioById(0x139,0,iVar5 + 0x14);
    if ((*(byte *)(param_1 + 0x4a) & 8) != 0) {
      CEntities__HandleAnimalScriptEvent(param_1,iVar5,0x107);
    }
    *(undefined2 *)(param_1 + 0x48) = 5;
  }
  if (*(short *)(param_1 + 0x3e) < 1) {
    CEntities__ProcessRuntimeEntryDeathAndRelease(param_1,1);
    return;
  }
  switch(*(undefined2 *)(param_1 + 0x48)) {
  case 0:
    if ((*(byte *)(param_1 + 0x4b) & 2) == 0) {
      *(undefined2 *)(param_1 + 0x48) = 1;
      iVar5 = RandomModulo(0x1e);
      *(int *)(param_1 + 0x4c) = iVar5 + 0x1e;
      CEntities__SelectScriptAttachmentSequence(iVar4,0);
      break;
    }
LAB_0043cc03:
    *(undefined2 *)(param_1 + 0x48) = 3;
    CEntities__SelectScriptAttachmentSequence(iVar4,4);
    break;
  case 1:
    iVar6 = *(int *)(param_1 + 0x4c) + -1;
    *(int *)(param_1 + 0x4c) = iVar6;
    if (-1 < iVar6) break;
    if (*(char *)(iVar5 + 0x75) == '\0') {
      if (400 < iVar9 - iVar8) goto LAB_0043cca2;
      *(undefined2 *)(param_1 + 0x48) = 6;
      CEntities__SelectScriptAttachmentSequence(iVar4,9);
      uVar10 = 0x137;
    }
    else if (iVar8 < 0x191) {
      *(undefined2 *)(param_1 + 0x48) = 6;
      CEntities__SelectScriptAttachmentSequence(iVar4,9);
      uVar10 = 0x137;
    }
    else {
LAB_0043cca2:
      uVar7 = CEntities__ComputeSignedPlayerFacingDistanceXZ(iVar5 + 0x14);
      if (*(char *)(iVar5 + 0x75) != '\0') {
        uVar7 = ~uVar7 + 1;
      }
      if (((int)uVar7 < 1) || (0x1c1 < (int)uVar7)) goto LAB_0043cc03;
      if (*(char *)(iVar5 + 0x75) != '\0') {
        iVar8 = iVar9 - iVar8;
      }
      if (iVar8 < 0x1f5) {
        *(undefined2 *)(param_1 + 0x48) = 0;
        break;
      }
      *(undefined2 *)(param_1 + 0x48) = 6;
      CEntities__SelectScriptAttachmentSequence(iVar4,9);
      uVar10 = 0x137;
    }
LAB_0043ce44:
    PlayAudioById(uVar10,0,iVar5 + 0x14);
    break;
  case 3:
    if (sVar3 != 0) {
      if (*(char *)(iVar5 + 0x75) == '\0') {
        if (400 < iVar9 - iVar8) break;
        if ((*(byte *)(param_1 + 0x4b) & 2) != 0) {
          CEntities__ReleaseRuntimeEntryAndMarkDescriptorConsumed(param_1);
          return;
        }
      }
      else if (400 < iVar8) break;
      *(undefined2 *)(param_1 + 0x48) = 4;
      CEntities__SelectScriptAttachmentSequence(iVar4,6);
    }
    break;
  case 4:
    if (sVar1 == 0) {
      if ((*(byte *)(param_1 + 0x4b) & 4) == 0) {
        *(undefined2 *)(param_1 + 0x48) = 1;
        *(undefined4 *)(param_1 + 0x4c) = 0;
        CEntities__SelectScriptAttachmentSequence(iVar4,0);
      }
      else if (*(char *)(iVar5 + 0x75) == '\0') {
        *(undefined2 *)(param_1 + 0x48) = 7;
        CEntities__SelectScriptAttachmentSequence(iVar4,1);
      }
      else {
        *(undefined2 *)(param_1 + 0x48) = 0;
      }
    }
    break;
  case 5:
    *(ushort *)(param_1 + 0x4a) = *(ushort *)(param_1 + 0x4a) & 0xfffc;
    CEntities__SelectScriptAttachmentSequence(iVar4,0xc);
    *(undefined2 *)(param_1 + 0x48) = 6;
    break;
  case 6:
    if (sVar1 == 0) {
      if ((*(byte *)(param_1 + 0x4b) & 2) == 0) {
        *(undefined2 *)(param_1 + 0x48) = 1;
        *(undefined4 *)(param_1 + 0x4c) = 0;
      }
      else {
        *(undefined2 *)(param_1 + 0x48) = 0;
      }
    }
    break;
  case 7:
    iVar4 = RandomModulo(3);
    *(int *)(param_1 + 0x4c) = iVar4 + 1;
    *(undefined2 *)(param_1 + 0x48) = 8;
    PlayAudioById(0x138,0,iVar5 + 0x14);
    break;
  case 8:
    if (sVar1 != 0) break;
    iVar9 = *(int *)(param_1 + 0x4c) + -1;
    *(int *)(param_1 + 0x4c) = iVar9;
    if (iVar9 < 1) {
      *(undefined2 *)(param_1 + 0x48) = 0;
      break;
    }
    CEntities__SelectScriptAttachmentSequence(iVar4,1);
    uVar10 = 0x138;
    goto LAB_0043ce44;
  }
switchD_0043cbf6_caseD_2:
  cVar2 = IsRuntimeEntryOutsideOuterActivationBounds(param_1);
  if (cVar2 != '\0') {
    CEntities__ReleaseRuntimeEntryToFreeList(param_1);
  }
  return;
}

