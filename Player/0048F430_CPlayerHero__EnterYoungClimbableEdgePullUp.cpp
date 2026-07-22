#include "tarzan_ghidra_types.hpp"

// Address: 0x0048F430
// Label: CPlayerHero::EnterYoungClimbableEdgePullUp
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterYoungClimbableEdgePullUp(void)

{
  switch(g_PlayerCurrentAnimationId) {
  case 0x6b:
  case 0x6c:
    CPlayerHero::PlayAnimation(0x6d);
    return;
  default:
    CPlayerHero::PlayAnimation(0x73);
    return;
  case 0x6f:
  case 0x70:
    CPlayerHero::PlayAnimation(0x71);
    return;
  }
}

