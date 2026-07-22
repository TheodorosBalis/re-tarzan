#include "tarzan_ghidra_types.hpp"

// Address: 0x004977E0
// Label: CaptureDirectDrawWindowState
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CaptureDirectDrawWindowState(HWND windowHandle)

{
  if (g_DirectDrawWindowStateCaptured == 0) {
    g_DirectDrawWindowStateCaptured = 1;
    GetCursorPos((LPPOINT)&g_DirectDrawSavedCursorX);
    _g_DirectDrawSavedWindowPlacement = 0x2c;
    GetWindowPlacement(windowHandle,(WINDOWPLACEMENT *)&g_DirectDrawSavedWindowPlacement);
    if ((g_DirectDrawSavedWindowShowCmd == 3) || (g_DirectDrawSavedWindowShowCmd == 2)) {
      ShowWindow(windowHandle,9);
    }
    GetWindowRect(windowHandle,(LPRECT)&g_DirectDrawSavedWindowRectLeft);
    g_DirectDrawSavedMenu = GetMenu(windowHandle);
    SetMenu(windowHandle,(HMENU)0x0);
    g_DirectDrawSavedWindowExStyle = GetWindowLongA(windowHandle,-0x14);
    g_DirectDrawSavedWindowStyle = GetWindowLongA(windowHandle,-0x10);
  }
  return;
}

