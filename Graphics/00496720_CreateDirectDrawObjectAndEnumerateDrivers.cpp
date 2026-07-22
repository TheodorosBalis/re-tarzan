#include "tarzan_ghidra_types.hpp"

// Address: 0x00496720
// Label: CreateDirectDrawObjectAndEnumerateDrivers
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

bool CreateDirectDrawObjectAndEnumerateDrivers(void)

{
  g_Direct3DLastResult = (*g_DirectDrawEnumerateAProc)(DirectDrawEnumerateDriverCallback,0);
  if (g_DirectDraw == 0) {
    g_Direct3DLastResult = (*g_DirectDrawCreateProc)(0,&g_DirectDraw,0);
  }
  return g_DirectDraw != 0;
}

