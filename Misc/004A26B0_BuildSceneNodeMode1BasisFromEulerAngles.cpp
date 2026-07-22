#include "tarzan_ghidra_types.hpp"

// Address: 0x004A26B0
// Label: BuildSceneNodeMode1BasisFromEulerAngles
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void BuildSceneNodeMode1BasisFromEulerAngles(short *arg1,short *arg2)

{
  short shortValue;
  short shortValue2;
  short shortValue3;
  int entry2;
  short shortValue4;
  int entry3;
  int entry4;
  int entry5;
  short shortValue5;
  int entry;
  
  shortValue = (&g_SinCosTable12Bit)[(int)*arg1 & 0xfff];
  entry3 = (int)shortValue;
  shortValue5 = (&g_SinCosTable12Bit)[(int)*arg1 - 0x400U & 0xfff];
  shortValue2 = (&g_SinCosTable12Bit)[(int)arg1[1] & 0xfff];
  entry5 = (int)shortValue2;
  shortValue3 = (&g_SinCosTable12Bit)[(int)arg1[1] - 0x400U & 0xfff];
  entry = (int)shortValue3;
  entry4 = (int)(short)(&g_SinCosTable12Bit)[(int)arg1[2] & 0xfff];
  entry2 = (int)(short)(&g_SinCosTable12Bit)[(int)arg1[2] - 0x400U & 0xfff];
  arg2[2] = (short)(entry * entry3 >> 0xc);
  arg2[5] = -shortValue5;
  arg2[8] = (short)(entry5 * entry3 >> 0xc);
  shortValue4 = (short)(entry * shortValue5 >> 0xc);
  arg2[1] = shortValue4;
  shortValue5 = (short)(entry5 * shortValue5 >> 0xc);
  arg2[7] = shortValue5;
  if (arg1[2] == 0) {
    arg2[4] = shortValue;
    arg2[6] = -shortValue3;
    *arg2 = shortValue2;
    arg2[3] = 0;
    return;
  }
  *arg2 = (short)(shortValue4 * entry2 + entry4 * entry5 >> 0xc);
  arg2[1] = (short)(shortValue4 * entry4 - entry2 * entry5 >> 0xc);
  arg2[3] = (short)(entry2 * entry3 >> 0xc);
  arg2[4] = (short)(entry4 * entry3 >> 0xc);
  arg2[6] = (short)(shortValue5 * entry2 - entry4 * entry >> 0xc);
  arg2[7] = (short)(shortValue5 * entry4 + entry2 * entry >> 0xc);
  return;
}

