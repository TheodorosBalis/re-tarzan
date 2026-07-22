#include "tarzan_ghidra_types.hpp"

// Address: 0x004A22F0
// Label: NormalizeVectorToFixed12
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void NormalizeVectorToFixed12(int *arg1,undefined4 *arg2)

{
  double value;
  double value2;
  double value3;
  double value4;
  double value5;
  
  value5 = (double)*arg1;
  value = (double)arg1[1];
  value4 = (double)arg1[2];
  value2 = SQRT(value5 * value5 + value * value + value4 * value4);
  value3 = _g_FloatFixed12Scale;
  if (_g_FloatFixed12Scale < value2) {
    value3 = _k_Fixed12ScaleFloat / value2;
  }
  g_SineCosineLookupTable = SUB84(value3 * value5 + _g_DoubleToIntRoundingBias,0);
  *arg2 = g_SineCosineLookupTable;
  g_SineCosineLookupTable = SUB84(value3 * value + _g_DoubleToIntRoundingBias,0);
  arg2[1] = g_SineCosineLookupTable;
  _g_SineCosineLookupTable = value3 * value4 + _g_DoubleToIntRoundingBias;
  arg2[2] = g_SineCosineLookupTable;
  return;
}

