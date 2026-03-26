// Address: 0x004A4B20

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ConvertGraphicsPageBufferToCurrentPixelLayout(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_0049cce0();
  if (DAT_005175f0 != iVar1) {
    DAT_005175f0 = FUN_0049cce0();
    if (DAT_005175f0 != 0) {
      iVar1 = 0;
      do {
        iVar2 = iVar1 + 2;
        _DAT_0079e7b8 =
             (*(ushort *)(iVar1 + g_GraphicsPageBufferBase) & 0x7fe0) << 1 |
             *(ushort *)(iVar1 + g_GraphicsPageBufferBase) & 0x3f;
        *(short *)(iVar1 + g_GraphicsPageBufferBase) = (short)_DAT_0079e7b8;
        iVar1 = iVar2;
      } while (iVar2 < 0x200000);
      return;
    }
    DAT_005175f0 = 0;
    iVar1 = 0;
    do {
      iVar2 = iVar1 + 2;
      _DAT_0079e7b8 =
           *(ushort *)(iVar1 + g_GraphicsPageBufferBase) >> 1 & 0x7fe0 |
           *(ushort *)(iVar1 + g_GraphicsPageBufferBase) & 0x1f;
      *(short *)(iVar1 + g_GraphicsPageBufferBase) = (short)_DAT_0079e7b8;
      iVar1 = iVar2;
    } while (iVar2 < 0x200000);
  }
  return;
}


