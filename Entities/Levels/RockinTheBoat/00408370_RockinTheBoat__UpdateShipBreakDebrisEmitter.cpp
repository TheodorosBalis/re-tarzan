#include "tarzan_ghidra_types.hpp"

// Address: 0x00408370
// Label: RockinTheBoat::UpdateShipBreakDebrisEmitter
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void RockinTheBoat::UpdateShipBreakDebrisEmitter(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  undefined4 value5;
  uint value6;
  int value2;
  int value3;
  int value4;
  undefined2 *dataCursor;
  uint *dataCursor2;
  int localState;
  
  value = entity->sceneObjects;
  if (((value != 0) &&
      (value2 = CEntities::FindEntityAttachmentByFlags(entry,0x10000000), value2 != 0)) &&
     (dataCursor = (undefined2 *)(*(int *)(value2 + 0x2c) + 0x10), *(int *)(value2 + 0x2c) != 0)) {
    localState = 0;
    if (0 < *(int *)(value2 + 0x14)) {
      dataCursor2 = (uint *)(value2 + 0x54);
      do {
        if (dataCursor2[-1] == 0) {
          value5 = *(undefined4 *)(value2 + 0x524);
          *dataCursor2 = (int)(0x1000 / (longlong)*(int *)(value2 + 0x10)) * localState;
          value3 = RandomModulo(*(undefined4 *)(value2 + 0x24));
          dataCursor2[1] = -(value3 + *(int *)(value2 + 0x24));
          value3 = RandomModulo(*(undefined4 *)(value2 + 0x28));
          dataCursor2[2] = value3 + *(int *)(value2 + 0x20);
          value3 = RandomModulo(value5);
          value4 = RandomModulo(value5);
          *(int *)(dataCursor + 4) = value3 - value4;
          value3 = RandomModulo(value5);
          value4 = RandomModulo(value5);
          *(int *)(dataCursor + 8) = value3 - value4;
          value3 = RandomModulo(value5);
          *(int *)(dataCursor + 6) = -value3;
          *(undefined4 *)(dataCursor + 2) = ((EntitySceneObject *)value)->worldObject;
          *dataCursor = *(undefined2 *)(value + 0xc);
          if (*(int *)(value2 + 0x52c) == 0) {
            dataCursor[1] = 0x9800;
          }
          if (*(int *)(value2 + 0x52c) == 1) {
            dataCursor[1] = 0x9c21;
            *(undefined4 *)(dataCursor + 0x12) = 0x1000;
          }
          value6 = dataCursor2[2];
          dataCursor2[3] = (int)((int)(short)(&g_SinCosTable12Bit)[*dataCursor2 - 0x400 & 0xfff] * value6) >>
                      0xd;
          dataCursor2[6] = (int)((int)(short)(&g_SinCosTable12Bit)[*dataCursor2 & 0xfff] * value6) >> 0xd;
          dataCursor2[4] = (int)((int)(short)(&g_SinCosTable12Bit)[dataCursor2[1] - 0x400 & 0xfff] * value6) >>
                      0xc;
          dataCursor2[5] = dataCursor2[4];
          dataCursor2[-1] = 1;
        }
        if (dataCursor2[-1] == 1) {
          *(uint *)(dataCursor + 4) = *(int *)(dataCursor + 4) - dataCursor2[3];
          *(uint *)(dataCursor + 8) = *(int *)(dataCursor + 8) - dataCursor2[6];
          *(uint *)(dataCursor + 6) = *(int *)(dataCursor + 6) + dataCursor2[4];
          dataCursor2[4] = dataCursor2[4] + 4;
          if (*(int *)(value2 + 0x34) < *(int *)(dataCursor + 6)) {
            dataCursor[1] = dataCursor[1] & 0x7fff;
            dataCursor2[-1] = 8;
          }
        }
        localState = localState + 1;
        dataCursor2 = dataCursor2 + 0xd;
        dataCursor = dataCursor + 0x14;
      } while (localState < *(int *)(value2 + 0x14));
    }
    *(int *)(value + 0xa8) = *(int *)(value + 0xa8) - *(int *)(value2 + 0x38);
    *(int *)(value + 0xac) = *(int *)(value + 0xac) - *(int *)(value2 + 0x38);
    *(int *)(value + 0xb0) = *(int *)(value + 0xb0) - *(int *)(value2 + 0x38);
    if (*(int *)(value + 0xa8) < *(int *)(value2 + 0x3c)) {
      CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
      return;
    }
    value = *(int *)(value2 + 0x10);
    if ((*(int *)(value2 + 0x14) < value) &&
       (value3 = *(int *)(value2 + 0x1c), *(int *)(value2 + 0x1c) = value3 + -1, value3 == 0)) {
      *(undefined4 *)(value2 + 0x1c) = *(undefined4 *)(value2 + 0x18);
      value3 = *(int *)(value2 + 0x40) + *(int *)(value2 + 0x14);
      *(int *)(value2 + 0x14) = value3;
      if (value + -1 < value3) {
        *(int *)(value2 + 0x14) = value;
      }
    }
  }
  return;
}

