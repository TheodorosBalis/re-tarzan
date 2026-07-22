#include "tarzan_ghidra_types.hpp"

// Address: 0x004A2540
// Label: BuildBasisMatrixFromEulerAngles
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void BuildBasisMatrixFromEulerAngles(short *arg1,short *arg2)

{
  short shortValue;
  short shortValue2;
  short shortValue3;
  short shortValue4;
  int value2;
  int value3;
  int value4;
  int value5;
  short shortValue5;
  int value;
  
  shortValue = (&g_SinCosTable12Bit)[(int)*arg1 - 0x400U & 0xfff];
  value5 = (int)shortValue;
  shortValue2 = (&g_SinCosTable12Bit)[(int)*arg1 & 0xfff];
  value = (int)shortValue2;
  shortValue3 = (&g_SinCosTable12Bit)[(int)arg1[1] & 0xfff];
  value4 = (int)shortValue3;
  shortValue4 = (&g_SinCosTable12Bit)[(int)arg1[1] - 0x400U & 0xfff];
  value2 = (int)(short)(&g_SinCosTable12Bit)[(int)arg1[2] & 0xfff];
  value3 = (int)(short)(&g_SinCosTable12Bit)[(int)arg1[2] - 0x400U & 0xfff];
  arg2[5] = (short)(-(value4 * value5) >> 0xc);
  arg2[2] = shortValue4;
  arg2[8] = (short)(value4 * value >> 0xc);
  shortValue5 = (short)(shortValue4 * value5 >> 0xc);
  arg2[3] = shortValue5;
  shortValue4 = (short)(-(shortValue4 * value) >> 0xc);
  arg2[6] = shortValue4;
  if (arg1[2] == 0) {
    arg2[4] = shortValue2;
    *arg2 = shortValue3;
    arg2[1] = 0;
    arg2[7] = shortValue;
    return;
  }
  *arg2 = (short)(value2 * value4 >> 0xc);
  arg2[1] = (short)(-(value3 * value4) >> 0xc);
  arg2[4] = (short)(value2 * value - shortValue5 * value3 >> 0xc);
  arg2[3] = (short)(shortValue5 * value2 + value3 * value >> 0xc);
  arg2[7] = (short)(value2 * value5 - shortValue4 * value3 >> 0xc);
  arg2[6] = (short)(shortValue4 * value2 + value3 * value5 >> 0xc);
  return;
}

