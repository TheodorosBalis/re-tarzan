#include "tarzan_ghidra_types.hpp"

// Address: 0x0045D500
// Label: JourneyToTheTreeHouse::UpdateHippo
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void JourneyToTheTreeHouse::UpdateHippo(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  char resultFlag;
  short shortValue;
  uint value3;
  undefined4 value4;
  
  value = entity->sceneObjects;
  value3 = NextRandomValue();
  if ((value3 & 0x3f) == 0) {
    value3 = NextRandomValue();
    switch(value3 & 7) {
    case 1:
      value4 = 0x13f;
      break;
    case 2:
      value4 = 0x140;
      break;
    case 3:
      value4 = 0x141;
      break;
    case 4:
      value4 = 0x142;
      break;
    case 5:
      value4 = 0x143;
      break;
    case 6:
      value4 = 0x144;
      break;
    case 7:
      value4 = 0x145;
      break;
    default:
      goto switchD_0045d520_default;
    }
    PlayAudioById(value4,(int *)0,(undefined4 *)&((EntitySceneObject *)value)->x);
  }
switchD_0045d520_default:
  shortValue = *(short *)(entry + 0x48);
  if (shortValue == 0x15) {
    CEntities::MoveSceneObjectForwardAndAlignToSurface(entry,value,5);
    if ((*(byte *)(value + 0x13c) & 2) != 0) {
      *(undefined2 *)(entry + 0x48) = 0x29;
      CEntities::SelectEntityAnimationAttachmentState(entry,6);
    }
  }
  else if (shortValue == 0x2c) {
    value2 = *(int *)(entry + 0x50);
    *(int *)(entry + 0x50) = value2 + 1;
    CEntities::MoveSceneObjectForwardAndAlignToSurface
              (entry,value,(int)(value2 + (value2 >> 0x1f & 3U)) >> 2);
  }
  else if (shortValue == 0x2d) {
    value2 = *(int *)(entry + 0x50);
    *(int *)(entry + 0x50) = value2 + -1;
    CEntities::MoveSceneObjectForwardAndAlignToSurface(entry,value,value2 / 5);
  }
  shortValue = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
  if (shortValue == 0) goto switchD_0045d62e_caseD_1;
  switch(*(undefined2 *)(entry + 0x48)) {
  case 0:
  case 0x2a:
    value3 = NextRandomValue();
    if ((value3 & 3) == 0) {
      *(undefined2 *)(entry + 0x48) = 0x2a;
      value4 = 1;
    }
    else if ((value3 & 3) == 1) {
      *(undefined2 *)(entry + 0x48) = 0x2a;
      value4 = 2;
    }
    else {
      *(undefined2 *)(entry + 0x48) = 0x2c;
      *(undefined4 *)(entry + 0x50) = 0;
      value4 = 3;
    }
    break;
  default:
    goto switchD_0045d62e_caseD_1;
  case 0x15:
    if ((*(byte *)(((EntitySceneObject *)value)->surface + 0x14) & 7) == 0) goto switchD_0045d62e_caseD_1;
    *(undefined2 *)(entry + 0x48) = 0x2d;
    CEntities::SelectEntityAnimationAttachmentState(entry,5);
    *(undefined4 *)(entry + 0x50) = 0x19;
    goto LAB_0045d6cb;
  case 0x29:
    ((EntitySceneObject *)value)->yaw = ((EntitySceneObject *)value)->yaw ^ 0x800;
    *(byte *)(value + 0x75) = ~*(byte *)(value + 0x75);
    *(undefined2 *)(entry + 0x48) = 0x2c;
    *(undefined4 *)(entry + 0x50) = 0;
    value4 = 3;
    break;
  case 0x2c:
    *(undefined2 *)(entry + 0x48) = 0x15;
    value4 = 4;
    break;
  case 0x2d:
    *(undefined2 *)(entry + 0x48) = 0;
    value4 = 0;
  }
  CEntities::SelectEntityAnimationAttachmentState(entry,value4);
LAB_0045d6cb:
  CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
switchD_0045d62e_caseD_1:
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

