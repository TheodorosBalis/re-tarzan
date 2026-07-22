#include "tarzan_ghidra_types.hpp"

// Address: 0x00495ED0
// Label: ShutdownDirect3DGraphicsMode
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ShutdownDirect3DGraphicsMode(void)

{
  int value;
  
  FlushPendingDirect3DFrame();
  UnlockDirect3DFrameBuffer();
  if (g_DirectDraw != (int *)0x0) {
    g_Direct3DLastResult = (**(code **)(*g_DirectDraw + 0x28))(g_DirectDraw);
  }
  value = 0;
  do {
    ReleaseDirect3DTexturePageSlot(value);
    value = value + 1;
  } while (value < 0x10);
  ReleaseDirect3DRenderTargetSurface();
  ReleaseDirect3DViewport();
  ReleaseDirect3DDevice();
  ReleaseDirectDrawPrimaryAndBackBufferSurfaces();
  SetDirectDrawCooperativeDisplayMode(0);
  ReleaseDirect3DInterface();
  ReleaseDirectDrawObject();
  RestoreWindowStateAfterDirect3DMode(g_Direct3DWindowHandle);
  g_Direct3DRendererInitialized = 0;
  if (g_DirectDrawDisplayModeChanged != 0) {
    InvalidateRect((HWND)0x0,(RECT *)0x0,1);
  }
  g_DirectDrawDisplayModeChanged = 0;
  if (g_DirectDrawLibraryHandle != (HMODULE)0x0) {
    FreeLibrary(g_DirectDrawLibraryHandle);
  }
  ResetDirect3DRendererGlobals();
  return;
}

