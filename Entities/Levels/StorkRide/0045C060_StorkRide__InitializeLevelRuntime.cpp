#include "tarzan_ghidra_types.hpp"

// Address: 0x0045C060
// Label: StorkRide::InitializeLevelRuntime
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void StorkRide::InitializeLevelRuntime(void)

{
  int value;
  int value2;
  
  g_StorkRideStartingCheckpointId = g_CurrentCheckpointId;
  *(undefined4 *)(g_CurrentWorldSceneContextPtr + 0x54) = 0;
  *(undefined2 *)(g_PlayerEntitySceneObject + 0x142) = 0x200;
  PlayAudioById(200,(int *)0,(undefined4 *)0);
  switch(g_StorkRideStartingCheckpointId) {
  case 0:
  case 1:
  case 2:
  case 3:
    g_StorkLeftBoundarySurfaceIndex = 1;
    g_StorkRightBoundarySurfaceIndex = 2;
    g_StorkMovementPathSurfaceIndex = 3;
    g_StorkCameraPathSurfaceIndex = 0;
  }
  InitHudCountdownFromLevelConfig();
  value = CEntities::FindEntityAttachmentByFlags(g_PlayerEntity,0x40000000);
  if (value == 0) {
    CEntities::CreateEntityAttachment(g_PlayerEntity,0x38,0x40000000);
  }
  value = CEntities::FindEntityAttachmentByFlags(g_PlayerEntity,0x40000000);
  if (value != 0) {
    value2 = g_StorkMovementPathSurfaceIndex * 4 + 4;
    value2 = *(int *)(value2 + g_CollisionSurfaceTable) + value2 + g_CollisionSurfaceTable;
    *(int *)(value + 0xc) = value2;
    value2 = FindRuntimePathSegmentForEntitySceneObject(value2,g_PlayerEntitySceneObject);
    *(int *)(value + 0x10) = value2;
    *(int *)(value + 0x18) = value2;
    *(undefined4 *)(value + 0x30) = 0;
    *(undefined4 *)(value + 0x34) = 0;
    *(int *)(value + 0x14) = *(int *)(value + 0xc) + 0x30 + value2 * 0x1c;
    AdvanceRuntimePathAttachmentFromEntitySceneObject(g_PlayerEntity);
  }
  _g_WaterTokenCollectionModeActive = 1;
  _g_LastCollectedWaterTokenSceneObjectId = 0;
  g_CollectedWaterTokenCount = 0;
  BuildParabolicMotionOffsetTable();
  *(int *)(g_PlayerEntitySceneObjectData + 2) = g_WorldEntitySceneObjectArrayBase + 0x1fb0;
  *g_PlayerEntitySceneObjectData = 0x14;
  *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  *(undefined2 *)(g_PlayerEntitySceneObject + 0xa2) = 0x800;
  CCamera::ResetYoungTarzanOnStorkCameraFocus();
  g_PlayerSpecialModeGroundShadowSceneObject = CreateEntityEntitySceneObject((uint *)g_PlayerEntity,5);
  if (g_PlayerSpecialModeGroundShadowSceneObject != 0) {
    *(ushort *)(g_PlayerSpecialModeGroundShadowSceneObject + 0xe) =
         *(ushort *)(g_PlayerSpecialModeGroundShadowSceneObject + 0xe) | 0xc41;
    *(undefined4 *)(g_PlayerSpecialModeGroundShadowSceneObject + 0x30) = 0x390;
    *(undefined4 *)(g_PlayerSpecialModeGroundShadowSceneObject + 0xb4) = 1;
    *(int *)(g_PlayerSpecialModeGroundShadowSceneObject + 0x10) =
         g_WorldEntitySceneObjectArrayBase + 0x3a8;
    *(undefined2 *)(g_PlayerSpecialModeGroundShadowSceneObject + 0xc) = 0x2010;
    *(undefined4 *)(g_PlayerSpecialModeGroundShadowSceneObject + 0x6c) = 0xffffffc0;
    *(int *)(g_PlayerSpecialModeGroundShadowSceneObject + 0x6c) =
         *(int *)(g_PlayerSpecialModeGroundShadowSceneObject + 0x6c) + -0x40;
  }
  return;
}

