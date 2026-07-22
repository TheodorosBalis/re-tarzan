#include "tarzan_ghidra_types.hpp"

// Address: 0x0042F770
// Label: CEntities::UpdateSmashableDebrisShardBurst
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::UpdateSmashableDebrisShardBurst(int entry)

{
  Entity *entity = (Entity *)entry;
  undefined4 value4;
  uint value5;
  int value;
  int value2;
  int value3;
  undefined2 *dataCursor;
  uint *dataCursor2;
  int localState;
  
  value = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
  if ((value != 0) && (*(int *)(value + 0x2c) != 0)) {
    dataCursor = (undefined2 *)(*(int *)(value + 0x2c) + 0x10);
    localState = 0;
    if (0 < *(int *)(value + 0x14)) {
      dataCursor2 = (uint *)(value + 0x54);
      do {
        if (dataCursor2[-1] == 0) {
          value4 = *(undefined4 *)(value + 0x524);
          *dataCursor2 = (int)(0x1000 / (longlong)*(int *)(value + 0x10)) * localState;
          value2 = RandomModulo(*(undefined4 *)(value + 0x24));
          dataCursor2[1] = -(value2 + *(int *)(value + 0x24));
          value2 = RandomModulo(*(undefined4 *)(value + 0x28));
          dataCursor2[2] = value2 + *(int *)(value + 0x20);
          value2 = RandomModulo(value4);
          value3 = RandomModulo(value4);
          *(int *)(dataCursor + 4) = value2 - value3;
          value2 = RandomModulo(value4);
          value3 = RandomModulo(value4);
          *(int *)(dataCursor + 8) = value2 - value3;
          value2 = RandomModulo(value4);
          *(int *)(dataCursor + 6) = -value2;
          *(undefined4 *)(dataCursor + 2) = *(undefined4 *)(entity->sceneObjects + 0x10);
          *dataCursor = *(undefined2 *)(entity->sceneObjects + 0xc);
          if (*(int *)(value + 0x52c) == 0) {
            dataCursor[1] = 0x9800;
          }
          if (*(int *)(value + 0x52c) == 1) {
            dataCursor[1] = 0x9c21;
            *(undefined4 *)(dataCursor + 0x12) = 0x1000;
          }
          value5 = dataCursor2[2];
          dataCursor2[3] = (int)((int)(short)(&g_SinCosTable12Bit)[*dataCursor2 - 0x400 & 0xfff] * value5) >>
                      0xd;
          dataCursor2[6] = (int)((int)(short)(&g_SinCosTable12Bit)[*dataCursor2 & 0xfff] * value5) >> 0xd;
          dataCursor2[4] = (int)((int)(short)(&g_SinCosTable12Bit)[dataCursor2[1] - 0x400 & 0xfff] * value5) >>
                      0xc;
          dataCursor2[5] = dataCursor2[4];
          dataCursor2[-1] = 1;
        }
        if (dataCursor2[-1] == 1) {
          *(uint *)(dataCursor + 4) = *(int *)(dataCursor + 4) - dataCursor2[3];
          *(uint *)(dataCursor + 8) = *(int *)(dataCursor + 8) - dataCursor2[6];
          *(uint *)(dataCursor + 6) = *(int *)(dataCursor + 6) + dataCursor2[4];
          dataCursor2[4] = dataCursor2[4] + 4;
          if (*(int *)(value + 0x34) < *(int *)(dataCursor + 6)) {
            dataCursor[1] = dataCursor[1] & 0x7fff;
            dataCursor2[-1] = 8;
          }
        }
        localState = localState + 1;
        dataCursor2 = dataCursor2 + 0xd;
        dataCursor = dataCursor + 0x14;
      } while (localState < *(int *)(value + 0x14));
    }
    *(int *)(entity->sceneObjects + 0xa8) =
         *(int *)(entity->sceneObjects + 0xa8) - *(int *)(value + 0x38);
    *(int *)(entity->sceneObjects + 0xac) =
         *(int *)(entity->sceneObjects + 0xac) - *(int *)(value + 0x38);
    *(int *)(entity->sceneObjects + 0xb0) =
         *(int *)(entity->sceneObjects + 0xb0) - *(int *)(value + 0x38);
    if (*(int *)(entity->sceneObjects + 0xa8) < *(int *)(value + 0x3c)) {
      CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
      return;
    }
    value2 = *(int *)(value + 0x10);
    if ((*(int *)(value + 0x14) < value2) &&
       (value3 = *(int *)(value + 0x1c), *(int *)(value + 0x1c) = value3 + -1, value3 == 0)) {
      *(undefined4 *)(value + 0x1c) = *(undefined4 *)(value + 0x18);
      value3 = *(int *)(value + 0x40) + *(int *)(value + 0x14);
      *(int *)(value + 0x14) = value3;
      if (value2 + -1 < value3) {
        *(int *)(value + 0x14) = value2;
      }
    }
  }
  return;
}

