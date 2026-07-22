#include "tarzan_ghidra_types.hpp"

// Address: 0x00454CD0
// Label: Stampede::InitializeLevelRuntime
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Stampede::InitializeLevelRuntime(void)

{
  int value;
  int value2;
  int value3;
  int value4;
  
  _g_UnusedStampedeRuntimeState = 0;
  *(undefined4 *)(g_CurrentWorldSceneContextPtr + 0x54) = 0;
  g_StampedeElephantsEntity = 0;
  g_PreviousPlayerActionState = g_PlayerActionState;
  g_PlayerActionState = 1;
  (*(code *)g_StampedeEnterRunningHandlerPtr)();
  *(int *)(g_PlayerEntitySceneObjectData + 4) = g_WorldEntitySceneObjectArrayBase + 0x3128;
  BuildParabolicMotionOffsetTable();
  value2 = CEntities::FindEntityAttachmentByFlags(g_PlayerEntity,0x40000000);
  if (value2 == 0) {
    CEntities::CreateEntityAttachment(g_PlayerEntity,0x38,0x40000000);
  }
  value2 = *(int *)(g_CollisionSurfaceTable + 8) + 8 + g_CollisionSurfaceTable;
  value = *(int *)(g_CollisionSurfaceTable + 0xc) + 0xc + g_CollisionSurfaceTable;
  value3 = CEntities::FindEntityAttachmentByFlags(g_PlayerEntity,0x10000018);
  if (value3 == 0) {
    CEntities::CreateEntityAttachment(g_PlayerEntity,0x70,0x10000018);
  }
  value3 = CEntities::FindEntityAttachmentByFlags(g_PlayerEntity,0x10000019);
  if (value3 == 0) {
    CEntities::CreateEntityAttachment(g_PlayerEntity,0x70,0x10000019);
  }
  value3 = CEntities::FindEntityAttachmentByFlags(g_PlayerEntity,0x40000000);
  if (value3 != 0) {
    value4 = *(int *)(g_CollisionSurfaceTable + 0x10) + 0x10 + g_CollisionSurfaceTable;
    *(int *)(value3 + 0xc) = value4;
    value4 = FindRuntimePathSegmentForEntitySceneObject(value4,g_PlayerEntitySceneObject);
    *(int *)(value3 + 0x10) = value4;
    *(int *)(value3 + 0x18) = value4;
    *(undefined4 *)(value3 + 0x30) = 0;
    *(undefined4 *)(value3 + 0x34) = 0;
    *(int *)(value3 + 0x14) = *(int *)(value3 + 0xc) + 0x30 + value4 * 0x1c;
    AdvanceRuntimePathAttachmentFromCachedDirection(g_PlayerEntity);
  }
  value3 = CEntities::FindEntityAttachmentByFlags(g_PlayerEntity,0x10000018);
  if (value3 != 0) {
    *(int *)(value3 + 0xc) = value2;
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
  value2 = CEntities::FindEntityAttachmentByFlags(g_PlayerEntity,0x10000019);
  if (value2 != 0) {
    *(undefined4 *)(value2 + 0x28) = 0;
    *(int *)(value2 + 0xc) = value;
    *(undefined4 *)(value2 + 0x2c) = 0;
    *(undefined4 *)(value2 + 0x30) = 0;
    *(undefined4 *)(value2 + 0x34) = 0;
    *(undefined4 *)(value2 + 0x38) = 0;
    *(undefined4 *)(value2 + 0x4c) = 0x7fffffff;
    *(undefined4 *)(value2 + 0x54) = 0;
    *(undefined4 *)(value2 + 0x68) = 0xffffffff;
    *(undefined4 *)(value2 + 0x50) = 0xffffffff;
    *(undefined4 *)(value2 + 100) = 0;
    SnapPathFollowerAttachmentToNearestSegment(value2,g_PlayerEntitySceneObject + 0x14);
  }
  *(undefined4 *)(g_PlayerEntitySceneObject + 0xb4) = 1;
  *(undefined4 *)(g_PlayerEntitySceneObject + 0xa8) = 0x1800;
  *(undefined4 *)(g_PlayerEntitySceneObject + 0xac) = 0x1800;
  *(undefined4 *)(g_PlayerEntitySceneObject + 0xb0) = 0x1800;
  g_PlayerSpecialModeGroundShadowSceneObject = CreateEntityEntitySceneObject((uint *)g_PlayerEntity,5);
  if (g_PlayerSpecialModeGroundShadowSceneObject != 0) {
    *(ushort *)(g_PlayerSpecialModeGroundShadowSceneObject + 0xe) =
         *(ushort *)(g_PlayerSpecialModeGroundShadowSceneObject + 0xe) | 0xc41;
    *(undefined4 *)(g_PlayerSpecialModeGroundShadowSceneObject + 0x30) = 0x400;
    *(int *)(g_PlayerSpecialModeGroundShadowSceneObject + 0x10) =
         g_WorldEntitySceneObjectArrayBase + 0x30c0;
    *(undefined2 *)(g_PlayerSpecialModeGroundShadowSceneObject + 0xc) = 0x203f;
    *(undefined4 *)(g_PlayerSpecialModeGroundShadowSceneObject + 0x6c) = 0xffffff9c;
  }
  CPlayerHero::InitStampedeCameraTrackState();
  g_StampedeElephantsEntity = CEntities::SpawnEntityByTypeAtPosition(0,0,0,0x87,0x11);
  return;
}

