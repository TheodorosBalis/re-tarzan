#include "tarzan_ghidra_types.hpp"

// Address: 0x00494EB0
// Label: IsDirect3DRendererInitialized
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

bool IsDirect3DRendererInitialized(void)

{
  return g_DirectDrawSelectedDriverGuid != 0;
}

