#include "tarzan_ghidra_types.hpp"

// Address: 0x00487740
// Label: TrashingTheCamp::UpdateTerkLongJumpBranch
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TrashingTheCamp::UpdateTerkLongJumpBranch(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  uint value5;
  short shortValue;
  char resultFlag;
  int value2;
  int value3;
  uint value6;
  int value4;
  
  value3 = entity->sceneObjects;
  value2 = g_CollisionTriggerEntryListHead;
  if (value3 == 0) goto LAB_004878e4;
  for (; value2 != 0; value2 = *(int *)(value2 + 0x20)) {
    if (*(short *)(value2 + 0x46) == 0xe1) {
      if (value2 != 0) {
        *(ushort *)(value2 + 0x48) = *(ushort *)(value2 + 0x48) & 0xfffe;
      }
      break;
    }
  }
  value = ((EntitySceneObject *)value3)->surface;
  value5 = *(uint *)(value + 0xc);
  if (value2 != 0) {
    if ((*(ushort *)(value2 + 0x48) & 4) != 0) {
      value2 = GetAngleFromXZVector12Bit
                        (*(int *)(*(int *)(value2 + 0x38) + 0x18) - *(int *)(value + 4),value5);
      ((EntitySceneObject *)value3)->pitch = (short)value2;
      shortValue = (&g_SinCosTable12Bit)[value2 - 0x400U & 0xfff];
LAB_004877f8:
      value3 = (int)((int)shortValue * value5) >> 0xc;
      *(int *)(value + -0x18) = *(int *)(value + 4) - value3;
      *(int *)(value + 0x20) = *(int *)(value + 4) + value3;
      return;
    }
    if ((*(ushort *)(value2 + 0x48) & 8) != 0) {
      if (g_PlayerActionState != 9) {
        g_PreviousPlayerActionState = g_PlayerActionState;
        g_PlayerActionState = 9;
        (*(code *)g_TerkEnterLongJumpHandlerPtr)();
      }
      ((EntitySceneObject *)value3)->pitch = 0xff;
      shortValue = g_LevelEntityInitScratch_Field1586;
      goto LAB_004877f8;
    }
  }
  value6 = *(int *)(g_PlayerEntitySceneObjectData + 8) - ((EntitySceneObject *)value3)->x;
  value4 = (int)((EntitySceneObject *)value3)->pitch;
  if ((int)value6 < 0) {
    value6 = ~value6 + 1;
    if ((value2 != 0) && (((int)value6 < 0x360 && (0x100 < (int)value6)))) {
      *(byte *)(value2 + 0x48) = *(byte *)(value2 + 0x48) | 1;
    }
    if ((int)value5 < (int)value6) {
      value6 = value5;
    }
    value2 = value4 - ((int)value6 >> 3);
    if (value2 < -0xff) {
      value2 = -0xff;
    }
    if ((-1 < value4) && (value2 < 0)) {
LAB_004878a2:
      PlayAudioById(0x28e,(int *)&((EntitySceneObject *)value3)->soundPosition,(undefined4 *)&((EntitySceneObject *)value3)->x);
    }
  }
  else {
    if ((int)value5 < (int)value6) {
      value6 = value5;
    }
    value2 = value4 + ((int)value6 >> 3);
    if (0xff < value2) {
      value2 = 0xff;
    }
    if ((value4 < 0) && (-1 < value2)) goto LAB_004878a2;
  }
  ((EntitySceneObject *)value3)->pitch = (short)value2;
  value3 = (int)((int)(short)(&g_SinCosTable12Bit)[value2 - 0x400U & 0xfff] * value5) >> 0xc;
  *(int *)(value + -0x18) = *(int *)(value + 4) - value3;
  *(int *)(value + 0x20) = *(int *)(value + 4) + value3;
LAB_004878e4:
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

