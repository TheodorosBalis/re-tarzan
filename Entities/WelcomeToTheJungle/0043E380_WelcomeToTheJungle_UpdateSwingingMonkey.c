
void WelcomeToTheJungle__UpdateSwingingMonkey(int param_1)

{
  short sVar1;
  short sVar2;
  short sVar3;
  longlong lVar4;
  char cVar5;
  short sVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int iStack_c;
  int iStack_8;
  int iStack_4;
  
  LoadEncodedResourceId(0x1014);
  iVar9 = *(int *)(param_1 + 0x38);
  if ((iVar9 == 0) || (iVar7 = FindRuntimeEntityAttachmentByFlags(param_1,0x400), iVar7 == 0))
  goto switchD_0043e4c1_caseD_2;
  sVar6 = CEntities__UpdateScriptedSceneEntryAttachment(param_1);
  sVar1 = *(short *)(iVar7 + 0x18);
  CEntities__HandleAnimalScriptEvent(param_1,iVar9,(int)sVar6);
  cVar5 = CEntities__CheckEntityHitByPlayerAttackOrThrowable(param_1);
  if (cVar5 == '\0') {
    cVar5 = CEntities__CheckPlayerDamageContact(iVar9);
    if (cVar5 != '\0') {
      QueuePlayerDamageEvent(param_1,0x2006);
    }
  }
  else {
    if (*(short *)(param_1 + 0x3e) < 1) goto LAB_0043e429;
    PlayAudioById(0x112,0,iVar9 + 0x14);
    *(undefined2 *)(param_1 + 0x48) = 8;
  }
  if (*(short *)(param_1 + 0x3e) < 1) {
LAB_0043e429:
    PlayAudioById(0x158,0,iVar9 + 0x14);
    *(int *)(iVar9 + 0x18) = *(int *)(iVar9 + 0x18) + 0x200;
    CEntities__ProcessRuntimeEntryDeathAndRelease(param_1,1);
    return;
  }
  if ((*(byte *)(param_1 + 0x4a) & 0x80) == 0) {
    iVar8 = GetAngleFromXZVector12Bit
                      (*(int *)(iVar9 + 0x14) - *(int *)(g_PlayerSceneEntryData + 8),
                       *(int *)(iVar9 + 0x1c) - *(int *)(g_PlayerSceneEntryData + 0x10));
    lVar4 = (longlong)((iVar8 - *(short *)(iVar9 + 0xa2)) * 0x100000 >> 0x14) * 0x55555556;
    *(short *)(iVar9 + 0xa2) =
         ((short)((ulonglong)lVar4 >> 0x20) - (short)(lVar4 >> 0x3f)) + *(short *)(iVar9 + 0xa2);
  }
  switch(*(undefined2 *)(param_1 + 0x48)) {
  case 0:
    iVar9 = RandomModulo(10);
    *(int *)(param_1 + 0x4c) = iVar9 + 10;
    *(undefined2 *)(param_1 + 0x48) = 1;
    break;
  case 1:
    iVar9 = *(int *)(param_1 + 0x4c) + -1;
    *(int *)(param_1 + 0x4c) = iVar9;
    if (iVar9 < 1) {
      *(undefined2 *)(param_1 + 0x48) = 4;
    }
    break;
  case 4:
    iVar8 = FUN_00430d40(param_1,g_PlayerRuntimeEntry);
    if (((iVar8 != 0) && (299 < *(int *)(g_PlayerSceneEntry + 0x18) - *(int *)(iVar9 + 0x18))) &&
       (iVar9 = CEntities__ComputeSceneEntryDataDistance3D(iVar9 + 0xc,g_PlayerSceneEntryData),
       iVar9 <= *(int *)(param_1 + 0x50))) {
      CEntities__SelectScriptAttachmentSequence(iVar7,1);
      *(undefined2 *)(param_1 + 0x48) = 5;
      break;
    }
    goto LAB_0043e72a;
  case 5:
    if (sVar6 == 0xb) {
      iVar9 = GetSceneAttachmentWorldPositionByMask(iVar9,0x100,&iStack_c);
      if ((iVar9 == 0) ||
         (iVar9 = CEntities__SpawnRuntimeEntryByTypeAtPosition(iStack_c,iStack_8,iStack_4,0x1a,0x11)
         , iVar9 == 0)) break;
      iVar9 = CEntities__CreateRuntimeEntryAttachment(iVar9,0x9c,0x10000000);
      if (iVar9 != 0) {
        iVar8 = iStack_c - *(int *)(g_PlayerSceneEntryData + 8);
        iStack_8 = iStack_8 - *(int *)(g_PlayerSceneEntryData + 0xc);
        iVar11 = iStack_4 - *(int *)(g_PlayerSceneEntryData + 0x10);
        iVar7 = SqrtToInt(iStack_8 * iStack_8 + iVar8 * iVar8 + iVar11 * iVar11);
        iVar12 = iVar7 >> 6;
        SqrtToInt(iVar8 * iVar8 + iVar11 * iVar11);
        uVar10 = GetAngleFromXZVector12Bit(iVar8,iVar11);
        iVar8 = RandomModulo(700);
        sVar6 = ((short)(iVar12 / 0x50) + (short)(iVar7 >> 0x1f)) -
                (short)((longlong)iVar12 * 0x66666667 >> 0x3f);
        *(undefined4 *)(iVar9 + 0x1c) = 6;
        *(short *)(iVar9 + 0x18) = sVar6;
        if (sVar6 == 0) {
          *(undefined2 *)(iVar9 + 0x18) = 1;
        }
        sVar6 = (&g_SinCosTable12Bit)[uVar10 & 0xfff];
        sVar2 = (&g_SinCosTable12Bit)[uVar10 - 0x400 & 0xfff];
        sVar3 = (&g_SinCosTable12Bit)[iVar8 + 0x514U & 0xfff];
        *(undefined1 *)(iVar9 + 0x20) = 0;
        uVar10 = (uint)*(ushort *)(iVar9 + 0x18);
        *(int *)(iVar9 + 0xc) =
             (int)(CONCAT44(sVar2 * iVar12 >> 0x1f,sVar2 * iVar12 >> 0xc) / (longlong)(int)uVar10);
        *(int *)(iVar9 + 0x14) =
             (int)(CONCAT44(sVar6 * iVar12 >> 0x1f,sVar6 * iVar12 >> 0xc) / (longlong)(int)uVar10);
        *(ushort *)(iVar9 + 0x18) = *(ushort *)(iVar9 + 0x18) * 4;
        *(uint *)(iVar9 + 0x10) =
             (int)(CONCAT44(sVar3 * iVar12 >> 0x1f,sVar3 * iVar12 >> 0xc) / (longlong)(int)uVar10) +
             uVar10 * 3;
        if ((*(int *)(param_1 + 0x34) != 0) &&
           (iVar7 = *(int *)(*(int *)(*(int *)(param_1 + 0x34) + 0x10) + 4), iVar7 != 0)) {
          *(short *)(iVar9 + 0x18) = (short)iVar7;
        }
      }
    }
    if (sVar1 == 0) {
      *(ushort *)(param_1 + 0x4a) = *(ushort *)(param_1 + 0x4a) & 0xfeff;
      *(undefined2 *)(param_1 + 0x48) = 0;
    }
    break;
  case 8:
    *(undefined2 *)(param_1 + 0x48) = 0xd;
    CEntities__SelectScriptAttachmentSequence(iVar7,4);
    break;
  case 0xd:
    if (sVar1 != 0) break;
LAB_0043e72a:
    *(undefined2 *)(param_1 + 0x48) = 0;
  }
switchD_0043e4c1_caseD_2:
  cVar5 = IsRuntimeEntryOutsideOuterActivationBounds(param_1);
  if (cVar5 != '\0') {
    CEntities__ReleaseRuntimeEntryToFreeList(param_1);
  }
  return;
}

