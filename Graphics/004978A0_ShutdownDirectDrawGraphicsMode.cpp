#include "tarzan_ghidra_types.hpp"

// Address: 0x004978A0
// Label: ShutdownDirectDrawGraphicsMode
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ShutdownDirectDrawGraphicsMode(void)

{
  UnlockDirectDrawPrimarySurface();
  ReleaseDirectDrawSurfaces();
  SetDirectDrawCooperativeAndDisplayMode(0);
  ReleaseDirectDrawObject();
  RestoreDirectDrawWindowState(g_DirectDrawWindowHandle);
  g_DirectDrawGraphicsModeInitialized = 0;
  if (g_DirectDrawExclusiveModeActive != 0) {
    InvalidateRect((HWND)0x0,(RECT *)0x0,1);
  }
  g_DirectDrawExclusiveModeActive = 0;
  if (g_DirectDrawDllModule != (HMODULE)0x0) {
    FreeLibrary(g_DirectDrawDllModule);
  }
  ResetDirectDrawInitState();
  return;
}

