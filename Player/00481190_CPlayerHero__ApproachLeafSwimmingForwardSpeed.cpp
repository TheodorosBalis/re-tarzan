#include "tarzan_ghidra_types.hpp"

// Address: 0x00481190
// Label: CPlayerHero::ApproachLeafSwimmingForwardSpeed
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::ApproachLeafSwimmingForwardSpeed(void)

{
  int value;
  
  value = *(int *)(g_PlayerMotionState + 0x10);
  if (value != *(int *)(g_PlayerMotionState + 0x1c)) {
    if (*(int *)(g_PlayerMotionState + 0x1c) < value) {
      *(int *)(g_PlayerMotionState + 0x10) = value - *(int *)(g_PlayerMotionState + 0x18);
      if (*(int *)(g_PlayerMotionState + 0x10) <= *(int *)(g_PlayerMotionState + 0x1c)) {
        *(int *)(g_PlayerMotionState + 0x10) = *(int *)(g_PlayerMotionState + 0x1c);
        return;
      }
    }
    else {
      *(int *)(g_PlayerMotionState + 0x10) = *(int *)(g_PlayerMotionState + 0x14) + value;
      if (*(int *)(g_PlayerMotionState + 0x1c) <= *(int *)(g_PlayerMotionState + 0x10)) {
        *(int *)(g_PlayerMotionState + 0x10) = *(int *)(g_PlayerMotionState + 0x1c);
      }
    }
  }
  return;
}

