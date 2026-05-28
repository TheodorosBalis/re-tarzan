
void WelcomeToTheJungle__UpdateCivet(int param_1)

{
  short sVar1;
  int iVar2;
  char cVar3;
  char cVar4;
  short sVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  
  iVar10 = *(int *)(param_1 + 0x38);
  if ((iVar10 == 0) || (iVar6 = FindRuntimeEntityAttachmentByFlags(param_1,0x400), iVar6 == 0))
  goto switchD_0043d2b2_caseD_4;
  sVar5 = CEntities__UpdateScriptedSceneEntryAttachment(param_1);
  sVar1 = *(short *)(iVar6 + 0x18);
  CEntities__MoveAnimalFromRuntimeFlagsAndCheckCollision(param_1,iVar10,0x28,0x1e);
  cVar3 = CEntities__HandleAnimalScriptEvent(param_1,iVar10,(int)sVar5);
  iVar2 = *(int *)(*(int *)(g_CollisionSurfaceTable + 4 + *(int *)(iVar10 + 0x110) * 4) + 8 +
                   *(int *)(iVar10 + 0x110) * 4 + g_CollisionSurfaceTable);
  iVar9 = *(int *)(iVar10 + 0x10c);
  cVar4 = CEntities__CheckPlayerDamageContact(iVar10);
  if ((cVar4 != '\0') &&
     (QueuePlayerDamageEvent(param_1,7), g_PlayerDamageContactSceneEntry = iVar10,
     *(short *)(param_1 + 0x48) != 1)) {
    *(ushort *)(param_1 + 0x4a) = *(ushort *)(param_1 + 0x4a) & 0xfffc;
    *(undefined2 *)(param_1 + 0x48) = 0;
  }
  cVar4 = CEntities__CheckEntityHitByPlayerAttackOrThrowable(param_1);
  if (cVar4 != '\0') {
    PlayAudioById(0xef,0,iVar10 + 0x14);
    if ((*(byte *)(param_1 + 0x4a) & 8) != 0) {
      CEntities__HandleAnimalScriptEvent(param_1,iVar10,0x107);
    }
    *(undefined2 *)(param_1 + 0x48) = 6;
  }
  if (*(short *)(param_1 + 0x3e) < 1) {
    CEntities__ProcessRuntimeEntryDeathAndRelease(param_1,1);
    return;
  }
  switch(*(undefined2 *)(param_1 + 0x48)) {
  case 0:
    CEntities__SelectScriptAttachmentSequence(iVar6,0);
    *(undefined2 *)(param_1 + 0x48) = 1;
    iVar10 = RandomModulo(2);
    *(int *)(param_1 + 0x4c) = iVar10 + 1;
    break;
  case 1:
    if ((cVar3 != '\0') &&
       ((iVar7 = *(int *)(param_1 + 0x4c) + -1, *(int *)(param_1 + 0x4c) = iVar7, iVar7 < 0 ||
        ((*(byte *)(param_1 + 0x4b) & 2) != 0)))) {
      PlayAudioById(0xee,0,iVar10 + 0x14);
      uVar8 = CEntities__ComputeSignedPlayerFacingDistanceXZ(iVar10 + 0x14);
      if (*(char *)(iVar10 + 0x75) != '\0') {
        uVar8 = ~uVar8 + 1;
      }
      if (((int)uVar8 < 1) || (499 < (int)uVar8)) {
        *(undefined2 *)(param_1 + 0x48) = 2;
      }
      else {
        if (*(char *)(iVar10 + 0x75) != '\0') {
          iVar9 = iVar2 - iVar9;
        }
        if (iVar9 < 0x259) {
          *(undefined2 *)(param_1 + 0x48) = 0;
        }
        else {
          CEntities__SelectScriptAttachmentSequence(iVar6,7);
          *(undefined2 *)(param_1 + 0x48) = 7;
        }
      }
    }
    break;
  case 2:
    CEntities__SelectScriptAttachmentSequence(iVar6,1);
    *(undefined2 *)(param_1 + 0x48) = 3;
    iVar10 = RandomModulo(10);
    *(int *)(param_1 + 0x4c) = iVar10 + 5;
    break;
  case 3:
    if (*(char *)(iVar10 + 0x75) == '\0') {
      if (0x226 < iVar2 - iVar9) break;
      if ((*(byte *)(param_1 + 0x4b) & 2) != 0) {
        CEntities__ReleaseRuntimeEntryAndMarkDescriptorConsumed(param_1);
        return;
      }
    }
    else if (0x226 < iVar9) break;
    *(undefined2 *)(param_1 + 0x48) = 7;
    CEntities__SelectScriptAttachmentSequence(iVar6,6);
    break;
  case 6:
    *(ushort *)(param_1 + 0x4a) = *(ushort *)(param_1 + 0x4a) & 0xfffc;
    CEntities__SelectScriptAttachmentSequence(iVar6,10);
    *(undefined2 *)(param_1 + 0x48) = 8;
    break;
  case 7:
    goto joined_r0x0043d3f9;
  case 8:
joined_r0x0043d3f9:
    if (sVar1 == 0) {
      *(undefined2 *)(param_1 + 0x48) = 0;
    }
  }
switchD_0043d2b2_caseD_4:
  cVar3 = IsRuntimeEntryOutsideOuterActivationBounds(param_1);
  if (cVar3 != '\0') {
    CEntities__ReleaseRuntimeEntryToFreeList(param_1);
  }
  return;
}

