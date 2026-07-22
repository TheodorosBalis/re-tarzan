#include "tarzan_ghidra_types.hpp"

// Address: 0x0049D420
// Label: SaveWindowStateBeforeGlideModeChange
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SaveWindowStateBeforeGlideModeChange(HWND windowHandle)

{
  if (g_GlideSavedWindowStyle == 0) {
    g_GlideSavedWindowStyle = 1;
    GetCursorPos((LPPOINT)&g_MainWindowReconfigureState_Field20CA98);
    _g_GlideWindowSavedState_Field0000 = 0x2c;
    GetWindowPlacement(windowHandle,(WINDOWPLACEMENT *)&g_GlideWindowSavedState_Field0000);
    if ((g_GlideWindowSavedState_Field0008 == 3) || (g_GlideWindowSavedState_Field0008 == 2)) {
      ShowWindow(windowHandle,9);
    }
    GetWindowRect(windowHandle,(LPRECT)&g_MainWindowReconfigureState_Field20CEA8);
    g_GlideSavedWindowMenuHandle = GetMenu(windowHandle);
    SetMenu(windowHandle,(HMENU)0x0);
    g_GlideSavedWindowExStyle = GetWindowLongA(windowHandle,-0x14);
    g_GlideSavedWindowStyle = GetWindowLongA(windowHandle,-0x10);
  }
  return;
}

