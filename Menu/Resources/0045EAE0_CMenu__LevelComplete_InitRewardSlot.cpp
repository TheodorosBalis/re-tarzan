#include "tarzan_ghidra_types.hpp"

// Address: 0x0045EAE0
// Label: CMenu::LevelComplete_InitRewardSlot
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CMenu::LevelComplete_InitRewardSlot(int menu)

{
  int slotIndex;
  
  slotIndex = menu * 0x144;
  *(undefined **)(&g_LevelCompleteRewardSlotPtrTable + menu * 0xc) =
       &g_LevelCompleteRewardSlotScenes + slotIndex;
  *(undefined4 *)(&DAT_0053918c + slotIndex) = 0;
  *(undefined4 *)(&DAT_00539190 + slotIndex) = 0;
  *(undefined4 *)(&DAT_00539194 + slotIndex) = 0;
  return;
}

