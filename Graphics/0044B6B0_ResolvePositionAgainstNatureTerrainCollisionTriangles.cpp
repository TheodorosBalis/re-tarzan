#include "tarzan_ghidra_types.hpp"

// Address: 0x0044B6B0
// Label: ResolvePositionAgainstNatureTerrainCollisionTriangles
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint ResolvePositionAgainstNatureTerrainCollisionTriangles(int arg1,int *arg2,int *arg3)

{
  byte flagByte;
  bool flagByte2;
  bool flagByte3;
  int value3;
  int value4;
  int value5;
  undefined4 *dataCursor;
  uint value9;
  byte *value6;
  int value;
  short *value7;
  int value2;
  short *value8;
  int localState12;
  int localState11;
  int localState10;
  int localState9;
  int localState7;
  short localState6;
  short localState5;
  short localState4;
  int localState3;
  int localState2;
  int localState;
  int localState14;
  int localState13;
  int localState8;
  
  localState7 = *(int *)(arg1 + 0x40);
  value9 = 0;
  dataCursor = (undefined4 *)(arg1 + 0x44);
  localState12 = -1;
  localState11 = 0x7fffffff;
  localState9 = 0;
  flagByte2 = false;
  flagByte3 = false;
  _g_NatureTerrainCollisionHitCount = 0;
  _g_NatureTerrainCollisionBestTriangle = 0;
  g_NatureTerrainCollisionBestDistance = 0;
  g_NatureTerrainCollisionResolveDeltaX = 0;
  g_NatureTerrainCollisionResolveDeltaY = 0;
  _g_NatureTerrainCollisionResolveDeltaZ = 0;
  g_NatureTerrainCollisionBestSurfaceFlags = 0;
  g_NatureTerrainHazardContactFlag = 0;
  if (localState7 != 0) {
    do {
      value8 = (short *)*dataCursor;
      dataCursor = dataCursor + 5;
      value7 = value8 + 8;
      for (value3 = (int)*value8; value3 != 0; value3 = value3 + -1) {
        value4 = ResolveSceneAssetPointerEntry(value7);
        if (((((value4 != 0) && (*(int *)(value4 + 0x24) != 0)) &&
             (value = *arg2, *(int *)(value7 + 4) + -0x100 < value)) &&
            ((value5 = arg2[2], *(int *)(value7 + 8) + -0x100 < value5 &&
             (value < *(int *)(value7 + 10) + 0x100)))) &&
           (value5 < *(int *)(value7 + 0xe) + 0x100)) {
          localState3 = value - *(int *)(value7 + 0x10);
          localState2 = arg2[1] - *(int *)(value7 + 0x12);
          localState = value5 - *(int *)(value7 + 0x14);
          value7[0x30] = 0;
          value7[0x31] = 0;
          value7[0x32] = 0;
          value7[0x33] = 0;
          value7[0x34] = 0;
          value7[0x35] = 0;
          TransformVectorByBasis(value7 + 0x26,&localState3,&localState3);
          value8 = (short *)(*(int *)(value4 + 0xc) + 0x4c + value4);
          value = *(int *)(value4 + 0x24) + 0x24 + value4;
          value6 = (byte *)(*(int *)(value4 + 0x10) + value4 + 0x11);
          flagByte = *value6;
          localState14 = localState3;
          localState13 = localState2;
          localState8 = localState;
          value4 = localState;
          while (value9 = (uint)flagByte, value9 != 0xff) {
            for (; value9 != 0; value9 = value9 - 1) {
              if ((value8[0xb] & 0x500U) != 0) {
                localState10 = (int)*value8;
                if ((((((localState10 + -0x100 < localState3) || (value8[4] + -0x100 < localState3)) ||
                      (value8[8] + -0x100 < localState3)) &&
                     (((localState3 < localState10 + 0x100 || (localState3 < value8[4] + 0x100)) ||
                      (localState3 < value8[8] + 0x100)))) &&
                    (((value8[2] + -0x100 < value4 || (value8[6] + -0x100 < value4)) ||
                     (value8[10] + -0x100 < value4)))) &&
                   (((value4 < value8[2] + 0x100 || (value4 < value8[6] + 0x100)) ||
                    (value4 < value8[10] + 0x100)))) {
                  if (*(short *)(value + 0x12) == 0) {
                    localState12 = localState9 >> 8;
                  }
                  else {
                    localState10 = (int)*value8;
                    value5 = (((value8[1] - localState13) * (int)*(short *)(value + 0x12) -
                             *(short *)(value + 0x10) * localState14) -
                            *(short *)(value + 0x14) * localState8) +
                            (int)*(short *)(value + 0x14) * (int)value8[2] +
                            *(short *)(value + 0x10) * localState10;
                    value4 = localState;
                    if ((((-1 < value5) || (*(short *)(value + 0x12) < 1)) &&
                        ((value5 < 1 || (-1 < *(short *)(value + 0x12))))) &&
                       (localState9 = (value5 * 0x100) / (int)*(short *)(value + 0x12), -1 < localState9))
                    {
                      localState12 = localState9 >> 8;
                    }
                  }
                }
                value5 = localState12;
                if ((localState12 != -1) && (localState12 < localState11)) {
                  localState12 = -1;
                  localState11 = value5;
                }
                value5 = localState2 + 0x100;
                if ((((value8[1] <= value5) || (value8[5] <= value5)) || (value8[9] <= value5)) &&
                   (((value5 = localState2 + -0x100, value5 <= value8[1] || (value5 <= value8[5])) ||
                    (value5 <= value8[9])))) {
                  value5 = value4 + 0x100;
                  if ((((((value8[2] <= value5) || (value8[6] <= value5)) || (value8[10] <= value5))
                       && (((value5 = localState3 + -0x100, value5 <= localState10 || (value5 <= value8[4]))
                           || (value5 <= value8[8])))) &&
                      (((value5 = value4 + -0x100, value5 <= value8[2] || (value5 <= value8[6])) ||
                       (value5 <= value8[10])))) &&
                     (((value5 = localState3 + 0x100, localState10 <= value5 || (value8[4] <= value5)) ||
                      (value8[8] <= value5)))) {
                    g_NatureTerrainCollisionBestDistance = g_NatureTerrainCollisionBestDistance + 1;
                    value5 = ComputePointToTriangleDistanceSquared(&localState3,value8);
                    value4 = localState;
                    if (value5 < 0x10001) {
                      value7[0x20] = 0;
                      value7[0x21] = 0;
                      value7[0x22] = 0;
                      value7[0x23] = 0;
                      value7[0x24] = 0;
                      value7[0x25] = 0;
                      TransformShortVectorByBasis(value7 + 0x16,value + 0x10,&localState6);
                      value4 = SqrtToInt(value5);
                      value2 = 0x100 - (value4 >> 6);
                      value4 = localState6 * value2 >> 0xd;
                      *arg3 = *arg3 + value4;
                      value5 = localState5 * value2 >> 0xc;
                      arg3[1] = arg3[1] + value5;
                      value2 = localState4 * value2 >> 0xd;
                      arg3[2] = arg3[2] + value2;
                      localState3 = localState3 + value4;
                      localState2 = localState2 + value5;
                      localState = localState + value2;
                      if ((*(byte *)((int)value8 + 0x17) & 4) != 0) {
                        g_NatureTerrainCollisionResolveDeltaX = 1;
                        if (0xb4 < *value8 - localState3) {
                          flagByte2 = true;
                        }
                        if (*value8 - localState3 < -0xb4) {
                          flagByte3 = true;
                        }
                      }
                      value4 = localState;
                      if ((*(byte *)((int)value8 + 0x17) & 2) != 0) {
                        g_NatureTerrainCollisionBestSurfaceFlags = 1;
                      }
                    }
                  }
                }
              }
              value8 = value8 + 4;
              value = value + 8;
            }
            value6 = value6 + 2;
            value8 = value8 + 8;
            value = value + 0x10;
            flagByte = *value6;
          }
        }
        value7 = value7 + 0x3a;
      }
      localState7 = localState7 + -1;
    } while (localState7 != 0);
    value9 = (uint)(g_NatureTerrainCollisionResolveDeltaX != 0);
    if (localState11 < 0x101) {
      localState11 = 0x100;
    }
    if (g_NatureTerrainCollisionResolveDeltaY != 0) {
      value9 = value9 | 4;
    }
    if (g_NatureTerrainCollisionBestSurfaceFlags != 0) {
      value9 = value9 | 8;
    }
    if (flagByte2) {
      value9 = value9 | 0x10;
    }
    if (flagByte3) {
      value9 = value9 | 0x20;
    }
  }
  return localState11 << 0x10 | value9;
}

