// Address: 0x00453040

void RenderMainMenuSelectionsText(undefined4 param_1)

{
  RenderSelectedMenuEntryText(param_1);
  RenderMenuUiBlockEntry(0x4f1e4c,&DAT_00533bd8,0,*(int *)(g_ActiveMenuContext + 0x1c) + 0x40,0);
  RenderMenuUiBlockEntry(0x4f1e6c,&DAT_00533bd8,1,*(int *)(g_ActiveMenuContext + 0x1c) + 0x40,0);
  return;
}


