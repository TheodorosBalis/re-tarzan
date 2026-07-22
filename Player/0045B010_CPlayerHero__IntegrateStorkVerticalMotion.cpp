#include "tarzan_ghidra_types.hpp"

// Address: 0x0045B010
// Label: CPlayerHero::IntegrateStorkVerticalMotion
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

bool CPlayerHero::IntegrateStorkVerticalMotion(void)

{
  int value;
  
  *(int *)(g_PlayerMotionState + 0x20) =
       *(int *)(g_PlayerMotionState + 0x20) - *(int *)(g_PlayerMotionState + 0x24);
  if (*(int *)(g_PlayerMotionState + 0x20) < *(int *)(g_PlayerMotionState + 0x2c)) {
    *(int *)(g_PlayerMotionState + 0x20) = *(int *)(g_PlayerMotionState + 0x2c);
  }
  value = *(int *)(g_PlayerMotionState + 0x20);
  *(int *)(g_PlayerEntitySceneObjectData + 0xc) =
       *(int *)(g_PlayerEntitySceneObjectData + 0xc) - value;
  return value < 1;
}

