#include "tarzan_ghidra_types.hpp"

// Address: 0x004277B0
// Label: ElephantHairDare::UpdateYoungRhino
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ElephantHairDare::UpdateYoungRhino(int entry)

{
  Entity *entity = (Entity *)entry;
  short shortValue;
  bool flagByte;
  char resultFlag;
  short shortValue2;
  int value2;
  int value3;
  int value4;
  int value5;
  int value6;
  int value;
  
  if ((_g_PlayerHeroMode == 2) && ((g_PlayerActionState == 0x28 || (g_PlayerActionState == 0x25))))
  {
    CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
    return;
  }
  value5 = entity->sceneObjects;
  if ((value5 == 0) ||
     (value2 = CEntities::FindEntityAttachmentByFlags(entry,0x400), value2 == 0))
  goto switchD_004278ad_default;
  shortValue2 = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
  shortValue = *(short *)(value2 + 0x18);
  CEntities::MoveAnimalFromRuntimeFlagsAndCheckCollision(entry,value5,0x1e,0x14);
  value3 = CEntities::HandleAnimalScriptEvent(entry,value5,(int)shortValue2);
  value = ((EntitySceneObject *)value5)->surfaceIndex;
  value6 = *(int *)(*(int *)(g_CollisionSurfaceTable + 4 + ((EntitySceneObject *)value5)->surfacePathIndex * 4) + 8 +
                   ((EntitySceneObject *)value5)->surfacePathIndex * 4 + g_CollisionSurfaceTable);
  resultFlag = CEntities::CheckPlayerDamageContact(value5);
  if (resultFlag != '\0') {
    QueuePlayerDamageEvent(entry,6);
    g_PlayerDamageContactEntitySceneObject = value5;
  }
  resultFlag = CEntities::CheckEntityHitByPlayerAttackOrThrowable(entry);
  if ((resultFlag == '\0') ||
     (value4 = CEntities::IsTargetEntityInFront(entry,g_PlayerEntity), value4 != 0)) {
    flagByte = false;
  }
  else {
    flagByte = true;
  }
  switch(*(undefined2 *)(entry + 0x48)) {
  case 0:
    *(undefined2 *)(entry + 0x48) = 1;
    CEntities::SelectScriptAttachmentSequence(value2,0);
    value5 = RandomModulo(3);
    *(int *)(entry + 0x4c) = value5 + 1;
    break;
  case 1:
    if (flagByte) {
      *(undefined2 *)(entry + 0x48) = 6;
      CEntities::SelectScriptAttachmentSequence(value2,7);
    }
    else if (value3 != 0) {
      value5 = *(int *)(entry + 0x4c) + -1;
      *(int *)(entry + 0x4c) = value5;
      if (value5 < 0) {
        *(undefined2 *)(entry + 0x48) = 2;
        CEntities::SelectScriptAttachmentSequence(value2,1);
      }
      else {
        CEntities::SelectScriptAttachmentSequence(value2,0);
      }
    }
    break;
  case 2:
    if (value3 != 0) {
      *(undefined2 *)(entry + 0x48) = 3;
      PlayAudioById(0x150,(int *)0,(undefined4 *)&((EntitySceneObject *)value5)->x);
    }
    break;
  case 3:
    if (flagByte) {
      *(undefined2 *)(entry + 0x48) = 5;
      CEntities::SelectScriptAttachmentSequence(value2,6);
    }
    else if (value3 != 0) {
      *(undefined2 *)(entry + 0x48) = 4;
      CEntities::SelectScriptAttachmentSequence(value2,3);
    }
    break;
  case 4:
    if (value3 == 0) break;
    goto LAB_00427a28;
  case 5:
  case 6:
    if (shortValue == 9) {
      *(undefined2 *)(entry + 0x48) = 7;
      PlayAudioById(0x153,(int *)0,(undefined4 *)&((EntitySceneObject *)value5)->x);
    }
    break;
  case 7:
    if (*(char *)(value5 + 0x75) == '\0') {
      value3 = CEntities::IsTargetEntityInFront(entry,g_PlayerEntity);
      if (value3 != 0) {
        value = value6 - value;
        goto LAB_004279d6;
      }
    }
    else {
      value6 = CEntities::IsTargetEntityInFront(entry,g_PlayerEntity);
      if (value6 != 0) {
LAB_004279d6:
        if (800 < value) break;
      }
    }
    CEntities::SelectScriptAttachmentSequence(value2,10);
    *(undefined2 *)(entry + 0x48) = 8;
    PlayAudioById(0x152,(int *)0,(undefined4 *)&((EntitySceneObject *)value5)->x);
    break;
  case 8:
    if (shortValue != 0) break;
LAB_00427a28:
    *(undefined2 *)(entry + 0x48) = 0;
  }
switchD_004278ad_default:
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

