#include "tarzan_ghidra_types.hpp"

// Address: 0x00437260
// Label: CPlayerHero::EnterJaneMode
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::EnterJaneMode(void)

{
  int value;
  int value2;
  int value3;
  
  _g_PlayerHeroMode = 4;
  *(ushort *)(g_PlayerEntitySceneObject + 0xe) =
       *(ushort *)(g_PlayerEntitySceneObject + 0xe) | 0x200;
  *(undefined4 *)(g_PlayerEntitySceneObject + 0x70) = 0;
  g_PlayerSequenceFlags = g_PlayerSequenceFlags & 0xdfff;
  g_NatureTerrainHazardContactFlag = 0;
  *(uint *)(*(int *)(g_CurrentWorldSceneContext + 0x24) + 4) =
       *(uint *)(*(int *)(g_CurrentWorldSceneContext + 0x24) + 4) & 0xfffffffd;
  *(undefined4 *)(g_PlayerEntitySceneObject + 0x6c) = 0xffffffc0;
  _g_JaneRouteEventValue = 0;
  *(undefined2 *)(g_PlayerEntitySceneObject + 0x142) = 0x200;
  value = CEntities::FindEntityAttachmentByFlags(g_PlayerEntity,0x40000000);
  if (value == 0) {
    CEntities::CreateEntityAttachment(g_PlayerEntity,0x38,0x40000000);
  }
  value = CEntities::FindEntityAttachmentByFlags(g_PlayerEntity,0x40000000);
  if (value != 0) {
    value2 = *(int *)(g_CollisionSurfaceTable + 100) + 100 + g_CollisionSurfaceTable;
    *(int *)(value + 0xc) = value2;
    value2 = FindRuntimePathSegmentForEntitySceneObject(value2,g_PlayerEntitySceneObject);
    *(int *)(value + 0x10) = value2;
    *(int *)(value + 0x18) = value2;
    *(undefined4 *)(value + 0x30) = 0;
    *(undefined4 *)(value + 0x34) = 0;
    *(int *)(value + 0x14) = *(int *)(value + 0xc) + 0x30 + value2 * 0x1c;
    AdvanceRuntimePathAttachmentFromCachedDirection(g_PlayerEntity);
  }
  value = *(int *)(g_CollisionSurfaceTable + 0x68) + 0x68 + g_CollisionSurfaceTable;
  value2 = *(int *)(g_CollisionSurfaceTable + 0x6c) + 0x6c + g_CollisionSurfaceTable;
  value3 = CEntities::FindEntityAttachmentByFlags(g_PlayerEntity,0x10000018);
  if (value3 == 0) {
    CEntities::CreateEntityAttachment(g_PlayerEntity,0x70,0x10000018);
  }
  value3 = CEntities::FindEntityAttachmentByFlags(g_PlayerEntity,0x10000019);
  if (value3 == 0) {
    CEntities::CreateEntityAttachment(g_PlayerEntity,0x70,0x10000019);
  }
  value3 = CEntities::FindEntityAttachmentByFlags(g_PlayerEntity,0x10000018);
  if (value3 != 0) {
    *(int *)(value3 + 0xc) = value;
    *(undefined4 *)(value3 + 0x28) = 0;
    *(undefined4 *)(value3 + 0x2c) = 0;
    *(undefined4 *)(value3 + 0x30) = 0;
    *(undefined4 *)(value3 + 0x34) = 0;
    *(undefined4 *)(value3 + 0x38) = 0;
    *(undefined4 *)(value3 + 0x4c) = 0x7fffffff;
    *(undefined4 *)(value3 + 0x54) = 0;
    *(undefined4 *)(value3 + 0x50) = 0xffffffff;
    *(undefined4 *)(value3 + 0x68) = 0xffffffff;
    *(undefined4 *)(value3 + 100) = 0;
    SnapPathFollowerAttachmentToNearestSegment(value3,g_PlayerEntitySceneObject + 0x14);
  }
  value = CEntities::FindEntityAttachmentByFlags(g_PlayerEntity,0x10000019);
  if (value != 0) {
    *(undefined4 *)(value + 0x28) = 0;
    *(int *)(value + 0xc) = value2;
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
  CPlayerHero::InitJaneCameraTrackState();
  *(int *)(g_PlayerEntitySceneObjectData + 4) = g_WorldEntitySceneObjectArrayBase + 0x208;
  g_PreviousPlayerActionState = g_PlayerActionState;
  g_PlayerActionState = 1;
  (*(code *)g_JaneEnterIdleHandlerPtr)();
  (**(code **)(&g_JaneActionStateUpdateColumn + (uint)g_PlayerActionState * 8))();
  g_CameraRelativeTurnInputMask = 0xa0;
  _g_JaneModeSavedHeroMode = 0;
  _g_JaneLateralRecoilAcceleration = 0;
  _g_JaneLateralRecoilTargetSpeed = 0;
  _g_JaneLateralRecoilDeceleration = 0;
  _g_JaneLateralRecoilSpeed = 0;
  g_JaneDamageReactionType = 0xffffffff;
  _g_JaneRouteEventEnabled = 0;
  g_PlayerFacingCurrentCollisionSurface = 0;
  g_JaneScriptedFollowActive = 0;
  g_JaneGroundSnapSuppressed = 0;
  *(undefined2 *)(g_PlayerEntitySceneObject + 0xa0) = 0;
  *(ushort *)(g_PlayerGroundShadowProbeEntitySceneObject + 0xe) =
       *(ushort *)(g_PlayerGroundShadowProbeEntitySceneObject + 0xe) & 0x7fff;
  return;
}

