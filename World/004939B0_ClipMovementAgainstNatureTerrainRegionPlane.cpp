#include "tarzan_ghidra_types.hpp"

// Address: 0x004939B0
// Label: ClipMovementAgainstNatureTerrainRegionPlane
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4
ClipMovementAgainstNatureTerrainRegionPlane
          (int arg1,int *arg2,int *arg3,uint arg4,int *arg5)

{
  int value;
  int value2;
  int value3;
  uint value9;
  int value4;
  int value5;
  int value6;
  int value7;
  int value8;
  
  value = (int)(short)(&g_SinCosTable12Bit)[*(uint *)(arg1 + 0x28) & 0xfff];
  value6 = (int)(short)(&g_SinCosTable12Bit)[*(uint *)(arg1 + 0x28) - 0x400 & 0xfff];
  value8 = *arg3 - *(int *)(arg1 + 0xc);
  value2 = arg3[2] - *(int *)(arg1 + 0x14);
  value7 = (value8 * value >> 0xc) + (value2 * value6 >> 0xc);
  if (value7 < 0) {
    value3 = *arg2 - *(int *)(arg1 + 0xc);
    value5 = arg2[2] - *(int *)(arg1 + 0x14);
    value4 = (value3 * value >> 0xc) + (value5 * value6 >> 0xc);
    value3 = value5 * value - value3 * value6 >> 0xc;
    if (0 < value4) {
      value7 = value4 - value7;
      value3 = (((value2 * value - value8 * value6 >> 0xc) - value3) * value4) / value7 + value3;
      if (((-1 < value3) && (value3 <= *(int *)(arg1 + 0x24))) &&
         (value = arg2[1], -0x400 < ((arg3[1] - value) * value4) / value7 + value)) {
        value9 = GetAngleFromXZVector12Bit(value + 0x400,value4);
        value = SqrtToInt((arg2[1] - arg3[1]) * (arg2[1] - arg3[1]) + value7 * value7);
        arg5[1] = arg2[1] -
                     ((int)(short)(&g_SinCosTable12Bit)[value9 - 0x400 & 0xfff] * (value >> 6) >> 0xc
                     );
        value = (int)(short)(&g_SinCosTable12Bit)[value9 & 0xfff] * (value >> 6) >> 0xc;
        value2 = (short)(&g_SinCosTable12Bit)[arg4 & 0xfff] * value >> 0xc;
        *arg5 = value2;
        arg5[2] = (short)(&g_SinCosTable12Bit)[arg4 - 0x400 & 0xfff] * value >> 0xc;
        *arg5 = value2 + *arg2;
        arg5[2] = arg5[2] + arg2[2];
        return 1;
      }
    }
  }
  *arg5 = *arg3;
  arg5[1] = arg3[1];
  arg5[2] = arg3[2];
  return 0;
}

