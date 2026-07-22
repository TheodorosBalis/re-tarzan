#include "tarzan_ghidra_types.hpp"

// Address: 0x0046CCE0
// Label: CPlayerHero::EnterAdultTarzanClimbableWallMoveUp
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterAdultTarzanClimbableWallMoveUp(void)

{
  undefined4 value;
  
  if (g_PlayerAnimationSurfaceSide == '\0') {
    value = 0x76;
  }
  else {
    value = 0x77;
  }
  CPlayerHero::PlayAdultTarzanAnimation(value);
  *(int *)(g_PlayerEntitySceneObjectData + 0xc) =
       *(int *)(g_PlayerEntitySceneObjectData + 0xc) + 0xb0;
  if (g_PlayerInteractionCollisionHeightRange <=
      *(int *)(g_PlayerEntitySceneObjectData + 0xc) - g_PlayerInteractionCollisionBaseY) {
    *(int *)(g_PlayerEntitySceneObjectData + 0xc) =
         g_PlayerInteractionCollisionHeightRange + g_PlayerInteractionCollisionBaseY;
    g_PreviousPlayerActionState = g_PlayerActionState;
    g_PlayerActionState = 0x24;
                    /* WARNING: Could not recover jumptable at 0x0046cd3e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)g_AdultTarzanEnterClimbableWallIdleHandlerPtr)();
    return;
  }
  return;
}

