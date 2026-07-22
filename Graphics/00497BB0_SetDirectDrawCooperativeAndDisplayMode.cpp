#include "tarzan_ghidra_types.hpp"

// Address: 0x00497BB0
// Label: SetDirectDrawCooperativeAndDisplayMode
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 SetDirectDrawCooperativeAndDisplayMode(int arg1)

{
  int value;
  int value2;
  int value3;
  int *intCursor;
  int scratchRect [27];
  
  if ((g_DirectDrawCurrentDisplayModeState != arg1) &&
     ((g_DirectDrawCurrentDisplayModeState != -1 || (arg1 != 0)))) {
    g_DirectDrawCurrentDisplayModeState = arg1;
    if (arg1 == 0) {
      value = 2;
      do {
        if (g_DirectDrawObject != (int *)0x0) {
          g_DirectDrawLastResult = (**(code **)(*g_DirectDrawObject + 0x4c))(g_DirectDrawObject);
        }
        ChangeDisplaySettingsA((DEVMODEA *)0x0,0);
        value = value + -1;
      } while (value != 0);
      if (g_DirectDrawObject != (int *)0x0) {
        g_DirectDrawLastResult =
             (**(code **)(*g_DirectDrawObject + 0x50))
                       (g_DirectDrawObject,g_DirectDrawWindowHandle,0xc);
      }
    }
    else {
      value3 = (-(uint)(g_DirectDrawUseHighResolutionMode != 0) & 0x140) + 0x140;
      value = (-(uint)(g_DirectDrawUseHighResolutionMode != 0) & 0xf0) + 0xf0;
      PrepareDirectDrawFullscreenWindow(g_DirectDrawWindowHandle,value3,value);
      if (g_DirectDrawObject != (int *)0x0) {
        g_DirectDrawLastResult =
             (**(code **)(*g_DirectDrawObject + 0x50))
                       (g_DirectDrawObject,g_DirectDrawWindowHandle,0x55);
        if (g_DirectDrawObject != (int *)0x0) {
          g_DirectDrawLastResult =
               (**(code **)(*g_DirectDrawObject + 0x54))(g_DirectDrawObject,value3,value,0x10);
        }
      }
      PrepareDirectDrawFullscreenWindow(g_DirectDrawWindowHandle,value3,value);
      intCursor = scratchRect;
      for (value2 = 0x1b; value2 != 0; value2 = value2 + -1) {
        *intCursor = 0;
        intCursor = intCursor + 1;
      }
      scratchRect[0] = 0x6c;
      if (g_DirectDrawObject != (int *)0x0) {
        g_DirectDrawLastResult =
             (**(code **)(*g_DirectDrawObject + 0x30))(g_DirectDrawObject,scratchRect);
      }
      if ((scratchRect[3] != value3) || (scratchRect[2] != value)) {
        return 0;
      }
    }
  }
  return 1;
}

