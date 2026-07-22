#include "tarzan_ghidra_types.hpp"

// Address: 0x00406010
// Label: RockinTheBoat::ChooseKnifeEnemyPathTarget
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 RockinTheBoat::ChooseKnifeEnemyPathTarget(int arg1,int *arg2)

{
  Entity *entity = (Entity *)arg1;
  bool flagByte;
  bool flagByte2;
  uint value5;
  int value;
  uint value6;
  int value2;
  int value3;
  int value4;
  int localState17;
  int localState16;
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
  undefined1 localState18 [12];
  
  localState12 = entity->sceneObjects;
  localState17 = 0x7fffffff;
  value2 = 0;
  localState15 = 0x7fffffff;
  localState4 = ((EntitySceneObject *)localState12)->x;
  localState13 = g_RockinTheBoatKnifeEnemyControllerEntry;
  localState3 = ((EntitySceneObject *)localState12)->y + -0x80;
  localState2 = ((EntitySceneObject *)localState12)->z;
  value3 = localState13;
  if (g_RockinTheBoatKnifeEnemyControllerEntry != 0) {
    do {
      localState17 = 0x7fffffff;
      localState11 = *(int *)(localState13 + 0x38);
      if (localState11 != localState12) {
        value3 = *(int *)(localState11 + 0x14) - *(int *)(entity->sceneObjects + 0x14);
        value4 = *(int *)(localState11 + 0x1c) - *(int *)(entity->sceneObjects + 0x1c);
        localState14 = SqrtToInt(value4 * value4 + value3 * value3);
        localState14 = localState14 >> 6;
        if (localState14 < 0x100000) {
          value5 = GetAngleFromXZVector12Bit(value3,value4);
          if (localState14 < 0x1b4) {
            *(int *)(entity->sceneObjects + 0x14) =
                 *(int *)(entity->sceneObjects + 0x14) -
                 ((int)(short)(&g_SinCosTable12Bit)[(value5 & 0xfff) - 0x400 & 0xfff] *
                  (0x1b4 - localState14) >> 0xc);
            *(int *)(entity->sceneObjects + 0x1c) =
                 *(int *)(entity->sceneObjects + 0x1c) -
                 ((int)(short)(&g_SinCosTable12Bit)[value5 & 0xfff] * (0x1b4 - localState14) >> 0xc);
          }
          value3 = RockinTheBoat::FindNearestKnifeEnemyAttackAnchor
                            (&localState4,localState11,&localState14,localState18,localState,&localState16);
          if ((value3 != 0) && (localState14 < localState15)) {
            localState15 = localState14;
            value2 = value3;
          }
        }
      }
      localState13 = *(int *)(localState13 + 0x18);
    } while (localState13 != 0);
    value3 = 0;
    if (value2 != 0) {
      localState16 = localState16 + 0x200;
      value5 = GetAngleFromXZVector12Bit
                        (*(int *)(g_PlayerEntitySceneObject + 0x14) -
                         *(int *)(entity->sceneObjects + 0x14),
                         g_RockinTheBoatKnifeEnemyTargetZ -
                         *(int *)(entity->sceneObjects + 0x1c));
      value4 = localState12;
      value6 = (int)(((value5 & 0xfff) + 0x400) * 0x100000) >> 0x14 & 0xfff;
      value5 = (int)(((value5 & 0xfff) - 0x400) * 0x100000) >> 0x14 & 0xfff;
      localState7 = *(int *)(value2 + 0x14) -
                 ((short)(&g_SinCosTable12Bit)[value6 - 0x400 & 0xfff] * localState16 >> 0xc);
      localState5 = *(int *)(value2 + 0x1c) - ((short)(&g_SinCosTable12Bit)[value6] * localState16 >> 0xc);
      localState6 = *(int *)(g_PlayerEntitySceneObject + 0x18);
      localState10 = *(int *)(value2 + 0x14) -
                 ((short)(&g_SinCosTable12Bit)[value5 - 0x400 & 0xfff] * localState16 >> 0xc);
      flagByte = false;
      localState8 = *(int *)(value2 + 0x1c) - ((short)(&g_SinCosTable12Bit)[value5] * localState16 >> 0xc);
      localState9 = *(int *)(g_PlayerEntitySceneObject + 0x18);
      value2 = localState11;
      for (value3 = g_RockinTheBoatKnifeEnemyControllerEntry; value3 != 0;
          value3 = *(int *)(value3 + 0x18)) {
        localState17 = 0x7fffffff;
        if (value2 != value4) {
          value2 = *(int *)(value3 + 0x38);
          value = RockinTheBoat::FindNearestKnifeEnemyAttackAnchor
                            (&localState7,value2,&localState17,localState18,localState,&localState16);
          if ((value != 0) && (localState17 < localState15)) {
            flagByte = true;
          }
        }
      }
      flagByte2 = false;
      for (value2 = g_RockinTheBoatKnifeEnemyControllerEntry; value2 != 0;
          value2 = *(int *)(value2 + 0x18)) {
        localState17 = 0x7fffffff;
        if (((*(int *)(value2 + 0x38) != value4) &&
            (value3 = RockinTheBoat::FindNearestKnifeEnemyAttackAnchor
                               (&localState10,*(int *)(value2 + 0x38),&localState17,localState18,localState,
                                &localState16), value3 != 0)) && (localState17 < localState15)) {
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
      value2 = *(int *)(entity->sceneObjects + 0x14);
      value3 = *(int *)(entity->sceneObjects + 0x1c);
      value = localState7 - value2;
      value4 = localState5 - value3;
      value2 = localState10 - value2;
      value3 = localState8 - value3;
      if (value4 * value4 + value * value <= value3 * value3 + value2 * value2) {
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
  localState13 = value3;
  value5 = GetAngleFromXZVector12Bit
                    (*(int *)(g_PlayerEntitySceneObject + 0x14) -
                     *(int *)(entity->sceneObjects + 0x14),
                     g_RockinTheBoatKnifeEnemyTargetZ - *(int *)(entity->sceneObjects + 0x1c));
  *arg2 = *(int *)(g_PlayerEntitySceneObject + 0x14) -
             ((short)(&g_SinCosTable12Bit)[(value5 & 0xfff) - 0x400 & 0xfff] * 0x15e >> 0xc);
  arg2[2] = g_RockinTheBoatKnifeEnemyTargetZ -
               ((short)(&g_SinCosTable12Bit)[value5 & 0xfff] * 0x15e >> 0xc);
  arg2[1] = *(int *)(g_PlayerEntitySceneObject + 0x18);
  return 0;
}

