#include "tarzan_ghidra_types.hpp"

// Address: 0x0046C6D0
// Label: CPlayerHero::EnterAdultTarzanClimbableEdgePullUp
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterAdultTarzanClimbableEdgePullUp(void)

{
  switch(g_PlayerCurrentAnimationId) {
  case 0x67:
  case 0x68:
    CPlayerHero::PlayAdultTarzanAnimation(0x69);
    return;
  default:
    CPlayerHero::PlayAdultTarzanAnimation(0x6f);
    return;
  case 0x6b:
  case 0x6c:
    CPlayerHero::PlayAdultTarzanAnimation(0x6d);
    return;
  }
}

