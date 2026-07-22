#include "tarzan_ghidra_types.hpp"

// Address: 0x004A22B0
// Label: SqrtToInt
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 SqrtToInt(int arg1)

{
  double value;
  undefined4 value2;
  
  _g_SineCosineLookupTable =
       SQRT((double)arg1) * _g_DoubleSqrtOutputScale64 + _g_DoubleToIntRoundingBias;
  value = _g_SineCosineLookupTable;
  value2 = g_SineCosineLookupTable;
  _g_SineCosineLookupTable = value;
  return value2;
}

