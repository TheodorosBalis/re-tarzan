#include "tarzan_ghidra_types.hpp"

// Address: 0x004A2DD0
// Label: InitGraphicsPageBufferBase
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void InitGraphicsPageBufferBase(void)

{
  g_GraphicsPageBufferBase = g_SoftwareRasterizerArenaBase;
  return;
}

