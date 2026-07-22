#include "tarzan_ghidra_types.hpp"

// Address: 0x00494EC0
// Label: TryInitDirect3DGraphicsMode
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 TryInitDirect3DGraphicsMode(int graphicsObject,int source2,int dest)

{
  char resultFlag;
  int value;
  int value2;
  
  if (dest != 0) {
    return 4;
  }
  if (g_Direct3DRendererInitialized != 0) {
    return 0;
  }
  if (graphicsObject == 0) {
    return 3;
  }
  SetGlideGammaEnvironmentVariables();
  g_Direct3DDevice = (uint)(source2 != 0);
  g_Direct3DWindowHandle = graphicsObject;
  ResetDirect3DRendererGlobals();
  value = LoadDirectDrawLibraryEntryPoints();
  if (value != 0) {
    value = CreateDirectDrawObjectAndEnumerateDrivers();
    if ((value == 0) || (value = CreateDirect3DInterfaceFromDirectDraw(), value == 0)) {
LAB_00494f5d:
      ShutdownDirect3DGraphicsMode();
      return 1;
    }
    SaveWindowStateBeforeGraphicsModeChange(g_Direct3DWindowHandle);
    value = SetDirectDrawCooperativeDisplayMode(1);
    if (value != 0) {
      g_DirectDrawDisplayModeChanged = 1;
      value = CreateDirect3DPrimaryAndBackBufferSurfaces();
      if (value != 0) {
        value = CreateDirect3DDeviceAndReadCapabilities();
        if (value == 0) goto LAB_00494f5d;
        value = CreateDirect3DViewport();
        if (((value != 0) && (value = BuildDefaultDirectDrawSurfaceDesc555(), value != 0)) &&
           (value = CreateDirect3DRenderTargetSurface(), value != 0)) {
          value = 0;
          do {
            value2 = CreateOrUploadDirect3DTexturePage(value,0);
            if (value2 == 0) goto LAB_00494fbf;
            value = value + 1;
          } while (value < 0x10);
          g_Direct3DRendererInitialized = 1;
          ConfigureDefaultDirect3DRenderStates();
          resultFlag = ProbeDirect3DFramebufferPixelLayout();
          if (resultFlag != '\0') {
            return 0;
          }
LAB_00494fbf:
          ShutdownDirect3DGraphicsMode();
          return 2;
        }
      }
    }
  }
  ShutdownDirect3DGraphicsMode();
  return 3;
}

