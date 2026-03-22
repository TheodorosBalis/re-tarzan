/* Address: 0x004ADDB0 */

void ClearFontInMenus(int param_1,int param_2)

{
  if (param_2 <= FrameCount - *(int *)(param_1 + 0x18)) {
    FUN_004adcb0(param_1);
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  return;
}

