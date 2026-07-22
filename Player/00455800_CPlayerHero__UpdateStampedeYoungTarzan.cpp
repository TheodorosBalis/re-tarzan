#include "tarzan_ghidra_types.hpp"

// Address: 0x00455800
// Label: CPlayerHero::UpdateStampedeYoungTarzan
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::UpdateStampedeYoungTarzan(void)

{
  short *value3;
  int value;
  int *intCursor;
  int value2;
  
  AdvanceRuntimePathAttachmentFromCachedDirection(g_PlayerEntity);
  (**(code **)(&g_StampedeYoungTarzanActionStateUpdateColumn + (uint)g_PlayerActionState * 8))();
  if (g_StampedeWorldConstraintUpdatesEnabled != 0) {
    value = CEntities::FindEntityAttachmentByFlags(g_PlayerEntity,0x10000018);
    if (value != 0) {
      UpdatePathFollowerAttachmentNearestSegment(value,*(int *)(g_PlayerEntity + 0x38) + 0x14);
      if (g_StampedeLeftRailScriptedPullActive != 0) {
        *(undefined4 *)(value + 0x28) = 0;
        *(undefined4 *)(value + 0x68) = 0xffffffff;
        *(undefined4 *)(value + 100) = 0;
      }
      if (((*(int *)(value + 0x28) != 0) && (*(int *)(value + 0x4c) < 0x1fa5)) &&
         (*(int *)(value + 0x50) == 0)) {
        *(undefined4 *)(value + 0x68) = 1;
      }
      if (*(int *)(value + 0x68) == 1) {
        if (*(int *)(value + 100) < *(int *)(*(int *)(value + 0x30) + 4)) {
          intCursor = (int *)InterpolateJungleSurfacePointByCoordRef
                                    (*(int *)(value + 0x28),*(int *)(value + 100),
                                     (undefined4 *)(value + 0x58));
          if (intCursor != (int *)0x0) {
            value3 = (short *)(g_PlayerEntitySceneObject + 0xa2);
            value2 = GetAngleFromXZVector12Bit(intCursor[7] - *intCursor,intCursor[9] - intCursor[2]);
            value2 = GetWrappedSignedAngleDelta12Bit
                              ((int)*(short *)(g_PlayerEntitySceneObject + 0xa2),value2 + 0x800);
            *value3 = *value3 + (short)(value2 >> 1);
          }
          *(undefined4 *)(g_PlayerEntitySceneObject + 0x14) = *(undefined4 *)(value + 0x58);
          *(undefined4 *)(g_PlayerEntitySceneObject + 0x1c) = *(undefined4 *)(value + 0x60);
          *(int *)(value + 100) = *(int *)(value + 100) + 0x3c;
        }
        else {
          *(undefined4 *)(value + 0x68) = 0;
        }
      }
      else {
        PushEntitySceneObjectOutsidePathBoundaryRadiusXZ
                  (g_PlayerEntitySceneObject,*(undefined4 *)(value + 0x10),1,value + 0x18,0x52);
      }
    }
    value = CEntities::FindEntityAttachmentByFlags(g_PlayerEntity,0x10000019);
    if (value != 0) {
      UpdatePathFollowerAttachmentNearestSegment(value,*(int *)(g_PlayerEntity + 0x38) + 0x14);
      PushEntitySceneObjectOutsidePathBoundaryRadiusXZ
                (g_PlayerEntitySceneObject,*(undefined4 *)(value + 0x10),0,value + 0x18,0x52);
    }
    if (0 < g_StampedeDamageRecoilTicksRemaining) {
      g_StampedeDamageRecoilTicksRemaining = g_StampedeDamageRecoilTicksRemaining + -1;
    }
    if (g_PlayerSpecialModeGroundShadowSceneObject != 0) {
      g_StampedeElephantRideDescriptor = *(int *)(g_PlayerEntitySceneObject + 0x58);
      *(undefined4 *)(g_PlayerSpecialModeGroundShadowSceneObject + 0x14) =
           *(undefined4 *)(g_PlayerEntitySceneObject + 0x14);
      *(int *)(g_PlayerSpecialModeGroundShadowSceneObject + 0x18) =
           *(int *)(g_PlayerEntitySceneObject + 0x18) + g_StampedeElephantRideDescriptor;
      *(undefined4 *)(g_PlayerSpecialModeGroundShadowSceneObject + 0x1c) =
           *(undefined4 *)(g_PlayerEntitySceneObject + 0x1c);
      *(int *)(g_PlayerSpecialModeGroundShadowSceneObject + 0x30) =
           0x8b0 - (g_StampedeElephantRideDescriptor * 0xc0 >> 8);
    }
    return;
  }
  return;
}

