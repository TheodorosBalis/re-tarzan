#include "tarzan_ghidra_types.hpp"

// Address: 0x004638C0
// Label: TarzanToTheRescue::ChooseKnifeEnemyPathTarget
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 TarzanToTheRescue::ChooseKnifeEnemyPathTarget(int arg1,int *arg2)

{
  Entity *entity = (Entity *)arg1;
  bool flagByte;
  bool flagByte2;
  uint value5;
  uint value6;
  int value;
  int value2;
  int value3;
  int value4;
  int localState15;
  int localState14;
  int localState13;
  int localState12;
  int localState11;
  int localState10;
  int localState9;
  int localState8;
  int localState7;
  int localState6;
  int localState5;
  undefined4 localState4;
  int localState3;
  undefined4 localState2;
  undefined1 localState [12];
  undefined1 localState16 [12];
  
  value4 = entity->sceneObjects;
  localState15 = 0x7fffffff;
  value3 = 0;
  localState4 = ((EntitySceneObject *)value4)->x;
  localState12 = g_ActiveEntityListHead;
  localState13 = 0x7fffffff;
  localState3 = ((EntitySceneObject *)value4)->y + -0x80;
  localState2 = ((EntitySceneObject *)value4)->z;
  value4 = localState12;
  if (g_ActiveEntityListHead != 0) {
    do {
      localState15 = 0x7fffffff;
      localState11 = *(int *)(localState12 + 0x38);
      value4 = entity->sceneObjects;
      if ((localState11 != value4) && (localState11 != g_PlayerEntitySceneObject)) {
        value2 = *(int *)(localState11 + 0x1c) - ((EntitySceneObject *)value4)->z;
        value4 = *(int *)(localState11 + 0x14) - ((EntitySceneObject *)value4)->x;
        value5 = GetAngleFromXZVector12Bit(value4,value2);
        value4 = SqrtToInt(value2 * value2 + value4 * value4);
        if (value4 >> 6 < 0x110) {
          value4 = 0x110 - (value4 >> 6);
          *(int *)(entity->sceneObjects + 0x14) =
               *(int *)(entity->sceneObjects + 0x14) -
               ((short)(&g_SinCosTable12Bit)[(value5 & 0xfff) - 0x400 & 0xfff] * value4 >> 0xc);
          *(int *)(entity->sceneObjects + 0x1c) =
               *(int *)(entity->sceneObjects + 0x1c) -
               ((short)(&g_SinCosTable12Bit)[value5 & 0xfff] * value4 >> 0xc);
        }
        value4 = TarzanToTheRescue::FindNearestKnifeEnemyAttackAnchor
                          (&localState4,localState11,&localState15,localState16,localState,&localState14);
        if ((value4 != 0) && (localState15 < localState13)) {
          localState13 = localState15;
          value3 = value4;
        }
      }
      localState12 = *(int *)(localState12 + 0x20);
    } while (localState12 != 0);
    value4 = 0;
    if (value3 != 0) {
      localState14 = localState14 + 0x264;
      value5 = GetAngleFromXZVector12Bit
                        (*(int *)(g_PlayerEntitySceneObject + 0x14) -
                         *(int *)(entity->sceneObjects + 0x14),
                         *(int *)(g_PlayerEntitySceneObject + 0x1c) -
                         *(int *)(entity->sceneObjects + 0x1c));
      value6 = (int)(((value5 & 0xfff) + 0x400) * 0x100000) >> 0x14 & 0xfff;
      value5 = (int)(((value5 & 0xfff) - 0x400) * 0x100000) >> 0x14 & 0xfff;
      localState7 = *(int *)(value3 + 0x14) -
                 ((short)(&g_SinCosTable12Bit)[value6 - 0x400 & 0xfff] * localState14 >> 0xc);
      localState5 = *(int *)(value3 + 0x1c) - ((short)(&g_SinCosTable12Bit)[value6] * localState14 >> 0xc);
      localState6 = *(int *)(g_PlayerEntitySceneObject + 0x18);
      localState10 = *(int *)(value3 + 0x14) -
                 ((short)(&g_SinCosTable12Bit)[value5 - 0x400 & 0xfff] * localState14 >> 0xc);
      localState8 = *(int *)(value3 + 0x1c) - ((short)(&g_SinCosTable12Bit)[value5] * localState14 >> 0xc);
      localState9 = *(int *)(g_PlayerEntitySceneObject + 0x18);
      flagByte = false;
      for (value4 = g_ActiveEntityListHead; value4 != 0; value4 = *(int *)(value4 + 0x20)) {
        localState15 = 0x7fffffff;
        if ((localState11 != entity->sceneObjects) && (localState11 != g_PlayerEntitySceneObject)) {
          localState11 = *(int *)(value4 + 0x38);
          value3 = TarzanToTheRescue::FindNearestKnifeEnemyAttackAnchor
                            (&localState7,localState11,&localState15,localState16,localState,&localState14);
          if ((value3 != 0) && (localState15 < localState13)) {
            flagByte = true;
          }
        }
      }
      flagByte2 = false;
      for (value4 = g_ActiveEntityListHead; value4 != 0; value4 = *(int *)(value4 + 0x20)) {
        localState15 = 0x7fffffff;
        value3 = *(int *)(value4 + 0x38);
        if ((((value3 != entity->sceneObjects) && (value3 != g_PlayerEntitySceneObject)) &&
            (value3 = TarzanToTheRescue::FindNearestKnifeEnemyAttackAnchor
                               (&localState10,value3,&localState15,localState16,localState,&localState14), value3 != 0))
           && (localState15 < localState13)) {
          flagByte2 = true;
        }
      }
      if (flagByte) {
        if (flagByte2) {
          *arg2 = localState10;
          arg2[1] = localState9;
          arg2[2] = localState8;
          return 0;
        }
        *arg2 = localState10;
        arg2[1] = localState9;
        arg2[2] = localState8;
        return 0;
      }
      if (flagByte2) {
        *arg2 = localState7;
        arg2[1] = localState6;
        arg2[2] = localState5;
        return 0;
      }
      value4 = *(int *)(entity->sceneObjects + 0x14);
      value3 = *(int *)(entity->sceneObjects + 0x1c);
      value = localState7 - value4;
      value2 = localState5 - value3;
      value4 = localState10 - value4;
      value3 = localState8 - value3;
      if (value2 * value2 + value * value <= value3 * value3 + value4 * value4) {
        *arg2 = localState7;
        arg2[1] = localState6;
        arg2[2] = localState5;
        return 0;
      }
      *arg2 = localState10;
      arg2[1] = localState9;
      arg2[2] = localState8;
      return 0;
    }
  }
  localState12 = value4;
  value5 = GetAngleFromXZVector12Bit
                    (*(int *)(g_PlayerEntitySceneObject + 0x14) -
                     *(int *)(entity->sceneObjects + 0x14),
                     *(int *)(g_PlayerEntitySceneObject + 0x1c) -
                     *(int *)(entity->sceneObjects + 0x1c));
  *arg2 = *(int *)(g_PlayerEntitySceneObject + 0x14) -
             ((short)(&g_SinCosTable12Bit)[(value5 & 0xfff) - 0x400 & 0xfff] * 400 >> 0xc);
  arg2[2] = *(int *)(g_PlayerEntitySceneObject + 0x1c) -
               ((short)(&g_SinCosTable12Bit)[value5 & 0xfff] * 400 >> 0xc);
  arg2[1] = *(int *)(g_PlayerEntitySceneObject + 0x18);
  return 0;
}

