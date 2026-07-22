#include "tarzan_ghidra_types.hpp"

// Address: 0x0045FB50
// Label: CPlayerHero::UpdateAdultTarzanOnElephant
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::UpdateAdultTarzanOnElephant(void)

{
  int value;
  uint value2;
  
  (**(code **)(&g_AdultTarzanElephantActionStateUpdateColumn + (uint)g_PlayerActionState * 8))();
  if (g_AdultTarzanElephantEntitySceneObject != 0) {
    value = CEntities::FindEntityAttachmentByFlags(g_PlayerEntity,0x10000018);
    if (value != 0) {
      UpdatePathFollowerAttachmentNearestSegment
                (value,g_AdultTarzanElephantEntitySceneObject + 0x14);
      value2 = (int)*(uint *)(g_PlayerMotionState + 0x10) >> 0x1f;
      PushEntitySceneObjectOutsidePathBoundaryRadiusXZ
                (g_AdultTarzanElephantEntitySceneObject,*(undefined4 *)(value + 0x10),0,value + 0x18
                 ,((*(uint *)(g_PlayerMotionState + 0x10) ^ value2) - value2) + 0x40);
    }
    value = CEntities::FindEntityAttachmentByFlags(g_PlayerEntity,0x10000019);
    if (value != 0) {
      UpdatePathFollowerAttachmentNearestSegment
                (value,g_AdultTarzanElephantEntitySceneObject + 0x14);
      value2 = (int)*(uint *)(g_PlayerMotionState + 0x10) >> 0x1f;
      PushEntitySceneObjectOutsidePathBoundaryRadiusXZ
                (g_AdultTarzanElephantEntitySceneObject,*(undefined4 *)(value + 0x10),1,value + 0x18
                 ,((*(uint *)(g_PlayerMotionState + 0x10) ^ value2) - value2) + 0x40);
    }
  }
  if (g_HudExtraLifeAwardTriggered != 0) {
    g_HudExtraLifeAwardTriggered = 0;
    *( undefined1 *)((int)&g_LevelTransitionContext + 3) = *( undefined1 *)((int)&g_LevelTransitionContext + 3) + '\x01';
  }
  return;
}

