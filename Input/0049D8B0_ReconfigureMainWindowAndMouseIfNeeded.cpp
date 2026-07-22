#include "tarzan_ghidra_types.hpp"

// Address: 0x0049D8B0
// Label: ReconfigureMainWindowAndMouseIfNeeded
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ReconfigureMainWindowAndMouseIfNeeded(HWND windowHandle)

{
  int value;
  
  if (g_GlideSavedWindowStyle != 0) {
    g_GlideSavedWindowStyle = 0;
    if (g_GlideSavedWindowMenuHandle != (HMENU)0x0) {
      SetMenu(windowHandle,g_GlideSavedWindowMenuHandle);
      g_GlideSavedWindowMenuHandle = (HMENU)0x0;
    }
    SetWindowLongA(windowHandle,-0x14,g_GlideSavedWindowExStyle);
    SetWindowLongA(windowHandle,-0x10,g_GlideSavedWindowStyle);
    SetWindowPos(windowHandle,(HWND)0xfffffffe,g_MainWindowReconfigureState_Field20CEA8,
                 g_MainWindowReconfigureState_Field20CEAC,
                 g_MainWindowReconfigureState_Field20CEB0 - g_MainWindowReconfigureState_Field20CEA8
                 ,g_MainWindowReconfigureState_Field20CEB4 -
                  g_MainWindowReconfigureState_Field20CEAC,0x10);
    ClipCursor((RECT *)0x0);
    SetCursorPos(g_MainWindowReconfigureState_Field20CA98,g_MainWindowReconfigureState_Field20CA9C);
    value = ShowCursor(1);
    while (value < 0) {
      value = ShowCursor(1);
    }
  }
  return;
}

