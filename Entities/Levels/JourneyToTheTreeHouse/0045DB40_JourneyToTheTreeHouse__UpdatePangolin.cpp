#include "tarzan_ghidra_types.hpp"

// Address: 0x0045DB40
// Label: JourneyToTheTreeHouse::UpdatePangolin
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void JourneyToTheTreeHouse::UpdatePangolin(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  char resultFlag;
  short shortValue;
  int value3;
  int value4;
  undefined4 value5;
  
  value = entity->sceneObjects;
  if (*(short *)(entry + 0x3e) < 0) {
    CEntities::ProcessEntityDeathAndRelease(entry,1);
    return;
  }
  resultFlag = CEntities::CheckEntityHitByPlayerAttackOrThrowable(entry);
  if (resultFlag != '\0') {
    PlayAudioById(0x136,(int *)0,(undefined4 *)&((EntitySceneObject *)value)->x);
    value3 = *(int *)(entry + 0x4c) + -1;
    *(int *)(entry + 0x4c) = value3;
    if (value3 == 0) {
      CEntities::ProcessEntityDeathAndRelease(entry,1);
      return;
    }
  }
  if (((*(short *)(entry + 0x48) != 0) &&
      (value3 = CEntities::ComputeEntityDistanceSqToPlayer3D(entry), value3 < 90000)) &&
     (QueuePlayerDamageEvent(entry,8), *(short *)(entry + 0x48) == 0x15)) {
    *(undefined2 *)(entry + 0x48) = 0;
    *(undefined4 *)(entry + 0x50) = 0x1e;
  }
  switch(*(undefined2 *)(entry + 0x48)) {
  case 0:
    value3 = ((EntitySceneObject *)value)->surfaceIndex;
    value2 = *(int *)(*(int *)(g_CollisionSurfaceTable + 4 + ((EntitySceneObject *)value)->surfacePathIndex * 4) + 8 +
                     ((EntitySceneObject *)value)->surfacePathIndex * 4 + g_CollisionSurfaceTable);
    value4 = *(int *)(entry + 0x50) + -1;
    *(int *)(entry + 0x50) = value4;
    if (value4 == 0) {
      value4 = CEntities::ComputeEntityDistanceSqToPlayer3D(entry);
      if (value4 < 0x15ff5) {
        if (*(char *)(value + 0x75) == '\0') {
          if (value3 < 0x321) goto LAB_0045dcaa;
          *(undefined2 *)(entry + 0x48) = 0x29;
          CEntities::SelectEntityAnimationAttachmentState(entry,5);
          PlayAudioById(0x155,(int *)0,(undefined4 *)&((EntitySceneObject *)value)->x);
        }
        else if (value2 - value3 < 0x321) {
LAB_0045dcaa:
          *(undefined4 *)(entry + 0x50) = 0x1e;
        }
        else {
          *(undefined2 *)(entry + 0x48) = 0x29;
          CEntities::SelectEntityAnimationAttachmentState(entry,5);
          PlayAudioById(0x155,(int *)0,(undefined4 *)&((EntitySceneObject *)value)->x);
        }
      }
      else {
        *(undefined2 *)(entry + 0x48) = 0x15;
      }
    }
    break;
  case 0x15:
  case 0x2c:
  case 0x2d:
    CEntities::MoveSceneObjectForwardAndAlignToSurface(entry,value,0xc);
    break;
  case 0x2e:
    CEntities::MoveSceneObjectForwardAndAlignToSurface(entry,value,0x32);
  }
  if ((*(short *)(entry + 0x48) != 0) &&
     (shortValue = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry), shortValue != 0)) {
    switch(*(undefined2 *)(entry + 0x48)) {
    case 0x15:
      if (199 < *(int *)(*(int *)(g_CollisionSurfaceTable + 4 + ((EntitySceneObject *)value)->surfacePathIndex * 4) + 8 +
                         ((EntitySceneObject *)value)->surfacePathIndex * 4 + g_CollisionSurfaceTable) -
                ((EntitySceneObject *)value)->surfaceIndex) break;
    case 0x2d:
      *(undefined2 *)(entry + 0x48) = 0x29;
      CEntities::SelectEntityAnimationAttachmentState(entry,5);
      CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
      break;
    case 0x29:
      ((EntitySceneObject *)value)->yaw = ((EntitySceneObject *)value)->yaw ^ 0x800;
      *(byte *)(value + 0x75) = ~*(byte *)(value + 0x75);
      CEntities::MoveSceneObjectForwardAndAlignToSurface(entry,value,0xc);
      if (*(char *)(value + 0x75) == '\0') {
        *(undefined2 *)(entry + 0x48) = 0x15;
        value5 = 1;
      }
      else {
        *(undefined2 *)(entry + 0x48) = 0x2c;
        value5 = 2;
      }
      CEntities::SelectEntityAnimationAttachmentState(entry,value5);
      CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
      break;
    case 0x2c:
      PlayAudioById(0x13c,(int *)0,(undefined4 *)&((EntitySceneObject *)value)->x);
      *(undefined2 *)(entry + 0x48) = 0x2e;
      CEntities::SelectEntityAnimationAttachmentState(entry,3);
      CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
      break;
    case 0x2e:
      if (((EntitySceneObject *)value)->surfaceIndex < 200) {
        PlayAudioById(0x13e,(int *)0,(undefined4 *)&((EntitySceneObject *)value)->x);
        *(undefined2 *)(entry + 0x48) = 0x2d;
        CEntities::SelectEntityAnimationAttachmentState(entry,4);
        CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
      }
    }
  }
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

