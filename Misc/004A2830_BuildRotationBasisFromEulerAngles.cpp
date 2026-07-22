#include "tarzan_ghidra_types.hpp"

// Address: 0x004A2830
// Label: BuildRotationBasisFromEulerAngles
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void BuildRotationBasisFromEulerAngles(short *arg1,undefined2 *arg2)

{
  short shortValue;
  short shortValue2;
  short shortValue3;
  int value2;
  int value3;
  int value4;
  int value5;
  short shortValue4;
  short shortValue5;
  int value;
  
  value2 = (int)(short)(&g_SinCosTable12Bit)[(int)*arg1 - 0x400U & 0xfff];
  value3 = (int)(short)(&g_SinCosTable12Bit)[(int)*arg1 & 0xfff];
  shortValue5 = (&g_SinCosTable12Bit)[(int)arg1[1] - 0x400U & 0xfff];
  shortValue = (&g_SinCosTable12Bit)[(int)arg1[1] & 0xfff];
  value4 = (int)shortValue;
  shortValue2 = (&g_SinCosTable12Bit)[(int)arg1[2] & 0xfff];
  value = (int)shortValue2;
  shortValue3 = (&g_SinCosTable12Bit)[(int)arg1[2] - 0x400U & 0xfff];
  value5 = (int)shortValue3;
  *arg2 = (short)(value * value4 >> 0xc);
  arg2[3] = (short)(value5 * value4 >> 0xc);
  arg2[6] = -shortValue5;
  shortValue4 = (short)(value * shortValue5 >> 0xc);
  arg2[2] = shortValue4;
  shortValue5 = (short)(value5 * shortValue5 >> 0xc);
  arg2[5] = shortValue5;
  if (*arg1 == 0) {
    arg2[4] = shortValue2;
    arg2[1] = -shortValue3;
    arg2[7] = 0;
    arg2[8] = shortValue;
    return;
  }
  arg2[1] = (short)(shortValue4 * value2 - value5 * value3 >> 0xc);
  arg2[2] = (short)(shortValue4 * value3 + value5 * value2 >> 0xc);
  arg2[4] = (short)(shortValue5 * value2 + value * value3 >> 0xc);
  arg2[5] = (short)(shortValue5 * value3 - value * value2 >> 0xc);
  arg2[7] = (short)(value4 * value2 >> 0xc);
  arg2[8] = (short)(value4 * value3 >> 0xc);
  return;
}

