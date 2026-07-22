#include "tarzan_ghidra_types.hpp"

// Address: 0x004B45BC
// Label: ComputeLongDoubleRemainder
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 ComputeLongDoubleRemainder(void)

{
  float10 fpuValue;
  float10 value;
  float10 fpuValue2;
  
  if (((uint)((unkuint10)fpuValue2 >> 0x30) & 0x7fff0000) != 0) {
    value = (float10)ComputeLongDoubleRemainderReduced();
    return value;
  }
  if (SUB104(fpuValue2,0) != 0 || (int)((unkuint10)fpuValue2 >> 0x20) != 0) {
    value = (float10)ComputeLongDoubleRemainderReduced
                               (fpuValue2 * (float10)_g_CrtLongDoubleRemainderScratch);
    return value;
  }
  return fpuValue - (fpuValue / fpuValue2) * fpuValue2;
}

