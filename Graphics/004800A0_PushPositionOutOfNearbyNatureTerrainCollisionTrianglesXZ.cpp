#include "tarzan_ghidra_types.hpp"

// Address: 0x004800A0
// Label: PushPositionOutOfNearbyNatureTerrainCollisionTrianglesXZ
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4
PushPositionOutOfNearbyNatureTerrainCollisionTrianglesXZ(int arg1,int *arg2,int *arg3)

{
  byte flagByte;
  int *intCursor;
  int value;
  int value2;
  int value3;
  byte *value5;
  undefined4 *dataCursor;
  undefined4 value8;
  int value4;
  short *value6;
  short *value7;
  undefined4 localState4;
  int localState3;
  short localState2 [2];
  short localState;
  int localState7;
  int localState6;
  int localState5;
  
  intCursor = arg3;
  value8 = 0;
  localState3 = *(int *)(arg1 + 0x40);
  dataCursor = (undefined4 *)(arg1 + 0x44);
  localState4 = 0;
  if (localState3 != 0) {
    do {
      value7 = (short *)*dataCursor;
      dataCursor = dataCursor + 5;
      value6 = value7 + 8;
      for (value = (int)*value7; value != 0; value = value + -1) {
        value2 = ResolveSceneAssetPointerEntry(value6);
        if ((((value2 != 0) && (*(int *)(value2 + 0x24) != 0)) &&
            (value3 = *arg2, *(int *)(value6 + 4) + -200 < value3)) &&
           (((value4 = arg2[2], *(int *)(value6 + 8) + -200 < value4 &&
             (value3 < *(int *)(value6 + 10) + 200)) && (value4 < *(int *)(value6 + 0xe) + 200)))) {
          localState7 = value3 - *(int *)(value6 + 0x10);
          localState6 = arg2[1] - *(int *)(value6 + 0x12);
          localState5 = value4 - *(int *)(value6 + 0x14);
          value6[0x30] = 0;
          value6[0x31] = 0;
          value6[0x32] = 0;
          value6[0x33] = 0;
          value6[0x34] = 0;
          value6[0x35] = 0;
          TransformVectorByBasis(value6 + 0x26,&localState7,&localState7);
          value7 = (short *)(*(int *)(value2 + 0xc) + 0x4c + value2);
          value5 = (byte *)(*(int *)(value2 + 0x10) + value2 + 0x11);
          value2 = *(int *)(value2 + 0x24) + 0x24 + value2;
          flagByte = *value5;
          while (arg3 = (int *)(uint)flagByte, arg3 != (int *)0xff) {
            if (arg3 != (int *)0x0) {
              arg1 = value2 + 0x10;
              value2 = value2 + (int)arg3 * 8;
              do {
                if ((value7[0xb] & 0x500U) != 0) {
                  value3 = localState6 + 200;
                  if ((((value7[1] <= value3) || (value7[5] <= value3)) || (value7[9] <= value3)) &&
                     (((value3 = localState6 + -200, value3 <= value7[1] || (value3 <= value7[5])) ||
                      (value3 <= value7[9])))) {
                    value3 = localState5 + 200;
                    if (((value7[2] <= value3) || (value7[6] <= value3)) || (value7[10] <= value3))
                    {
                      value3 = localState7 + -200;
                      if (((((value3 <= *value7) || (value3 <= value7[4])) || (value3 <= value7[8]))
                          && (((value3 = localState5 + -200, value3 <= value7[2] || (value3 <= value7[6])
                               ) || (value3 <= value7[10])))) &&
                         ((((value3 = localState7 + 200, *value7 <= value3 || (value7[4] <= value3)) ||
                           (value7[8] <= value3)) &&
                          (value3 = ComputePointToTriangleDistanceSquared(&localState7,value7),
                          value3 < 0x9c41)))) {
                        value6[0x20] = 0;
                        value6[0x21] = 0;
                        value6[0x22] = 0;
                        value6[0x23] = 0;
                        value6[0x24] = 0;
                        value6[0x25] = 0;
                        TransformShortVectorByBasis(value6 + 0x16,arg1,localState2);
                        value3 = SqrtToInt(value3);
                        value4 = 200 - (value3 >> 6);
                        localState4 = 1;
                        value3 = localState2[0] * value4 >> 0xc;
                        *intCursor = *intCursor + value3;
                        value4 = localState * value4 >> 0xc;
                        localState7 = localState7 + value3;
                        localState5 = localState5 + value4;
                        intCursor[2] = intCursor[2] + value4;
                      }
                    }
                  }
                }
                value7 = value7 + 4;
                arg1 = arg1 + 8;
                arg3 = (int *)((int)arg3 - 1);
              } while (arg3 != (int *)0x0);
            }
            value5 = value5 + 2;
            value7 = value7 + 8;
            value2 = value2 + 0x10;
            flagByte = *value5;
          }
        }
        value6 = value6 + 0x3a;
        value8 = localState4;
      }
      localState3 = localState3 + -1;
    } while (localState3 != 0);
    return value8;
  }
  return 0;
}

