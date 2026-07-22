#include "tarzan_ghidra_types.hpp"

// Address: 0x00460800
// Label: CPlayerHero::EnterAdultTarzanElephantTransitionArc
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::EnterAdultTarzanElephantTransitionArc(void)

{
  int value;
  int value2;
  
  g_PlayerCurrentAnimationId = 1;
  *(undefined **)(g_PlayerAnimationState + 0xc) =
       g_AdultTarzanElephantTransitionArcAnimationScriptPtr;
  *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
  *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  CPlayerHero::AdvanceAnimationScript();
  if (g_AdultTarzanElephantLevelExitDismountActive == 0) {
    if (g_AdultTarzanElephantMountTargetEntity == 0) {
      return;
    }
    value2 = *(int *)(g_PlayerEntity + 0x38);
    value = *(int *)(g_AdultTarzanElephantMountTargetEntity + 0x38);
    _g_AdultTarzanElephantTransitionArcDeltaX = *(int *)(value + 0x14) - *(int *)(value2 + 0x14);
    _g_AdultTarzanElephantTransitionArcDeltaZ = *(int *)(value + 0x1c) - *(int *)(value2 + 0x1c);
    _g_AdultTarzanElephantTransitionArcDeltaY = *(int *)(value + 0x18) - *(int *)(value2 + 0x18);
    _g_AdultTarzanElephantTransitionArcDeltaX =
         _g_AdultTarzanElephantTransitionArcDeltaX +
         (_g_AdultTarzanElephantTransitionArcDeltaX >> 0x1f & 0x1fU);
    _g_AdultTarzanElephantTransitionArcDeltaZ =
         _g_AdultTarzanElephantTransitionArcDeltaZ +
         (_g_AdultTarzanElephantTransitionArcDeltaZ >> 0x1f & 0x1fU);
    _g_AdultTarzanElephantTransitionArcDeltaY =
         _g_AdultTarzanElephantTransitionArcDeltaY +
         (_g_AdultTarzanElephantTransitionArcDeltaY >> 0x1f & 0x1fU);
    _g_AdultTarzanElephantTransitionArcBaseY =
         *(undefined4 *)(*(int *)(g_AdultTarzanElephantMountTargetEntity + 0x38) + 0x18);
    value2 = *(int *)(g_AdultTarzanElephantMountTargetEntity + 0x38);
  }
  else {
    *(int *)(g_PlayerEntitySceneObjectData + 4) = g_WorldEntitySceneObjectArrayBase + 0xd0;
    UnloadEncodedResourceId(0x68);
    _g_AdultTarzanElephantExitResourceReleaseTicks = 0;
    value2 = *(int *)(g_PlayerEntity + 0x38);
    _g_AdultTarzanElephantTransitionArcDeltaX = 0x81f - *(int *)(value2 + 0x14);
    _g_AdultTarzanElephantTransitionArcDeltaY =
         (*(int *)(g_AdultTarzanElephantEntitySceneObject + 0x18) + -0x200) - *(int *)(value2 + 0x18)
    ;
    _g_AdultTarzanElephantTransitionArcDeltaX =
         _g_AdultTarzanElephantTransitionArcDeltaX +
         (_g_AdultTarzanElephantTransitionArcDeltaX >> 0x1f & 0x1fU);
    _g_AdultTarzanElephantTransitionArcDeltaZ = 0x116b7 - *(int *)(value2 + 0x1c);
    _g_AdultTarzanElephantTransitionArcDeltaZ =
         _g_AdultTarzanElephantTransitionArcDeltaZ +
         (_g_AdultTarzanElephantTransitionArcDeltaZ >> 0x1f & 0x1fU);
    _g_AdultTarzanElephantTransitionArcDeltaY =
         _g_AdultTarzanElephantTransitionArcDeltaY +
         (_g_AdultTarzanElephantTransitionArcDeltaY >> 0x1f & 0x1fU);
    _g_AdultTarzanElephantTransitionArcBaseY =
         *(undefined4 *)(*(int *)(g_PlayerEntity + 0x38) + 0x18);
    value2 = *(int *)(g_PlayerEntity + 0x38);
  }
  _g_AdultTarzanElephantTransitionArcDeltaZ = _g_AdultTarzanElephantTransitionArcDeltaZ >> 5;
  _g_AdultTarzanElephantTransitionArcDeltaY = _g_AdultTarzanElephantTransitionArcDeltaY >> 5;
  _g_AdultTarzanElephantTransitionArcDeltaX = _g_AdultTarzanElephantTransitionArcDeltaX >> 5;
  _g_AdultTarzanElephantTransitionArcElapsedTicks = 0;
  _g_AdultTarzanElephantTransitionArcStartZ = *(undefined4 *)(value2 + 0x1c);
  _g_AdultTarzanElephantTransitionArcStartY = *(undefined4 *)(value2 + 0x18);
  _g_AdultTarzanElephantTransitionArcStartX = *(undefined4 *)(value2 + 0x14);
  _g_AdultTarzanElephantTransitionArcPhaseStep = 8;
  _g_AdultTarzanElephantTransitionArcPhase = 0;
  _g_AdultTarzanElephantTransitionArcDurationTicks = 0x20;
  return;
}

