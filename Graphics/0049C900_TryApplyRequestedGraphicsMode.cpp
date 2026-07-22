#include "tarzan_ghidra_types.hpp"

// Address: 0x0049C900
// Label: TryApplyRequestedGraphicsMode
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int TryApplyRequestedGraphicsMode(void)

{
  int value;
  int value2;
  
  value = g_RequestedGraphicsMode;
  value2 = 0;
  if (g_RequestedGraphicsMode == g_CurrentGraphicsMode) {
    return g_CurrentGraphicsMode;
  }
  if (g_RequestedGraphicsMode == 7) {
    return g_CurrentGraphicsMode;
  }
  if (g_RequestedGraphicsMode < 0) {
    g_RequestedGraphicsMode = g_CurrentGraphicsMode;
    g_LastGraphicsModeFailureId = -value;
    return value;
  }
  g_GraphicsModeChangeSerial = g_GraphicsModeChangeSerial + 1;
  DoReconfigurationStuffOnWindow();
  ShutdownDirect3DGraphicsMode();
  ShutdownDirectDrawGraphicsMode();
  switch(g_RequestedGraphicsMode) {
  case 1:
    value = TryInitGlideGraphicsMode(g_GraphicsWindowHandle,0,g_RequestedGraphicsModePending == 1);
    if (value == 0) {
      g_RequestedGraphicsModePending = -1;
    }
    else {
      if (g_GlideInitFailureCode == 0) {
        g_GlideInitFailureCode = value;
      }
      value2 = 1;
    }
    break;
  case 2:
    value = TryInitDirect3DGraphicsMode
                      (g_GraphicsWindowHandle,0,g_RequestedGraphicsModePending == -1);
    if (value == 0) {
      value = IsDirect3DRendererInitialized();
      if (value != 0) {
        g_RequestedGraphicsModePending = 1;
      }
    }
    else {
      if (g_Direct3DInitFailureCode == 0) {
        g_Direct3DInitFailureCode = value;
      }
      value2 = 2;
    }
    break;
  case 3:
    value = TryInitDirectDrawGraphicsMode
                      (g_GraphicsWindowHandle,0,&g_DirectDrawDirtyTexturePageFlags,
                       &g_DirectDrawDirtyTexturePageIndex);
    if (value == 0) goto LAB_0049c9af;
    if (g_DirectDrawLowResInitFailureCode == 0) {
      g_DirectDrawLowResInitFailureCode = value;
    }
    value2 = 3;
    goto LAB_0049ca70;
  case 4:
    value = TryInitDirectDrawGraphicsMode
                      (g_GraphicsWindowHandle,1,&g_DirectDrawDirtyTexturePageFlags,
                       &g_DirectDrawDirtyTexturePageIndex);
    if (value != 0) {
      if (g_DirectDrawHighResInitFailureCode == 0) {
        g_DirectDrawHighResInitFailureCode = value;
      }
      g_CurrentGraphicsMode = 0;
      g_LastGraphicsModeFailureId = 4;
      return -4;
    }
    goto LAB_0049c9af;
  case 5:
    g_DirectDrawDirtyTexturePageIndex = 0;
    _g_DirectDrawDirtyTexturePageFlags = 0;
    g_RequestedGraphicsMode = 5;
    goto LAB_0049c9af;
  default:
    g_CurrentGraphicsMode = 0;
    g_LastGraphicsModeFailureId = 1;
    return -1;
  }
  g_DirectDrawDirtyTexturePageIndex = 0;
  _g_DirectDrawDirtyTexturePageFlags = 0;
  if (value2 != 0) {
LAB_0049ca70:
    g_LastGraphicsModeFailureId = value2;
    g_CurrentGraphicsMode = 0;
    return -value2;
  }
LAB_0049c9af:
  g_CurrentGraphicsMode = g_RequestedGraphicsMode;
  ConfirmGraphicsInitialized();
  BeginFrameBufferWriteForCurrentGraphicsMode(0,0,0);
  ConfirmGraphicsInitialized();
  ShowFrameOnScreen();
  return 0;
}

