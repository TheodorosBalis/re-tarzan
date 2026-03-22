/* Address: 0x0049D8B0 */

void ReconfigureMainWindowAndMouseIfNeeded(HWND param_1)

{
  int iVar1;
  
  if (DAT_0072371c != 0) {
    DAT_0072371c = 0;
    if (DAT_00723720 != (HMENU)0x0) {
      SetMenu(param_1,DAT_00723720);
      DAT_00723720 = (HMENU)0x0;
    }
    SetWindowLongA(param_1,-0x14,DAT_00723268);
    SetWindowLongA(param_1,-0x10,DAT_007229a4);
    SetWindowPos(param_1,(HWND)0xfffffffe,DAT_00722da8,DAT_00722dac,DAT_00722db0 - DAT_00722da8,
                 DAT_00722db4 - DAT_00722dac,0x10);
    ClipCursor((RECT *)0x0);
    SetCursorPos(DAT_00722998,DAT_0072299c);
    iVar1 = ShowCursor(1);
    while (iVar1 < 0) {
      iVar1 = ShowCursor(1);
    }
  }
  return;
}

