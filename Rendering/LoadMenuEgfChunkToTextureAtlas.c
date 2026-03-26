// Address: 0x00498860

void LoadMenuEgfChunkToTextureAtlas(int param_1,int param_2)

{
  int iVar1;
  
  if (((g_MenuEgfHandle != 0) && (-1 < param_1)) && (param_1 < g_MenuEgfChunkCount)) {
    iVar1 = (param_2 - (&g_MenuEgfChunkSizes)[param_1]) + 0x20000;
    SeekVirtualGameFileHandle(g_MenuEgfHandle,(&g_MenuEgfChunkOffsets)[param_1],0);
    ReadVirtualGameFileIntoBuffer(iVar1,(&g_MenuEgfChunkSizes)[param_1],1,g_MenuEgfHandle);
    DecodeMenuEgfRleTexture256x256(param_2,iVar1);
  }
  return;
}


