
void WelcomeToTheJungle__UpdateBongo(int param_1)

{
  short sVar1;
  int iVar2;
  char cVar3;
  char cVar4;
  short sVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  bool bVar11;
  
  bVar11 = false;
  iVar8 = *(int *)(param_1 + 0x38);
  if ((iVar8 == 0) || (iVar6 = FindRuntimeEntityAttachmentByFlags(param_1,0x400), iVar6 == 0))
  goto switchD_0043c632_default;
  sVar5 = CEntities__UpdateScriptedSceneEntryAttachment(param_1);
  sVar1 = *(short *)(iVar6 + 0x18);
  CEntities__MoveAnimalFromRuntimeFlagsAndCheckCollision(param_1,iVar8,0x14,0xe);
  cVar3 = CEntities__HandleAnimalScriptEvent(param_1,iVar8,(int)sVar5);
  iVar2 = *(int *)(*(int *)(g_CollisionSurfaceTable + 4 + *(int *)(iVar8 + 0x110) * 4) + 8 +
                   *(int *)(iVar8 + 0x110) * 4 + g_CollisionSurfaceTable);
  iVar10 = *(int *)(iVar8 + 0x10c);
  cVar4 = CEntities__CheckPlayerDamageContact(iVar8);
  if ((cVar4 != '\0') && (bVar11 = true, *(short *)(param_1 + 0x48) == 3)) {
    *(undefined2 *)(param_1 + 0x4a) = 0;
    *(undefined2 *)(param_1 + 0x48) = 0;
  }
  cVar4 = CEntities__CheckEntityHitByPlayerAttackOrThrowable(param_1);
  if ((cVar4 != '\0') && (PlayAudioById(0xf2,0,iVar8 + 0x14), *(short *)(param_1 + 0x48) == 4)) {
    *(undefined4 *)(param_1 + 0x4c) = 0;
    *(undefined2 *)(param_1 + 0x48) = 6;
  }
  switch(*(undefined2 *)(param_1 + 0x48)) {
  case 0:
    CEntities__SelectScriptAttachmentSequence(iVar6,0);
    *(undefined2 *)(param_1 + 0x48) = 1;
    iVar8 = RandomModulo(0x3c);
    *(int *)(param_1 + 0x4c) = iVar8 + 0x1e;
    break;
  case 1:
    iVar8 = *(int *)(param_1 + 0x4c) + -1;
    *(int *)(param_1 + 0x4c) = iVar8;
    if ((-1 < iVar8) || (cVar3 == '\0')) break;
    uVar7 = RandomModulo(4);
    switch(uVar7) {
    case 0:
      *(undefined2 *)(param_1 + 0x48) = 4;
      CEntities__SelectScriptAttachmentSequence(iVar6,1);
      break;
    case 1:
      *(undefined2 *)(param_1 + 0x48) = 4;
      CEntities__SelectScriptAttachmentSequence(iVar6,4);
      break;
    case 2:
    case 3:
      goto switchD_0043c688_caseD_2;
    }
    break;
  case 2:
    if (!bVar11) {
      CEntities__SelectScriptAttachmentSequence(iVar6,7);
      *(undefined2 *)(param_1 + 0x48) = 3;
      iVar8 = RandomModulo(6);
      *(int *)(param_1 + 0x4c) = iVar8 + 6;
      break;
    }
    if (*(char *)(g_PlayerSceneEntry + 0x75) == *(char *)(iVar8 + 0x75)) break;
    goto LAB_0043c751;
  case 3:
    if (cVar3 == '\0') break;
    iVar9 = *(int *)(param_1 + 0x4c) + -1;
    *(int *)(param_1 + 0x4c) = iVar9;
    if (iVar9 < 0) {
      CEntities__SelectScriptAttachmentSequence(iVar6,0xc);
      *(undefined2 *)(param_1 + 0x48) = 4;
    }
    if (*(char *)(iVar8 + 0x75) == '\0') {
      iVar10 = iVar2 - iVar10;
      iVar8 = iVar10 + -500;
      bVar11 = iVar10 == 500;
    }
    else {
      iVar8 = iVar10 + -500;
      bVar11 = iVar8 == 0;
    }
    if (!bVar11 && SBORROW4(iVar10,500) == iVar8 < 0) break;
LAB_0043c751:
    *(undefined2 *)(param_1 + 0x48) = 5;
    CEntities__SelectScriptAttachmentSequence(iVar6,9);
    break;
  case 4:
    if (sVar1 == 0) {
      *(undefined2 *)(param_1 + 0x48) = 0;
    }
    break;
  case 5:
    if (sVar1 == 8) {
      *(undefined2 *)(param_1 + 0x48) = 3;
    }
    break;
  case 6:
    iVar8 = *(int *)(param_1 + 0x4c) + -1;
    *(int *)(param_1 + 0x4c) = iVar8;
    if ((-1 < iVar8) || (cVar3 == '\0')) break;
switchD_0043c688_caseD_2:
    *(undefined2 *)(param_1 + 0x48) = 2;
  }
switchD_0043c632_default:
  cVar3 = IsRuntimeEntryOutsideOuterActivationBounds(param_1);
  if (cVar3 != '\0') {
    CEntities__ReleaseRuntimeEntryToFreeList(param_1);
  }
  return;
}

