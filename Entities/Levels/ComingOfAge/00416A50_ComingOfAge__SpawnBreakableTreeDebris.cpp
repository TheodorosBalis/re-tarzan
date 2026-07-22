#include "tarzan_ghidra_types.hpp"

// Address: 0x00416A50
// Label: ComingOfAge::SpawnBreakableTreeDebris
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ComingOfAge::SpawnBreakableTreeDebris(int entry)

{
  short shortValue;
  int value;
  int value2;
  int value3;
  int value4;
  int value5;
  undefined4 *dataCursor;
  short *value6;
  undefined4 *dataCursor2;
  
  value2 = CEntities::SpawnEntityByTypeAtPosition
                    (*(undefined4 *)(entry + 0x14),*(undefined4 *)(entry + 0x18),
                     *(undefined4 *)(entry + 0x1c),0x9a,0x11);
  if (value2 != 0) {
    value = *(int *)(value2 + 0x38);
    if (value != 0) {
      *(int *)(value + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x3a8;
      *(undefined2 *)(value + 0xa6) = 0;
      *(undefined2 *)(value + 0xe) = 0x421;
      dataCursor = (undefined4 *)(entry + 0x108);
      dataCursor2 = (undefined4 *)(value + 0x108);
      for (value4 = 0xf; value4 != 0; value4 = value4 + -1) {
        *dataCursor2 = *dataCursor;
        dataCursor = dataCursor + 1;
        dataCursor2 = dataCursor2 + 1;
      }
      shortValue = *(short *)(entry + 0xa2);
      value4 = 0;
      value6 = &DAT_004c2caa;
      do {
        value3 = CreateEntityEntitySceneObject((uint *)value2,value4 + 10);
        if (value3 != 0) {
          *(int *)(value3 + 0x18) = (int)value6[1] + *(int *)(value + 0x18);
          *(int *)(value3 + 0x14) =
               *(int *)(value + 0x14) -
               ((int)(short)(&g_SinCosTable12Bit)[(int)shortValue - 0x400U & 0xfff] * (int)*value6 >> 0xc
               );
          *(int *)(value3 + 0x1c) =
               *(int *)(value + 0x1c) -
               ((int)(short)(&g_SinCosTable12Bit)[(int)shortValue & 0xfff] * (int)*value6 >> 0xc);
          *(char *)(value3 + 0x74) = (char)value6[-1];
          value5 = g_WorldEntitySceneObjectArrayBase + 0x3a8;
          *(undefined2 *)(value3 + 0xc) = 0x204c;
          *(int *)(value3 + 0x10) = value5;
          *(undefined2 *)(value3 + 0xe) = 0x1021;
        }
        value6 = value6 + 4;
        value4 = value4 + 1;
      } while ((int)value6 < 0x4c2cda);
      CEntities::SpawnSmashableFlyingDebris
                (*(int *)(value + 0x14) + 0x19,*(int *)(value + 0x18) + -0x154,
                 *(undefined4 *)(value + 0x1c),0x8000,0x2010,0x400);
      CEntities::SpawnSmashableDebrisShardBurst
                (*(int *)(value + 0x14) + 0x1e,*(int *)(value + 0x18) + -0x32,
                 *(undefined4 *)(value + 0x1c),0x8000,0x2011,4,8,0x400);
    }
    if (*(short *)(value2 + 0x44) != 0) {
      CEntities::ReleaseEntityToFreeList((byte *)value2);
    }
  }
  return;
}

