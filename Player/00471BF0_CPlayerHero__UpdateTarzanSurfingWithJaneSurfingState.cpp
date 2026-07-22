#include "tarzan_ghidra_types.hpp"

// Address: 0x00471BF0
// Label: CPlayerHero::UpdateTarzanSurfingWithJaneSurfingState
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateTarzanSurfingWithJaneSurfingState(void)

{
  undefined2 stateFlags2;
  int value;
  char resultFlag;
  undefined *stateFlags;
  uint stateFlags3;
  
  value = g_PlayerTreeSurfingLateralThresholdSide;
  g_PlayerTreeSurfingLateralThresholdSide = 0;
  stateFlags3 = *(uint *)(*(int *)(g_PlayerEntitySceneObject + 0x114) + 0x14) & 0xf;
  CPlayerHero::AdvanceAnimationScript();
  g_PlayerSurfaceLeanScale = 200;
  _g_PlayerAnimationPlaybackFrame = 400;
  switch(g_PlayerActionState) {
  case 2:
    resultFlag = CPlayerHero::TryHandleTarzanSurfingWithJaneHazardCue1To4(stateFlags3);
    if (((resultFlag != '\0') ||
        (resultFlag = CPlayerHero::TryHandleTarzanSurfingWithJaneHazardCue5To7(stateFlags3), resultFlag != '\0')) ||
       (resultFlag = CPlayerHero::TryHandleTarzanSurfingWithJaneDamageCue8To10(stateFlags3),
       stateFlags2 = g_PlayerActionState, resultFlag != '\0')) goto switchD_00471c3f_caseD_5;
    if (((_g_PlayerSequenceFlags & 0x2000) == 0) && (g_PlayerFacingCurrentCollisionSurface != '\0'))
    {
      g_PlayerActionState = 8;
      g_PreviousPlayerActionState = stateFlags2;
      (*(code *)g_JaneSurfingEnterCollisionReactionHandlerPtr)();
      goto switchD_00471c3f_caseD_5;
    }
    if ((g_PlayerInputPressedMask & 0x200000) != 0) {
      g_PlayerActionState = 4;
      g_PreviousPlayerActionState = stateFlags2;
      (*(code *)g_JaneSurfingEnterJumpTakeoffHandlerPtr)();
      goto switchD_00471c3f_caseD_5;
    }
    CPlayerHero::UpdateTarzanSurfingWithJaneLateralOffset();
    stateFlags2 = g_PlayerActionState;
    if ((g_PlayerInputHeldMask & 0x40) == 0) {
      _g_TarzanSurfingWithJaneActionPhaseValue = 0;
    }
    else if (g_PlayerLateralSurfaceOffset == 0) {
      g_PlayerActionState = 3;
      g_PreviousPlayerActionState = stateFlags2;
      (*(code *)g_JaneSurfingEnterBrakingHandlerPtr)();
      _g_TarzanSurfingWithJaneActionPhaseValue = 10;
      goto switchD_00471c3f_caseD_5;
    }
    if (value != g_PlayerTreeSurfingLateralThresholdSide) {
      if (g_PlayerTreeSurfingLateralThresholdSide == 1) {
        g_PlayerCurrentAnimationId = 0xc;
        stateFlags = g_JaneSurfingStateTimer;
LAB_00471dcb:
        *(undefined **)(g_PlayerAnimationState + 0xc) = stateFlags;
        *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
        *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
      }
      else {
        if (g_PlayerTreeSurfingLateralThresholdSide != 2) {
          if (value == 1) {
            g_PlayerCurrentAnimationId = 0xe;
            stateFlags = g_JaneSurfingCurrentPathNode;
          }
          else {
            if (value == 2) {
              g_PlayerCurrentAnimationId = 0x11;
              stateFlags = g_JaneSurfingNextPathNode;
              goto LAB_00471d9b;
            }
            g_PlayerCurrentAnimationId = 2;
            stateFlags = g_JaneSurfingSurfAnimationScript;
          }
          goto LAB_00471dcb;
        }
        g_PlayerCurrentAnimationId = 0xf;
        stateFlags = g_JaneSurfingCurrentPathProgress;
LAB_00471d9b:
        *(undefined **)(g_PlayerAnimationState + 0xc) = stateFlags;
        *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
        *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
      }
      CPlayerHero::AdvanceAnimationScript();
    }
    if ((_g_PlayerSequenceFlags & 0x2000) == 0) {
      if ((g_PlayerInputHeldMask & 0x400000) == 0) {
        if (g_TarzanSurfingWithJaneActionSoundActive != '\0') {
          PlayAudioById(0x237,(int *)g_PlayerEntitySceneObject + 0x104,(undefined4 *)g_PlayerEntitySceneObject + 0x14);
        }
        g_TarzanSurfingWithJaneActionEffectTimer = 0;
        g_TarzanSurfingWithJaneActionSoundActive = '\0';
      }
      else if ((g_TarzanSurfingWithJaneActionSoundActive == '\0') &&
              (g_TarzanSurfingWithJaneActionEffectTimer == 0)) {
        PlayAudioById(0x236,(int *)g_PlayerEntitySceneObject + 0x104,(undefined4 *)g_PlayerEntitySceneObject + 0x14);
        g_TarzanSurfingWithJaneActionEffectTimer = 0x3c;
        g_TarzanSurfingWithJaneActionSoundActive = '\x01';
      }
    }
    if (0xa0 < g_PlayerSurfaceMotionSpeed) {
      g_PlayerSurfaceMotionSpeed = g_PlayerSurfaceMotionSpeed + -0x10;
      if (g_PlayerSurfaceMotionSpeed < 0xa0) {
        g_PlayerSurfaceMotionSpeed = 0xa0;
      }
      goto switchD_00471c3f_caseD_5;
    }
    break;
  case 3:
    resultFlag = CPlayerHero::TryHandleTarzanSurfingWithJaneHazardCue1To4(stateFlags3);
    if ((resultFlag != '\0') ||
       (resultFlag = CPlayerHero::TryHandleTarzanSurfingWithJaneHazardCue5To7(stateFlags3),
       stateFlags2 = g_PlayerActionState, resultFlag != '\0')) goto switchD_00471c3f_caseD_5;
    if (((_g_PlayerSequenceFlags & 0x2000) == 0) && (g_PlayerFacingCurrentCollisionSurface != '\0'))
    {
      g_PlayerActionState = 8;
      g_PreviousPlayerActionState = stateFlags2;
      (*(code *)g_JaneSurfingEnterCollisionReactionHandlerPtr)();
      goto switchD_00471c3f_caseD_5;
    }
    if ((g_PlayerInputPressedMask & 0x200000) != 0) {
      g_PlayerActionState = 4;
      g_PreviousPlayerActionState = stateFlags2;
      (*(code *)g_JaneSurfingEnterJumpTakeoffHandlerPtr)();
      goto switchD_00471c3f_caseD_5;
    }
    CPlayerHero::UpdateTarzanSurfingWithJaneLateralOffset();
    stateFlags2 = g_PlayerActionState;
    g_PlayerSurfaceMotionSpeed = g_PlayerSurfaceMotionSpeed + -0x10;
    if (g_PlayerSurfaceMotionSpeed < 0x60) {
      g_PlayerSurfaceMotionSpeed = 0x60;
    }
    if ((((g_PlayerCurrentAnimationId == 10) || (g_PlayerCurrentAnimationId == 0x13)) ||
        (g_PlayerCurrentAnimationId == 0x16)) && ((g_PlayerInputHeldMask & 0x40) == 0)) {
      g_PlayerActionState = 2;
      g_PreviousPlayerActionState = stateFlags2;
      (*(code *)g_JaneSurfingEnterSurfingHandlerPtr)();
    }
  case 7:
  case 8:
    if (g_PlayerLateralSurfaceOffset != 0) {
      if (g_PlayerLateralSurfaceOffset < 0) {
        g_PlayerLateralSurfaceOffset = g_PlayerLateralSurfaceOffset + 1;
      }
      else {
        g_PlayerLateralSurfaceOffset = g_PlayerLateralSurfaceOffset + -1;
      }
    }
    g_PlayerSurfaceMotionSpeed = g_PlayerSurfaceMotionSpeed + -0x10;
    if (g_PlayerSurfaceMotionSpeed < 0x60) {
      g_PlayerSurfaceMotionSpeed = 0x60;
    }
    goto switchD_00471c3f_caseD_5;
  case 4:
    resultFlag = CPlayerHero::TryHandleTarzanSurfingWithJaneHazardCue5To7(stateFlags3);
    if (resultFlag == '\0') {
      CPlayerHero::TryHandleTarzanSurfingWithJaneDamageCue8To10(stateFlags3);
    }
  default:
    goto switchD_00471c3f_caseD_5;
  case 6:
  }
  if ((g_PlayerSurfaceMotionSpeed < 0xa0) &&
     (g_PlayerSurfaceMotionSpeed = g_PlayerSurfaceMotionSpeed + 0x10,
     0xa0 < g_PlayerSurfaceMotionSpeed)) {
    g_PlayerSurfaceMotionSpeed = 0xa0;
  }
switchD_00471c3f_caseD_5:
  *(int *)(g_PlayerMotionState + 0x1c) = g_PlayerSurfaceMotionSpeed;
  CPlayerHero::UpdateMovementAndCollision(1);
  resultFlag = CPlayerHero::TrySnapToNearbyGround();
  if (resultFlag == '\0') {
    DetachEntitySoundHandle(&g_PlayerLoopingSoundHandle);
  }
  return;
}

