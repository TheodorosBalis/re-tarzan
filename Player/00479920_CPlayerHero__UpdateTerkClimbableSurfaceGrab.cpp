#include "tarzan_ghidra_types.hpp"

// Address: 0x00479920
// Label: CPlayerHero::UpdateTerkClimbableSurfaceGrab
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::UpdateTerkClimbableSurfaceGrab(void)

{
  undefined2 value;
  char resultFlag;
  
  CPlayerHero::UpdateMovementAndCollision(1);
  resultFlag = CPlayerHero::TrySnapToNearbyGround();
  value = g_PlayerActionState;
  if (resultFlag == '\0') {
    g_PlayerActionState = 10;
    g_PreviousPlayerActionState = value;
    (*(code *)g_TerkEnterFallingHandlerPtr)();
  }
  CPlayerHero::AdvanceAnimationScript();
  return;
}

