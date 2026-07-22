#include "tarzan_ghidra_types.hpp"

// Address: 0x00497880
// Label: ResetDirectDrawInitState
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ResetDirectDrawInitState(void)

{
  g_DirectDrawPrimarySurfaceLocked = 0;
  g_DirectDrawLastResult = 0;
  g_DirectDrawDllModule = 0;
  g_DirectDrawCreateProc = 0;
  return;
}

