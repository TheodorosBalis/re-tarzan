#include "tarzan_ghidra_types.hpp"

// Address: 0x0040B8A0
// Label: CampsiteCommotion::UpdateWorkerEnemy
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CampsiteCommotion::UpdateWorkerEnemy(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  char resultFlag;
  short shortValue;
  int value3;
  int value4;
  bool flagByte;
  undefined4 value5;
  int localState2;
  int localState;
  
  value2 = entry;
  value = entity->sceneObjects;
  if (value == 0) goto LAB_0040bb6a;
  flagByte = false;
  value3 = CEntities::FindEntityAttachmentByFlags(entry,0x400);
  if (value3 == 0) goto LAB_0040bb6a;
  shortValue = CEntities::UpdateScriptedEntitySceneObjectAttachment(value2);
  localState = (int)shortValue;
  localState2 = 0x7ffff;
  entry = 0x7ffff;
  CampsiteCommotion::ComputeWorkerEnemyPathDistanceToPlayer(value,&localState2,&entry);
  if (*(char *)(value + 0x74) != '\0') {
    *(char *)(value + 0x74) = *(char *)(value + 0x74) + -1;
  }
  resultFlag = CEntities::CheckEntityHitByPlayerAttackOrThrowable(value2);
  if ((resultFlag != '\0') && (flagByte = true, *(char *)(value + 0x74) == '\0')) {
    if ((*(int *)(value2 + 0x50) == 1) || (*(int *)(value2 + 0x50) == 2)) {
      value5 = 0x2c5;
    }
    else {
      value5 = 0x2c4;
    }
    PlayAudioById(value5,(int *)0,(undefined4 *)&((EntitySceneObject *)value)->x);
    *(undefined1 *)(value + 0x74) = 0x3c;
  }
  switch(*(undefined2 *)(value2 + 0x48)) {
  case 0:
switchD_0040b965_caseD_0:
    *(undefined2 *)(value2 + 0x48) = 1;
    value5 = 0;
    goto LAB_0040ba5e;
  case 1:
    if (flagByte) {
      if (localState2 < 0x481) {
LAB_0040b9c0:
        if (entry < 0x481) break;
        *(undefined2 *)(value2 + 0x48) = 2;
        value5 = 1;
      }
      else {
        *(undefined2 *)(value2 + 0x48) = 3;
        value5 = 4;
      }
    }
    else {
      if ((localState != 8) || (value4 = RandomModulo(3), value4 != 0)) break;
      if (localState2 < 0x481) goto LAB_0040b9c0;
      *(undefined2 *)(value2 + 0x48) = 3;
      value5 = 4;
    }
    goto LAB_0040ba5e;
  case 2:
    if (localState == 4) {
      ((EntitySceneObject *)value)->yaw = ((EntitySceneObject *)value)->yaw ^ 0x800;
      *(byte *)(value + 0x75) = ~*(byte *)(value + 0x75);
      goto switchD_0040b965_caseD_0;
    }
    break;
  case 3:
    if ((*(byte *)(value + 0x13c) & 2) == 0) {
      if (flagByte) {
        *(undefined2 *)(value2 + 0x48) = 4;
        value5 = 9;
      }
      else {
        if (0x2ff < localState2) break;
        if (entry < 0x401) {
          *(undefined2 *)(value2 + 0x48) = 1;
          value5 = 6;
        }
        else {
          *(undefined2 *)(value2 + 0x48) = 4;
          value5 = 9;
        }
      }
    }
    else {
      *(undefined2 *)(value2 + 0x48) = 4;
      value5 = 9;
    }
LAB_0040ba5e:
    CEntities::SelectScriptAttachmentSequence(value3,value5);
    break;
  case 4:
    if (localState == 4) {
      ((EntitySceneObject *)value)->yaw = ((EntitySceneObject *)value)->yaw ^ 0x800;
      *(byte *)(value + 0x75) = ~*(byte *)(value + 0x75);
      *(undefined2 *)(value2 + 0x48) = 3;
      value5 = 5;
      goto LAB_0040ba5e;
    }
  }
  if (*(short *)(value2 + 0x48) == 3) {
    value5 = *(undefined4 *)(value2 + 0x4c);
  }
  else {
    value5 = 0;
  }
  CEntities::MoveEntitySceneObjectAndEaseFacingAngles(value2,value5);
  if ((*(byte *)(value2 + 0x43) & 0x20) != 0) {
    if (*(char *)(value + 0x74) == '\0') {
      if ((*(int *)(value2 + 0x50) == 1) || (*(int *)(value2 + 0x50) == 2)) {
        value5 = 0x2c3;
      }
      else {
        value5 = 0x2c2;
      }
      PlayAudioById(value5,(int *)0,(undefined4 *)&((EntitySceneObject *)value)->x);
      *(undefined1 *)(value + 0x74) = 0x3c;
    }
    *(ushort *)(value2 + 0x42) = *(ushort *)(value2 + 0x42) & 0xdfff;
  }
  resultFlag = CEntities::CheckPlayerDamageContact(value);
  if (resultFlag != '\0') {
    QueuePlayerDamageEvent(value2,5);
    if (*(int *)(g_PlayerEntitySceneObjectData + 8) - ((EntitySceneObject *)value)->x < 0) {
      flagByte = *(char *)(value + 0x75) != '\0';
    }
    else {
      flagByte = *(char *)(value + 0x75) == '\0';
    }
    g_PlayerDamageContactEntitySceneObject = value;
    if (*(short *)(value2 + 0x48) == 1) {
      if (flagByte) {
        if (entry < 0x801) goto LAB_0040bb6a;
        *(undefined2 *)(value2 + 0x48) = 2;
        value5 = 1;
      }
      else {
        if (localState2 < 0x501) goto LAB_0040bb6a;
        *(undefined2 *)(value2 + 0x48) = 3;
        value5 = 4;
      }
    }
    else {
      if ((*(short *)(value2 + 0x48) != 3) || (!flagByte)) goto LAB_0040bb6a;
      if (entry < 0x601) {
        *(undefined2 *)(value2 + 0x48) = 1;
        value5 = 6;
      }
      else {
        *(undefined2 *)(value2 + 0x48) = 4;
        value5 = 9;
      }
    }
    CEntities::SelectScriptAttachmentSequence(value3,value5);
  }
LAB_0040bb6a:
  resultFlag = IsEntityOutsideOuterActivationBounds(value2);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)value2);
  }
  return;
}

