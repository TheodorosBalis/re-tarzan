#include "tarzan_ghidra_types.hpp"

// Address: 0x0048FA90
// Label: CPlayerHero::EnterYoungClimbableWallMoveUp
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterYoungClimbableWallMoveUp(void)

{
  undefined4 value;
  
  if (g_PlayerAnimationSurfaceSide == '\0') {
    value = 0x82;
  }
  else {
    value = 0x83;
  }
  CPlayerHero::PlayAnimation(value);
  *(int *)(g_PlayerEntitySceneObjectData + 0xc) =
       *(int *)(g_PlayerEntitySceneObjectData + 0xc) + 0x70;
  if (g_PlayerInteractionCollisionHeightRange <=
      *(int *)(g_PlayerEntitySceneObjectData + 0xc) - g_PlayerInteractionCollisionBaseY) {
    *(int *)(g_PlayerEntitySceneObjectData + 0xc) =
         g_PlayerInteractionCollisionHeightRange + g_PlayerInteractionCollisionBaseY;
    g_PreviousPlayerActionState = g_PlayerActionState;
    g_PlayerActionState = 0x2b;
                    /* WARNING: Could not recover jumptable at 0x0048faf1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)g_YoungEnterClimbableWallIdleHandlerPtr)();
    return;
  }
  return;
}

