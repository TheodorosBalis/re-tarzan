
void WelcomeToTheJungle__UpdateLemur(int param_1)

{
  short sVar1;
  int iVar2;
  char cVar3;
  short sVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  bool bVar11;
  bool bVar12;
  
  iVar9 = *(int *)(param_1 + 0x38);
  if ((iVar9 == 0) || (iVar5 = FindRuntimeEntityAttachmentByFlags(param_1,0x400), iVar5 == 0))
  goto switchD_0043d7ae_default;
  sVar4 = CEntities__UpdateScriptedSceneEntryAttachment(param_1);
  sVar1 = *(short *)(iVar5 + 0x18);
  CEntities__MoveAnimalFromRuntimeFlagsAndCheckCollision(param_1,iVar9,0x14,10);
  iVar6 = CEntities__HandleAnimalScriptEvent(param_1,iVar9,(int)sVar4);
  iVar2 = *(int *)(iVar9 + 0x10c);
  iVar10 = *(int *)(*(int *)(g_CollisionSurfaceTable + 4 + *(int *)(iVar9 + 0x110) * 4) + 8 +
                    *(int *)(iVar9 + 0x110) * 4 + g_CollisionSurfaceTable);
  cVar3 = CEntities__CheckPlayerDamageContact(iVar9);
  if (cVar3 != '\0') {
    g_PlayerDamageContactSceneEntry = iVar9;
    if ((*(byte *)(param_1 + 0x4b) & 1) == 0) {
      QueuePlayerDamageEvent(param_1,7);
      if ((2 < *(ushort *)(param_1 + 0x48)) && (*(ushort *)(param_1 + 0x48) < 6)) {
        *(ushort *)(param_1 + 0x4a) = *(ushort *)(param_1 + 0x4a) & 0xfffc;
        *(undefined2 *)(param_1 + 0x48) = 0;
      }
    }
    else {
      QueuePlayerDamageEvent(param_1,0x1007);
    }
  }
  cVar3 = CEntities__CheckEntityHitByPlayerAttackOrThrowable(param_1);
  if (cVar3 != '\0') {
    PlayAudioById(0x103,0,iVar9 + 0x14);
    if ((*(byte *)(param_1 + 0x4a) & 8) != 0) {
      CEntities__HandleAnimalScriptEvent(param_1,iVar9,0x107);
    }
    *(undefined2 *)(param_1 + 0x48) = 6;
  }
  if (*(short *)(param_1 + 0x3e) < 0) {
    CEntities__ProcessRuntimeEntryDeathAndRelease(param_1,1);
    return;
  }
  switch(*(undefined2 *)(param_1 + 0x48)) {
  case 0:
    if ((*(byte *)(param_1 + 0x4b) & 1) == 0) {
      CEntities__SelectScriptAttachmentSequence(iVar5,0);
      *(undefined2 *)(param_1 + 0x48) = 1;
      iVar9 = RandomModulo(2);
      *(int *)(param_1 + 0x4c) = iVar9 + 1;
    }
    else {
      CEntities__SelectScriptAttachmentSequence(iVar5,0xc);
      *(undefined2 *)(param_1 + 0x48) = 5;
      *(undefined4 *)(param_1 + 0x4c) = 10000;
    }
    break;
  case 1:
    if ((iVar6 == 0) ||
       (iVar9 = *(int *)(param_1 + 0x4c) + -1, *(int *)(param_1 + 0x4c) = iVar9, 0 < iVar9)) break;
    if ((*(byte *)(param_1 + 0x4a) & 0x80) == 0) {
      uVar8 = RandomModulo(7);
      if ((uVar8 & 1) == 0) {
switchD_0043d82c_caseD_2:
        *(undefined2 *)(param_1 + 0x48) = 2;
        break;
      }
switchD_0043d82c_caseD_0:
      *(undefined2 *)(param_1 + 0x48) = 8;
      CEntities__SelectScriptAttachmentSequence(iVar5,1);
    }
    else {
      uVar7 = RandomModulo(7);
      switch(uVar7) {
      case 0:
      case 1:
        goto switchD_0043d82c_caseD_0;
      case 2:
        goto switchD_0043d82c_caseD_2;
      case 3:
      case 4:
      case 5:
      case 6:
        *(undefined2 *)(param_1 + 0x48) = 4;
      }
    }
    break;
  case 2:
    uVar8 = CEntities__ComputeSignedPlayerFacingDistanceXZ(iVar9 + 0x14);
    if (*(char *)(iVar9 + 0x75) != '\0') {
      uVar8 = ~uVar8 + 1;
    }
    if (((int)uVar8 < 1) || (0x1c1 < (int)uVar8)) {
      CEntities__SelectScriptAttachmentSequence(iVar5,4);
      *(undefined2 *)(param_1 + 0x48) = 3;
      iVar9 = RandomModulo(4);
      *(int *)(param_1 + 0x4c) = iVar9 + 3;
      break;
    }
    if (*(char *)(iVar9 + 0x75) == '\0') {
      if (500 < iVar2) {
        CEntities__SelectScriptAttachmentSequence(iVar5,6);
        *(undefined2 *)(param_1 + 0x48) = 7;
        break;
      }
    }
    else if (500 < iVar10 - iVar2) goto LAB_0043d9aa;
    *(undefined2 *)(param_1 + 0x48) = 0;
    break;
  case 3:
    if (iVar6 == 0) break;
    iVar6 = *(int *)(param_1 + 0x4c) + -1;
    *(int *)(param_1 + 0x4c) = iVar6;
    if (iVar6 < 0) {
      CEntities__SelectScriptAttachmentSequence(iVar5,9);
      *(undefined2 *)(param_1 + 0x48) = 8;
    }
    if (*(char *)(iVar9 + 0x75) != '\0') {
      if (iVar2 < 0x1f5) {
        *(undefined2 *)(param_1 + 0x48) = 7;
        CEntities__SelectScriptAttachmentSequence(iVar5,6);
      }
      break;
    }
    iVar10 = iVar10 - iVar2;
    bVar12 = SBORROW4(iVar10,500);
    iVar9 = iVar10 + -500;
    bVar11 = iVar10 == 500;
LAB_0043d9cc:
    if (!bVar11 && bVar12 == iVar9 < 0) break;
    if ((*(byte *)(param_1 + 0x4b) & 1) != 0) {
      CEntities__ReleaseRuntimeEntryAndMarkDescriptorConsumed(param_1);
      return;
    }
    goto LAB_0043d9aa;
  case 4:
    CEntities__SelectScriptAttachmentSequence(iVar5,0xc);
    *(undefined2 *)(param_1 + 0x48) = 5;
    iVar9 = RandomModulo(4);
    *(int *)(param_1 + 0x4c) = iVar9 + 4;
    break;
  case 5:
    if (iVar6 == 0) break;
    iVar6 = *(int *)(param_1 + 0x4c) + -1;
    *(int *)(param_1 + 0x4c) = iVar6;
    if (iVar6 < 0) {
      CEntities__SelectScriptAttachmentSequence(iVar5,0x11);
      *(undefined2 *)(param_1 + 0x48) = 8;
    }
    if (*(char *)(iVar9 + 0x75) == '\0') {
      iVar10 = iVar10 - iVar2;
      bVar12 = SBORROW4(iVar10,700);
      iVar9 = iVar10 + -700;
      bVar11 = iVar10 == 700;
      goto LAB_0043d9cc;
    }
    if (700 < iVar2) break;
LAB_0043d9aa:
    *(undefined2 *)(param_1 + 0x48) = 7;
    CEntities__SelectScriptAttachmentSequence(iVar5,6);
    break;
  case 6:
    *(ushort *)(param_1 + 0x4a) = *(ushort *)(param_1 + 0x4a) & 0xfffc;
    CEntities__SelectScriptAttachmentSequence(iVar5,0x14);
    *(undefined2 *)(param_1 + 0x48) = 8;
    break;
  case 7:
    if (sVar1 == 5) {
      *(undefined2 *)(param_1 + 0x48) = 3;
    }
    break;
  case 8:
    if (sVar1 == 0) {
      *(undefined2 *)(param_1 + 0x48) = 0;
    }
  }
switchD_0043d7ae_default:
  cVar3 = IsRuntimeEntryOutsideOuterActivationBounds(param_1);
  if (cVar3 != '\0') {
    CEntities__ReleaseRuntimeEntryToFreeList(param_1);
  }
  return;
}

