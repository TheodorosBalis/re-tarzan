#include "tarzan_ghidra_types.hpp"

// Address: 0x00460B90
// Label: TarzanToTheRescue::PushSceneObjectOutOfCollisionRail
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4
TarzanToTheRescue::PushSceneObjectOutOfCollisionRail
          (int arg1,int *arg2,int arg3,int arg4,int arg5)

{
  int entry;
  int entry4;
  int entry5;
  int *intCursor;
  int entry6;
  int entry7;
  int entry8;
  int *intCursor2;
  int entry9;
  int entry2;
  int entry3;
  int localState2;
  int localState;
  
  entry8 = arg5 * 4 + 0x18;
  localState2 = 0x7fffffff;
  entry6 = arg4 + 0x80;
  entry8 = *(int *)(entry8 + *(int *)(g_NatureTerrainDataBlock + 0x14) + g_NatureTerrainDataBlock) +
          *(int *)(g_NatureTerrainDataBlock + 0x14) + entry8 + g_NatureTerrainDataBlock;
  if (entry8 != 0) {
    entry7 = 0;
    arg4 = 0;
    localState = 0;
    if (0 < *(int *)(entry8 + 0x38)) {
      entry = *arg2;
      entry4 = arg2[2];
      intCursor = (int *)(entry8 + 0x4c);
      intCursor2 = (int *)(entry8 + 100);
      do {
        entry5 = *intCursor2;
        entry2 = entry - intCursor[-1];
        entry9 = ((short)(&g_SinCosTable12Bit)[-entry5 & 0xfff] * entry2 >> 0xc) -
                ((int)(short)(&g_SinCosTable12Bit)[-entry5 - 0x400U & 0xfff] * (entry4 - intCursor[1]) >>
                0xc);
        if ((-1 < entry9) && (entry9 <= entry6)) {
          entry3 = intCursor[2] - intCursor[-1];
          entry9 = intCursor[5] * intCursor[5] >> 0xc;
          if (entry9 != 0) {
            arg4 = ((intCursor[3] - *intCursor) * (intCursor[3] - *intCursor) +
                       (intCursor[4] - intCursor[1]) * (entry4 - intCursor[1]) + entry3 * entry2) / entry9;
          }
          if ((((0 < arg4) ||
               (entry7 = (intCursor[1] - entry4) * (intCursor[1] - entry4) +
                        (intCursor[-1] - entry) * (intCursor[-1] - entry), entry7 <= entry6 * entry6)) &&
              ((arg4 < 0x1000 ||
               (entry7 = (intCursor[4] - entry4) * (intCursor[4] - entry4) +
                        (intCursor[2] - entry) * (intCursor[2] - entry), entry7 <= entry6 * entry6)))) &&
             (((arg4 < 1 || (0xfff < arg4)) ||
              (entry7 = ((entry3 * arg4 >> 0xc) + intCursor[-1]) - entry,
              entry9 = (((intCursor[4] - intCursor[1]) * arg4 >> 0xc) + intCursor[1]) - entry4,
              entry7 = entry9 * entry9 + entry7 * entry7, entry7 <= entry6 * entry6)))) {
            if (entry7 < 0) {
              entry7 = 0x7fffffff;
            }
            if ((entry7 <= localState2) && (localState2 = entry7, entry7 <= entry6 * entry6)) {
              entry8 = SqrtToInt(entry7);
              *(int *)(arg3 + 4) = entry5;
              entry6 = (entry6 - (entry8 >> 6)) + 8;
              entry8 = (short)(&g_SinCosTable12Bit)[-entry5 & 0xfff] * entry6 >> 0xc;
              entry6 = (short)(&g_SinCosTable12Bit)[-entry5 + 0x400U & 0xfff] * entry6 >> 0xc;
              *(int *)(arg1 + 0x14) = *(int *)(arg1 + 0x14) + entry8;
              *(int *)(arg1 + 0x1c) = *(int *)(arg1 + 0x1c) + entry6;
              *arg2 = *arg2 + entry8;
              arg2[2] = arg2[2] + entry6;
              return 1;
            }
          }
        }
        localState = localState + 1;
        intCursor2 = intCursor2 + 0xe;
        intCursor = intCursor + 0xe;
        if (*(int *)(entry8 + 0x38) <= localState) {
          return 0;
        }
      } while( true );
    }
  }
  return 0;
}

