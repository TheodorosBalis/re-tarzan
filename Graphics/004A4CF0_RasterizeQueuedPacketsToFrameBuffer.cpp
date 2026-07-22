#include "tarzan_ghidra_types.hpp"

// Address: 0x004A4CF0
// Label: RasterizeQueuedPacketsToFrameBuffer
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void RasterizeQueuedPacketsToFrameBuffer(void)

{
  DWORD apiResult;
  int value;
  int value2;
  
  apiResult = timeGetTime();
  _g_RenderPacketSortElapsedMs = _g_RenderPacketSortElapsedMs - apiResult;
  RebuildSortedRenderPacketTable();
  apiResult = timeGetTime();
  _g_RenderPacketSortElapsedMs = _g_RenderPacketSortElapsedMs + apiResult;
  apiResult = timeGetTime();
  _appUpTime = _appUpTime - apiResult;
  value = GetGraphicsModeRevision();
  if (value != g_LastGraphicsPageLayoutRevision) {
    g_LastGraphicsPageLayoutRevision = GetGraphicsModeRevision();
    _g_DirtyTexturePageFlags = 0x1010101;
    _g_FrameBufferRasterScratch_Field0004 = 0x1010101;
    _g_FrameBufferRasterScratch_Field0008 = 0x1010101;
    _g_FrameBufferRasterScratch_Field000C = 0x1010101;
    ConvertGraphicsPageBufferToCurrentPixelLayout();
  }
  value = 0;
  value2 = 0;
  do {
    if ((&g_DirtyTexturePageFlags)[value] != '\0') {
      RefreshDirtyTexturePage(value,value2 + g_GraphicsPageBufferBase);
      (&g_DirtyTexturePageFlags)[value] = 0;
    }
    value2 = value2 + 0x20000;
    value = value + 1;
  } while (value2 < 0x200000);
  BeginFrameBufferWriteForCurrentGraphicsMode
            (g_FrameClearColor,&g_BackBufferPixelsPtr,&g_BackBufferStridePixels);
  value = CurrentGraphicsMode();
  if (value == 1) {
    value = PopNextSortedRenderPacket();
    while (value != 0) {
      if ((*(ushort *)(value + 0x38) & 0x1800) == 0x1000) {
        *(undefined1 *)(value + 0x26) = (&g_RenderPacketShadeLookupTable)[*(byte *)(value + 0x26)];
        *(undefined1 *)(value + 0x25) = (&g_RenderPacketShadeLookupTable)[*(byte *)(value + 0x25)];
        *(undefined1 *)(value + 0x24) = (&g_RenderPacketShadeLookupTable)[*(byte *)(value + 0x24)];
        *(undefined1 *)(value + 0x2a) = (&g_RenderPacketShadeLookupTable)[*(byte *)(value + 0x2a)];
        *(undefined1 *)(value + 0x29) = (&g_RenderPacketShadeLookupTable)[*(byte *)(value + 0x29)];
        *(undefined1 *)(value + 0x28) = (&g_RenderPacketShadeLookupTable)[*(byte *)(value + 0x28)];
        *(undefined1 *)(value + 0x2e) = (&g_RenderPacketShadeLookupTable)[*(byte *)(value + 0x2e)];
        *(undefined1 *)(value + 0x2d) = (&g_RenderPacketShadeLookupTable)[*(byte *)(value + 0x2d)];
        *(undefined1 *)(value + 0x2c) = (&g_RenderPacketShadeLookupTable)[*(byte *)(value + 0x2c)];
      }
      if ((g_IsBrightnessLookupIdentity == 0) && ((*(ushort *)(value + 0x38) & 0x20) == 0)) {
        *(undefined1 *)(value + 0x26) = (&g_BrightnessLookupTable)[*(byte *)(value + 0x26)];
        *(undefined1 *)(value + 0x25) = (&g_BrightnessLookupTable)[*(byte *)(value + 0x25)];
        *(undefined1 *)(value + 0x24) = (&g_BrightnessLookupTable)[*(byte *)(value + 0x24)];
        *(undefined1 *)(value + 0x2a) = (&g_BrightnessLookupTable)[*(byte *)(value + 0x2a)];
        *(undefined1 *)(value + 0x29) = (&g_BrightnessLookupTable)[*(byte *)(value + 0x29)];
        *(undefined1 *)(value + 0x28) = (&g_BrightnessLookupTable)[*(byte *)(value + 0x28)];
        *(undefined1 *)(value + 0x2e) = (&g_BrightnessLookupTable)[*(byte *)(value + 0x2e)];
        *(undefined1 *)(value + 0x2d) = (&g_BrightnessLookupTable)[*(byte *)(value + 0x2d)];
        *(undefined1 *)(value + 0x2c) = (&g_BrightnessLookupTable)[*(byte *)(value + 0x2c)];
      }
      SubmitGlideTexturedTriangle(value);
      value = PopNextSortedRenderPacket();
    }
  }
  else {
    value = CurrentGraphicsMode();
    if (value == 2) {
      value = PopNextSortedRenderPacket();
      while (value != 0) {
        if ((*(ushort *)(value + 0x38) & 0x1800) == 0x1000) {
          *(undefined1 *)(value + 0x26) = (&g_RenderPacketShadeLookupTable)[*(byte *)(value + 0x26)]
          ;
          *(undefined1 *)(value + 0x25) = (&g_RenderPacketShadeLookupTable)[*(byte *)(value + 0x25)]
          ;
          *(undefined1 *)(value + 0x24) = (&g_RenderPacketShadeLookupTable)[*(byte *)(value + 0x24)]
          ;
          *(undefined1 *)(value + 0x2a) = (&g_RenderPacketShadeLookupTable)[*(byte *)(value + 0x2a)]
          ;
          *(undefined1 *)(value + 0x29) = (&g_RenderPacketShadeLookupTable)[*(byte *)(value + 0x29)]
          ;
          *(undefined1 *)(value + 0x28) = (&g_RenderPacketShadeLookupTable)[*(byte *)(value + 0x28)]
          ;
          *(undefined1 *)(value + 0x2e) = (&g_RenderPacketShadeLookupTable)[*(byte *)(value + 0x2e)]
          ;
          *(undefined1 *)(value + 0x2d) = (&g_RenderPacketShadeLookupTable)[*(byte *)(value + 0x2d)]
          ;
          *(undefined1 *)(value + 0x2c) = (&g_RenderPacketShadeLookupTable)[*(byte *)(value + 0x2c)]
          ;
        }
        if ((g_IsBrightnessLookupIdentity == 0) && ((*(ushort *)(value + 0x38) & 0x20) == 0)) {
          *(undefined1 *)(value + 0x26) = (&g_BrightnessLookupTable)[*(byte *)(value + 0x26)];
          *(undefined1 *)(value + 0x25) = (&g_BrightnessLookupTable)[*(byte *)(value + 0x25)];
          *(undefined1 *)(value + 0x24) = (&g_BrightnessLookupTable)[*(byte *)(value + 0x24)];
          *(undefined1 *)(value + 0x2a) = (&g_BrightnessLookupTable)[*(byte *)(value + 0x2a)];
          *(undefined1 *)(value + 0x29) = (&g_BrightnessLookupTable)[*(byte *)(value + 0x29)];
          *(undefined1 *)(value + 0x28) = (&g_BrightnessLookupTable)[*(byte *)(value + 0x28)];
          *(undefined1 *)(value + 0x2e) = (&g_BrightnessLookupTable)[*(byte *)(value + 0x2e)];
          *(undefined1 *)(value + 0x2d) = (&g_BrightnessLookupTable)[*(byte *)(value + 0x2d)];
          *(undefined1 *)(value + 0x2c) = (&g_BrightnessLookupTable)[*(byte *)(value + 0x2c)];
        }
        QueueDirect3DTriangleDraw(value);
        value = PopNextSortedRenderPacket();
      }
    }
    else {
      g_RenderWindowWidth = GetWindowWidth();
      g_RenderWindowHeight = GetWindowHeight();
      _g_RenderWindowWidthF = (float)g_RenderWindowWidth * _g_FloatMillisecondsPerSecond;
      _g_RenderWindowHeightF = (float)g_RenderWindowHeight * _g_FloatMillisecondsPerSecond;
      if (g_BackBufferPixelsPtr != 0) {
        value = PopNextSortedRenderPacket();
        while (value != 0) {
          if ((g_IsBrightnessLookupIdentity == 0) && ((*(byte *)(value + 0x38) & 0x20) == 0)) {
            *(undefined1 *)(value + 0x26) = (&g_BrightnessLookupTable)[*(byte *)(value + 0x26)];
            *(undefined1 *)(value + 0x25) = (&g_BrightnessLookupTable)[*(byte *)(value + 0x25)];
            *(undefined1 *)(value + 0x24) = (&g_BrightnessLookupTable)[*(byte *)(value + 0x24)];
            *(undefined1 *)(value + 0x2a) = (&g_BrightnessLookupTable)[*(byte *)(value + 0x2a)];
            *(undefined1 *)(value + 0x29) = (&g_BrightnessLookupTable)[*(byte *)(value + 0x29)];
            *(undefined1 *)(value + 0x28) = (&g_BrightnessLookupTable)[*(byte *)(value + 0x28)];
            *(undefined1 *)(value + 0x2e) = (&g_BrightnessLookupTable)[*(byte *)(value + 0x2e)];
            *(undefined1 *)(value + 0x2d) = (&g_BrightnessLookupTable)[*(byte *)(value + 0x2d)];
            *(undefined1 *)(value + 0x2c) = (&g_BrightnessLookupTable)[*(byte *)(value + 0x2c)];
          }
          RasterizeRenderPacketToBackBuffer(value);
          value = PopNextSortedRenderPacket();
        }
      }
    }
  }
  g_BackBufferPixelsPtr = 0;
  g_BackBufferStridePixels = 0;
  ConfirmGraphicsInitialized();
  return;
}

