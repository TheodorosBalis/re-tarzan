#include "tarzan_ghidra_types.hpp"

// Address: 0x0040C020
// Label: CampsiteCommotion::UpdateSackOnPlank
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CampsiteCommotion::UpdateSackOnPlank(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  char resultFlag;
  int value2;
  int value3;
  
  value = entity->sceneObjects;
  if (value == 0) goto LAB_0040c0f7;
  CEntities::MoveEntitySceneObjectAndEaseFacingAngles(entry,0);
  value3 = *(int *)(entry + 0x4c);
  switch(*(undefined2 *)(entry + 0x48)) {
  case 1:
  case 2:
  case 3:
    *(undefined2 *)(value + 0xc) = 0x2002;
    value2 = ((EntitySceneObject *)value)->y + *(int *)(value + 0x58);
LAB_0040c0d5:
    ((EntitySceneObject *)value)->y = value2;
    break;
  case 8:
    *(undefined2 *)(value + 0xc) = 0x2010;
    value2 = ((EntitySceneObject *)value)->y - value3;
    value3 = value3 + -10;
    ((EntitySceneObject *)value)->y = value2;
    if (value3 < 1) {
      *(undefined2 *)(entry + 0x48) = 9;
    }
    break;
  case 9:
    *(undefined2 *)(value + 0xc) = 0x2010;
    value2 = ((EntitySceneObject *)value)->y + value3;
    value3 = value3 + 10;
    ((EntitySceneObject *)value)->y = value2;
    if (0x60 < value3) {
      value3 = 0x60;
    }
    resultFlag = CEntities::CheckEntitySceneObjectVerticalImpact(value);
    if (resultFlag != '\0') {
      *(undefined2 *)(entry + 0x48) = 2;
      PlayAudioById(0x2cc,(int *)0,(undefined4 *)&((EntitySceneObject *)value)->x);
      value2 = ((EntitySceneObject *)value)->y + *(int *)(value + 0x58);
      goto LAB_0040c0d5;
    }
  }
  *(int *)(entry + 0x4c) = value3;
  resultFlag = CEntities::CheckPlayerDamageContact(value);
  if (resultFlag != '\0') {
    QueuePlayerDamageEvent(entry,0x100a);
  }
LAB_0040c0f7:
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

