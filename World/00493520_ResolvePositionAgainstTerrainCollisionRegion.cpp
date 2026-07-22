#include "tarzan_ghidra_types.hpp"

// Address: 0x00493520
// Label: ResolvePositionAgainstTerrainCollisionRegion
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int ResolvePositionAgainstTerrainCollisionRegion
              (undefined4 *arg1,int *arg2,int arg3,int *arg4)

{
  short shortValue;
  int value;
  uint value8;
  int value2;
  int value3;
  int value4;
  int value5;
  uint value9;
  short *value6;
  undefined4 value7;
  int localState;
  int localState2 [2];
  
  localState2[0] = arg1[1];
  value5 = localState2[0] + 0x3c;
  localState = *(int *)(localState2[0] + 0x38);
  arg1[2] = 0;
  do {
    if (localState == 0) {
      return 0;
    }
    localState = localState + -1;
    value4 = (int)(short)(&g_SinCosTable12Bit)[*(uint *)(value5 + 0x28) & 0xfff];
    value2 = (int)(short)(&g_SinCosTable12Bit)[*(uint *)(value5 + 0x28) - 0x400 & 0xfff];
    value8 = *arg2 - *(int *)(value5 + 0xc);
    value9 = arg2[2] - *(int *)(value5 + 0x14);
    value = ((int)(value8 * value4) >> 0xc) + ((int)(value9 * value2) >> 0xc);
    if (value < arg3) {
      value3 = (int)(value9 * value4 - value8 * value2) >> 0xc;
      if (value3 < 0) {
        if (((-1 < value) &&
            ((int)((value8 ^ (int)value8 >> 0x1f) - ((int)value8 >> 0x1f)) <= arg3 * 2)) &&
           (((int)((value9 ^ (int)value9 >> 0x1f) - ((int)value9 >> 0x1f)) <= arg3 * 2 &&
            ((int)(value9 * value9 + value8 * value8) < arg3 * arg3)))) {
          value8 = GetAngleFromXZVector12Bit(value9,value8);
          shortValue = (&g_SinCosTable12Bit)[value8 - 0x400 & 0xfff];
          *arg4 = ((int)(short)(&g_SinCosTable12Bit)[value8 & 0xfff] * (arg3 + 2) >> 0xc) +
                     *(int *)(value5 + 0xc);
          arg4[2] = *(int *)(value5 + 0x14) + ((int)shortValue * (arg3 + 2) >> 0xc);
          return value5;
        }
      }
      else if (*(int *)(value5 + 0x24) < value3) {
        if (-1 < value) {
          value8 = arg2[2] - *(int *)(value5 + 0x20);
          value9 = *arg2 - *(int *)(value5 + 0x18);
          if ((((int)((value9 ^ (int)value9 >> 0x1f) - ((int)value9 >> 0x1f)) <= arg3 * 2) &&
              ((int)((value8 ^ (int)value8 >> 0x1f) - ((int)value8 >> 0x1f)) <= arg3 * 2)) &&
             ((int)(value8 * value8 + value9 * value9) < arg3 * arg3)) {
            value8 = GetAngleFromXZVector12Bit(value8,value9);
            if (localState == 0) {
              value7 = *(undefined4 *)(localState2[0] + 100);
            }
            else {
              value7 = *(undefined4 *)(value5 + 0x60);
            }
            value = GetWrappedSignedAngleDelta12Bit(value7,value8);
            if (value < 0) {
              shortValue = (&g_SinCosTable12Bit)[value8 - 0x400 & 0xfff];
              *arg4 = ((int)(short)(&g_SinCosTable12Bit)[value8 & 0xfff] * (arg3 + 2) >> 0xc) +
                         *(int *)(value5 + 0x18);
              arg4[2] = *(int *)(value5 + 0x20) + ((int)shortValue * (arg3 + 2) >> 0xc);
              return value5;
            }
          }
        }
      }
      else if ((*(uint *)(value5 + 0x34) & 3) == 0) {
        if (-1 < value) {
          arg3 = arg3 + (2 - value);
          arg4[2] = (value2 * arg3 >> 0xc) + arg2[2];
          *arg4 = (value4 * arg3 >> 0xc) + *arg2;
          return value5;
        }
      }
      else {
        value6 = (short *)(value5 + 0x30);
        if ((*(uint *)(value5 + 0x34) & 2) == 0) {
          value6 = (short *)(value5 + 0x2c);
        }
        value2 = *value6 * 4 + 4;
        value4 = *(int *)(value2 + g_CollisionSurfaceTable) + value2 + g_CollisionSurfaceTable;
        value2 = value4 + 0x30 + value6[1] * 0x1c;
        if (value < 0x11) {
          *arg1 = 1;
          arg1[2] = (int)*value6;
          arg1[3] = value2;
          arg1[1] = *(undefined4 *)(value2 + 0xc);
          ResolveJungleSurfaceCoordToPointAndAngles
                    (value4,*(undefined4 *)(value2 + 0xc),arg4,localState2);
          return 0;
        }
      }
    }
    value5 = value5 + 0x38;
  } while( true );
}

