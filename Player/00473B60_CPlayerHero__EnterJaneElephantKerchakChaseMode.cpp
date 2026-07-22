#include "tarzan_ghidra_types.hpp"

// Address: 0x00473B60
// Label: CPlayerHero::EnterJaneElephantKerchakChaseMode
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::EnterJaneElephantKerchakChaseMode(void)

{
  int value;
  int value2;
  int value3;
  
  *(uint *)(*(int *)(g_CurrentWorldSceneContext + 0x24) + 4) =
       *(uint *)(*(int *)(g_CurrentWorldSceneContext + 0x24) + 4) & 0xfffffffd;
  g_KerchakChasePursuerStartChecked = 0;
  _g_ElephantRideAndChaseState_Field0190 = 0;
  _g_ElephantRideAndChaseState_Field0194 = 0;
  value = CEntities::FindEntityAttachmentByFlags(g_PlayerEntity,0x40000000);
  if (value == 0) {
    CEntities::CreateEntityAttachment(g_PlayerEntity,0x38,0x40000000);
  }
  value = CEntities::FindEntityAttachmentByFlags(g_PlayerEntity,0x40000000);
  if (value != 0) {
    value2 = *(int *)(g_CollisionSurfaceTable + 0x10) + 0x10 + g_CollisionSurfaceTable;
    *(int *)(value + 0xc) = value2;
    value2 = FindRuntimePathSegmentForEntitySceneObject(value2,g_PlayerEntitySceneObject);
    *(int *)(value + 0x10) = value2;
    *(int *)(value + 0x18) = value2;
    *(undefined4 *)(value + 0x30) = 0;
    *(undefined4 *)(value + 0x34) = 0;
    *(int *)(value + 0x14) = *(int *)(value + 0xc) + 0x30 + value2 * 0x1c;
    AdvanceRuntimePathAttachmentFromCachedDirection(g_PlayerEntity);
  }
  value = *(int *)(g_CollisionSurfaceTable + 8) + 8 + g_CollisionSurfaceTable;
  value2 = *(int *)(g_CollisionSurfaceTable + 0xc) + 0xc + g_CollisionSurfaceTable;
  value3 = CEntities::FindEntityAttachmentByFlags(g_PlayerEntity,0x10000018);
  if (value3 == 0) {
    CEntities::CreateEntityAttachment(g_PlayerEntity,0x70,0x10000018);
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
  if (value == 0) {
    CEntities::CreateEntityAttachment(g_PlayerEntity,0x70,0x10000019);
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
  CPlayerHero::InitKerchakChaseCameraTrackState();
  g_PreviousPlayerActionState = g_PlayerActionState;
  g_PlayerActionState = 0;
  (*(code *)g_JaneElephantKerchakChaseActionStateEnterColumn)();
  *(int *)(g_PlayerEntitySceneObjectData + 4) = g_WorldEntitySceneObjectArrayBase + 0x2ff0;
  *(undefined4 *)(g_PlayerMotionState + 0x10) = 0xffffba00;
  *(ushort *)(g_PlayerGroundShadowProbeEntitySceneObject + 0xe) =
       *(ushort *)(g_PlayerGroundShadowProbeEntitySceneObject + 0xe) & 0x7fff;
  return;
}

