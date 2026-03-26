// Address: 0x00445160

void RenderMenuSceneModelNode(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char cVar6;
  int *piVar7;
  int iVar8;
  
  iVar3 = *(int *)(param_1 + 0x10);
  iVar4 = *(int *)(iVar3 + 0xc);
  iVar1 = *(int *)(iVar4 + 8) + 8 + iVar4;
  iVar8 = *(int *)(iVar1 + 8 + (*(ushort *)(param_1 + 0xc) & 0xfff) * 4);
  cVar6 = (char)iVar8;
  iVar5 = iVar4;
  if ((cVar6 == '\0') || (iVar5 = *(int *)(iVar3 + 0x28 + cVar6 * 8), iVar5 != 0)) {
    piVar7 = (int *)((iVar8 >> 8) + iVar5);
    piVar2 = (int *)(*(int *)(iVar4 + 4) + 4 + iVar4);
    if ((*(ushort *)(param_1 + 0xe) & 0x200) == 0) {
      iVar8 = *piVar7;
    }
    else {
      if ((int *)(*piVar2 + (int)piVar2) <= piVar2 + *(int *)(param_1 + 0x70)) {
        *(undefined4 *)(param_1 + 0x70) = 0;
      }
      iVar8 = *(int *)(param_1 + 0x70);
    }
    DAT_00a438c0 = piVar2[iVar8] + iVar8 * 4 + (int)piVar2;
    if (*(short *)(param_1 + 0x78) == 0) {
      DAT_00a438fa = *(short *)(param_1 + 0x7a);
      if (DAT_00a438fa < 1) {
        DAT_00a438fa = 0;
      }
      else {
        DAT_00a438dc = param_1 + 0x80;
      }
      FUN_00454c60(piVar7,piVar7,*(undefined2 *)(param_1 + 0xe));
    }
    else {
      iVar1 = *(int *)(iVar1 + 8 + (*(ushort *)(param_1 + 0x76) & 0xfff) * 4);
      cVar6 = (char)iVar1;
      if ((cVar6 == '\0') || (iVar4 = *(int *)(iVar3 + 0x28 + cVar6 * 8), iVar4 != 0)) {
        FUN_00454be0(piVar7,(iVar1 >> 8) + iVar4,(int)*(short *)(param_1 + 0x78),&DAT_00a43920,
                     *(ushort *)(param_1 + 0xe) & 0x800);
        return;
      }
    }
  }
  return;
}


