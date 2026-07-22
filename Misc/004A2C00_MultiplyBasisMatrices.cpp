#include "tarzan_ghidra_types.hpp"

// Address: 0x004A2C00
// Label: MultiplyBasisMatrices
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void MultiplyBasisMatrices(short *arg1,short *arg2,undefined4 *arg3)

{
  short shortValue;
  int value10;
  int value11;
  int value12;
  int value13;
  int value14;
  int value15;
  int value16;
  int value17;
  int value;
  int value2;
  int value3;
  int value4;
  int value5;
  int value6;
  int value7;
  int value8;
  int value9;
  
  value13 = (int)arg1[2];
  value17 = (int)*arg1;
  value4 = (int)arg2[3];
  value7 = (int)arg1[1];
  value14 = (int)arg2[6];
  value8 = (int)arg1[5];
  value = (int)arg1[4];
  value9 = (int)arg1[3];
  shortValue = *arg2;
  value2 = (int)arg1[8];
  value3 = (int)arg1[7];
  value10 = (int)arg1[6];
  value5 = (int)arg2[4];
  value11 = (int)arg2[1];
  value15 = (int)arg2[7];
  value6 = (int)arg2[5];
  value16 = (int)arg2[8];
  value12 = (int)arg2[2];
  *arg3 = CONCAT22((short)(value11 * value17 + value5 * value7 + value15 * value13 >> 0xc),
                      (short)(*arg2 * value17 + value4 * value7 + value14 * value13 >> 0xc));
  arg3[1] = CONCAT22((short)(value9 * shortValue + value * value4 + value8 * value14 >> 0xc),
                        (short)(value12 * value17 + value6 * value7 + value16 * value13 >> 0xc));
  arg3[2] = CONCAT22((short)(value12 * value9 + value6 * value + value16 * value8 >> 0xc),
                        (short)(value11 * value9 + value5 * value + value15 * value8 >> 0xc));
  arg3[3] = CONCAT22((short)(value11 * value10 + value5 * value3 + value15 * value2 >> 0xc),
                        (short)(value10 * shortValue + value3 * value4 + value2 * value14 >> 0xc));
  *(short *)(arg3 + 4) = (short)(value12 * value10 + value6 * value3 + value16 * value2 >> 0xc);
  return;
}

