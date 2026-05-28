
void WelcomeToTheJungle__UpdateMonkey(int param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  char cVar5;
  char cVar6;
  short sVar7;
  int iVar8;
  int iVar9;
  
  LoadEncodedResourceId(0x1015);
  iVar9 = *(int *)(param_1 + 0x38);
  if ((iVar9 == 0) || (iVar8 = FindRuntimeEntityAttachmentByFlags(param_1,0x400), iVar8 == 0))
  goto switchD_0043dfed_caseD_4;
  sVar7 = CEntities__UpdateScriptedSceneEntryAttachment(param_1);
  sVar1 = *(short *)(iVar8 + 0x18);
  CEntities__MoveAnimalFromRuntimeFlagsAndCheckCollision(param_1,iVar9,0x24,0x14);
  cVar5 = CEntities__HandleAnimalScriptEvent(param_1,iVar9,(int)sVar7);
  iVar2 = *(int *)(iVar9 + 0x10c);
  iVar3 = *(int *)(*(int *)(g_CollisionSurfaceTable + 4 + *(int *)(iVar9 + 0x110) * 4) + 8 +
                   *(int *)(iVar9 + 0x110) * 4 + g_CollisionSurfaceTable);
  cVar6 = CEntities__CheckPlayerDamageContact(iVar9);
  if (cVar6 != '\0') {
    g_PlayerDamageContactSceneEntry = iVar9;
    QueuePlayerDamageEvent(param_1,0x1006);
  }
  bVar4 = false;
  cVar6 = CEntities__CheckEntityHitByPlayerAttackOrThrowable(param_1);
  if (cVar6 != '\0') {
    if (*(short *)(param_1 + 0x3e) < 1) goto LAB_0043dfbb;
    PlayAudioById(0x112,0,iVar9 + 0x14);
    bVar4 = true;
  }
  if (*(short *)(param_1 + 0x3e) < 1) {
LAB_0043dfbb:
    PlayAudioById(0x158,0,iVar9 + 0x14);
    CEntities__ProcessRuntimeEntryDeathAndRelease(param_1,1);
    return;
  }
  switch(*(undefined2 *)(param_1 + 0x48)) {
  case 0:
    if (bVar4) {
      *(undefined2 *)(param_1 + 0x48) = 9;
    }
    else {
      CEntities__SelectScriptAttachmentSequence(iVar8,0);
      *(undefined2 *)(param_1 + 0x48) = 1;
    }
    break;
  case 1:
    if (bVar4) {
      *(undefined2 *)(param_1 + 0x48) = 9;
      break;
    }
    if ((*(ushort *)(param_1 + 0x4a) & 0x80) == 0) {
      iVar9 = CEntities__ComputeSceneEntryDataDistance3D(iVar9 + 0xc,g_PlayerSceneEntryData);
      if (0x419 < iVar9) break;
    }
    else if ((*(ushort *)(param_1 + 0x4a) & 0x800) != 0) {
LAB_0043e106:
      CEntities__SelectScriptAttachmentSequence(iVar8,10);
      *(undefined2 *)(param_1 + 0x48) = 0xf;
      break;
    }
    *(undefined2 *)(param_1 + 0x48) = 2;
    break;
  case 2:
    if (bVar4) {
      *(undefined2 *)(param_1 + 0x48) = 10;
    }
    else {
      CEntities__SelectScriptAttachmentSequence(iVar8,1);
      *(undefined2 *)(param_1 + 0x48) = 3;
    }
    break;
  case 3:
    if (bVar4) {
      *(undefined2 *)(param_1 + 0x48) = 10;
      break;
    }
    if (cVar5 == '\0') break;
    if (*(char *)(iVar9 + 0x75) == '\0') {
      if (0x400 < iVar3 - iVar2) goto LAB_0043e0f2;
      if ((*(byte *)(param_1 + 0x4b) & 4) != 0) {
        CEntities__ReleaseRuntimeEntryAndMarkDescriptorConsumed(param_1);
        return;
      }
    }
    else if (0x400 < iVar2) {
LAB_0043e0f2:
      if ((((*(char *)(iVar9 + 0x75) == '\0') || ((*(byte *)(param_1 + 0x4b) & 1) == 0)) ||
          (iVar2 < 0x601)) &&
         ((((*(byte *)(param_1 + 0x4b) & 2) == 0 ||
           (iVar9 = CEntities__ComputeSceneEntryDataDistance3D(iVar9 + 0xc,g_PlayerSceneEntryData),
           799 < iVar9)) || (iVar9 = FUN_00430d40(param_1,g_PlayerRuntimeEntry), iVar9 == 0))))
      break;
      goto LAB_0043e106;
    }
    CEntities__SelectScriptAttachmentSequence(iVar8,6);
    *(undefined2 *)(param_1 + 0x48) = 0xc;
    break;
  case 9:
    if ((*(byte *)(param_1 + 0x4a) & 8) != 0) {
      CEntities__HandleAnimalScriptEvent(param_1,iVar9,0x107);
    }
    *(ushort *)(param_1 + 0x4a) = *(ushort *)(param_1 + 0x4a) & 0xfffc;
    CEntities__SelectScriptAttachmentSequence(iVar8,0x12);
    *(undefined2 *)(param_1 + 0x48) = 0xc;
    break;
  case 10:
    *(ushort *)(param_1 + 0x4a) = *(ushort *)(param_1 + 0x4a) & 0xfffc;
    CEntities__SelectScriptAttachmentSequence(iVar8,0x18);
    *(undefined2 *)(param_1 + 0x48) = 0xe;
    break;
  case 0xc:
    if (sVar1 == 0) {
      *(undefined2 *)(param_1 + 0x48) = 0;
    }
    break;
  case 0xe:
    if (sVar1 == 2) {
      *(undefined2 *)(param_1 + 0x48) = 3;
    }
    break;
  case 0xf:
    if (*(char *)(iVar9 + 0x75) == '\0') {
      if (iVar3 - iVar2 < 0x601) {
        CEntities__AdvanceScriptAttachmentSequence(iVar8);
        *(undefined2 *)(param_1 + 0x48) = 3;
      }
    }
    else if (iVar2 < 0x601) {
      CEntities__AdvanceScriptAttachmentSequence(iVar8);
      *(undefined2 *)(param_1 + 0x48) = 3;
    }
  }
switchD_0043dfed_caseD_4:
  cVar5 = IsRuntimeEntryOutsideOuterActivationBounds(param_1);
  if (cVar5 != '\0') {
    CEntities__ReleaseRuntimeEntryToFreeList(param_1);
  }
  return;
}

