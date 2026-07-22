#include "tarzan_ghidra_types.hpp"

// Address: 0x004064C0
// Label: RockinTheBoat::PushPointAwayFromShipRail
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

uint RockinTheBoat::PushPointAwayFromShipRail(int *arg1)

{
  int value;
  int *intCursor;
  int value3;
  int value4;
  int *intCursor2;
  int value5;
  int *intCursor3;
  uint value7;
  int value6;
  int value2;
  int localState3;
  int localState2;
  int localState;
  
  localState2 = 0x7fffffff;
  value5 = 0;
  value = *(int *)(g_NatureTerrainDataBlock[5] + 0x1c + (int)g_NatureTerrainDataBlock) +
          g_NatureTerrainDataBlock[5] + 0x1c + (int)g_NatureTerrainDataBlock;
  intCursor2 = g_NatureTerrainDataBlock;
  if (value != 0) {
    intCursor = *(int **)(value + 0x38);
    localState3 = 0;
    localState = 0;
    intCursor2 = intCursor;
    if (0 < (int)intCursor) {
      value3 = *arg1;
      value4 = arg1[2];
      intCursor2 = (int *)(value + 0x4c);
      intCursor3 = (int *)(value + 100);
      do {
        value = *intCursor3;
        value7 = -value;
        value2 = value3 - intCursor2[-1];
        value6 = ((short)(&g_SinCosTable12Bit)[value7 & 0xfff] * value2 >> 0xc) -
                ((int)(short)(&g_SinCosTable12Bit)[value7 - 0x400 & 0xfff] * (value4 - intCursor2[1]) >>
                0xc);
        if ((-1 < value6) && (value6 < 0x81)) {
          value6 = intCursor2[2] - intCursor2[-1];
          value7 = intCursor2[5] * intCursor2[5];
          if ((value7 & 0xfffff000) != 0) {
            localState3 = ((intCursor2[3] - *intCursor2) * (intCursor2[3] - *intCursor2) +
                        (intCursor2[4] - intCursor2[1]) * (value4 - intCursor2[1]) + value6 * value2) /
                       ((int)value7 >> 0xc);
          }
          if ((((0 < localState3) ||
               (value5 = (intCursor2[1] - value4) * (intCursor2[1] - value4) +
                        (intCursor2[-1] - value3) * (intCursor2[-1] - value3), value5 < 0x4001)) &&
              ((localState3 < 0x1000 ||
               (value5 = (intCursor2[4] - value4) * (intCursor2[4] - value4) +
                        (intCursor2[2] - value3) * (intCursor2[2] - value3), value5 < 0x4001)))) &&
             (((localState3 < 1 || (0xfff < localState3)) ||
              (value5 = ((value6 * localState3 >> 0xc) + intCursor2[-1]) - value3,
              value6 = (((intCursor2[4] - intCursor2[1]) * localState3 >> 0xc) + intCursor2[1]) - value4,
              value5 = value6 * value6 + value5 * value5, value5 < 0x4001)))) {
            if (value5 < 0) {
              value5 = 0x7fffffff;
            }
            if ((value5 <= localState2) && (localState2 = value5, value5 < 0x4001)) {
              value5 = SqrtToInt(value5);
              value7 = -value;
              value = 0x88 - (value5 >> 6);
              value5 = (short)(&g_SinCosTable12Bit)[value7 + 0x400 & 0xfff] * value;
              *arg1 = *arg1 + ((short)(&g_SinCosTable12Bit)[value7 & 0xfff] * value >> 0xc);
              arg1[2] = arg1[2] + (value5 >> 0xc);
              return CONCAT31((int3)(value5 >> 0x14),1);
            }
          }
        }
        localState = localState + 1;
        intCursor3 = intCursor3 + 0xe;
        intCursor2 = intCursor2 + 0xe;
      } while (localState < (int)intCursor);
    }
  }
  return (uint)intCursor2 & 0xffffff00;
}

