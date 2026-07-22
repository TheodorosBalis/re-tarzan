#include "tarzan_ghidra_types.hpp"

// Address: 0x004A2B10
// Label: ScaleBasisAxesClamped
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ScaleBasisAxesClamped(short *arg1,int *arg2)

{
  int value;
  
  value = *arg2;
  if (value < 0x4000) {
    if (value < -0x3fff) {
      value = -0x3fff;
    }
  }
  else {
    value = 0x3fff;
  }
  *arg1 = (short)(*arg1 * value >> 0xc);
  arg1[1] = (short)(arg1[1] * value >> 0xc);
  arg1[2] = (short)(arg1[2] * value >> 0xc);
  value = arg2[1];
  if (value < 0x4000) {
    if (value < -0x3fff) {
      value = -0x3fff;
    }
  }
  else {
    value = 0x3fff;
  }
  arg1[3] = (short)(arg1[3] * value >> 0xc);
  arg1[4] = (short)(arg1[4] * value >> 0xc);
  arg1[5] = (short)(arg1[5] * value >> 0xc);
  value = arg2[2];
  if (value < 0x4000) {
    if (value < -0x3fff) {
      value = -0x3fff;
    }
  }
  else {
    value = 0x3fff;
  }
  arg1[6] = (short)(arg1[6] * value >> 0xc);
  arg1[7] = (short)(arg1[7] * value >> 0xc);
  arg1[8] = (short)(arg1[8] * value >> 0xc);
  return;
}

