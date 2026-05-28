
void CEntities__UpdateSwings(int param_1)

{
  int iVar1;
  char cVar2;
  ushort uVar3;
  short sVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  
  iVar1 = *(int *)(param_1 + 0x38);
  if (iVar1 == 0) {
    CEntities__ReleaseRuntimeEntryToFreeList(param_1);
  }
  else {
    iVar5 = FindRuntimeEntityAttachmentByFlags(param_1,0x8000000);
    if (iVar5 != 0) {
      SyncSwingStateToSceneEntry(iVar1,iVar5);
      if ((*(int *)(param_1 + 0x24) == 0) && (*(short *)(iVar5 + 0x12) != 0)) {
        CEntities__LinkRuntimeEntryIntoProcessingList(&g_ActiveSwingRuntimeEntryList,param_1);
      }
      sVar4 = *(short *)(iVar5 + 0xe);
      if (sVar4 == 2) {
        iVar7 = *(int *)(iVar5 + 0x14) + *(int *)(iVar5 + 0x18);
        *(int *)(iVar5 + 0x14) = iVar7;
        if (*(int *)(iVar5 + 0x20) < iVar7) {
          *(int *)(iVar5 + 0x14) = *(int *)(iVar5 + 0x20);
        }
        *(short *)(iVar5 + 0x10) = *(short *)(iVar5 + 0x10) + 1;
        uVar6 = (uint)*(ushort *)(iVar5 + 0x10);
        if (*(short *)(g_ActiveSwingMotionTable + uVar6 * 0xc) < 0) {
          sVar4 = *(short *)(g_ActiveSwingMotionTable + uVar6 * 0xc + 2);
          uVar6 = (uint)sVar4;
          *(short *)(iVar5 + 0x10) = sVar4;
        }
        uVar3 = *(ushort *)(g_ActiveSwingMotionTable + 2 + uVar6 * 0xc);
        if ((uVar3 & 0x800) == 0) {
          uVar3 = uVar3 & 0x7ff;
        }
        else {
          uVar3 = uVar3 | 0xf800;
        }
        sVar4 = (short)((uint)((int)(short)uVar3 * *(int *)(iVar5 + 0x14)) >> 8);
        *(short *)(iVar1 + 0xa0) = sVar4;
        *(short *)(iVar1 + 0x80) = -((sVar4 >> 2) + sVar4);
        *(short *)(iVar1 + 0x7a) = (short)g_CurrentSwingSegmentIndex + 1;
      }
      else if (sVar4 == 4) {
        iVar7 = *(int *)(iVar5 + 0x14) - *(int *)(iVar5 + 0x1c);
        *(int *)(iVar5 + 0x14) = iVar7;
        if (iVar7 < 0) {
          *(undefined4 *)(iVar5 + 0x14) = 0;
          *(undefined2 *)(iVar5 + 0xe) = 1;
        }
        *(short *)(iVar5 + 0x10) = *(short *)(iVar5 + 0x10) + 1;
        uVar6 = (uint)*(ushort *)(iVar5 + 0x10);
        if (*(short *)(g_ActiveSwingMotionTable + uVar6 * 0xc) < 0) {
          sVar4 = *(short *)(g_ActiveSwingMotionTable + uVar6 * 0xc + 2);
          uVar6 = (uint)sVar4;
          *(short *)(iVar5 + 0x10) = sVar4;
        }
        uVar3 = *(ushort *)(g_ActiveSwingMotionTable + 2 + uVar6 * 0xc);
        if ((uVar3 & 0x800) == 0) {
          uVar3 = uVar3 & 0x7ff;
        }
        else {
          uVar3 = uVar3 | 0xf800;
        }
        sVar4 = (short)((uint)((int)(short)uVar3 * *(int *)(iVar5 + 0x14)) >> 8);
        *(short *)(iVar1 + 0xa0) = sVar4;
        *(short *)(iVar1 + 0x80) = -((sVar4 >> 2) + sVar4);
        sVar4 = (short)g_CurrentSwingSegmentIndex;
        *(undefined2 *)(iVar1 + 0x7c) = 0xffff;
        *(short *)(iVar1 + 0x7a) = sVar4 + 1;
      }
      else if (sVar4 == 8) {
        iVar7 = *(int *)(iVar5 + 0x14) - *(int *)(iVar5 + 0x1c);
        *(int *)(iVar5 + 0x14) = iVar7;
        if (iVar7 < 0) {
          *(undefined4 *)(iVar5 + 0x14) = 0;
          *(undefined2 *)(iVar5 + 0xe) = 1;
        }
        *(short *)(iVar5 + 0x10) = *(short *)(iVar5 + 0x10) + 1;
        uVar6 = (uint)*(ushort *)(iVar5 + 0x10);
        if (*(short *)(g_ActiveSwingMotionTable + uVar6 * 0xc) < 0) {
          sVar4 = *(short *)(g_ActiveSwingMotionTable + uVar6 * 0xc + 2);
          uVar6 = (uint)sVar4;
          *(short *)(iVar5 + 0x10) = sVar4;
        }
        uVar3 = *(ushort *)(g_ActiveSwingMotionTable + 2 + uVar6 * 0xc);
        if ((uVar3 & 0x800) == 0) {
          uVar3 = uVar3 & 0x7ff;
        }
        else {
          uVar3 = uVar3 | 0xf800;
        }
        sVar4 = (short)((uint)((int)(short)uVar3 * *(int *)(iVar5 + 0x14)) >> 8);
        *(short *)(iVar1 + 0xa0) = sVar4;
        *(short *)(iVar1 + 0x80) = -((sVar4 >> 2) + sVar4);
      }
      else {
        *(undefined2 *)(iVar1 + 0xa0) = 0;
        *(undefined2 *)(iVar1 + 0x7a) = 0;
        *(undefined2 *)(iVar1 + 0x7c) = 0xffff;
        *(undefined2 *)(iVar5 + 0x10) = 0;
      }
    }
  }
  cVar2 = IsRuntimeEntryOutsideOuterActivationBounds(param_1);
  if (cVar2 != '\0') {
    CEntities__ReleaseRuntimeEntryToFreeList(param_1);
  }
  return;
}

