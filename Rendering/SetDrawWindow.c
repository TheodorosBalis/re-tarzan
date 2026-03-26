// Address: 0x004A99B0

void SetDrawWindow(int param_1,int param_2)

{
  if (param_1 != 0) {
    g_DrawWindowMode = *(int *)(param_1 + 8);
  }
  if (g_DrawWindowMode == 0) {
    g_DrawWindowMinX = 3000;
    g_DrawWindowMaxX = 65000;
    g_DrawWindowXOffset = param_2 * 4 + 3000;
    return;
  }
  if (g_DrawWindowMode == 1) {
    g_DrawWindowMinX = 1;
    g_DrawWindowMaxX = 3000;
    g_DrawWindowXOffset = param_2 * 4 + -700;
    return;
  }
  if (g_DrawWindowMode != 2) {
    InternalError(s_MACHINE_SET_DRAW_WINDOW___00517678);
    g_DrawWindowXOffset = g_DrawWindowXOffset + param_2 * 4;
    return;
  }
  g_DrawWindowMinX = 65000;
  g_DrawWindowMaxX = 0xffff;
  g_DrawWindowXOffset = param_2 * 4 + 65000;
  return;
}


