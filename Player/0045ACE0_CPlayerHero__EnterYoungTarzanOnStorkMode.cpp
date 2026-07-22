#include "tarzan_ghidra_types.hpp"

// Address: 0x0045ACE0
// Label: CPlayerHero::EnterYoungTarzanOnStorkMode
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::EnterYoungTarzanOnStorkMode(void)

{
  int value;
  int value2;
  
  *(undefined4 *)(g_CurrentWorldSceneContextPtr + 0x54) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0x6000;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 0x700;
  *(undefined4 *)(g_PlayerMotionState + 0x18) = 0x300;
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0x3000;
  *(undefined4 *)(g_PlayerMotionState + 0x10) = 0x3f00;
  *(ushort *)(g_PlayerGroundShadowProbeEntitySceneObject + 0xe) =
       *(ushort *)(g_PlayerGroundShadowProbeEntitySceneObject + 0xe) & 0x7fff;
  CEntities::ResetRandomAmbientSoundCountdown();
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
  g_StorkImpactReactionCooldownActive = 0;
  _g_StorkTerrainCollisionFlags = 0;
  g_PreviousPlayerActionState = g_PlayerActionState;
  g_PlayerActionState = 1;
  (*(code *)g_StorkEnterFreeFlightHandlerPtr)();
  (**(code **)(&g_StorkActionStateUpdateColumn + (uint)g_PlayerActionState * 8))();
  g_CameraYaw = 0;
  g_StorkCameraTrackInitialized = 0;
  g_StorkBoundaryRailsInitialized = 0;
  g_StorkFlapBoostStage = 8;
  return;
}

