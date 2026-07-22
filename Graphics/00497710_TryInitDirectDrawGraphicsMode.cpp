#include "tarzan_ghidra_types.hpp"

// Address: 0x00497710
// Label: TryInitDirectDrawGraphicsMode
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4
TryInitDirectDrawGraphicsMode
          (int graphicsObject,undefined4 source2,undefined4 *dest,undefined4 *flags)

{
  int value;
  
  if (g_DirectDrawGraphicsModeInitialized != 0) {
    return 0;
  }
  if (graphicsObject != 0) {
    g_DirectDrawWindowHandle = graphicsObject;
    g_DirectDrawUseHighResolutionMode = source2;
    ResetDirectDrawInitState();
    g_DirectDrawDllModule = LoadLibraryA(s_ddraw_dll);
    if ((g_DirectDrawDllModule != (HMODULE)0x0) &&
       (g_DirectDrawCreateProc = GetProcAddress(g_DirectDrawDllModule,s_DirectDrawCreate),
       g_DirectDrawCreateProc != (FARPROC)0x0)) {
      value = CreateDirectDrawObject();
      if (value == 0) {
        ShutdownDirectDrawGraphicsMode();
        return 1;
      }
      CaptureDirectDrawWindowState(g_DirectDrawWindowHandle);
      value = SetDirectDrawCooperativeAndDisplayMode(1);
      if (value != 0) {
        g_DirectDrawExclusiveModeActive = 1;
        value = CreateDirectDrawPrimaryAndBackBuffer();
        if (value != 0) {
          if (dest != (undefined4 *)0x0) {
            *dest = g_DirectDrawBackBufferIsRgb565;
          }
          if (flags != (undefined4 *)0x0) {
            *flags = g_DirectDrawBackBufferIsRgb565;
          }
          g_DirectDrawGraphicsModeInitialized = 1;
          return 0;
        }
      }
    }
    ShutdownDirectDrawGraphicsMode();
    return 3;
  }
  return 3;
}

