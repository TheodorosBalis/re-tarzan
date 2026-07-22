#include "tarzan_ghidra_types.hpp"

// Address: 0x004808A0
// Label: CPlayerHero::UpdateJungleCruiseBonusStageCountdown
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::UpdateJungleCruiseBonusStageCountdown(void)

{
  if ((g_HudCountdownBcdTime & 0xffffff00) == 0) {
    *( undefined1 *)((int)&g_PlayerSequenceFlags + 1) = *( undefined1 *)((int)&g_PlayerSequenceFlags + 1) | 0x40;
    *( undefined2 *)((int)&g_LevelTransitionRequestFlags + 0) = 0x8001;
    SetHudCountdownDisplay(0,0x8000);
  }
  if ((g_HudCountdownBcdTime >> 8 == 0x18) && (g_LeafSwimmingCountdownTicks == 0)) {
    if (g_LeafSwimmingSurfaceDriftZ == 2) {
      PlayAudioById(0x80d1,(int *)0,(undefined4 *)0);
      g_LeafSwimmingCountdownTicks = 1;
    }
    if (g_LeafSwimmingSurfaceDriftZ == 3) {
      PlayAudioById(0x80cf,(int *)0,(undefined4 *)0);
      g_LeafSwimmingCountdownTicks = 1;
    }
  }
  return;
}

