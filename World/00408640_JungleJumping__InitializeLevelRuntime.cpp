#include "tarzan_ghidra_types.hpp"

// Address: 0x00408640
// Label: JungleJumping::InitializeLevelRuntime
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void JungleJumping::InitializeLevelRuntime(void)

{
  undefined2 upperWord;
  
  InitHudCountdownScene(0x110,0xc0,0);
  SetHudCountdownDisplay
            (CONCAT22(upperWord,
                      g_LevelHudCountdownStartValueTable[*( undefined1 *)((int)&g_LevelTransitionContext + 1)]),0x81d0);
  return;
}

