// Address: 0x004A4CF0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void GetAppTime_FillGraphicsBuffer(void)

{
  DWORD DVar1;
  int iVar2;
  int iVar3;
  
  DVar1 = timeGetTime();
  _g_RenderPacketSortElapsedMs = _g_RenderPacketSortElapsedMs - DVar1;
  RebuildSortedRenderPacketTable();
  DVar1 = timeGetTime();
  _g_RenderPacketSortElapsedMs = _g_RenderPacketSortElapsedMs + DVar1;
  DVar1 = timeGetTime();
  _appUpTime = _appUpTime - DVar1;
  iVar2 = ReadFromGlobal722994();
  if (iVar2 != g_LastGraphicsPageLayoutRevision) {
    g_LastGraphicsPageLayoutRevision = ReadFromGlobal722994();
    _g_DirtyTexturePageFlags = 0x1010101;
    _DAT_009cef14 = 0x1010101;
    _DAT_009cef18 = 0x1010101;
    _DAT_009cef1c = 0x1010101;
    ConvertGraphicsPageBufferToCurrentPixelLayout();
  }
  iVar2 = 0;
  iVar3 = 0;
  do {
    if ((&g_DirtyTexturePageFlags)[iVar2] != '\0') {
      RefreshDirtyTexturePage(iVar2,iVar3 + g_GraphicsPageBufferBase);
      (&g_DirtyTexturePageFlags)[iVar2] = 0;
    }
    iVar3 = iVar3 + 0x20000;
    iVar2 = iVar2 + 1;
  } while (iVar3 < 0x200000);
  WriteToGraphicsBufferIfGraphicsInitialized_stub
            (unused0,&g_BackBufferPixelsPtr,&g_BackBufferStridePixels);
  iVar2 = CurrentGraphicsMode();
  if (iVar2 == 1) {
    iVar2 = PopNextSortedRenderPacket();
    while (iVar2 != 0) {
      if ((*(ushort *)(iVar2 + 0x38) & 0x1800) == 0x1000) {
        *(undefined1 *)(iVar2 + 0x26) = (&DAT_009cf004)[*(byte *)(iVar2 + 0x26)];
        *(undefined1 *)(iVar2 + 0x25) = (&DAT_009cf004)[*(byte *)(iVar2 + 0x25)];
        *(undefined1 *)(iVar2 + 0x24) = (&DAT_009cf004)[*(byte *)(iVar2 + 0x24)];
        *(undefined1 *)(iVar2 + 0x2a) = (&DAT_009cf004)[*(byte *)(iVar2 + 0x2a)];
        *(undefined1 *)(iVar2 + 0x29) = (&DAT_009cf004)[*(byte *)(iVar2 + 0x29)];
        *(undefined1 *)(iVar2 + 0x28) = (&DAT_009cf004)[*(byte *)(iVar2 + 0x28)];
        *(undefined1 *)(iVar2 + 0x2e) = (&DAT_009cf004)[*(byte *)(iVar2 + 0x2e)];
        *(undefined1 *)(iVar2 + 0x2d) = (&DAT_009cf004)[*(byte *)(iVar2 + 0x2d)];
        *(undefined1 *)(iVar2 + 0x2c) = (&DAT_009cf004)[*(byte *)(iVar2 + 0x2c)];
      }
      if ((g_IsBrightnessLookupIdentity == 0) && ((*(ushort *)(iVar2 + 0x38) & 0x20) == 0)) {
        *(undefined1 *)(iVar2 + 0x26) = (&arrayofnumbers255)[*(byte *)(iVar2 + 0x26)];
        *(undefined1 *)(iVar2 + 0x25) = (&arrayofnumbers255)[*(byte *)(iVar2 + 0x25)];
        *(undefined1 *)(iVar2 + 0x24) = (&arrayofnumbers255)[*(byte *)(iVar2 + 0x24)];
        *(undefined1 *)(iVar2 + 0x2a) = (&arrayofnumbers255)[*(byte *)(iVar2 + 0x2a)];
        *(undefined1 *)(iVar2 + 0x29) = (&arrayofnumbers255)[*(byte *)(iVar2 + 0x29)];
        *(undefined1 *)(iVar2 + 0x28) = (&arrayofnumbers255)[*(byte *)(iVar2 + 0x28)];
        *(undefined1 *)(iVar2 + 0x2e) = (&arrayofnumbers255)[*(byte *)(iVar2 + 0x2e)];
        *(undefined1 *)(iVar2 + 0x2d) = (&arrayofnumbers255)[*(byte *)(iVar2 + 0x2d)];
        *(undefined1 *)(iVar2 + 0x2c) = (&arrayofnumbers255)[*(byte *)(iVar2 + 0x2c)];
      }
      FUN_0049d970(iVar2);
      iVar2 = PopNextSortedRenderPacket();
    }
  }
  else {
    iVar2 = CurrentGraphicsMode();
    if (iVar2 == 2) {
      iVar2 = PopNextSortedRenderPacket();
      while (iVar2 != 0) {
        if ((*(ushort *)(iVar2 + 0x38) & 0x1800) == 0x1000) {
          *(undefined1 *)(iVar2 + 0x26) = (&DAT_009cf004)[*(byte *)(iVar2 + 0x26)];
          *(undefined1 *)(iVar2 + 0x25) = (&DAT_009cf004)[*(byte *)(iVar2 + 0x25)];
          *(undefined1 *)(iVar2 + 0x24) = (&DAT_009cf004)[*(byte *)(iVar2 + 0x24)];
          *(undefined1 *)(iVar2 + 0x2a) = (&DAT_009cf004)[*(byte *)(iVar2 + 0x2a)];
          *(undefined1 *)(iVar2 + 0x29) = (&DAT_009cf004)[*(byte *)(iVar2 + 0x29)];
          *(undefined1 *)(iVar2 + 0x28) = (&DAT_009cf004)[*(byte *)(iVar2 + 0x28)];
          *(undefined1 *)(iVar2 + 0x2e) = (&DAT_009cf004)[*(byte *)(iVar2 + 0x2e)];
          *(undefined1 *)(iVar2 + 0x2d) = (&DAT_009cf004)[*(byte *)(iVar2 + 0x2d)];
          *(undefined1 *)(iVar2 + 0x2c) = (&DAT_009cf004)[*(byte *)(iVar2 + 0x2c)];
        }
        if ((g_IsBrightnessLookupIdentity == 0) && ((*(ushort *)(iVar2 + 0x38) & 0x20) == 0)) {
          *(undefined1 *)(iVar2 + 0x26) = (&arrayofnumbers255)[*(byte *)(iVar2 + 0x26)];
          *(undefined1 *)(iVar2 + 0x25) = (&arrayofnumbers255)[*(byte *)(iVar2 + 0x25)];
          *(undefined1 *)(iVar2 + 0x24) = (&arrayofnumbers255)[*(byte *)(iVar2 + 0x24)];
          *(undefined1 *)(iVar2 + 0x2a) = (&arrayofnumbers255)[*(byte *)(iVar2 + 0x2a)];
          *(undefined1 *)(iVar2 + 0x29) = (&arrayofnumbers255)[*(byte *)(iVar2 + 0x29)];
          *(undefined1 *)(iVar2 + 0x28) = (&arrayofnumbers255)[*(byte *)(iVar2 + 0x28)];
          *(undefined1 *)(iVar2 + 0x2e) = (&arrayofnumbers255)[*(byte *)(iVar2 + 0x2e)];
          *(undefined1 *)(iVar2 + 0x2d) = (&arrayofnumbers255)[*(byte *)(iVar2 + 0x2d)];
          *(undefined1 *)(iVar2 + 0x2c) = (&arrayofnumbers255)[*(byte *)(iVar2 + 0x2c)];
        }
        FUN_00497050(iVar2);
        iVar2 = PopNextSortedRenderPacket();
      }
    }
    else {
      g_RenderWindowWidth = GetWindowWidth();
      g_RenderWindowHeight = GetWindowHeight();
      _g_RenderWindowWidthF = (float)g_RenderWindowWidth * _DAT_004ba2e4;
      _g_RenderWindowHeightF = (float)g_RenderWindowHeight * _DAT_004ba2e4;
      if (g_BackBufferPixelsPtr != 0) {
        iVar2 = PopNextSortedRenderPacket();
        while (iVar2 != 0) {
          if ((g_IsBrightnessLookupIdentity == 0) && ((*(byte *)(iVar2 + 0x38) & 0x20) == 0)) {
            *(undefined1 *)(iVar2 + 0x26) = (&arrayofnumbers255)[*(byte *)(iVar2 + 0x26)];
            *(undefined1 *)(iVar2 + 0x25) = (&arrayofnumbers255)[*(byte *)(iVar2 + 0x25)];
            *(undefined1 *)(iVar2 + 0x24) = (&arrayofnumbers255)[*(byte *)(iVar2 + 0x24)];
            *(undefined1 *)(iVar2 + 0x2a) = (&arrayofnumbers255)[*(byte *)(iVar2 + 0x2a)];
            *(undefined1 *)(iVar2 + 0x29) = (&arrayofnumbers255)[*(byte *)(iVar2 + 0x29)];
            *(undefined1 *)(iVar2 + 0x28) = (&arrayofnumbers255)[*(byte *)(iVar2 + 0x28)];
            *(undefined1 *)(iVar2 + 0x2e) = (&arrayofnumbers255)[*(byte *)(iVar2 + 0x2e)];
            *(undefined1 *)(iVar2 + 0x2d) = (&arrayofnumbers255)[*(byte *)(iVar2 + 0x2d)];
            *(undefined1 *)(iVar2 + 0x2c) = (&arrayofnumbers255)[*(byte *)(iVar2 + 0x2c)];
          }
          RasterizeRenderPacketToBackBuffer(iVar2);
          iVar2 = PopNextSortedRenderPacket();
        }
      }
    }
  }
  g_BackBufferPixelsPtr = 0;
  g_BackBufferStridePixels = 0;
  ConfirmGraphicsInitialized();
  return;
}


