#include "tarzan_ghidra_types.hpp"

// Address: 0x00411730
// Label: CEntities::UpdateChargingAnimal
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CEntities::UpdateChargingAnimal(int entry)

{
  Entity *entity = (Entity *)entry;
  ushort *dataCursor;
  byte *value3;
  char resultFlag;
  short shortValue;
  int value;
  int value2;
  
  value2 = entity->sceneObjects;
  value = CEntities::GetClaytonDistanceAheadOfPlayer(value2);
  if (0x680 < ((EntitySceneObject *)value2)->y - *(int *)(g_PlayerEntitySceneObjectData + 0xc)) {
    CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
    return;
  }
  resultFlag = CEntities::IsEntitySceneObjectWithinCameraYawWindow(value2,800);
  if (resultFlag == '\0') {
    value3 = (byte *)(entity->sceneObjects + 0xf);
    *value3 = *value3 | 0x80;
    resultFlag = CEntities::CheckEntityHitByPlayerAttackOrThrowable(entry);
    if (resultFlag != '\0') {
      PlayAudioById(0x136,(int *)0,(undefined4 *)&((EntitySceneObject *)value2)->x);
      CEntities::ProcessEntityDeathAndRelease(entry,1);
      return;
    }
    if ((((g_PlayerDamageInvulnerabilityTicks == 0) && (g_PlayerActionState != 0x31)) &&
        ((_g_PlayerSequenceFlags & 0x8000) == 0)) &&
       ((*(uint *)(g_PlayerContactSurfaceThisFrame + 0x14) & 0x800) == 0)) {
      resultFlag = CEntities::CheckPlayerDamageContact(value2);
      if (resultFlag != '\0') {
        QueuePlayerDamageEvent(entry,0x1005);
        g_PlayerDamageContactEntitySceneObject = value2;
      }
    }
  }
  else {
    dataCursor = (ushort *)(entity->sceneObjects + 0xe);
    *dataCursor = *dataCursor & 0x7fff;
  }
  if (*(short *)(entry + 0x48) == 0x1f) {
    CEntities::MoveClaytonForwardAndUpdateFacing(entry,value2,*(undefined4 *)(entry + 0x4c));
  }
  else if (value < 0x6a4) {
    *(undefined2 *)(entry + 0x48) = 0x1f;
    CEntities::SelectEntityAnimationAttachmentState(entry,1);
    *(undefined4 *)(entry + 0x4c) = 0;
    PlayAudioById(0x135,(int *)&((EntitySceneObject *)value2)->soundPosition,(undefined4 *)&((EntitySceneObject *)value2)->x);
  }
  shortValue = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
  if (shortValue == 2) {
    if (*(short *)(entry + 0x48) == 0) {
      CEntities::SelectEntityAnimationAttachmentState(entry,0);
      CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
    }
    else if (*(short *)(entry + 0x48) == 0x1f) {
      CEntities::SelectEntityAnimationAttachmentState(entry,1);
      CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
      return;
    }
  }
  else {
    if (shortValue == 0xc) {
      *(int *)(entry + 0x4c) = *(int *)(entry + 0x4c) + 0x18;
      return;
    }
    if ((shortValue == 0xd) &&
       (value2 = *(int *)(entry + 0x4c) + -0x18, *(int *)(entry + 0x4c) = value2, value2 < 0)) {
      *(undefined4 *)(entry + 0x4c) = 0;
      return;
    }
  }
  return;
}

