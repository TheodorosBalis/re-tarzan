#include "tarzan_ghidra_types.hpp"

// Address: 0x004B060D
// Label: CheckCpuFeatureModuloThreshold
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 CheckCpuFeatureModuloThreshold(void)

{
  if (_g_FloatFixed12Scale <
      _k_CpuFeatureModuloConstantA -
      (_k_CpuFeatureModuloConstantA / _k_CpuFeatureModuloConstantB) * _k_CpuFeatureModuloConstantB)
  {
    return 1;
  }
  return 0;
}

