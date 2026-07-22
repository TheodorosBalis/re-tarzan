#include "tarzan_ghidra_types.hpp"

// Address: 0x0048BEE0
// Label: CEntities::SpawnPowerFruitExplosionDebrisCloud
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::SpawnPowerFruitExplosionDebrisCloud(int entry)

{
  short shortValue;
  short shortValue2;
  int value;
  int value2;
  uint value6;
  int value3;
  int value4;
  int value5;
  ushort *dataCursor;
  short *value7;
  int *localState;
  
  value = CEntities::SpawnEntityByTypeAtPosition
                    (*(undefined4 *)(entry + 0x14),*(undefined4 *)(entry + 0x18),
                     *(undefined4 *)(entry + 0x1c),0x12,0x11);
  value2 = g_WorldEntitySceneObjectArrayBase;
  if (value != 0) {
    value3 = *(int *)(value + 0x38);
    shortValue2 = *(short *)(entry + 0xa2);
    if (value3 != 0) {
      *(undefined2 *)(value3 + 0xe) = 0x1000;
      *(undefined2 *)(value3 + 0xa6) = 3;
      *(int *)(value3 + 0x10) = value2 + 0x3a8;
      entry = 0;
      value7 = &DAT_0051184a;
      do {
        value2 = CreateEntityEntitySceneObject((uint *)value,entry + 10);
        if (value2 != 0) {
          *(int *)(value2 + 0x18) = (int)value7[1] + *(int *)(value3 + 0x18);
          *(int *)(value2 + 0x14) =
               *(int *)(value3 + 0x14) -
               ((int)(short)(&g_SinCosTable12Bit)[(int)shortValue2 - 0x400U & 0xfff] * (int)*value7 >>
               0xc);
          *(int *)(value2 + 0x1c) =
               *(int *)(value3 + 0x1c) -
               ((int)(short)(&g_SinCosTable12Bit)[(int)shortValue2 & 0xfff] * (int)*value7 >> 0xc);
          shortValue = value7[-1];
          *(char *)(value2 + 0x74) = (char)shortValue;
          value5 = g_WorldEntitySceneObjectArrayBase + 0x3a8;
          *(undefined2 *)(value2 + 0xc) = 0x204c;
          *(int *)(value2 + 0x10) = value5;
          if ((char)shortValue != '\0') {
            *(ushort *)(value2 + 0xe) = *(ushort *)(value2 + 0xe) & 0x7fff;
          }
          *(ushort *)(value2 + 0xe) = *(ushort *)(value2 + 0xe) | 0x1421;
          *(undefined4 *)(value2 + 0x20) = 0x700;
          *(undefined4 *)(value2 + 0x24) = 0x600;
          value5 = RandomModulo(0x600);
          *(int *)(value2 + 0x28) = value5 + 0x800;
          *(undefined4 *)(value2 + 0x30) = 0;
        }
        value7 = value7 + 4;
        entry = entry + 1;
      } while ((int)value7 < 0x511862);
      value2 = CEntities::CreateEntityAttachment(value,0x138,0x10000000);
      if (((value2 != 0) &&
          (value = CEntities::CreateChildEntitySceneObjectArrayAttachment(value,1,0x10), value != 0)
          ) && (entry = 0, *(short *)(value + 0xc) != 0)) {
        value7 = (short *)(value2 + 0x110);
        dataCursor = (ushort *)(value + 0x12);
        localState = (int *)(value2 + 0x14);
        do {
          *dataCursor = *dataCursor & 0x6fff | 0x1000;
          *(undefined1 *)(value2 + 0xfc + entry) = 0;
          shortValue2 = RandomModulo(4);
          *value7 = shortValue2 + 1;
          dataCursor[-1] = 0x2027;
          *(int *)(dataCursor + 1) = g_WorldEntitySceneObjectArrayBase + 0x3a8;
          shortValue2 = RandomModulo(8);
          *value7 = shortValue2 + -5;
          value6 = RandomModulo(0x1000);
          value3 = RandomModulo(0x2aa);
          value5 = RandomModulo(0x10);
          value4 = RandomModulo(0x20);
          dataCursor = dataCursor + 0x14;
          localState[-2] = (int)(short)(&g_SinCosTable12Bit)[value6 - 0x400 & 0xfff] * (value5 + 0x30) >>
                        0xc;
          *localState = (int)(short)(&g_SinCosTable12Bit)[value6 & 0xfff] * (value5 + 0x30) >> 0xc;
          localState[-1] = -((int)(short)(&g_SinCosTable12Bit)[value3 + 0x155U & 0xfff] * (value4 + 0x40)
                         ) >> 0xc;
          entry = entry + 1;
          value7 = value7 + 1;
          localState = localState + 3;
        } while (entry < (int)(uint)*(ushort *)(value + 0xc));
      }
    }
  }
  return;
}

