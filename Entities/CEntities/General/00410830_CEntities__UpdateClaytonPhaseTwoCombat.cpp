#include "tarzan_ghidra_types.hpp"

// Address: 0x00410830
// Label: CEntities::UpdateClaytonPhaseTwoCombat
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Switch with 1 destination removed at 0x00410b82 : 53 cases all go to same destination */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CEntities::UpdateClaytonPhaseTwoCombat(int entry,int sceneObject)

{
  int *intCursor;
  int value;
  char resultFlag;
  undefined2 value7;
  int value2;
  int value3;
  uint value8;
  int value4;
  int value5;
  undefined4 value6;
  undefined4 localState3;
  undefined4 localState2;
  undefined4 localState;
  
  CEntities::FindEntityAttachmentByFlags(entry,0x800);
  value7 = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
  value3 = *(int *)(sceneObject + 0x18);
  value5 = *(int *)(g_PlayerEntitySceneObjectData + 0xc);
  intCursor = (int *)(sceneObject + 0x14);
  value4 = *(int *)(g_PlayerEntitySceneObjectData + 8) - *intCursor;
  switch(value7) {
  case 0:
    break;
  default:
    CEntities::ChooseClaytonPhaseTwoAttack(entry);
    CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
    break;
  case 0xb:
    GetSceneAttachmentWorldPositionByMask(sceneObject,1,&localState3);
    value3 = CEntities::SpawnEntityByTypeAtPosition(localState3,localState2,localState,0x189,0x11);
    if (value3 == 0) {
      CEntities::ReleaseEntityToFreeList((byte *)entry);
      return;
    }
    value5 = *(int *)(value3 + 0x38);
    *(undefined4 *)(value3 + 0x4c) = 0;
    *(undefined2 *)(value5 + 0xa6) = 0;
    *(undefined2 *)(value5 + 0xa0) = 0;
    *(undefined2 *)(value5 + 0xa2) = 0x400;
    *(undefined2 *)(value5 + 0xa4) = 0x400;
    *(undefined4 *)(*(int *)(value3 + 0x38) + 0x110) = *(undefined4 *)(sceneObject + 0x110);
    *(undefined4 *)(*(int *)(value3 + 0x38) + 0x10c) = *(undefined4 *)(sceneObject + 0x10c);
    value5 = *(int *)(value3 + 0x38);
    *(undefined4 *)(value5 + 0x10c) = *(undefined4 *)(sceneObject + 0x10c);
    *(undefined4 *)(value5 + 0x110) = *(undefined4 *)(sceneObject + 0x110);
    *(undefined4 *)(*(int *)(value3 + 0x38) + 0x114) = *(undefined4 *)(sceneObject + 0x114);
    *(undefined4 *)(*(int *)(value3 + 0x38) + 0x108) = *(undefined4 *)(sceneObject + 0x108);
    ComputeEntitySceneObjectCollisionMoveDelta(0x17c,0,*(undefined4 *)(value3 + 0x38));
    break;
  case 0x10:
    g_ClaytonAttackDamageWindowActive = 1;
    break;
  case 0x11:
    g_ClaytonAttackDamageWindowActive = 0;
    break;
  case 0x14:
    GetSceneAttachmentWorldPositionByMask(sceneObject,1,&localState3);
    value3 = CEntities::SpawnEntityByTypeAtPosition(localState3,localState2,localState,0x189,0x11);
    if (value3 == 0) {
      CEntities::ReleaseEntityToFreeList((byte *)entry);
      return;
    }
    value5 = *(int *)(value3 + 0x38);
    *(undefined4 *)(value3 + 0x4c) = 1;
    *(undefined2 *)(value5 + 0xa6) = 1;
    *(undefined2 *)(value5 + 0xa0) = 0;
    *(undefined2 *)(value5 + 0xa2) = 0x400;
    *(undefined2 *)(value5 + 0xa4) = 0x400;
    *(undefined4 *)(*(int *)(value3 + 0x38) + 0x110) = *(undefined4 *)(sceneObject + 0x110);
    *(undefined4 *)(*(int *)(value3 + 0x38) + 0x10c) = *(undefined4 *)(sceneObject + 0x10c);
    value5 = *(int *)(value3 + 0x38);
    *(undefined4 *)(value5 + 0x10c) = *(undefined4 *)(sceneObject + 0x10c);
    *(undefined4 *)(value5 + 0x110) = *(undefined4 *)(sceneObject + 0x110);
    *(undefined4 *)(*(int *)(value3 + 0x38) + 0x114) = *(undefined4 *)(sceneObject + 0x114);
    *(undefined4 *)(*(int *)(value3 + 0x38) + 0x108) = *(undefined4 *)(sceneObject + 0x108);
    ComputeEntitySceneObjectCollisionMoveDelta(0x17c,0,*(undefined4 *)(value3 + 0x38));
    break;
  case 0x15:
    value2 = CEntities::SpawnEntityByTypeAtPosition
                      (*intCursor,value3,*(undefined4 *)(sceneObject + 0x1c),0x2b,0x11);
    if (value2 != 0) {
      *(undefined4 *)(*(int *)(value2 + 0x38) + 0x110) = *(undefined4 *)(sceneObject + 0x110);
      *(undefined4 *)(*(int *)(value2 + 0x38) + 0x10c) = *(undefined4 *)(sceneObject + 0x10c);
      value = *(int *)(value2 + 0x38);
      *(undefined4 *)(value + 0x10c) = *(undefined4 *)(sceneObject + 0x10c);
      *(undefined4 *)(value + 0x110) = *(undefined4 *)(sceneObject + 0x110);
      *(undefined4 *)(*(int *)(value2 + 0x38) + 0x114) = *(undefined4 *)(sceneObject + 0x114);
      *(undefined4 *)(*(int *)(value2 + 0x38) + 0x108) = *(undefined4 *)(sceneObject + 0x108);
      ComputeEntitySceneObjectCollisionMoveDelta(0x17c,0,*(undefined4 *)(value2 + 0x38));
      value = *(int *)(value2 + 0x38);
      *(int *)(value + 0x14) = *(int *)(value + 0x14) + *(int *)(value + 0x54);
      value = *(int *)(value2 + 0x38);
      *(int *)(value + 0x18) = *(int *)(value + 0x18) + *(int *)(value + 0x58);
      value = *(int *)(value2 + 0x38);
      *(int *)(value + 0x1c) = *(int *)(value + 0x1c) + *(int *)(value + 0x5c);
      *(int *)(*(int *)(value2 + 0x38) + 0x18) = *(int *)(*(int *)(value2 + 0x38) + 0x18) + -0x140;
      *(int *)(*(int *)(value2 + 0x38) + 0x14) = *(int *)(*(int *)(value2 + 0x38) + 0x14) + 0xb4;
      if ((((g_PlayerDamageInvulnerabilityTicks == 0) && (g_PlayerActionState != 0x31)) &&
          (-200 < value5 - value3)) && (g_PlayerBlockDamageGuardActive == 0)) {
        QueuePlayerDamageEvent(entry,8);
      }
    }
  }
  switch(*(undefined2 *)(entry + 0x48)) {
  case 0x14:
    CEntities::CheckEntityHitByPlayerAttackOrThrowable(entry);
    if ((*(byte *)(*(int *)(sceneObject + 0x114) + 0x14) & 4) == 0) {
      if (g_ClaytonBattleCameraState == 0) {
        CEntities::MoveEntitySceneObjectXZAndSnapSurfaceFacingAngles
                  (sceneObject,(value4 * 0x28) / 0xd00 + 0x32);
        CEntities::CheckEntitySceneObjectCollisionDelta(sceneObject);
        break;
      }
      CEntities::MoveEntitySceneObjectXZAndSnapSurfaceFacingAngles(sceneObject,0x3f);
    }
    else {
      value3 = *(int *)(sceneObject + 0x10c);
      value2 = *(int *)(*(int *)(g_CollisionSurfaceTable + 4 + *(int *)(sceneObject + 0x110) * 4) + 8 +
                       *(int *)(sceneObject + 0x110) * 4 + g_CollisionSurfaceTable) / 2;
      value5 = value2 - value3;
      CEntities::MoveEntitySceneObjectXZAndSnapSurfaceFacingAngles(sceneObject,(value5 * 0x5a) / value2);
      if (value2 < value3) {
        CEntities::MoveEntitySceneObjectXZAndSnapSurfaceFacingAngles(sceneObject,value5);
        CEntities::CheckEntitySceneObjectCollisionDelta(sceneObject);
        break;
      }
    }
    CEntities::CheckEntitySceneObjectCollisionDelta(sceneObject);
    break;
  case 0x22:
    if (g_ClaytonAttackDamageWindowActive != 0) {
      CEntities::MoveEntitySceneObjectXZAndSnapSurfaceFacingAngles(sceneObject,0xffffffbc);
    }
  default:
    CEntities::CheckEntityHitByPlayerAttackOrThrowable(entry);
    break;
  case 0x30:
  case 0x31:
    if (((g_ClaytonAttackDamageWindowActive != 0) && (g_PlayerDamageInvulnerabilityTicks == 0)) &&
       (value4 < 0x227)) {
      QueuePlayerDamageEvent(entry,0x100a);
      g_ClaytonAttackDamageWindowActive = 0;
    }
    break;
  case 0x33:
    if ((_g_PlayerSequenceFlags & 0x8000) == 0) {
      resultFlag = CEntities::CheckEntityHitByPlayerAttackOrThrowable(entry);
      if (resultFlag != '\0') {
        DetachEntitySoundHandle(sceneObject + 0x104);
        InitAudioLine_stub();
        if (*(int *)(sceneObject + 0x10c) < 0x15f) {
          *(undefined2 *)(entry + 0x48) = 0x34;
          CEntities::SelectEntityAnimationAttachmentState(entry,0x15);
          *(undefined4 *)(entry + 0x4c) = 0xffffffb0;
          g_ClaytonFallExitCountdown = 0x28;
        }
        else {
          value8 = NextRandomValue();
          if ((value8 & 3) == 0) {
            value6 = 0x3f0;
          }
          else if ((value8 & 2) == 0) {
            value6 = 0x3f1;
          }
          else {
            value6 = 0x3f2;
          }
          PlayAudioById(value6,(int *)0,(undefined4 *)intCursor);
          *(undefined2 *)(entry + 0x48) = 0x22;
          CEntities::SelectEntityAnimationAttachmentState(entry,0x14);
          _g_ClaytonPendingVoiceLineState = 7;
          _g_ClaytonVoiceLineCooldown = 0x1e;
        }
      }
    }
    else if (*(short *)(sceneObject + 0xc) == 0x114) {
      PlayAudioById(0x3ea,(int *)sceneObject + 0x104,(undefined4 *)intCursor);
    }
    break;
  case 0x34:
    *intCursor = *intCursor + -0x18;
    value3 = *(int *)(entry + 0x4c) + 6;
    *(int *)(entry + 0x4c) = value3;
    *(int *)(sceneObject + 0x18) = *(int *)(sceneObject + 0x18) + value3;
    g_ClaytonFallExitCountdown = g_ClaytonFallExitCountdown + -1;
    if (g_ClaytonFallExitCountdown < 1) {
      *( undefined2 *)((int)&g_LevelTransitionRequestFlags + 0) = 0x8001;
    }
  }
  if (value4 < 0xfa) {
    CEntities::MoveEntitySceneObjectXZAndSnapSurfaceFacingAngles
              (g_PlayerEntitySceneObject,0xfa - value4);
  }
  return;
}

