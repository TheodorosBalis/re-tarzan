#include "tarzan_ghidra_types.hpp"

// Address: 0x0048BD20
// Label: CEntities::UpdateBouncingThrowableDebris3D
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::UpdateBouncingThrowableDebris3D(int entry)

{
  Entity *entity = (Entity *)entry;
  undefined4 value5;
  char resultFlag;
  int value;
  int value2;
  int value3;
  int value4;
  uint value6;
  
  value3 = entity->sceneObjects;
  if (value3 == 0) goto LAB_0048bebf;
  if (*(short *)(entry + 0x48) == 2) {
    value = CEntities::FindEntityAttachmentByFlags(entry,0x800);
    if (value == 0) goto LAB_0048bebf;
    value4 = *(int *)(value + 0x1c);
    if ((*(int *)(value + 0x10) != value4) &&
       (value2 = *(int *)(value + 0x10) - *(int *)(value + 0x18), *(int *)(value + 0x10) = value2,
       value2 < value4)) {
      *(int *)(value + 0x10) = value4;
    }
    value4 = *(int *)(value + 0x20) + (*(int *)(value + 0x24) - *(int *)(value + 0x28));
    *(int *)(value + 0x20) = value4;
    if (value4 < 0) {
      *(undefined4 *)(value + 0x20) = 0;
    }
    if (*(int *)(value + 0x2c) < *(int *)(value + 0x20)) {
      *(int *)(value + 0x20) = *(int *)(value + 0x2c);
    }
    if (*(char *)(value + 0xd) == '\0') {
      value4 = ((EntitySceneObject *)value3)->y + *(int *)(value + 0x20);
    }
    else {
      value4 = ((EntitySceneObject *)value3)->y - *(int *)(value + 0x20);
    }
    ((EntitySceneObject *)value3)->y = value4;
    if (*(int *)(value + 0x20) == 0) {
      value5 = *(undefined4 *)(value + 0x28);
      *(undefined4 *)(value + 0x28) = 0;
      *(undefined4 *)(value + 0x24) = value5;
      *(undefined1 *)(value + 0xd) = 0;
    }
    if (*(char *)(value + 0xd) == '\0') {
      resultFlag = CEntities::CheckEntitySceneObjectVerticalImpact(value3);
      if (resultFlag != '\0') {
        value5 = *(undefined4 *)(value + 0x24);
        *(undefined4 *)(value + 0x24) = 0;
        value4 = *(int *)(value + 0x10) >> 1;
        *(int *)(value + 0x20) = *(int *)(value + 0x20) >> 1;
        *(int *)(value + 0x10) = value4;
        *(undefined4 *)(value + 0x28) = value5;
        *(undefined1 *)(value + 0xd) = 0xff;
        if (value4 < 1) {
          *(undefined2 *)(entry + 0x48) = 6;
        }
      }
    }
    if (*(char *)(value3 + 0x74) == '\0') {
      *(undefined2 *)(entry + 0x48) = 6;
    }
    else {
      *(char *)(value3 + 0x74) = *(char *)(value3 + 0x74) + -1;
    }
    value6 = *(uint *)(value + 0x10);
    if (*(char *)(value3 + 0x75) != '\0') {
      value6 = ~value6 + 1;
    }
    ComputeEntitySceneObjectCollisionMoveDelta(value6,0,value3);
    *(short *)(value3 + 0xa0) = *(short *)(value3 + 0xa0) + 0x200;
    ((EntitySceneObject *)value3)->yaw = *(undefined2 *)(value3 + 0x132);
    ((EntitySceneObject *)value3)->x = ((EntitySceneObject *)value3)->x + *(int *)(value3 + 0x54);
    ((EntitySceneObject *)value3)->z = ((EntitySceneObject *)value3)->z + *(int *)(value3 + 0x5c);
    if ((*(byte *)(value3 + 0x13c) & 2) == 0) goto LAB_0048bebf;
  }
  PlayAudioById(0xb8,0,(undefined4 *)(&((EntitySceneObject *)value3)->x));
  value3 = CEntities::SpawnEntityByTypeAtPosition
                    (((EntitySceneObject *)value3)->x,((EntitySceneObject *)value3)->y,
                     ((EntitySceneObject *)value3)->z,0x13,0x11);
  if ((value3 != 0) && (value3 = *(int *)(value3 + 0x38), value3 != 0)) {
    *(undefined4 *)(value3 + 0x20) = 0x1000;
    *(undefined4 *)(value3 + 0x24) = 0x800;
    *(undefined4 *)(value3 + 0x28) = 0x800;
    *(undefined4 *)(value3 + 0x30) = 0;
  }
  CEntities::ReleaseEntityToFreeList((byte *)entry);
LAB_0048bebf:
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

