#include "tarzan_ghidra_types.hpp"

// Address: 0x004A29A0
// Label: BuildRotationMatrixFromEulerAngles12Bit
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void BuildRotationMatrixFromEulerAngles12Bit(short *arg1,short *arg2)

{
  short shortValue;
  short shortValue2;
  short shortValue3;
  short shortValue4;
  int value2;
  int value3;
  short shortValue5;
  int value4;
  int value5;
  int value;
  
  shortValue4 = (&g_SinCosTable12Bit)[(int)*arg1 - 0x400U & 0xfff];
  shortValue = (&g_SinCosTable12Bit)[(int)*arg1 & 0xfff];
  value4 = (int)shortValue;
  value5 = (int)(short)(&g_SinCosTable12Bit)[(int)arg1[1] & 0xfff];
  value3 = (int)(short)(&g_SinCosTable12Bit)[(int)arg1[1] - 0x400U & 0xfff];
  shortValue2 = (&g_SinCosTable12Bit)[(int)arg1[2] & 0xfff];
  value = (int)shortValue2;
  shortValue3 = (&g_SinCosTable12Bit)[(int)arg1[2] - 0x400U & 0xfff];
  value2 = (int)shortValue3;
  arg2[7] = shortValue4;
  arg2[1] = (short)(-(value2 * value4) >> 0xc);
  arg2[4] = (short)(value * value4 >> 0xc);
  shortValue5 = (short)(value2 * shortValue4 >> 0xc);
  arg2[2] = shortValue5;
  shortValue4 = (short)(-(value * shortValue4) >> 0xc);
  arg2[5] = shortValue4;
  if (arg1[1] == 0) {
    *arg2 = shortValue2;
    arg2[3] = shortValue3;
    arg2[6] = 0;
    arg2[8] = shortValue;
    return;
  }
  *arg2 = (short)(value * value5 - shortValue5 * value3 >> 0xc);
  arg2[2] = (short)(shortValue5 * value5 + value * value3 >> 0xc);
  arg2[5] = (short)(shortValue4 * value5 + value2 * value3 >> 0xc);
  arg2[8] = (short)(value5 * value4 >> 0xc);
  arg2[3] = (short)(value2 * value5 - shortValue4 * value3 >> 0xc);
  arg2[6] = (short)(-(value3 * value4) >> 0xc);
  return;
}

