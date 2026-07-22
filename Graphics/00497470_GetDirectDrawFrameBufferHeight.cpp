#include "tarzan_ghidra_types.hpp"

// Address: 0x00497470
// Label: GetDirectDrawFrameBufferHeight
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int GetDirectDrawFrameBufferHeight(void)

{
  return (-(uint)(g_DirectDrawUseHighResolutionMode != 0) & 0xf0) + 0xf0;
}

