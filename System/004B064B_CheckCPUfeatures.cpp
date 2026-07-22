#include "tarzan_ghidra_types.hpp"

// Address: 0x004B064B
// Label: CheckCPUfeatures
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int CheckCPUfeatures(void)

{
  HMODULE hModule;
  FARPROC value;
  
  hModule = GetModuleHandleA("KERNEL32");
  if (hModule != (HMODULE)0x0) {
    value = GetProcAddress(hModule,"IsProcessorFeaturePresent");
    if (value != (FARPROC)0x0) {
      (*value)(0);
      return 0;
    }
  }
  CheckCpuFeatureModuloThreshold();
  return 0;
}

