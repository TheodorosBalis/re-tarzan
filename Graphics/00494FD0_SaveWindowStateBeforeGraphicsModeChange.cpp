#include "tarzan_ghidra_types.hpp"

// Address: 0x00494FD0
// Label: SaveWindowStateBeforeGraphicsModeChange
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SaveWindowStateBeforeGraphicsModeChange(HWND windowHandle)

{
  if (g_Direct3DWindowModeStateSaved == 0) {
    g_Direct3DWindowModeStateSaved = 1;
    GetCursorPos((LPPOINT)&g_Direct3DWindowRestoreState_Field248F8);
    _g_WindowModeSavedState_Field0000 = 0x2c;
    GetWindowPlacement(windowHandle,(WINDOWPLACEMENT *)&g_WindowModeSavedState_Field0000);
    if ((g_WindowModeSavedState_Field0008 == 3) || (g_WindowModeSavedState_Field0008 == 2)) {
      ShowWindow(windowHandle,9);
    }
    GetWindowRect(windowHandle,(LPRECT)&g_Direct3DWindowRestoreState_Field24D08);
    g_SavedWindowMenuHandle = GetMenu(windowHandle);
    SetMenu(windowHandle,(HMENU)0x0);
    g_SavedWindowExStyleBeforeDirect3D = GetWindowLongA(windowHandle,-0x14);
    g_SavedWindowStyleBeforeDirect3D = GetWindowLongA(windowHandle,-0x10);
  }
  return;
}

