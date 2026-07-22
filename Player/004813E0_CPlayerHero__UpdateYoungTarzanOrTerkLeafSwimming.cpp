#include "tarzan_ghidra_types.hpp"

// Address: 0x004813E0
// Label: CPlayerHero::UpdateYoungTarzanOrTerkLeafSwimming
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateYoungTarzanOrTerkLeafSwimming(void)

{
  int value;
  int value2;
  int value3;
  
  value = g_LeafSwimmingBoundarySurfaceIndexA * 4 + 4;
  value3 = *(int *)(value + g_CollisionSurfaceTable) + value + g_CollisionSurfaceTable;
  value = g_LeafSwimmingBoundarySurfaceIndexB * 4 + 4;
  value2 = *(int *)(value + g_CollisionSurfaceTable) + value + g_CollisionSurfaceTable;
  (**(code **)(&g_LeafSwimmingActionStateUpdateColumn + (uint)g_PlayerActionState * 8))();
  _g_LeafSwimmingPreviousRouteNode = 0;
  _g_LeafSwimmingPreviousRouteNode =
       PushPositionOutOfNearbyNatureTerrainCollisionTrianglesXZ
                 (&g_CurrentWorldSceneContext,g_PlayerEntitySceneObjectData + 8,
                  g_PlayerEntitySceneObjectData + 8);
  CPlayerHero::AdvanceLeafSwimmingSurfaceTrack();
  CPlayerHero::ProcessLeafSwimmingRouteSegmentFlags();
  value = CEntities::FindEntityAttachmentByFlags(g_PlayerEntity,0x10000019);
  if (value != 0) {
    *(int *)(value + 0xc) = value2;
    UpdatePathFollowerAttachmentNearestSegment(value,*(int *)(g_PlayerEntity + 0x38) + 0x14);
    PushEntitySceneObjectOutsidePathBoundaryRadiusXZ
              (g_PlayerEntitySceneObject,*(undefined4 *)(value + 0x10),1,value + 0x18,0x40);
  }
  value = CEntities::FindEntityAttachmentByFlags(g_PlayerEntity,0x10000018);
  if (value != 0) {
    *(int *)(value + 0xc) = value3;
    UpdatePathFollowerAttachmentNearestSegment(value,*(int *)(g_PlayerEntity + 0x38) + 0x14);
    PushEntitySceneObjectOutsidePathBoundaryRadiusXZ
              (g_PlayerEntitySceneObject,*(undefined4 *)(value + 0x10),0,value + 0x18,0x40);
  }
  return;
}

