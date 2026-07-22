#include "tarzan_ghidra_types.hpp"

// Address: 0x00460030
// Label: CPlayerHero::EnterAdultTarzanElephantMountArrival
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterAdultTarzanElephantMountArrival(void)

{
  undefined4 value3;
  int value;
  int value2;
  
  *(int *)(g_PlayerEntitySceneObjectData + 4) = g_WorldEntitySceneObjectArrayBase + 0x2a40;
  g_PlayerCurrentAnimationId = 3;
  *(undefined **)(g_PlayerAnimationState + 0xc) =
       g_AdultTarzanElephantMountArrivalAnimationScriptPtr;
  *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
  *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  CPlayerHero::AdvanceAnimationScript();
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 6;
  *(undefined4 *)(g_PlayerMotionState + 0x18) = 6;
  SetHudExtraLifeMeterEnabled(1);
  *(undefined1 *)(g_PlayerEntitySceneObject + 0x74) = 0;
  value = CEntities::FindEntityAttachmentByFlags(g_PlayerEntity,0x40000000);
  if (value != 0) {
    value2 = *(int *)(g_CollisionSurfaceTable + 4) + 4 + g_CollisionSurfaceTable;
    *(int *)(value + 0xc) = value2;
    value2 = FindRuntimePathSegmentForEntitySceneObject(value2,g_PlayerEntitySceneObject);
    *(int *)(value + 0x10) = value2;
    *(int *)(value + 0x18) = value2;
    *(undefined4 *)(value + 0x30) = 2;
    *(int *)(value + 0x14) = *(int *)(value + 0xc) + 0x30 + value2 * 0x1c;
    AdvanceRuntimePathAttachmentFromEntitySceneObject(g_PlayerEntity);
  }
  value = CEntities::FindEntityAttachmentByFlags(g_PlayerEntity,0x10000018);
  value3 = g_AdultTarzanElephantFirstBoundaryRailPathBase;
  if (value != 0) {
    *(undefined4 *)(value + 0x28) = 0;
    *(undefined4 *)(value + 0xc) = value3;
    *(undefined4 *)(value + 0x2c) = 0;
    *(undefined4 *)(value + 0x30) = 0;
    *(undefined4 *)(value + 0x34) = 0;
    *(undefined4 *)(value + 0x38) = 0;
    *(undefined4 *)(value + 0x4c) = 0x7fffffff;
    *(undefined4 *)(value + 0x54) = 0;
    *(undefined4 *)(value + 0x50) = 0xffffffff;
    *(undefined4 *)(value + 0x68) = 0xffffffff;
    *(undefined4 *)(value + 100) = 0;
    SnapPathFollowerAttachmentToNearestSegment(value,g_PlayerEntitySceneObject + 0x14);
  }
  value = CEntities::FindEntityAttachmentByFlags(g_PlayerEntity,0x10000019);
  value3 = g_AdultTarzanElephantSecondBoundaryRailPathBase;
  if (value != 0) {
    *(undefined4 *)(value + 0x28) = 0;
    *(undefined4 *)(value + 0xc) = value3;
    *(undefined4 *)(value + 0x2c) = 0;
    *(undefined4 *)(value + 0x30) = 0;
    *(undefined4 *)(value + 0x34) = 0;
    *(undefined4 *)(value + 0x38) = 0;
    *(undefined4 *)(value + 0x4c) = 0x7fffffff;
    *(undefined4 *)(value + 0x54) = 0;
    *(undefined4 *)(value + 0x68) = 0xffffffff;
    *(undefined4 *)(value + 0x50) = 0xffffffff;
    *(undefined4 *)(value + 100) = 0;
    SnapPathFollowerAttachmentToNearestSegment(value,g_PlayerEntitySceneObject + 0x14);
  }
  return;
}

