#include "tarzan_ghidra_types.hpp"

// Address: 0x0043C550
// Label: WelcomeToTheJungle::UpdateBongo
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void WelcomeToTheJungle::UpdateBongo(int entry)

{
  Entity *entity = (Entity *)entry;
  short shortValue;
  int value2;
  char resultFlag;
  char resultFlag2;
  short shortValue2;
  int value3;
  undefined4 value6;
  int value4;
  int value5;
  int value;
  bool flagByte;
  
  flagByte = false;
  value4 = entity->sceneObjects;
  if ((value4 == 0) ||
     (value3 = CEntities::FindEntityAttachmentByFlags(entry,0x400), value3 == 0))
  goto switchD_0043c632_default;
  shortValue2 = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
  shortValue = *(short *)(value3 + 0x18);
  CEntities::MoveAnimalFromRuntimeFlagsAndCheckCollision(entry,value4,0x14,0xe);
  resultFlag = CEntities::HandleAnimalScriptEvent(entry,value4,(int)shortValue2);
  value2 = *(int *)(*(int *)(g_CollisionSurfaceTable + 4 + ((EntitySceneObject *)value4)->surfacePathIndex * 4) + 8 +
                   ((EntitySceneObject *)value4)->surfacePathIndex * 4 + g_CollisionSurfaceTable);
  value = ((EntitySceneObject *)value4)->surfaceIndex;
  resultFlag2 = CEntities::CheckPlayerDamageContact(value4);
  if ((resultFlag2 != '\0') && (flagByte = true, *(short *)(entry + 0x48) == 3)) {
    *(undefined2 *)(entry + 0x4a) = 0;
    *(undefined2 *)(entry + 0x48) = 0;
  }
  resultFlag2 = CEntities::CheckEntityHitByPlayerAttackOrThrowable(entry);
  if ((resultFlag2 != '\0') && (PlayAudioById(0xf2,(int *)0,(undefined4 *)&((EntitySceneObject *)value4)->x), *(short *)(entry + 0x48) == 4)) {
    *(undefined4 *)(entry + 0x4c) = 0;
    *(undefined2 *)(entry + 0x48) = 6;
  }
  switch(*(undefined2 *)(entry + 0x48)) {
  case 0:
    CEntities::SelectScriptAttachmentSequence(value3,0);
    *(undefined2 *)(entry + 0x48) = 1;
    value4 = RandomModulo(0x3c);
    *(int *)(entry + 0x4c) = value4 + 0x1e;
    break;
  case 1:
    value4 = *(int *)(entry + 0x4c) + -1;
    *(int *)(entry + 0x4c) = value4;
    if ((-1 < value4) || (resultFlag == '\0')) break;
    value6 = RandomModulo(4);
    switch(value6) {
    case 0:
      *(undefined2 *)(entry + 0x48) = 4;
      CEntities::SelectScriptAttachmentSequence(value3,1);
      break;
    case 1:
      *(undefined2 *)(entry + 0x48) = 4;
      CEntities::SelectScriptAttachmentSequence(value3,4);
      break;
    case 2:
    case 3:
      goto switchD_0043c688_caseD_2;
    }
    break;
  case 2:
    if (!flagByte) {
      CEntities::SelectScriptAttachmentSequence(value3,7);
      *(undefined2 *)(entry + 0x48) = 3;
      value4 = RandomModulo(6);
      *(int *)(entry + 0x4c) = value4 + 6;
      break;
    }
    if (*(char *)(g_PlayerEntitySceneObject + 0x75) == *(char *)(value4 + 0x75)) break;
    goto LAB_0043c751;
  case 3:
    if (resultFlag == '\0') break;
    value5 = *(int *)(entry + 0x4c) + -1;
    *(int *)(entry + 0x4c) = value5;
    if (value5 < 0) {
      CEntities::SelectScriptAttachmentSequence(value3,0xc);
      *(undefined2 *)(entry + 0x48) = 4;
    }
    if (*(char *)(value4 + 0x75) == '\0') {
      value = value2 - value;
      value4 = value + -500;
      flagByte = value == 500;
    }
    else {
      value4 = value + -500;
      flagByte = value4 == 0;
    }
    if (!flagByte && SBORROW4(value,500) == value4 < 0) break;
LAB_0043c751:
    *(undefined2 *)(entry + 0x48) = 5;
    CEntities::SelectScriptAttachmentSequence(value3,9);
    break;
  case 4:
    if (shortValue == 0) {
      *(undefined2 *)(entry + 0x48) = 0;
    }
    break;
  case 5:
    if (shortValue == 8) {
      *(undefined2 *)(entry + 0x48) = 3;
    }
    break;
  case 6:
    value4 = *(int *)(entry + 0x4c) + -1;
    *(int *)(entry + 0x4c) = value4;
    if ((-1 < value4) || (resultFlag == '\0')) break;
switchD_0043c688_caseD_2:
    *(undefined2 *)(entry + 0x48) = 2;
  }
switchD_0043c632_default:
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

