#include "tarzan_ghidra_types.hpp"

// Address: 0x00446300
// Label: InitHudCountdownScene
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void InitHudCountdownScene(undefined4 arg1,undefined4 arg2,undefined4 arg3)

{
  g_HudCountdownScene = &DAT_00532a48;
  g_HudCountdownBcdTime = 0;
  *( undefined2 *)((int)&g_HudCountdownFlags + 0) = 0;
  g_HudCountdownPosY = arg2;
  g_HudCountdownPosX = arg1;
  g_HudCountdownPosZ = arg3;
  *( undefined2 *)((int)&g_BonusTimerHudDigits + 0) = 99;
  return;
}

