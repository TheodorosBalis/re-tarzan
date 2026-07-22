#include "tarzan_ghidra_types.hpp"

// Address: 0x004B7987
// Label: ConvertStringBuffersIfNeeded
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ConvertStringBuffersIfNeeded(void)

{
  if (g_CrtRuntimeStringBuffersInitialized == 0) {
    StringConvertBuffersBigFunction(0xfffffffd);
    g_CrtRuntimeStringBuffersInitialized = 1;
  }
  return;
}

