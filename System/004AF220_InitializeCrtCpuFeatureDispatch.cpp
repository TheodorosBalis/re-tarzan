#include "tarzan_ghidra_types.hpp"

// Address: 0x004AF220
// Label: InitializeCrtCpuFeatureDispatch
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void InitializeCrtCpuFeatureDispatch(void)

{
  FillVFtable1();
  CPUFeatureRes = CheckCPUfeatures();
  SSEenableCheck();
  return;
}

