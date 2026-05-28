
void WelcomeToTheJungle__UpdatePangolin(int param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  char cVar5;
  short sVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  
  iVar9 = *(int *)(param_1 + 0x38);
  if ((iVar9 != 0) && (iVar7 = FindRuntimeEntityAttachmentByFlags(param_1,0x400), iVar7 != 0)) {
    sVar6 = CEntities__UpdateScriptedSceneEntryAttachment(param_1);
    sVar1 = *(short *)(iVar7 + 0x18);
    CEntities__MoveAnimalFromRuntimeFlagsAndCheckCollision(param_1,iVar9,0x14,0xe);
    cVar4 = CEntities__HandleAnimalScriptEvent(param_1,iVar9,(int)sVar6);
    iVar2 = *(int *)(*(int *)(g_CollisionSurfaceTable + 4 + *(int *)(iVar9 + 0x110) * 4) + 8 +
                     *(int *)(iVar9 + 0x110) * 4 + g_CollisionSurfaceTable);
    iVar3 = *(int *)(iVar9 + 0x10c);
    cVar5 = CEntities__CheckPlayerDamageContact(iVar9);
    if (cVar5 != '\0') {
      QueuePlayerDamageEvent(param_1,3);
      g_PlayerDamageContactSceneEntry = iVar9;
      if ((1 < *(ushort *)(param_1 + 0x48)) && (*(ushort *)(param_1 + 0x48) < 4)) {
        *(ushort *)(param_1 + 0x4a) = *(ushort *)(param_1 + 0x4a) & 0xfffc;
        *(undefined2 *)(param_1 + 0x48) = 0;
      }
    }
    cVar5 = CEntities__CheckEntityHitByPlayerAttackOrThrowable(param_1);
    if (cVar5 != '\0') {
      PlayAudioById(0x13e,0,iVar9 + 0x14);
      if ((*(byte *)(param_1 + 0x4a) & 8) != 0) {
        CEntities__HandleAnimalScriptEvent(param_1,iVar9,0x107);
      }
      *(ushort *)(param_1 + 0x4a) = *(ushort *)(param_1 + 0x4a) & 0xfffc;
      *(undefined2 *)(param_1 + 0x48) = 0;
    }
    if (*(short *)(param_1 + 0x3e) < 1) {
      CEntities__ProcessRuntimeEntryDeathAndRelease(param_1,1);
      return;
    }
    switch(*(undefined2 *)(param_1 + 0x48)) {
    case 0:
      CEntities__SelectScriptAttachmentSequence(iVar7,0);
      *(undefined2 *)(param_1 + 0x48) = 1;
      iVar9 = RandomModulo(3);
      *(int *)(param_1 + 0x4c) = iVar9 + 3;
      break;
    case 1:
      if ((cVar4 != '\0') &&
         (iVar10 = *(int *)(param_1 + 0x4c) + -1, *(int *)(param_1 + 0x4c) = iVar10, iVar10 < 0)) {
        iVar10 = iVar9 + 0x14;
        uVar8 = CEntities__ComputeSignedPlayerFacingDistanceXZ(iVar10);
        if (*(char *)(iVar9 + 0x75) != '\0') {
          uVar8 = ~uVar8 + 1;
        }
        if (((int)uVar8 < 1) || (499 < (int)uVar8)) {
          *(undefined2 *)(param_1 + 0x48) = 2;
        }
        else {
          if (*(char *)(iVar9 + 0x75) == '\0') {
            if (800 < iVar3) {
              *(undefined2 *)(param_1 + 0x48) = 4;
              CEntities__SelectScriptAttachmentSequence(iVar7,3);
              PlayAudioById(0x155,0,iVar10);
              break;
            }
          }
          else if (800 < iVar2 - iVar3) {
            *(undefined2 *)(param_1 + 0x48) = 4;
            CEntities__SelectScriptAttachmentSequence(iVar7,3);
            PlayAudioById(0x155,0,iVar10);
            break;
          }
          *(undefined2 *)(param_1 + 0x48) = 0;
        }
      }
      break;
    case 2:
      CEntities__SelectScriptAttachmentSequence(iVar7,1);
      *(undefined2 *)(param_1 + 0x48) = 3;
      iVar9 = RandomModulo(0xc);
      *(int *)(param_1 + 0x4c) = iVar9 + 6;
      break;
    case 3:
      if (cVar4 != '\0') {
        iVar10 = *(int *)(param_1 + 0x4c) + -1;
        *(int *)(param_1 + 0x4c) = iVar10;
        if (iVar10 < 0) {
          CEntities__SelectScriptAttachmentSequence(iVar7,6);
          *(undefined2 *)(param_1 + 0x48) = 5;
        }
        if (*(char *)(iVar9 + 0x75) == '\0') {
          if (iVar2 - iVar3 < 0x28b) {
            *(undefined2 *)(param_1 + 0x48) = 4;
            CEntities__SelectScriptAttachmentSequence(iVar7,3);
            PlayAudioById(0x155,0,iVar9 + 0x14);
          }
        }
        else if (iVar3 < 0x28b) {
          *(undefined2 *)(param_1 + 0x48) = 4;
          CEntities__SelectScriptAttachmentSequence(iVar7,3);
          PlayAudioById(0x155,0,iVar9 + 0x14);
        }
      }
      break;
    case 4:
      if (sVar1 == 2) {
        *(undefined2 *)(param_1 + 0x48) = 3;
      }
      break;
    case 5:
      if (sVar1 == 0) {
        *(undefined2 *)(param_1 + 0x48) = 0;
      }
    }
  }
  cVar4 = IsRuntimeEntryOutsideOuterActivationBounds(param_1);
  if (cVar4 != '\0') {
    CEntities__ReleaseRuntimeEntryToFreeList(param_1);
  }
  return;
}

