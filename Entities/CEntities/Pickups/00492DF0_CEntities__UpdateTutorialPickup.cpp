#include "tarzan_ghidra_types.hpp"

// Address: 0x00492DF0
// Label: CEntities::UpdateTutorialPickup
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::UpdateTutorialPickup(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  undefined4 value4;
  int value2;
  char resultFlag;
  int value3;
  
  value = entity->sceneObjects;
  if (value != 0) {
    if (g_PlayerPickupInteractionFlags == 0) {
      ((EntitySceneObject *)value)->yaw = ((EntitySceneObject *)value)->yaw + 0x38U & 0xfff;
      resultFlag = CEntities::IsPlayerWithinPickupTriggerBounds
                        (value,0xc0,(int)*(short *)(g_PlayerEntitySceneObject + 0x142),0);
      if ((resultFlag != '\0') && (resultFlag = CEntities::CanStartPickupCollection(entry), resultFlag != '\0'))
      {
        g_PlayerDamageInvulnerabilityTicks = 0x3c;
        g_TutorialPickupSkipApproachFlag = 0;
        g_PlayerPickupInteractionFlags = 0x8000;
        g_ActiveTutorialPickupEntity = entry;
        g_ActiveTutorialPickupId = *(int *)(entry + 0x4c);
        *(ushort *)(value + 0xe) = *(ushort *)(value + 0xe) ^ 0x8000;
        LoadEncodedResourceId(0x23);
        CEntities::SpawnEntityByTypeAtPosition
                  (((EntitySceneObject *)value)->x,((EntitySceneObject *)value)->y,
                   ((EntitySceneObject *)value)->z,0x14,0x11);
        PlayAudioById(0x22,(int *)0,(undefined4 *)g_PlayerEntitySceneObject + 0x14);
      }
    }
    else if (g_ActiveTutorialPickupId != *(int *)(entry + 0x4c)) {
      resultFlag = IsEntityOutsideOuterActivationBounds(entry);
      if (resultFlag == '\0') {
        return;
      }
      CEntities::ReleaseEntityToFreeList((byte *)entry);
      return;
    }
    switch(g_TutorialPickupSequencePhase) {
    case 1:
      g_TutorialPickupSequencePhase = 2;
      *(undefined4 *)(value + 0xa8) = 0x1000;
      *(undefined4 *)(value + 0xac) = 0x1000;
      *(undefined4 *)(value + 0xb0) = 0x1000;
      ((EntitySceneObject *)value)->x = *(undefined4 *)(g_PlayerEntitySceneObjectData + 4);
      ((EntitySceneObject *)value)->y = *(undefined4 *)(g_PlayerEntitySceneObjectData + 6);
      ((EntitySceneObject *)value)->z = *(undefined4 *)(g_PlayerEntitySceneObjectData + 8);
      *(undefined2 *)(value + 0xe) = g_PlayerEntitySceneObjectData[1];
      *(undefined4 *)(value + 0x6c) = *(undefined4 *)(g_PlayerEntitySceneObject + 0x6c);
      ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x1a0;
      *(undefined2 *)(value + 0xc) = *g_PlayerEntitySceneObjectData;
      *(undefined4 *)(value + 0x70) = *(undefined4 *)(g_PlayerEntitySceneObject + 0x70);
      *(undefined2 *)(value + 0xa0) = *(undefined2 *)(g_PlayerEntitySceneObject + 0xa0);
      ((EntitySceneObject *)value)->yaw = *(undefined2 *)(g_PlayerEntitySceneObject + 0xa2);
      ((EntitySceneObject *)value)->pitch = *(undefined2 *)(g_PlayerEntitySceneObject + 0xa4);
      ((EntitySceneObject *)value)->roll = *(undefined2 *)(g_PlayerEntitySceneObject + 0xa6);
      *(undefined1 *)(value + 0x75) = *(undefined1 *)(g_PlayerEntitySceneObject + 0x75);
      value3 = g_PlayerEntitySceneObject;
      ((EntitySceneObject *)value)->surfaceIndex = *(undefined4 *)(g_PlayerEntitySceneObject + 0x10c);
      ((EntitySceneObject *)value)->surfacePathIndex = *(undefined4 *)(value3 + 0x110);
      ((EntitySceneObject *)value)->surfacePathIndex = *(undefined4 *)(g_PlayerEntitySceneObject + 0x110);
      ((EntitySceneObject *)value)->surfaceIndex = *(undefined4 *)(g_PlayerEntitySceneObject + 0x10c);
      ((EntitySceneObject *)value)->surface = *(undefined4 *)(g_PlayerEntitySceneObject + 0x114);
      *(undefined2 *)(value + 0x142) = *(undefined2 *)(g_PlayerEntitySceneObject + 0x142);
      value3 = g_PlayerEntitySceneObject;
      ((EntitySceneObject *)value)->x = *(undefined4 *)(g_PlayerEntitySceneObject + 0x14);
      ((EntitySceneObject *)value)->y = *(undefined4 *)(value3 + 0x18);
      ((EntitySceneObject *)value)->z = *(undefined4 *)(value3 + 0x1c);
      value3 = g_PlayerEntitySceneObject;
      *(undefined4 *)(value + 0x3c) = *(undefined4 *)(g_PlayerEntitySceneObject + 0x3c);
      *(undefined4 *)(value + 0x40) = *(undefined4 *)(value3 + 0x40);
      *(undefined4 *)(value + 0x44) = *(undefined4 *)(value3 + 0x44);
      value3 = g_PlayerEntitySceneObject;
      *(undefined4 *)(value + 0x48) = *(undefined4 *)(g_PlayerEntitySceneObject + 0x48);
      *(undefined4 *)(value + 0x4c) = *(undefined4 *)(value3 + 0x4c);
      *(undefined4 *)(value + 0x50) = *(undefined4 *)(value3 + 0x50);
      value3 = g_PlayerEntitySceneObject;
      *(undefined4 *)(value + 0x54) = *(undefined4 *)(g_PlayerEntitySceneObject + 0x54);
      *(undefined4 *)(value + 0x58) = *(undefined4 *)(value3 + 0x58);
      *(undefined4 *)(value + 0x5c) = *(undefined4 *)(value3 + 0x5c);
      g_ActiveCameraAnchorEntry =
           CEntities::SpawnEntityByTypeAtPosition
                     (*(undefined4 *)(g_PlayerEntitySceneObjectData + 4),
                      *(undefined4 *)(g_PlayerEntitySceneObjectData + 6),
                      *(undefined4 *)(g_PlayerEntitySceneObjectData + 8),0x2d,0x11);
      value3 = *(int *)(g_ActiveCameraAnchorEntry + 0x38);
      if (value3 == 0) {
        g_ActiveCameraAnchorEntry = entry;
      }
      else {
        *(undefined4 *)(value3 + 0x14) = *(undefined4 *)(g_PlayerEntitySceneObjectData + 4);
        *(undefined4 *)(value3 + 0x18) = *(undefined4 *)(g_PlayerEntitySceneObjectData + 6);
        value4 = *(undefined4 *)(g_PlayerEntitySceneObjectData + 8);
        *(ushort *)(value3 + 0xe) = *(ushort *)(value3 + 0xe) & 0x7fff;
        *(undefined4 *)(value3 + 0x1c) = value4;
        *(int *)(value3 + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x1a0;
        *(undefined2 *)(value3 + 0xc) = *g_PlayerEntitySceneObjectData;
        *(undefined2 *)(value3 + 0xa0) = *(undefined2 *)(g_PlayerEntitySceneObject + 0xa0);
        *(undefined2 *)(value3 + 0xa2) = *(undefined2 *)(g_PlayerEntitySceneObject + 0xa2);
        *(undefined2 *)(value3 + 0xa4) = *(undefined2 *)(g_PlayerEntitySceneObject + 0xa4);
        *(undefined2 *)(value3 + 0xa6) = *(undefined2 *)(g_PlayerEntitySceneObject + 0xa6);
        value2 = g_PlayerEntitySceneObject;
        *(undefined4 *)(value3 + 0x10c) = *(undefined4 *)(g_PlayerEntitySceneObject + 0x10c);
        *(undefined4 *)(value3 + 0x110) = *(undefined4 *)(value2 + 0x110);
        *(undefined4 *)(value3 + 0x110) = *(undefined4 *)(g_PlayerEntitySceneObject + 0x110);
        *(undefined4 *)(value3 + 0x10c) = *(undefined4 *)(g_PlayerEntitySceneObject + 0x10c);
        *(undefined4 *)(value3 + 0x114) = *(undefined4 *)(g_PlayerEntitySceneObject + 0x114);
        *(undefined2 *)(value3 + 0x142) = *(undefined2 *)(g_PlayerEntitySceneObject + 0x142);
        value2 = g_PlayerEntitySceneObject;
        *(undefined4 *)(value3 + 0x14) = *(undefined4 *)(g_PlayerEntitySceneObject + 0x14);
        *(undefined4 *)(value3 + 0x18) = *(undefined4 *)(value2 + 0x18);
        *(undefined4 *)(value3 + 0x1c) = *(undefined4 *)(value2 + 0x1c);
        value2 = g_PlayerEntitySceneObject;
        *(undefined4 *)(value3 + 0x3c) = *(undefined4 *)(g_PlayerEntitySceneObject + 0x3c);
        *(undefined4 *)(value3 + 0x40) = *(undefined4 *)(value2 + 0x40);
        *(undefined4 *)(value3 + 0x44) = *(undefined4 *)(value2 + 0x44);
        value2 = g_PlayerEntitySceneObject;
        *(undefined4 *)(value3 + 0x48) = *(undefined4 *)(g_PlayerEntitySceneObject + 0x48);
        *(undefined4 *)(value3 + 0x4c) = *(undefined4 *)(value2 + 0x4c);
        *(undefined4 *)(value3 + 0x50) = *(undefined4 *)(value2 + 0x50);
        value2 = g_PlayerEntitySceneObject;
        *(undefined4 *)(value3 + 0x54) = *(undefined4 *)(g_PlayerEntitySceneObject + 0x54);
        *(undefined4 *)(value3 + 0x58) = *(undefined4 *)(value2 + 0x58);
        *(undefined4 *)(value3 + 0x5c) = *(undefined4 *)(value2 + 0x5c);
        value3 = g_ActiveTutorialPickupId * 0x30;
        g_TutorialPickupCameraMoveXStep = (int)*(short *)(&g_TutorialPickupCameraTargetX + value3);
        g_TutorialPickupCameraMoveYStep = (int)*(short *)(&g_TutorialPickupCameraTargetY + value3);
        g_TutorialPickupCameraMoveZStep = (int)*(short *)(&g_TutorialPickupCameraTargetZ + value3);
        g_TutorialPickupCameraMoveXTicksRemaining =
             *(undefined4 *)(&g_TutorialPickupFinalPoseScript + value3);
        g_TutorialPickupCameraMoveYTicksRemaining =
             *(undefined4 *)(&g_TutorialPickupReactionScript + value3);
        g_TutorialPickupCameraMoveZTicksRemaining =
             *(undefined4 *)(&g_TutorialPickupReturnIdleScript + value3);
      }
      g_TutorialPickupGroundShadowEntitySceneObject = CreateEntityEntitySceneObject((uint *)entry,2);
      if (g_TutorialPickupGroundShadowEntitySceneObject != 0) {
        *(int *)(g_TutorialPickupGroundShadowEntitySceneObject + 0x10) =
             g_WorldEntitySceneObjectArrayBase + 0x3a8;
        *(undefined2 *)(g_TutorialPickupGroundShadowEntitySceneObject + 0xc) = 0x2010;
        value2 = g_TutorialPickupGroundShadowEntitySceneObject;
        value3 = g_PlayerEntitySceneObject;
        *(undefined4 *)(g_TutorialPickupGroundShadowEntitySceneObject + 0x14) =
             *(undefined4 *)(g_PlayerEntitySceneObject + 0x14);
        *(undefined4 *)(value2 + 0x18) = *(undefined4 *)(value3 + 0x18);
        *(undefined4 *)(value2 + 0x1c) = *(undefined4 *)(value3 + 0x1c);
        *(ushort *)(g_TutorialPickupGroundShadowEntitySceneObject + 0xe) =
             *(ushort *)(g_TutorialPickupGroundShadowEntitySceneObject + 0xe) | 0x441;
        *(undefined4 *)(g_TutorialPickupGroundShadowEntitySceneObject + 0x30) = 0x400;
        *(undefined4 *)(g_TutorialPickupGroundShadowEntitySceneObject + 0x6c) = 0xffffffec;
        *(undefined4 *)(value + 0x6c) = 0xffffffe2;
        ((EntitySceneObject *)value)->roll = 1;
        *(undefined4 *)(g_TutorialPickupGroundShadowEntitySceneObject + 0x108) =
             *(undefined4 *)(g_PlayerEntitySceneObject + 0x108);
        *(undefined4 *)(g_TutorialPickupGroundShadowEntitySceneObject + 0x110) =
             *(undefined4 *)(g_PlayerEntitySceneObject + 0x110);
        *(undefined4 *)(g_TutorialPickupGroundShadowEntitySceneObject + 0x10c) =
             *(undefined4 *)(g_PlayerEntitySceneObject + 0x10c);
        *(ushort *)(g_PlayerGroundShadowProbeEntitySceneObject + 0xe) =
             *(ushort *)(g_PlayerGroundShadowProbeEntitySceneObject + 0xe) & 0x7fff;
      }
      TutorialPickupSoundCallbackNoOp
                (*(undefined4 *)(&g_TutorialPickupApproachScript + g_ActiveTutorialPickupId * 0x30))
      ;
      CEntities::SetEntitySceneObjectScriptAttachment
                (entry,&g_TutorialPickupTransformScriptAttachmentDesc);
    case 2:
    case 3:
      CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
      break;
    case 4:
      g_ActiveCameraAnchorEntry = g_EntityPoolBase;
      g_TutorialPickupSequencePhase = 5;
      g_ActiveTutorialPickupId = 0;
      g_PreviousPlayerActionState = g_PlayerActionState;
      g_PlayerActionState = 0x3e;
      (*(code *)g_YoungEnterTutorialPickupReturnIdleHandlerPtr)();
      UnloadEncodedResourceId(0x23);
      CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
      g_ActiveTutorialPickupEntity = 0;
      return;
    }
  }
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

