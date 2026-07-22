#include "tarzan_ghidra_types.hpp"

// Address: 0x00460FB0
// Label: TarzanToTheRescue::InitLevelRuntimeHook
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void TarzanToTheRescue::InitLevelRuntimeHook(void)

{
  undefined2 value4;
  int value;
  int value2;
  int value3;
  
  g_AdultTarzanElephantEntitySceneObject = 0;
  CEntities::ResetRandomAmbientSoundCountdown();
  *(undefined4 *)(g_CurrentWorldSceneContextPtr + 0x54) = 0;
  g_AdultTarzanElephantScriptedRiseActive = 0;
  g_AdultTarzanElephantRouteEvent40Active = 0;
  g_AdultTarzanElephantRouteEvent100Active = 0;
  g_AdultTarzanElephantRouteEvent10Value = 0;
  g_AdultTarzanElephantRouteEvent100Height = 0;
  g_TarzanToTheRescueScriptedPathPropFlagA = 0;
  g_TarzanToTheRescueScriptedPathPropFlagB = 0;
  g_AdultTarzanElephantRouteEvent10Active = 0;
  g_AdultTarzanElephantMountTransitionBlocked = 0;
  _g_ElephantRideAndChaseState_Field00B8 = 0;
  g_TarzanToTheRescueScriptedBarrierAltDone = 0;
  g_TarzanToTheRescueScriptedBarrierLeftDone = 0;
  g_TarzanToTheRescueElephantRescueSequenceActive = 0;
  g_TarzanToTheRescueTrackedKnifeEnemyVariantC = 0;
  g_TarzanToTheRescueTrackedKnifeEnemyGroupA1 = 0;
  _g_TarzanToTheRescueKnifeEnemyVariantDReleased = 0;
  g_TarzanToTheRescueTrackedKnifeEnemyGroupB2 = 0;
  SetHudExtraLifeMeterEnabled(0);
  *(undefined2 *)(g_PlayerEntitySceneObject + 0xa2) = 0x800;
  g_PlayerMoveHeadingAngle = 0x800;
  g_CameraFocusX = *(undefined4 *)(g_PlayerEntitySceneObject + 0x14);
  g_CameraFocusY = *(undefined4 *)(g_PlayerEntitySceneObject + 0x18);
  g_CameraFocusZ = *(undefined4 *)(g_PlayerEntitySceneObject + 0x1c);
  *(undefined2 *)(g_PlayerEntitySceneObject + 0xa4) = 0;
  *(undefined2 *)(g_PlayerEntitySceneObject + 0xa0) = 0;
  PlayAudioById(200,(int *)0,(undefined4 *)0);
  value2 = CEntities::FindEntityAttachmentByFlags(g_PlayerEntity,0x40000000);
  if (value2 == 0) {
    CEntities::CreateEntityAttachment(g_PlayerEntity,0x38,0x40000000);
  }
  value2 = CEntities::FindEntityAttachmentByFlags(g_PlayerEntity,0x40000000);
  if (value2 != 0) {
    value3 = *(int *)(g_CollisionSurfaceTable + 4) + 4 + g_CollisionSurfaceTable;
    *(int *)(value2 + 0xc) = value3;
    value3 = FindRuntimePathSegmentForEntitySceneObject(value3,g_PlayerEntitySceneObject);
    *(int *)(value2 + 0x10) = value3;
    *(int *)(value2 + 0x18) = value3;
    *(undefined4 *)(value2 + 0x30) = 2;
    *(int *)(value2 + 0x14) = *(int *)(value2 + 0xc) + 0x30 + value3 * 0x1c;
    AdvanceRuntimePathAttachmentFromEntitySceneObject(g_PlayerEntity);
  }
  CPlayerHero::InitElephantRideCameraTrackState();
  if (g_AdultTarzanElephantEntitySceneObject == 0) {
    g_AdultTarzanElephantEntitySceneObject = CreateEntityEntitySceneObject((uint *)g_PlayerEntity,5);
    if (g_AdultTarzanElephantEntitySceneObject != 0) {
      *(int *)(g_AdultTarzanElephantEntitySceneObject + 0x10) =
           g_WorldEntitySceneObjectArrayBase + 0xfd8;
      *(undefined2 *)(g_AdultTarzanElephantEntitySceneObject + 0xc) = 2;
      *(ushort *)(g_AdultTarzanElephantEntitySceneObject + 0xe) =
           *(ushort *)(g_AdultTarzanElephantEntitySceneObject + 0xe) & 0x7fff;
      *(undefined2 *)(g_AdultTarzanElephantEntitySceneObject + 0xa6) = 0;
      *(undefined2 *)(g_AdultTarzanElephantEntitySceneObject + 0xa2) = 0x800;
      *(undefined2 *)(g_AdultTarzanElephantEntitySceneObject + 0xc) =
           g_ElephantRideAndChaseState_Field0068;
      value = g_AdultTarzanElephantEntitySceneObject;
      value3 = g_PlayerEntitySceneObject;
      *(undefined4 *)(g_AdultTarzanElephantEntitySceneObject + 0x14) =
           *(undefined4 *)(g_PlayerEntitySceneObject + 0x14);
      *(undefined4 *)(value + 0x18) = *(undefined4 *)(value3 + 0x18);
      *(undefined4 *)(value + 0x1c) = *(undefined4 *)(value3 + 0x1c);
    }
  }
  value4 = g_PlayerActionState;
  if (_g_PlayerHeroMode == 7) {
    g_PlayerActionState = 1;
    g_PreviousPlayerActionState = value4;
    (*(code *)g_AdultTarzanElephantEnterIdleHandlerPtr)();
    *(int *)(g_PlayerEntitySceneObjectData + 4) = g_WorldEntitySceneObjectArrayBase + 0x2a40;
    *(ushort *)(g_PlayerEntitySceneObject + 0xa2) = -*(short *)(value2 + 0x1c) - 0x800U & 0xfff;
    *(undefined1 *)(g_PlayerEntitySceneObject + 0x74) = 0;
    if (g_AdultTarzanElephantEntitySceneObject != 0) {
      *(byte *)(g_AdultTarzanElephantEntitySceneObject + 0xf) =
           *(byte *)(g_AdultTarzanElephantEntitySceneObject + 0xf) | 0x80;
    }
  }
  g_AdultTarzanElephantFirstBoundaryRailPathBase =
       *(int *)(g_CollisionSurfaceTable + 0x38) + 0x38 + g_CollisionSurfaceTable;
  g_AdultTarzanElephantSecondBoundaryRailPathBase =
       *(int *)(g_CollisionSurfaceTable + 0x3c) + 0x3c + g_CollisionSurfaceTable;
  value2 = CEntities::FindEntityAttachmentByFlags(g_PlayerEntity,0x10000018);
  if (value2 == 0) {
    CEntities::CreateEntityAttachment(g_PlayerEntity,0x70,0x10000018);
  }
  value3 = CEntities::FindEntityAttachmentByFlags(g_PlayerEntity,0x10000018);
  value2 = g_AdultTarzanElephantFirstBoundaryRailPathBase;
  if (value3 != 0) {
    *(undefined4 *)(value3 + 0x2c) = 0;
    *(int *)(value3 + 0xc) = value2;
    *(undefined4 *)(value3 + 0x30) = 0;
    *(undefined4 *)(value3 + 0x34) = 0;
    *(undefined4 *)(value3 + 0x38) = 0;
    *(undefined4 *)(value3 + 0x4c) = 0;
    *(undefined4 *)(value3 + 0x54) = 0;
    *(undefined4 *)(value3 + 0x50) = 0xffffffff;
    *(undefined4 *)(value3 + 100) = 0;
  }
  value2 = CEntities::FindEntityAttachmentByFlags(g_PlayerEntity,0x10000019);
  if (value2 == 0) {
    CEntities::CreateEntityAttachment(g_PlayerEntity,0x70,0x10000019);
  }
  value3 = CEntities::FindEntityAttachmentByFlags(g_PlayerEntity,0x10000019);
  value2 = g_AdultTarzanElephantSecondBoundaryRailPathBase;
  if (value3 != 0) {
    *(undefined4 *)(value3 + 0x2c) = 0;
    *(int *)(value3 + 0xc) = value2;
    *(undefined4 *)(value3 + 0x30) = 0;
    *(undefined4 *)(value3 + 0x34) = 0;
    *(undefined4 *)(value3 + 0x38) = 0;
    *(undefined4 *)(value3 + 0x4c) = 0;
    *(undefined4 *)(value3 + 0x54) = 0;
    *(undefined4 *)(value3 + 0x50) = 0xffffffff;
    *(undefined4 *)(value3 + 100) = 0;
  }
  BuildParabolicMotionOffsetTable();
  _g_ElephantRideAndChaseState_Field0084 = 0;
  g_TarzanToTheRescueKnifeEnemyGroupCReleased = 0;
  g_TarzanToTheRescueScriptedBarrierRightDone = 0;
  g_TarzanToTheRescueTrackedKnifeEnemyVariantC = 0;
  g_TarzanToTheRescueTrackedKnifeEnemyGroupA1 = 0;
  _g_TarzanToTheRescueKnifeEnemyVariantDReleased = 0;
  g_TarzanToTheRescueTrackedKnifeEnemyGroupB2 = 0;
  g_TarzanToTheRescueTrackedKnifeEnemyGroupB3 = 0;
  g_TarzanToTheRescueElephantRideMountState = 0;
  g_TarzanToTheRescueKnifeEnemyVariantCReleased = 0;
  return;
}

