#include "tarzan_ghidra_types.hpp"

// Address: 0x00495F80
// Label: RestoreWindowStateAfterDirect3DMode
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void RestoreWindowStateAfterDirect3DMode(HWND windowHandle)

{
  int value;
  
  if (g_Direct3DWindowModeStateSaved != 0) {
    g_Direct3DWindowModeStateSaved = 0;
    if (g_SavedWindowMenuHandle != (HMENU)0x0) {
      SetMenu(windowHandle,g_SavedWindowMenuHandle);
      g_SavedWindowMenuHandle = (HMENU)0x0;
    }
    SetWindowLongA(windowHandle,-0x14,g_SavedWindowExStyleBeforeDirect3D);
    SetWindowLongA(windowHandle,-0x10,g_SavedWindowStyleBeforeDirect3D);
    SetWindowPos(windowHandle,(HWND)0xfffffffe,g_Direct3DWindowRestoreState_Field24D08,
                 g_Direct3DWindowRestoreState_Field24D0C,
                 g_Direct3DWindowRestoreState_Field24D10 - g_Direct3DWindowRestoreState_Field24D08,
                 g_Direct3DWindowRestoreState_Field24D14 - g_Direct3DWindowRestoreState_Field24D0C,
                 0x10);
    ClipCursor((RECT *)0x0);
    SetCursorPos(g_Direct3DWindowRestoreState_Field248F8,g_Direct3DWindowRestoreState_Field248FC);
    value = ShowCursor(1);
    while (value < 0) {
      value = ShowCursor(1);
    }
  }
  return;
}

