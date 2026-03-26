// Address: 0x00498930

void ResetMenuEgfState(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (g_MenuEgfHandle != 0) {
    CloseVirtualGameFileHandle(g_MenuEgfHandle);
  }
  puVar2 = &g_MenuEgfHeader;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  puVar2 = &g_MenuEgfChunkOffsets;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  g_MenuEgfHandle = 0;
  g_MenuEgfChunkCount = 0;
  return;
}


