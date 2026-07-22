#include "tarzan_ghidra_types.hpp"

// Address: 0x00497910
// Label: RestoreDirectDrawWindowState
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void RestoreDirectDrawWindowState(HWND windowHandle)

{
  int value;
  
  if (g_DirectDrawWindowStateCaptured != 0) {
    g_DirectDrawWindowStateCaptured = 0;
    if (g_DirectDrawSavedMenu != (HMENU)0x0) {
      SetMenu(windowHandle,g_DirectDrawSavedMenu);
      g_DirectDrawSavedMenu = (HMENU)0x0;
    }
    SetWindowLongA(windowHandle,-0x14,g_DirectDrawSavedWindowExStyle);
    SetWindowLongA(windowHandle,-0x10,g_DirectDrawSavedWindowStyle);
    SetWindowPos(windowHandle,(HWND)0xfffffffe,g_DirectDrawSavedWindowRectLeft,
                 g_DirectDrawSavedWindowRectTop,
                 g_DirectDrawSavedWindowRectRight - g_DirectDrawSavedWindowRectLeft,
                 g_DirectDrawSavedWindowRectBottom - g_DirectDrawSavedWindowRectTop,0x10);
    ClipCursor((RECT *)0x0);
    SetCursorPos(g_DirectDrawSavedCursorX,g_DirectDrawSavedCursorY);
    value = ShowCursor(1);
    while (value < 0) {
      value = ShowCursor(1);
    }
  }
  return;
}

