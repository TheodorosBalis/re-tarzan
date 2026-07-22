#include "tarzan_ghidra_types.hpp"

// Address: 0x00437560
// Label: CPlayerHero::UpdateJane
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::UpdateJane(void)

{
  int value;
  
  AdvanceRuntimePathAttachmentFromCachedDirection(g_PlayerEntity);
  (**(code **)(&g_JaneActionStateUpdateColumn + (uint)g_PlayerActionState * 8))();
  CPlayerHero::UpdateJaneGroundShadowPosition();
  value = CEntities::FindEntityAttachmentByFlags(g_PlayerEntity,0x10000019);
  if (value != 0) {
    UpdatePathFollowerAttachmentNearestSegment(value,*(int *)(g_PlayerEntity + 0x38) + 0x14);
    PushEntitySceneObjectOutsidePathBoundaryRadiusXZ
              (g_PlayerEntitySceneObject,*(undefined4 *)(value + 0x10),0,value + 0x18,0x40);
  }
  value = CEntities::FindEntityAttachmentByFlags(g_PlayerEntity,0x10000018);
  if (value != 0) {
    UpdatePathFollowerAttachmentNearestSegment(value,*(int *)(g_PlayerEntity + 0x38) + 0x14);
    PushEntitySceneObjectOutsidePathBoundaryRadiusXZ
              (g_PlayerEntitySceneObject,*(undefined4 *)(value + 0x10),1,value + 0x18,0x40);
  }
  return;
}

