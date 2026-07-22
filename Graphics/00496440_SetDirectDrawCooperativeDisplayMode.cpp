#include "tarzan_ghidra_types.hpp"

// Address: 0x00496440
// Label: SetDirectDrawCooperativeDisplayMode
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 SetDirectDrawCooperativeDisplayMode(int arg1)

{
  int value;
  undefined4 *dataCursor;
  int scratchRect [27];
  
  if ((g_DirectDrawCooperativeModeState != arg1) &&
     ((g_DirectDrawCooperativeModeState != -1 || (arg1 != 0)))) {
    g_DirectDrawCooperativeModeState = arg1;
    if (arg1 == 0) {
      value = 2;
      do {
        if (g_DirectDraw != (int *)0x0) {
          g_Direct3DLastResult = (**(code **)(*g_DirectDraw + 0x4c))(g_DirectDraw);
        }
        ChangeDisplaySettingsA((DEVMODEA *)0x0,0);
        value = value + -1;
      } while (value != 0);
      if (g_DirectDraw != (int *)0x0) {
        g_Direct3DLastResult =
             (**(code **)(*g_DirectDraw + 0x50))(g_DirectDraw,g_Direct3DWindowHandle,0xc);
      }
    }
    else {
      EnterFullscreenWindowModeAndHideCursor(g_Direct3DWindowHandle,0x280,0x1e0);
      if (g_DirectDraw != (int *)0x0) {
        g_Direct3DLastResult =
             (**(code **)(*g_DirectDraw + 0x50))(g_DirectDraw,g_Direct3DWindowHandle,0x55);
        if (g_DirectDraw != (int *)0x0) {
          g_Direct3DLastResult = (**(code **)(*g_DirectDraw + 0x54))(g_DirectDraw,0x280,0x1e0,0x10);
        }
      }
      dataCursor = (undefined4 *)&stack0xffffff90;
      EnterFullscreenWindowModeAndHideCursor(g_Direct3DWindowHandle,0x280,0x1e0);
      for (value = 0x1b; dataCursor = dataCursor + 1, value != 0; value = value + -1) {
        *dataCursor = 0;
      }
      scratchRect[0] = 0x6c;
      if (g_DirectDraw != (int *)0x0) {
        g_Direct3DLastResult = (**(code **)(*g_DirectDraw + 0x30))(g_DirectDraw,scratchRect);
      }
      if ((scratchRect[3] != 0x280) || (scratchRect[2] != 0x1e0)) {
        return 0;
      }
    }
  }
  return 1;
}

