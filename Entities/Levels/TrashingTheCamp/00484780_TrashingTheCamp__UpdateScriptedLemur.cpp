#include "tarzan_ghidra_types.hpp"

// Address: 0x00484780
// Label: TrashingTheCamp::UpdateScriptedLemur
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TrashingTheCamp::UpdateScriptedLemur(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  char resultFlag;
  short shortValue;
  int value2;
  int value3;
  undefined4 value4;
  
  value = entity->sceneObjects;
  if (value == 0) goto LAB_004848a0;
  value2 = CEntities::FindEntityAttachmentByFlags(entry,0x400);
  if (value2 == 0) goto LAB_004848a0;
  if (*(short *)(entry + 0x48) == 1) {
    if ((*(byte *)(((EntitySceneObject *)value)->surface + 0x14) & 1) == 0) {
      value4 = *(undefined4 *)(entry + 0x50);
      goto LAB_004847fd;
    }
    *(undefined2 *)(entry + 0x48) = 0;
    value3 = RandomModulo(0x32);
    *(int *)(entry + 0x4c) = value3 + 10;
    CEntities::SelectScriptAttachmentSequence(value2,0);
  }
  else if (*(short *)(entry + 0x48) == 2) {
    if ((*(byte *)(((EntitySceneObject *)value)->surface + 0x14) & 1) == 0) {
      *(undefined2 *)(entry + 0x48) = 1;
    }
    value4 = *(undefined4 *)(entry + 0x50);
LAB_004847fd:
    CEntities::MoveEntitySceneObjectAndEaseFacingAngles(entry,value4);
  }
  else {
    *(int *)(entry + 0x4c) = *(int *)(entry + 0x4c) + -1;
  }
  shortValue = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
  if (shortValue == 4) {
    *(undefined4 *)(entry + 0x50) = 0;
  }
  else if (shortValue == 8) {
    if (*(int *)(entry + 0x4c) < 0) {
      *(undefined2 *)(entry + 0x48) = 2;
      CEntities::SelectScriptAttachmentSequence(value2,4);
    }
    else {
      value3 = RandomModulo(4);
      if (value3 == 0) {
        CEntities::SelectScriptAttachmentSequence(value2,1);
      }
    }
  }
  else if (shortValue == 0x105) {
    *(undefined4 *)(entry + 0x50) = 10;
  }
  resultFlag = CEntities::CheckPlayerDamageContact(value);
  if (resultFlag != '\0') {
    QueuePlayerDamageEvent(entry,7);
  }
  resultFlag = CEntities::CheckEntityHitByPlayerAttackOrThrowable(entry);
  if (resultFlag != '\0') {
    PlayAudioById(0x103,(int *)0,(undefined4 *)&((EntitySceneObject *)value)->x);
  }
LAB_004848a0:
  if (*(int *)(g_WorldEntitySceneObjectArrayBase + 0x484) != 0) {
    resultFlag = IsEntityOutsideOuterActivationBounds(entry);
    if (resultFlag != '\0') {
      CEntities::ReleaseEntityToFreeList((byte *)entry);
    }
  }
  return;
}

