#include "tarzan_ghidra_types.hpp"

// Address: 0x0045F890
// Label: CPlayerHero::ResetAdultTarzanElephantRideState
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::ResetAdultTarzanElephantRideState(void)

{
  undefined2 stateFlags;
  undefined4 stateFlags2;
  int value;
  int value2;
  
  PlayAudioById(200,(int *)0,(undefined4 *)0);
  _g_SelectMoviePreviewScene_Field001C = 0;
  SetHudExtraLifeMeterEnabled(0);
  *(undefined1 *)(g_PlayerEntitySceneObject + 0x74) = 0;
  *(undefined2 *)(g_PlayerEntitySceneObject + 0xa4) = 0;
  *(undefined2 *)(g_PlayerEntitySceneObject + 0xa0) = 0;
  *(undefined2 *)(g_PlayerEntitySceneObject + 0xa2) = 0x800;
  g_PlayerMoveHeadingAngle = 0x800;
  g_AdultTarzanElephantScriptedRiseActive = 0;
  g_AdultTarzanElephantRouteEvent40Active = 0;
  g_AdultTarzanElephantRouteEvent100Active = 0;
  g_AdultTarzanElephantRouteEvent10Value = 0;
  g_AdultTarzanElephantRouteEvent100Height = 0;
  g_TarzanToTheRescueScriptedPathPropFlagA = 0;
  g_TarzanToTheRescueScriptedPathPropFlagB = 0;
  g_AdultTarzanElephantRouteEvent10Active = 0;
  g_AdultTarzanElephantMountTransitionBlocked = 0;
  g_TarzanToTheRescueElephantRideMountState = 0;
  _g_ElephantRideAndChaseState_Field00B8 = 0;
  g_TarzanToTheRescueTrackedKnifeEnemyVariantC = 0;
  g_TarzanToTheRescueTrackedKnifeEnemyGroupA1 = 0;
  _g_TarzanToTheRescueKnifeEnemyVariantDReleased = 0;
  g_TarzanToTheRescueTrackedKnifeEnemyGroupB3 = 0;
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
  stateFlags = g_PlayerActionState;
  if (_g_PlayerHeroMode == 7) {
    g_PlayerActionState = 1;
    g_PreviousPlayerActionState = stateFlags;
    (*(code *)g_AdultTarzanElephantEnterIdleHandlerPtr)();
    *(int *)(g_PlayerEntitySceneObjectData + 4) = g_WorldEntitySceneObjectArrayBase + 0x2a40;
    if (g_AdultTarzanElephantEntitySceneObject == 0) goto LAB_0045fa4b;
    *(ushort *)(g_AdultTarzanElephantEntitySceneObject + 0xe) =
         *(ushort *)(g_AdultTarzanElephantEntitySceneObject + 0xe) & 0x7fff;
    *(undefined4 *)(g_AdultTarzanElephantEntitySceneObject + 0x14) = 0;
    *(undefined4 *)(g_AdultTarzanElephantEntitySceneObject + 0x18) = 1000;
    *(undefined4 *)(g_AdultTarzanElephantEntitySceneObject + 0x1c) = 2000;
    GetSceneAttachmentWorldPositionByMask
              (g_AdultTarzanElephantEntitySceneObject,1,g_PlayerEntitySceneObject + 0x14);
    *(undefined2 *)(g_AdultTarzanElephantEntitySceneObject + 0xa0) = 0;
  }
  if (g_AdultTarzanElephantEntitySceneObject != 0) {
    *(undefined2 *)(g_AdultTarzanElephantEntitySceneObject + 0xa0) = 0;
  }
LAB_0045fa4b:
  CPlayerHero::InitElephantRideCameraTrackState();
  value = CEntities::FindEntityAttachmentByFlags(g_PlayerEntity,0x10000018);
  stateFlags2 = g_AdultTarzanElephantFirstBoundaryRailPathBase;
  if (value != 0) {
    *(undefined4 *)(value + 0x2c) = 0;
    *(undefined4 *)(value + 0xc) = stateFlags2;
    *(undefined4 *)(value + 0x30) = 0;
    *(undefined4 *)(value + 0x34) = 0;
    *(undefined4 *)(value + 0x38) = 0;
    *(undefined4 *)(value + 0x4c) = 0;
    *(undefined4 *)(value + 0x54) = 0;
    *(undefined4 *)(value + 0x50) = 0xffffffff;
    *(undefined4 *)(value + 100) = 0;
    SnapPathFollowerAttachmentToNearestSegment(value,g_PlayerEntitySceneObject + 0x14);
  }
  value = CEntities::FindEntityAttachmentByFlags(g_PlayerEntity,0x10000019);
  stateFlags2 = g_AdultTarzanElephantSecondBoundaryRailPathBase;
  if (value != 0) {
    *(undefined4 *)(value + 0x2c) = 0;
    *(undefined4 *)(value + 0xc) = stateFlags2;
    *(undefined4 *)(value + 0x30) = 0;
    *(undefined4 *)(value + 0x34) = 0;
    *(undefined4 *)(value + 0x38) = 0;
    *(undefined4 *)(value + 0x4c) = 0;
    *(undefined4 *)(value + 0x54) = 0;
    *(undefined4 *)(value + 0x50) = 0xffffffff;
    *(undefined4 *)(value + 100) = 0;
    SnapPathFollowerAttachmentToNearestSegment(value,g_PlayerEntitySceneObject + 0x14);
  }
  _g_ElephantRideAndChaseState_Field0034 = 0;
  _g_ElephantRideAndChaseState_Field0038 = 0;
  _g_TarzanToTheRescueActiveEntityCount = 0;
  return;
}

