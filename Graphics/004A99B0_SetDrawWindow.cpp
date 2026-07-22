#include "tarzan_ghidra_types.hpp"

// Address: 0x004A99B0
// Label: SetDrawWindow
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void SetDrawWindow(int windowHandle,int messageId)

{
  if (windowHandle != 0) {
    g_DrawWindowMode = *(int *)(windowHandle + 8);
  }
  if (g_DrawWindowMode == 0) {
    g_DrawWindowMinX = 3000;
    g_DrawWindowMaxX = 65000;
    g_DrawWindowXOffset = messageId * 4 + 3000;
    return;
  }
  if (g_DrawWindowMode == 1) {
    g_DrawWindowMinX = 1;
    g_DrawWindowMaxX = 3000;
    g_DrawWindowXOffset = messageId * 4 + -700;
    return;
  }
  if (g_DrawWindowMode != 2) {
    InternalError(s_MACHINE_SET_DRAW_WINDOW___00517678);
    g_DrawWindowXOffset = g_DrawWindowXOffset + messageId * 4;
    return;
  }
  g_DrawWindowMinX = 65000;
  g_DrawWindowMaxX = 0xffff;
  g_DrawWindowXOffset = messageId * 4 + 65000;
  return;
}

