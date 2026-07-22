#include "tarzan_ghidra_types.hpp"

// Address: 0x004086A0
// Label: TerkBonus::UpdateCountdownAndFinish
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TerkBonus::UpdateCountdownAndFinish(void)

{
  if ((g_HudCountdownBcdTime & 0xffffff00) == 0) {
    *( undefined1 *)((int)&g_PlayerSequenceFlags + 1) = *( undefined1 *)((int)&g_PlayerSequenceFlags + 1) | 0x40;
    *( undefined2 *)((int)&g_LevelTransitionRequestFlags + 0) = 0x8001;
    SetHudCountdownDisplay(0,0x8000);
  }
  return;
}

