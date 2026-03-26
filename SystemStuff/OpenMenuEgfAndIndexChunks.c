// Address: 0x004987E0

int OpenMenuEgfAndIndexChunks(undefined4 param_1)

{
  int iVar1;
  
  ResetMenuEgfState();
  g_MenuEgfHandle = OpenVirtualGameFileByPath(param_1,&DAT_005156bc);
  if ((g_MenuEgfHandle != 0) &&
     (ReadVirtualGameFileIntoBuffer(&g_MenuEgfHeader,0x48,1,g_MenuEgfHandle),
     g_MenuEgfHeader == 0x2464745)) {
    g_MenuEgfChunkCount = 0;
    iVar1 = 0x48;
    do {
      if ((&g_MenuEgfChunkSizes)[g_MenuEgfChunkCount] == 0) {
        return g_MenuEgfChunkCount;
      }
      (&g_MenuEgfChunkOffsets)[g_MenuEgfChunkCount] = iVar1;
      iVar1 = iVar1 + (&g_MenuEgfChunkSizes)[g_MenuEgfChunkCount];
      g_MenuEgfChunkCount = g_MenuEgfChunkCount + 1;
    } while (g_MenuEgfChunkCount < 0x10);
    return g_MenuEgfChunkCount;
  }
  ResetMenuEgfState();
  return 0;
}


