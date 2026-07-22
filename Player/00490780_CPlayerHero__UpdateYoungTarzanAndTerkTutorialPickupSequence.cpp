#include "tarzan_ghidra_types.hpp"

// Address: 0x00490780
// Label: CPlayerHero::UpdateYoungTarzanAndTerkTutorialPickupSequence
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateYoungTarzanAndTerkTutorialPickupSequence(void)

{
  ushort value3;
  undefined2 value4;
  char resultFlag;
  int value;
  int value2;
  
  value4 = g_PlayerActionState;
  g_PlayerDamageInvulnerabilityTicks = 0x3c;
  if (g_TutorialPickupSequencePhase == 5) {
    g_PlayerActionState = 0x3e;
    g_PreviousPlayerActionState = value4;
    (*(code *)g_YoungEnterTutorialPickupReturnIdleHandlerPtr)();
    *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0;
    *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
    CPlayerHero::UpdateMovementAndCollision(1);
    return;
  }
  switch(g_PlayerActionState) {
  case 0x37:
    goto LAB_00490865;
  case 0x38:
    *(byte *)(g_PlayerGroundShadowProbeEntitySceneObject + 0xf) =
         *(byte *)(g_PlayerGroundShadowProbeEntitySceneObject + 0xf) | 0x80;
    if (g_TutorialPickupSkipApproachFlag != 0) {
      g_PlayerActionState = 0x39;
      CPlayerHero::PlayAnimation(0xa1);
      return;
    }
    *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0x20;
    *(undefined4 *)(g_PlayerMotionState + 0x10) = 0x20;
    CPlayerHero::UpdateMovementAndCollision(1);
    value4 = g_PlayerActionState;
    if (g_PlayerCollisionFacingFlags != '\x01') goto LAB_00490d30;
    g_PlayerActionState = 0x3a;
    g_PreviousPlayerActionState = value4;
    (*(code *)g_YoungEnterTutorialPickupFinalPoseHandlerPtr)();
LAB_00490865:
    *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0;
    *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
    break;
  case 0x39:
    if (g_PlayerCurrentAnimationId == 0xa1) {
      *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0;
      *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
    }
    else {
      *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0x20;
      *(undefined4 *)(g_PlayerMotionState + 0x10) = 0x20;
    }
    CPlayerHero::UpdateMovementAndCollision(1);
    if (g_PlayerCollisionFacingFlags == '\x01') {
      g_TutorialPickupSequencePhase = 4;
      value2 = *(int *)(g_ActiveTutorialPickupEntity + 0x38);
      *(undefined4 *)(g_PlayerEntitySceneObjectData + 4) = *(undefined4 *)(value2 + 0x14);
      *(undefined4 *)(g_PlayerEntitySceneObjectData + 6) = *(undefined4 *)(value2 + 0x18);
      *(undefined4 *)(g_PlayerEntitySceneObjectData + 8) = *(undefined4 *)(value2 + 0x1c);
      g_PlayerEntitySceneObjectData[1] = *(undefined2 *)(value2 + 0xe);
      *(undefined4 *)(g_PlayerEntitySceneObject + 0x6c) = *(undefined4 *)(value2 + 0x6c);
      *(undefined2 *)(g_PlayerEntitySceneObject + 0xa0) = *(undefined2 *)(value2 + 0xa0);
      _g_PlayerMoveTiltAngle = *(undefined2 *)(g_PlayerEntitySceneObject + 0xa0);
      *(undefined2 *)(g_PlayerEntitySceneObject + 0xa2) = *(undefined2 *)(value2 + 0xa2);
      g_PlayerMoveHeadingAngle = *(undefined2 *)(g_PlayerEntitySceneObject + 0xa2);
      *(undefined2 *)(g_PlayerEntitySceneObject + 0xa4) = *(undefined2 *)(value2 + 0xa4);
      *(undefined2 *)(g_PlayerEntitySceneObject + 0xa6) = *(undefined2 *)(value2 + 0xa6);
      *(undefined4 *)(g_PlayerEntitySceneObject + 0x10c) = *(undefined4 *)(value2 + 0x10c);
      *(undefined4 *)(g_PlayerEntitySceneObject + 0x110) = *(undefined4 *)(value2 + 0x110);
      *(undefined4 *)(g_PlayerEntitySceneObject + 0x110) = *(undefined4 *)(value2 + 0x110);
      *(undefined4 *)(g_PlayerEntitySceneObject + 0x10c) = *(undefined4 *)(value2 + 0x10c);
      *(undefined4 *)(g_PlayerEntitySceneObject + 0x114) = *(undefined4 *)(value2 + 0x114);
      *(undefined2 *)(g_PlayerEntitySceneObject + 0x142) = *(undefined2 *)(value2 + 0x142);
      value = g_PlayerEntitySceneObject;
      *(undefined4 *)(g_PlayerEntitySceneObject + 0x14) = *(undefined4 *)(value2 + 0x14);
      *(undefined4 *)(value + 0x18) = *(undefined4 *)(value2 + 0x18);
      *(undefined4 *)(value + 0x1c) = *(undefined4 *)(value2 + 0x1c);
      value = g_PlayerEntitySceneObject;
      *(undefined4 *)(g_PlayerEntitySceneObject + 0x3c) = *(undefined4 *)(value2 + 0x3c);
      *(undefined4 *)(value + 0x40) = *(undefined4 *)(value2 + 0x40);
      *(undefined4 *)(value + 0x44) = *(undefined4 *)(value2 + 0x44);
      value = g_PlayerEntitySceneObject;
      *(undefined4 *)(g_PlayerEntitySceneObject + 0x48) = *(undefined4 *)(value2 + 0x48);
      *(undefined4 *)(value + 0x4c) = *(undefined4 *)(value2 + 0x4c);
      *(undefined4 *)(value + 0x50) = *(undefined4 *)(value2 + 0x50);
      value = g_PlayerEntitySceneObject;
      *(undefined4 *)(g_PlayerEntitySceneObject + 0x54) = *(undefined4 *)(value2 + 0x54);
      *(undefined4 *)(value + 0x58) = *(undefined4 *)(value2 + 0x58);
      *(undefined4 *)(value + 0x5c) = *(undefined4 *)(value2 + 0x5c);
      *(int *)(g_PlayerEntitySceneObjectData + 2) = g_WorldEntitySceneObjectArrayBase + 0x1a0;
      *g_PlayerEntitySceneObjectData = 0x9d;
      *(undefined4 *)(g_PlayerEntitySceneObject + 0x70) = *(undefined4 *)(value2 + 0x70);
      *(undefined4 *)(g_PlayerEntitySceneObject + 0xb4) = 1;
      *(undefined4 *)(g_PlayerEntitySceneObject + 0xa8) = 0x1000;
      *(undefined4 *)(g_PlayerEntitySceneObject + 0xac) = 0x1000;
      *(undefined4 *)(g_PlayerEntitySceneObject + 0xb0) = 0x1000;
      *(undefined1 *)(g_PlayerEntitySceneObject + 0x75) = *(undefined1 *)(value2 + 0x75);
      *(undefined2 *)(g_PlayerEntitySceneObject + 0x140) = 0x80;
      if (g_PlayerGroundShadowProbeEntitySceneObject != 0) {
        *(int *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x10) =
             g_WorldEntitySceneObjectArrayBase + 0x3a8;
        *(undefined2 *)(g_PlayerGroundShadowProbeEntitySceneObject + 0xc) = 0x2010;
        value = g_PlayerGroundShadowProbeEntitySceneObject;
        value2 = g_PlayerEntitySceneObject;
        *(undefined4 *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x14) =
             *(undefined4 *)(g_PlayerEntitySceneObject + 0x14);
        *(undefined4 *)(value + 0x18) = *(undefined4 *)(value2 + 0x18);
        *(undefined4 *)(value + 0x1c) = *(undefined4 *)(value2 + 0x1c);
        *(ushort *)(g_PlayerGroundShadowProbeEntitySceneObject + 0xe) =
             *(ushort *)(g_PlayerGroundShadowProbeEntitySceneObject + 0xe) | 0x441;
        *(undefined4 *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x30) = 0x400;
        *(undefined4 *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x6c) = 0xffffffec;
        *(undefined4 *)(g_PlayerEntitySceneObject + 0x6c) = 0xffffffe2;
        *(undefined2 *)(g_PlayerEntitySceneObject + 0xa6) = 1;
        *(undefined4 *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x108) =
             *(undefined4 *)(g_PlayerEntitySceneObject + 0x108);
        *(undefined4 *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x110) =
             *(undefined4 *)(g_PlayerEntitySceneObject + 0x110);
        *(undefined4 *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x10c) =
             *(undefined4 *)(g_PlayerEntitySceneObject + 0x10c);
      }
    }
    goto LAB_00490d30;
  case 0x3a:
    *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0;
    *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
    CPlayerHero::UpdateMovementAndCollision(1);
    if (g_TutorialPickupSkipApproachFlag != 0) {
      g_TutorialPickupSequenceTick = g_TutorialPickupFinalPoseDurationTicks;
      InitAudioLine_stub();
    }
    g_TutorialPickupSequenceTick = g_TutorialPickupSequenceTick + 1;
    value2 = g_ActiveTutorialPickupId;
    if (g_TutorialPickupFinalPoseDurationTicks < g_TutorialPickupSequenceTick) {
      g_PlayerActionState = 0x39;
      g_PlayerCurrentCollisionMode =
           CPlayerHero::ApplyPlacementDescriptorToEntitySceneObject
                     (g_PlayerEntitySceneObject,
                      (&g_TutorialPickupFinalPlacementTable)[g_ActiveTutorialPickupId * 0xc]);
      CPlayerHero::PlayAnimation
                (*(undefined4 *)
                  (&g_TutorialPickupFinalAnimationIdTable + g_ActiveTutorialPickupId * 0x30));
      value2 = g_ActiveTutorialPickupId;
      value = g_ActiveTutorialPickupId * 0x30;
      value3 = *(ushort *)(&g_TutorialPickupCameraTargetX + value);
      *(ushort *)(&g_TutorialPickupCameraTargetX + value) = ~value3 + 1;
      g_TutorialPickupCameraMoveXStep = (int)(short)(~value3 + 1);
      value3 = *(ushort *)(&g_TutorialPickupCameraTargetY + value);
      *(ushort *)(&g_TutorialPickupCameraTargetY + value) = ~value3 + 1;
      g_TutorialPickupCameraMoveYStep = (int)(short)(~value3 + 1);
      value3 = *(ushort *)(&g_TutorialPickupCameraTargetZ + value);
      *(ushort *)(&g_TutorialPickupCameraTargetZ + value) = ~value3 + 1;
      g_TutorialPickupCameraMoveZStep = (int)(short)(~value3 + 1);
      g_TutorialPickupCameraMoveXTicksRemaining =
           *(undefined4 *)(&g_TutorialPickupFinalPoseScript + value);
      g_TutorialPickupCameraMoveYTicksRemaining =
           *(undefined4 *)(&g_TutorialPickupReactionScript + value);
      g_TutorialPickupCameraMoveZTicksRemaining =
           *(undefined4 *)(&g_TutorialPickupReturnIdleScript + value);
    }
    if (g_TutorialPickupSequenceTick == g_TutorialPickupVoiceCueTick) {
      PlayAudioById(*(undefined4 *)(&g_TutorialPickupApproachScript + value2 * 0x30),(int *)0,(undefined4 *)0);
    }
    *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0;
    *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
    break;
  default:
    *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0;
    *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
  }
  CPlayerHero::UpdateMovementAndCollision(1);
LAB_00490d30:
  resultFlag = CPlayerHero::TrySnapToNearbyGround();
  value4 = g_PlayerActionState;
  if (resultFlag == '\0') {
    g_PlayerActionState = 7;
    g_PreviousPlayerActionState = value4;
    (*(code *)g_YoungEnterTarzanFallingHandlerPtr)();
    return;
  }
  value2 = CPlayerHero::AdvanceAnimationScript();
  if (value2 == 6) {
    *(byte *)(g_PlayerEntitySceneObject + 0x75) = ~*(byte *)(g_PlayerEntitySceneObject + 0x75);
    *(ushort *)(g_PlayerEntitySceneObject + 0xa2) =
         *(ushort *)(g_PlayerEntitySceneObject + 0xa2) ^ 0x800;
    _g_PlayerMoveTiltAngle = *(undefined2 *)(g_PlayerEntitySceneObject + 0xa0);
    g_PlayerMoveHeadingAngle = *(undefined2 *)(g_PlayerEntitySceneObject + 0xa2);
  }
  else if (value2 == 8) {
    CPlayerHero::PlayAnimation(0x94);
    return;
  }
  return;
}

