// Address: 0x00452CD0

void RenderSelectedMenuEntryText(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = (int *)(param_1[2] + param_1[9] * 0x18);
  iVar2 = piVar1[1];
  if ((-1 < iVar2) && (iVar3 = *piVar1, iVar3 != 0)) {
    RenderMenuUiBlockEntry
              (iVar3 + 4,&DAT_00533bd8,iVar2,*(int *)(g_ActiveMenuContext + 0x1c) + 0x40,0);
  }
  ReleaseMenuTextBlockIfUnused(*param_1 + 4,2);
  return;
}


