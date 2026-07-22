#include "tarzan_ghidra_types.hpp"

// Address: 0x00480930
// Label: CPlayerHero::EnterYoungTarzanOrTerkLeafSwimmingMode
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::EnterYoungTarzanOrTerkLeafSwimmingMode(void)

{
  int value;
  int value2;
  int value3;
  
  *(short *)(g_PlayerEntitySceneObject + 0xa2) =
       *(short *)(g_PlayerEntitySceneObject + 0xa2) + 0x800;
  g_LeafSwimmingPlayerRouteSurfaceIndex = 0;
  *(byte *)(g_PlayerEntitySceneObject + 0xf) = *(byte *)(g_PlayerEntitySceneObject + 0xf) | 4;
  *(ushort *)(g_PlayerGroundShadowProbeEntitySceneObject + 0xe) =
       *(ushort *)(g_PlayerGroundShadowProbeEntitySceneObject + 0xe) & 0x7fff;
  g_LeafSwimmingCameraYawTarget = 0;
  _g_ElephantRideAndChaseState_Field03F0 = 0;
  _g_ElephantRideAndChaseState_Field03F4 = 0;
  _g_ElephantRideAndChaseState_Field03F8 = 0;
  _g_LeafSwimmingPreviousRouteNode = 0;
  g_LeafSwimmingWhirlpoolPullActive = 0;
  g_ActiveLeafSwimmingTokenCount = 0;
  _g_LeafSwimmingSurfaceProgress = 0;
  g_LeafSwimmingEarlyStageMotionTable = 0x800;
  _g_LeafSwimmingCameraRouteNode = 0;
  CPlayerHero::ResetLeafSwimmingCameraState();
  g_PreviousPlayerActionState = g_PlayerActionState;
  g_PlayerActionState = 1;
  (*(code *)g_LeafSwimmingEnterPaddlingCallback)();
  (**(code **)(&g_LeafSwimmingActionStateUpdateColumn + (uint)g_PlayerActionState * 8))();
  g_LeafSwimmingCurrentRouteNode = 0;
  _g_LeafSwimmingBoostInputSeen = 0;
  CPlayerHero::AdvanceLeafSwimmingSurfaceTrack();
  g_LeafSwimmingWhirlpoolSoundVariant = 0;
  g_LeafSwimmingCountdownTicks = 0;
  value = g_LeafSwimmingBoundarySurfaceIndexA * 4 + 4;
  value3 = *(int *)(value + g_CollisionSurfaceTable) + value + g_CollisionSurfaceTable;
  value = g_LeafSwimmingBoundarySurfaceIndexB * 4 + 4;
  value2 = *(int *)(value + g_CollisionSurfaceTable) + value + g_CollisionSurfaceTable;
  value = CEntities::FindEntityAttachmentByFlags(g_PlayerEntity,0x10000018);
  if (value == 0) {
    CEntities::CreateEntityAttachment(g_PlayerEntity,0x70,0x10000018);
  }
  value = CEntities::FindEntityAttachmentByFlags(g_PlayerEntity,0x10000019);
  if (value == 0) {
    CEntities::CreateEntityAttachment(g_PlayerEntity,0x70,0x10000019);
  }
  value = CEntities::FindEntityAttachmentByFlags(g_PlayerEntity,0x10000018);
  if (value != 0) {
    *(int *)(value + 0xc) = value3;
    *(undefined4 *)(value + 0x28) = 0;
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
  if (value != 0) {
    *(int *)(value + 0xc) = value2;
    *(undefined4 *)(value + 0x28) = 0;
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
  _g_LastCollectedWaterTokenSceneObjectId = 0;
  g_CollectedWaterTokenCount = 0;
  g_LeafSwimmingNextRouteNode = 0;
  g_LeafSwimmingCameraOrbitAngle = 0;
  g_LeafSwimmingWaterfallDropActive = 0;
  _g_LeafSwimmingWaterfallSurfaceIndex = 0;
  _g_LeafSwimmingWhirlpoolSurfaceIndex = 0;
  g_LeafSwimmingBonusTimerActive = 0;
  g_LeafSwimmingSurfaceSpeed = 0;
  g_LeafSwimmingSurfaceDriftX = 0;
  _g_WaterTokenCollectionModeActive = 1;
  return;
}

