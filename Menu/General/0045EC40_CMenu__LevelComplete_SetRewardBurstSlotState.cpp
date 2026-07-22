#include "tarzan_ghidra_types.hpp"

// Address: 0x0045EC40
// Label: CMenu::LevelComplete_SetRewardBurstSlotState
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CMenu::LevelComplete_SetRewardBurstSlotState(int menu)

{
  if (((byte)(1 << ((byte)menu & 0x1f)) & g_CollectedSketchPieceMask4) != 0) {
    *(undefined2 *)(&g_LevelCompleteRewardBurstSlotFlags + menu * 0x144) = 0x8100;
    return;
  }
  *(undefined2 *)(&g_LevelCompleteRewardBurstSlotFlags + menu * 0x144) = 0x8521;
  return;
}

