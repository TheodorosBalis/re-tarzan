#include "tarzan_ghidra_types.hpp"

// Address: 0x004346D0
// Label: TryStartPlayerAttachmentInteraction
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 TryStartPlayerAttachmentInteraction(void)

{
  int value;
  undefined2 value9;
  int value2;
  int value3;
  int value4;
  int value5;
  int value6;
  int value7;
  int value8;
  
  value5 = g_ActiveSwingEntityList;
  value = g_PlayerInteractionCollisionHeightRange;
  g_PlayerTiltControlEnabled = 0;
  value3 = GetSceneAttachmentWorldPositionByMask
                    (g_PlayerEntitySceneObject,0x10,&g_BranchBoostChildWorldPositionScratch);
  value7 = g_BranchBoostChildWorldPositionZScratch;
  value2 = g_BranchBoostChildSceneObjectPtrScratch;
  value8 = g_BranchBoostChildWorldPositionScratch;
  if (value3 != 0) {
    for (; value5 != 0; value5 = *(int *)(value5 + 0x20)) {
      value3 = *(int *)(value5 + 0x38);
      if ((((value3 != 0) && (*(int *)(value3 + 0x94) < value2)) && (value2 < *(int *)(value3 + 0x98)))
         && ((value4 = value8 - *(int *)(value3 + 0x14), value6 = value7 - *(int *)(value3 + 0x1c),
             value6 * value6 + value4 * value4 < *(int *)(value3 + 0x90) &&
             (g_CurrentSwingSegmentIndex = FindSwingSegmentIndexAtHeight(value3,value2),
             g_CurrentSwingSegmentIndex != 0)))) {
        GetSceneAttachmentWorldPositionByIndex
                  (value3,&g_BranchBoostChildWorldPositionScratch,g_CurrentSwingSegmentIndex + -1);
        g_PlayerFacingBeforeSwing = *(undefined1 *)(g_PlayerEntitySceneObject + 0x75);
        if (_g_PlayerHeroMode == 1) {
          PlayAudioById(0x50,(int *)0,(undefined4 *)g_PlayerEntitySceneObject + 0x14);
          value = g_PlayerEntitySceneObject;
          *(int *)(g_PlayerEntitySceneObject + 0x14) = g_BranchBoostChildWorldPositionScratch;
          *(int *)(value + 0x18) = g_BranchBoostChildSceneObjectPtrScratch;
          *(int *)(value + 0x1c) = g_BranchBoostChildWorldPositionZScratch;
          g_PreviousPlayerActionState = g_PlayerActionState;
          g_CurrentSwingEntity = value5;
          if ((g_PlayerInputHeldMask & g_CameraFollowFlags) != 0) {
            g_PlayerActionState = 0x1e;
            (*(code *)g_AdultTarzanEnterSwingPumpHandlerPtr)();
            return 1;
          }
          goto LAB_00434975;
        }
        if (_g_PlayerHeroMode == 2) {
          PlayAudioById(0x11,(int *)0,(undefined4 *)g_PlayerEntitySceneObject + 0x14);
          value = g_PlayerEntitySceneObject;
          *(int *)(g_PlayerEntitySceneObject + 0x14) = g_BranchBoostChildWorldPositionScratch;
          *(int *)(value + 0x18) = g_BranchBoostChildSceneObjectPtrScratch;
          *(int *)(value + 0x1c) = g_BranchBoostChildWorldPositionZScratch;
          g_PreviousPlayerActionState = g_PlayerActionState;
          g_CurrentSwingEntity = value5;
          if ((g_PlayerInputHeldMask & g_CameraFollowFlags) != 0) {
            g_PlayerActionState = 0x1f;
            (*(code *)g_YoungEnterSwingPumpHandlerPtr)();
            return 1;
          }
          goto LAB_0043484c;
        }
      }
    }
    if (((g_PlayerCurrentCollisionSurface != (int *)0x0) &&
        ((*(byte *)(g_PlayerCurrentCollisionSurface + 5) & 0x10) != 0)) &&
       (value5 = ((int)*(short *)((int)g_PlayerCurrentCollisionSurface + 0x12) -
                g_PlayerCurrentCollisionSurface[1]) + value2,
       value5 * value5 +
       (value7 - g_PlayerCurrentCollisionSurface[2]) * (value7 - g_PlayerCurrentCollisionSurface[2]) +
       (value8 - *g_PlayerCurrentCollisionSurface) * (value8 - *g_PlayerCurrentCollisionSurface) <
       0x2400)) {
      if (_g_PlayerHeroMode == 1) {
        *(int *)(g_PlayerEntitySceneObject + 0x10c) = g_PlayerCurrentCollisionSurface[3];
        CPlayerHero::SnapToCurrentJungleSurface();
        g_CurrentSwingEntity = 0;
LAB_00434975:
        g_PreviousPlayerActionState = g_PlayerActionState;
        g_PlayerActionState = 0x16;
        (*(code *)g_AdultTarzanEnterGrabSwingHandlerPtr)();
        return 1;
      }
      if (_g_PlayerHeroMode == 2) {
        *(int *)(g_PlayerEntitySceneObject + 0x10c) = g_PlayerCurrentCollisionSurface[3];
        CPlayerHero::SnapToCurrentJungleSurface();
        g_CurrentSwingEntity = 0;
LAB_0043484c:
        g_PreviousPlayerActionState = g_PlayerActionState;
        g_PlayerActionState = 0x17;
        (*(code *)g_YoungEnterGrabSwingHandlerPtr)();
        return 1;
      }
    }
    if (g_PlayerInteractionCollisionSurface == (int *)0x0) {
      return 0;
    }
    value8 = value8 - *g_PlayerInteractionCollisionSurface;
    value7 = value7 - g_PlayerInteractionCollisionSurface[2];
    if ((((*(byte *)(g_PlayerInteractionCollisionSurface + 5) & 0x80) != 0) &&
        ((value2 - g_PlayerInteractionCollisionSurface[1]) *
         (value2 - g_PlayerInteractionCollisionSurface[1]) + value7 * value7 + value8 * value8 < 0x4000))
       && (value5 = IsFacingBlockedEndOfSurfaceSegment
                             (_g_PlayerMoveHeadingAngle & 0xffff,g_PlayerInteractionCollisionSurface
                             ), value5 != 0)) {
      g_CurrentSwingEntity = 0;
      CPlayerHero::SnapPlayerToAttachmentSurfaceCoord
                (g_PlayerInteractionCollisionSurface,g_PlayerInteractionCollisionSurfaceIndex,1);
      value9 = g_PlayerActionState;
      if (_g_PlayerHeroMode == 1) {
        g_PlayerActionState = 0x1f;
        g_PreviousPlayerActionState = value9;
        (*(code *)g_AdultTarzanEnterClimbableEdgeGrabHandlerPtr)();
        return 1;
      }
      if (_g_PlayerHeroMode == 2) {
        g_PlayerActionState = 0x20;
        g_PreviousPlayerActionState = value9;
        (*(code *)g_YoungEnterClimbableEdgeGrabHandlerPtr)();
        return 1;
      }
      if (_g_PlayerHeroMode == 6) {
        g_PreviousPlayerActionState = g_PlayerActionState;
        goto LAB_00434b36;
      }
    }
    if ((((*(byte *)(g_PlayerInteractionCollisionSurface + 5) & 0x40) != 0) &&
        (g_PlayerInteractionCollisionBaseY < value2)) &&
       ((value2 <= g_PlayerInteractionCollisionBaseY + value &&
        (value7 * value7 + value8 * value8 < 0x2400)))) {
      g_CurrentSwingEntity = 0;
      CPlayerHero::SnapPlayerToAttachmentSurfaceCoord
                (g_PlayerInteractionCollisionSurface,g_PlayerInteractionCollisionSurfaceIndex,0);
      *(int *)(g_PlayerEntitySceneObjectData + 0xc) =
           ((value2 - g_PlayerInteractionCollisionBaseY) / g_PlayerCollisionStepHeight) *
           g_PlayerCollisionStepHeight + g_PlayerInteractionCollisionBaseY;
      value9 = g_PlayerActionState;
      if (_g_PlayerHeroMode == 1) {
        g_PlayerActionState = 0x23;
        g_PreviousPlayerActionState = value9;
        (*(code *)g_AdultTarzanEnterClimbableWallGrabHandlerPtr)();
        return 1;
      }
      if (_g_PlayerHeroMode == 2) {
        g_PlayerActionState = 0x2a;
        g_PreviousPlayerActionState = value9;
        (*(code *)g_YoungEnterClimbableWallGrabHandlerPtr)();
        return 1;
      }
      if (_g_PlayerHeroMode == 6) {
        g_PreviousPlayerActionState = g_PlayerActionState;
LAB_00434b36:
        g_PlayerActionState = 0x18;
        (*(code *)g_TerkEnterClimbableWallGrabHandlerPtr)();
        return 1;
      }
    }
  }
  return 0;
}

