#include "tarzan_ghidra_types.hpp"

// Address: 0x00488760
// Label: TrashingTheCamp::UpdateFallingCampDebris
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TrashingTheCamp::UpdateFallingCampDebris(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  char resultFlag;
  int value2;
  int value3;
  uint value4;
  undefined4 value5;
  
  value = entity->sceneObjects;
  if (value == 0) {
    return;
  }
  value2 = CEntities::FindEntityAttachmentByFlags(entry,0x800);
  if (value2 == 0) {
    return;
  }
  value3 = *(int *)(value2 + 0x20) + (*(int *)(value2 + 0x24) - *(int *)(value2 + 0x28));
  *(int *)(value2 + 0x20) = value3;
  if (value3 < 0) {
    *(undefined4 *)(value2 + 0x20) = 0;
  }
  if (*(int *)(value2 + 0x2c) < *(int *)(value2 + 0x20)) {
    *(int *)(value2 + 0x20) = *(int *)(value2 + 0x2c);
  }
  if (*(char *)(value2 + 0xd) == '\0') {
    value3 = ((EntitySceneObject *)value)->y + *(int *)(value2 + 0x20);
  }
  else {
    value3 = ((EntitySceneObject *)value)->y - *(int *)(value2 + 0x20);
  }
  ((EntitySceneObject *)value)->y = value3;
  if (*(int *)(value2 + 0x20) == 0) {
    value5 = *(undefined4 *)(value2 + 0x28);
    *(undefined4 *)(value2 + 0x28) = 0;
    *(undefined4 *)(value2 + 0x24) = value5;
    *(undefined1 *)(value2 + 0xd) = 0;
  }
  if ((*(char *)(value2 + 0xd) != '\0') ||
     (resultFlag = CEntities::CheckEntitySceneObjectVerticalImpact(value), resultFlag == '\0'))
  goto LAB_00488945;
  if (*(int *)(entry + 0x4c) == 3) {
    *(undefined4 *)(value2 + 0x10) = 0;
  }
  value3 = RandomModulo(6);
  if (value3 == 0) {
    *(undefined4 *)(value2 + 0x10) = 0;
  }
  value5 = *(undefined4 *)(value2 + 0x24);
  *(undefined4 *)(value2 + 0x24) = 0;
  value3 = *(int *)(value2 + 0x10) >> 1;
  *(int *)(value2 + 0x20) = *(int *)(value2 + 0x20) >> 1;
  *(int *)(value2 + 0x10) = value3;
  *(undefined4 *)(value2 + 0x28) = value5;
  *(undefined1 *)(value2 + 0xd) = 0xff;
  if (7 < value3) goto LAB_00488945;
  value3 = *(int *)(entry + 0x4c);
  if (value3 == 1) {
    value3 = RandomModulo(4);
    if (value3 == 1) {
      value5 = 0x2b3;
    }
    else if (value3 == 2) {
      value5 = 0x2b4;
    }
    else if (value3 == 3) {
      value5 = 0x2b5;
    }
    else {
      value5 = 0x2b2;
    }
LAB_0048891f:
    PlayAudioById(value5,(int *)0,(undefined4 *)&((EntitySceneObject *)value)->x);
  }
  else {
    if (value3 == 2) {
      value3 = RandomModulo(4);
      if (value3 == 1) {
        value5 = 0x2b7;
      }
      else if (value3 == 2) {
        value5 = 0x2b8;
      }
      else if (value3 == 3) {
        value5 = 0x2b9;
      }
      else {
        value5 = 0x2b6;
      }
      goto LAB_0048891f;
    }
    if (value3 == 3) {
      value3 = RandomModulo(4);
      if (value3 == 1) {
        value5 = 0x2af;
      }
      else if (value3 == 2) {
        value5 = 0x2b0;
      }
      else if (value3 == 3) {
        value5 = 0x2b1;
      }
      else {
        value5 = 0x2ae;
      }
      goto LAB_0048891f;
    }
  }
  CEntities::SpawnEntityByTypeAtPosition
            (((EntitySceneObject *)value)->x,((EntitySceneObject *)value)->y,
             ((EntitySceneObject *)value)->z,0x13,0x11);
  CEntities::ReleaseEntityToFreeList((byte *)entry);
LAB_00488945:
  value4 = *(uint *)(value2 + 0x10);
  if (*(char *)(value + 0x75) != '\0') {
    value4 = ~value4 + 1;
  }
  ComputeEntitySceneObjectCollisionMoveDelta(value4,0,value);
  ((EntitySceneObject *)value)->x = ((EntitySceneObject *)value)->x + *(int *)(value + 0x54);
  ((EntitySceneObject *)value)->z = ((EntitySceneObject *)value)->z + *(int *)(value + 0x5c);
  if (*(char *)(value + 0x74) != '\0') {
    *(short *)(value + 0xa0) = *(short *)(value + 0xa0) + 0xe3;
  }
  resultFlag = CEntities::CheckPlayerDamageContact(value);
  if (resultFlag != '\0') {
    QueuePlayerDamageEvent(entry,2);
    CEntities::SpawnEntityByTypeAtPosition
              (((EntitySceneObject *)value)->x,((EntitySceneObject *)value)->y,
               ((EntitySceneObject *)value)->z,0x13,0x11);
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

