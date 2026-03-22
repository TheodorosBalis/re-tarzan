/* Address: 0x0045EB10 */

void CMenu::LevelComplete_AddSlotSpin(int param_1,short param_2)

{
  *(undefined2 *)(param_1 + 0xa6) = 0;
  *(ushort *)(param_1 + 0xa2) =
       ((*(short *)(param_1 + 0xa2) + param_2) - 0x400U & 0x7ff) - 0x400 & 0xfff;
  return;
}

