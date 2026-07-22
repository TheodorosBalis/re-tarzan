#include "tarzan_ghidra_types.hpp"

// Address: 0x00411490
// Label: ConflictWithClayton::UpdateActivatedAnimalChaser
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ConflictWithClayton::UpdateActivatedAnimalChaser(int entry)

{
  Entity *entity = (Entity *)entry;
  ushort *dataCursor;
  int value;
  char resultFlag;
  short shortValue;
  int value2;
  int value3;
  int value4;
  undefined4 value5;
  
  value = entity->sceneObjects;
  value2 = CEntities::GetClaytonDistanceAheadOfPlayer(value);
  value4 = *(int *)(g_PlayerEntitySceneObjectData + 0xc) - ((EntitySceneObject *)value)->y;
  if ((value4 < -0x680) && (0x1380 < value2)) goto LAB_00411657;
  resultFlag = CEntities::IsEntitySceneObjectWithinCameraYawWindow(value,800);
  if (resultFlag == '\0') {
    dataCursor = (ushort *)(entity->sceneObjects + 0xe);
    *dataCursor = *dataCursor | 0x8000;
    resultFlag = CEntities::CheckEntityHitByPlayerAttackOrThrowable(entry);
    if (resultFlag != '\0') {
      PlayAudioById(0x13c,(int *)0,(undefined4 *)&((EntitySceneObject *)value)->x);
      CEntities::ProcessEntityDeathAndRelease(entry,1);
      return;
    }
    if (((((_g_PlayerSequenceFlags & 0x8000) == 0) &&
         ((*(uint *)(g_PlayerContactSurfaceThisFrame + 0x14) & 0x800) == 0)) &&
        (g_PlayerActionState != 0x31)) &&
       (value3 = CEntities::ComputeEntityDistanceSqToPlayer3D(entry), value3 < 90000)) {
      QueuePlayerDamageEvent(entry,5);
    }
  }
  else {
    dataCursor = (ushort *)(entity->sceneObjects + 0xe);
    *dataCursor = *dataCursor & 0x7fff;
  }
  switch(*(undefined2 *)(entry + 0x48)) {
  case 0x15:
  case 0x2d:
    if (value4 < -0x680) {
      value5 = 0x18;
    }
    else {
      value5 = 0xc;
    }
    break;
  default:
    goto switchD_00411573_caseD_16;
  case 0x2c:
  case 0x2e:
    value5 = 0x32;
  }
  CEntities::MoveClaytonForwardAndUpdateFacing(entry,value,value5);
switchD_00411573_caseD_16:
  shortValue = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
  if (shortValue == 0) goto switchD_004115c2_caseD_16;
  switch(*(undefined2 *)(entry + 0x48)) {
  case 0x15:
    if ((value2 < 2000) && (100 < value2)) {
      PlayAudioById(0x13c,(int *)0,(undefined4 *)&((EntitySceneObject *)value)->x);
      *(undefined2 *)(entry + 0x48) = 0x2c;
      CEntities::SelectEntityAnimationAttachmentState(entry,2);
    }
    break;
  case 0x2c:
    *(undefined2 *)(entry + 0x48) = 0x2e;
    value5 = 3;
    goto LAB_0041163b;
  case 0x2d:
    *(undefined2 *)(entry + 0x48) = 0x15;
    value5 = 1;
LAB_0041163b:
    CEntities::SelectEntityAnimationAttachmentState(entry,value5);
    CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
    break;
  case 0x2e:
    if ((2000 < value2) || (value2 < 100)) {
      PlayAudioById(0x13e,(int *)0,(undefined4 *)&((EntitySceneObject *)value)->x);
      *(undefined2 *)(entry + 0x48) = 0x2d;
      CEntities::SelectEntityAnimationAttachmentState(entry,4);
    }
  }
switchD_004115c2_caseD_16:
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
LAB_00411657:
    CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
  }
  return;
}

