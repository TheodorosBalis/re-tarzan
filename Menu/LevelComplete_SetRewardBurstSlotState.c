/* Address: 0x0045EC40 */

void CMenu::LevelComplete_SetRewardBurstSlotState(int param_1)

{
  if (((byte)(1 << ((byte)param_1 & 0x1f)) & g_LevelTransitionRewardMask4) != 0) {
    *(undefined2 *)(&g_LevelCompleteRewardBurstSlotFlags + param_1 * 0x144) = 0x8100;
    return;
  }
  *(undefined2 *)(&g_LevelCompleteRewardBurstSlotFlags + param_1 * 0x144) = 0x8521;
  return;
}

