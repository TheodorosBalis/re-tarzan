#include "tarzan_ghidra_types.hpp"

// Address: 0x00410060
// Label: CEntities::UpdateClaytonMainCombat
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CEntities::UpdateClaytonMainCombat(int entry,int sceneObject)

{
  int *intCursor;
  short shortValue;
  char resultFlag;
  undefined2 value6;
  int value;
  int value2;
  uint value7;
  int value3;
  int value4;
  undefined4 value5;
  
  value = CEntities::GetPlayerDistanceAheadOfClayton(sceneObject);
  if (*(short *)(entry + 0x48) == 0x16) {
    if ((value < 0xd64) && (0xc9c < value)) {
      return;
    }
    *(undefined2 *)(entry + 0x48) = 0x14;
  }
  value6 = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
  if (((g_GameplayRuntimeFlags & 0x80000000) != 0) && ((g_GameplayRuntimeFlags & 0x8000) != 0)) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
    return;
  }
  switch(value6) {
  case 0:
    break;
  default:
    if (((_g_PlayerSequenceFlags & 0x8000) != 0) ||
       ((*(uint *)(g_PlayerContactSurfaceThisFrame + 0x14) & 0x800) != 0)) {
      *(undefined2 *)(entry + 0x48) = 0x33;
      CEntities::SelectEntityAnimationAttachmentState(entry,0x11);
      CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
      return;
    }
    if (value < 300) {
      *(undefined2 *)(entry + 0x48) = 0x11;
      CEntities::SelectEntityAnimationAttachmentState(entry,7);
      CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
    }
    else {
      if ((*(byte *)(*(int *)(sceneObject + 0x114) + 0x14) & 4) != 0) {
        *(undefined2 *)(entry + 0x48) = 0x2d;
        PlayAudioById(0x801f,(int *)0,(undefined4 *)0);
        CEntities::SelectEntityAnimationAttachmentState(entry,4);
        CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
        g_ClaytonBattleBehaviorState = 6;
        return;
      }
      if ((*(short *)(entry + 0x48) == 0x22) && (0x578 < value)) {
        *(undefined2 *)(entry + 0x48) = 0x25;
        value5 = 9;
      }
      else {
        *(undefined2 *)(entry + 0x48) = 0x14;
        value5 = 2;
      }
      CEntities::SelectEntityAnimationAttachmentState(entry,value5);
      CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
    }
    break;
  case 0x10:
    g_ClaytonAttackDamageWindowActive = 1;
    break;
  case 0x11:
    g_ClaytonAttackDamageWindowActive = 0;
    break;
  case 0x15:
    value2 = CEntities::SpawnEntityByTypeAtPosition
                      (*(undefined4 *)(sceneObject + 0x14),*(undefined4 *)(sceneObject + 0x18),
                       *(undefined4 *)(sceneObject + 0x1c),0x2b,0x11);
    if (value2 != 0) {
      *(undefined4 *)(*(int *)(value2 + 0x38) + 0x110) = *(undefined4 *)(sceneObject + 0x110);
      *(undefined4 *)(*(int *)(value2 + 0x38) + 0x10c) = *(undefined4 *)(sceneObject + 0x10c);
      value3 = *(int *)(value2 + 0x38);
      *(undefined4 *)(value3 + 0x10c) = *(undefined4 *)(sceneObject + 0x10c);
      *(undefined4 *)(value3 + 0x110) = *(undefined4 *)(sceneObject + 0x110);
      *(undefined4 *)(*(int *)(value2 + 0x38) + 0x114) = *(undefined4 *)(sceneObject + 0x114);
      *(undefined4 *)(*(int *)(value2 + 0x38) + 0x108) = *(undefined4 *)(sceneObject + 0x108);
      ComputeEntitySceneObjectCollisionMoveDelta(0x17c,0,*(undefined4 *)(value2 + 0x38));
      value3 = *(int *)(value2 + 0x38);
      *(int *)(value3 + 0x14) = *(int *)(value3 + 0x14) + *(int *)(value3 + 0x54);
      value3 = *(int *)(value2 + 0x38);
      *(int *)(value3 + 0x18) = *(int *)(value3 + 0x18) + *(int *)(value3 + 0x58);
      value3 = *(int *)(value2 + 0x38);
      *(int *)(value3 + 0x1c) = *(int *)(value3 + 0x1c) + *(int *)(value3 + 0x5c);
      *(int *)(*(int *)(value2 + 0x38) + 0x18) = *(int *)(*(int *)(value2 + 0x38) + 0x18) + -0x140;
      if ((g_PlayerDamageInvulnerabilityTicks == 0) && (value < 3000)) {
        QueuePlayerDamageEvent(entry,8);
        _g_ClaytonPendingVoiceLineState = 4;
        InitAudioLine_stub();
        _g_ClaytonVoiceLineCooldown = 0x14;
      }
    }
  }
  resultFlag = CEntities::CheckEntityHitByPlayerAttackOrThrowable(entry);
  if (resultFlag != '\0') {
    switch(*(undefined2 *)(entry + 0x48)) {
    case 0x11:
    case 0x1d:
    case 0x22:
    case 0x25:
    case 0x33:
      break;
    default:
      *(undefined2 *)(entry + 0x48) = 0x22;
      CEntities::SelectEntityAnimationAttachmentState(entry,8);
      DetachEntitySoundHandle(sceneObject + 0x104);
      InitAudioLine_stub();
      value7 = NextRandomValue();
      if ((value7 & 3) == 0) {
        value5 = 0x3ed;
      }
      else if ((value7 & 2) == 0) {
        value5 = 0x3ee;
      }
      else {
        value5 = 0x3ef;
      }
      PlayAudioById(value5,(int *)0,(undefined4 *)sceneObject + 0x14);
    }
  }
  shortValue = *(short *)(entry + 0x48);
  if (shortValue == 0x11) {
    if (((g_ClaytonAttackDamageWindowActive != 0) &&
        (value7 = _g_PlayerSequenceFlags & 0x8000,
        _g_PlayerSequenceFlags = _g_PlayerSequenceFlags & 0xffff8000, value7 == 0)) &&
       ((*(uint *)(g_PlayerContactSurfaceThisFrame + 0x14) & 0x800) == 0)) {
      CPlayerHero::StartAdultTarzanScriptedDeathKnockback(1);
      intCursor = (int *)(sceneObject + 0x14);
      PlayAudioById(0x5b,(int *)0,(undefined4 *)intCursor);
      PlayAudioById(0x3f5,(int *)0,(undefined4 *)intCursor);
      value = *(int *)(g_PlayerEntitySceneObjectData + 8) - *intCursor;
      *(int *)(g_PlayerMotionState + 0x10) =
           *(int *)(g_PlayerMotionState + 0x10) + ((int)(value + (value >> 0x1f & 3U)) >> 2);
      *(undefined4 *)(g_PlayerMotionState + 0x20) = 0x30;
      value = *(int *)(g_PlayerEntitySceneObjectData + 0x10) - *(int *)(sceneObject + 0x1c);
      *(int *)(g_PlayerMotionState + 0x30) =
           *(int *)(g_PlayerMotionState + 0x30) + ((int)(value + (value >> 0x1f & 3U)) >> 2);
      QueuePlayerDamageEvent(0,0x200);
      g_PlayerSequenceDelayTicks = 100;
      _g_ClaytonPendingVoiceLineState = 5;
      g_ClaytonBattleCameraState = 1;
      g_ClaytonBattleBehaviorState = 2;
      return;
    }
    CEntities::MoveEntitySceneObjectXZAndSnapSurfaceFacingAngles(sceneObject,value + -200);
    CEntities::CheckEntitySceneObjectCollisionDelta(sceneObject);
  }
  else if (shortValue == 0x14) {
    if ((*(byte *)(*(int *)(sceneObject + 0x114) + 0x14) & 4) == 0) {
      if (g_ClaytonBattleCameraState == 0) {
        CEntities::MoveEntitySceneObjectXZAndSnapSurfaceFacingAngles
                  (sceneObject,(value * 0x28) / 0xd00 + 0x32);
        CEntities::CheckEntitySceneObjectCollisionDelta(sceneObject);
      }
      else {
        CEntities::MoveEntitySceneObjectXZAndSnapSurfaceFacingAngles(sceneObject,0x3f);
        CEntities::CheckEntitySceneObjectCollisionDelta(sceneObject);
      }
    }
    else {
      value2 = *(int *)(sceneObject + 0x10c);
      value4 = *(int *)(*(int *)(g_CollisionSurfaceTable + 4 + *(int *)(sceneObject + 0x110) * 4) + 8 +
                       *(int *)(sceneObject + 0x110) * 4 + g_CollisionSurfaceTable) / 2;
      value3 = value4 - value2;
      CEntities::MoveEntitySceneObjectXZAndSnapSurfaceFacingAngles(sceneObject,(value3 * 0x5a) / value4);
      if (value4 < value2) {
        CEntities::MoveEntitySceneObjectXZAndSnapSurfaceFacingAngles(sceneObject,value3);
      }
      CEntities::CheckEntitySceneObjectCollisionDelta(sceneObject);
    }
  }
  else if (shortValue == 0x1d) {
    CEntities::MoveEntitySceneObjectXZAndSnapSurfaceFacingAngles(sceneObject,0x3c);
    *(int *)(sceneObject + 0x18) = *(int *)(sceneObject + 0x18) + -0xf;
  }
  if ((*(uint *)(g_PlayerContactSurfaceThisFrame + 0x14) & 0x800) == 0) {
    if (*(short *)(entry + 0x48) == 0x25) {
      if (0xdc8 < value) {
        CEntities::MoveEntitySceneObjectXZAndSnapSurfaceFacingAngles(sceneObject,value + -0xdc8);
        *(int *)(sceneObject + 0x18) = *(int *)(sceneObject + 0x18) + *(int *)(sceneObject + 0x58);
      }
    }
    else if (0xd00 < value) {
      CEntities::MoveEntitySceneObjectXZAndSnapSurfaceFacingAngles(sceneObject,value + -0xd00);
      *(int *)(sceneObject + 0x18) = *(int *)(sceneObject + 0x18) + *(int *)(sceneObject + 0x58);
    }
    if (value < 200) {
      CEntities::MoveEntitySceneObjectXZAndSnapSurfaceFacingAngles
                (g_PlayerEntitySceneObject,200 - value);
      resultFlag = CPlayerHero::TrySnapToNearbyGround();
      value6 = g_PlayerActionState;
      if (resultFlag == '\0') {
        g_PlayerActionState = 7;
        g_PreviousPlayerActionState = value6;
        (*(code *)g_AdultTarzanEnterFallOrKnockbackHandlerPtr)();
      }
    }
  }
  if (((*(uint *)(*(int *)(sceneObject + 0x114) + 0x14) & 0xf) == 1) &&
     (*(short *)(entry + 0x48) != 0x1d)) {
    *(undefined2 *)(entry + 0x48) = 0x1d;
    CEntities::SelectEntityAnimationAttachmentState(entry,10);
    PlayAudioById(0x3eb,(int *)0,(undefined4 *)0);
  }
  if ((*(byte *)(g_PlayerContactSurfaceThisFrame + 0x14) & 2) != 0) {
    _g_PlayerSequenceFlags = _g_PlayerSequenceFlags | 0x2000;
    g_ClaytonBattleCameraState = 9;
  }
  *(undefined2 *)(sceneObject + 0xa0) = 0;
  return;
}

