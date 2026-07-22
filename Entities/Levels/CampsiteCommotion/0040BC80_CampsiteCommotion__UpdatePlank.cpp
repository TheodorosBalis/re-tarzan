#include "tarzan_ghidra_types.hpp"

// Address: 0x0040BC80
// Label: CampsiteCommotion::UpdatePlank
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CampsiteCommotion::UpdatePlank(int entry)

{
  Entity *entity = (Entity *)entry;
  int *intCursor;
  int value3;
  uint value7;
  undefined2 value8;
  char resultFlag;
  int value4;
  int value5;
  uint value9;
  uint value10;
  int value;
  bool flagByte;
  undefined4 value6;
  int value2;
  
  value5 = entity->sceneObjects;
  value4 = g_CollisionTriggerEntryListHead;
  if (value5 == 0) goto LAB_0040bf8f;
  for (; (value4 != 0 && (*(short *)(value4 + 0x46) != 0x101)); value4 = *(int *)(value4 + 0x20)) {
  }
  value3 = ((EntitySceneObject *)value5)->surface;
  value = (int)((EntitySceneObject *)value5)->pitch;
  value7 = *(uint *)(value3 + 0xc);
  intCursor = (int *)(&((EntitySceneObject *)value5)->x);
  value9 = *(int *)(g_PlayerEntitySceneObjectData + 8) - *intCursor;
  if (value4 == 0) {
    value4 = CEntities::SpawnEntityByTypeAtPosition
                      (*intCursor,((EntitySceneObject *)value5)->y,((EntitySceneObject *)value5)->z,0x101,
                       0x11);
    if ((value4 != 0) && (value4 = *(int *)(value4 + 0x38), value4 != 0)) {
      *(undefined4 *)(value4 + 0x108) = 1;
      *(undefined4 *)(value4 + 0x110) = ((EntitySceneObject *)value5)->surfacePathIndex;
      *(int *)(value4 + 0x10c) = ((EntitySceneObject *)value5)->surfaceIndex * 2 + -0xfa;
      UpdateEntityEntitySceneObjectTransformFromPlacement(value4);
    }
  }
  else {
    switch(*(undefined2 *)(value4 + 0x48)) {
    case 1:
      if ((*(byte *)(entry + 0x42) & 0x80) == 0) {
        if (*(int *)(entry + 0x4c) != 0) {
          *(int *)(entry + 0x4c) = *(int *)(entry + 0x4c) + -1;
        }
        value = value + 0x20;
        if (0x7f < value) {
          value = 0x7f;
        }
      }
      else {
        if ((int)value9 < 0) {
          flagByte = -1 < value;
          value10 = ~value9 + 1;
          if ((int)value7 < (int)(~value9 + 1)) {
            value10 = value7;
          }
          value = value - ((int)value10 >> 3);
          if (value < -0x7f) {
            value = -0x7f;
          }
          if ((flagByte) && (value < 0)) {
            PlayAudioById(0x28f,(int *)&((EntitySceneObject *)value5)->soundPosition,(undefined4 *)&((EntitySceneObject *)value5)->x);
          }
          if ((*(int *)(entry + 0x4c) == 0) && (300 < (int)value10)) {
            *(undefined2 *)(value4 + 0x48) = 8;
            value2 = 0;
            *(int *)(value4 + 0x4c) = (int)value10 >> 2;
            value6 = 0x2cb;
LAB_0040bda6:
            PlayAudioById(value6,(int *)value2,(undefined4 *)&((EntitySceneObject *)value5)->x);
          }
        }
        else {
          flagByte = value < 0;
          if ((int)value7 < (int)value9) {
            value9 = value7;
          }
          value = value + ((int)value9 >> 3);
          if (0x7f < value) {
            value = 0x7f;
          }
          if ((flagByte) && (-1 < value)) {
            value2 = &((EntitySceneObject *)value5)->soundPosition;
            value6 = 0x28f;
            goto LAB_0040bda6;
          }
        }
        *(undefined4 *)(entry + 0x4c) = 10;
      }
      break;
    case 2:
      value = 0x7f;
      PlayAudioById(0x2ca,(int *)&((EntitySceneObject *)value5)->soundPosition,(undefined4 *)intCursor);
      value8 = g_PlayerActionState;
      if ((int)value9 < 0) {
        value10 = ~value9 + 1;
        if ((int)value7 < (int)(~value9 + 1)) {
          value10 = value7;
        }
        if (((*(byte *)(entry + 0x42) & 0x80) != 0) && (300 < (int)value10)) {
          g_PlayerActionState = 0x30;
          g_PreviousPlayerActionState = value8;
          (*(code *)g_AdultTarzanEnterFastForwardLaunchHandlerPtr)();
        }
      }
      *(undefined2 *)(value4 + 0x48) = 3;
      *(undefined4 *)(entry + 0x4c) = 10;
      break;
    case 3:
      value = 0x7f;
      if (*(int *)(entry + 0x4c) == 0) {
        *(undefined2 *)(value4 + 0x48) = 1;
      }
      else {
        *(int *)(entry + 0x4c) = *(int *)(entry + 0x4c) + -1;
      }
      break;
    case 8:
    case 9:
      if ((*(byte *)(entry + 0x42) & 0x80) != 0) {
        if ((int)value9 < 0) {
          flagByte = -1 < value;
          value10 = ~value9 + 1;
          if ((int)value7 < (int)(~value9 + 1)) {
            value10 = value7;
          }
          value = value - ((int)value10 >> 3);
          if (value < -0x7f) {
            value = -0x7f;
          }
          if ((flagByte) && (value < 0)) {
LAB_0040be52:
            PlayAudioById(0x28f,(int *)&((EntitySceneObject *)value5)->soundPosition,(undefined4 *)intCursor);
          }
        }
        else {
          flagByte = value < 0;
          if ((int)value7 < (int)value9) {
            value9 = value7;
          }
          value = value + ((int)value9 >> 3);
          if (0x7f < value) {
            value = 0x7f;
          }
          if ((flagByte) && (-1 < value)) goto LAB_0040be52;
        }
        *(undefined4 *)(entry + 0x4c) = 10;
      }
    }
  }
  ((EntitySceneObject *)value5)->pitch = (short)value;
  value5 = (int)((int)(short)(&g_SinCosTable12Bit)[value - 0x400U & 0xfff] * value7) >> 0xc;
  *(int *)(value3 + -0x18) = *(int *)(value3 + 4) - value5;
  *(int *)(value3 + 0x20) = *(int *)(value3 + 4) + value5;
LAB_0040bf8f:
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

