#include "tarzan_ghidra_types.hpp"

// Address: 0x00497450
// Label: GetDirectDrawFrameBufferWidth
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int GetDirectDrawFrameBufferWidth(void)

{
  return (-(uint)(g_DirectDrawUseHighResolutionMode != 0) & 0x140) + 0x140;
}

