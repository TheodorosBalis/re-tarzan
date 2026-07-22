#include "tarzan_ghidra_types.hpp"

// Address: 0x004979D0
// Label: CreateDirectDrawObject
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

bool CreateDirectDrawObject(void)

{
  (*g_DirectDrawCreateProc)(0,&g_DirectDrawObject,0);
  return g_DirectDrawObject != 0;
}

