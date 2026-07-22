#include "tarzan_ghidra_types.hpp"

// Address: 0x00491680
// Label: CPlayerHero::EnterYoungTreeSurfingResume
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterYoungTreeSurfingResume(void)

{
  CPlayerHero::PlayAnimation(0x2d);
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = g_PlayerSurfaceMotionSpeed;
  return;
}

