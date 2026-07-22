#include "tarzan_ghidra_types.hpp"

// Address: 0x004386C0
// Label: RequestCurrentWorldSceneAuxResourceIfMissing
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void RequestCurrentWorldSceneAuxResourceIfMissing(int arg1)

{
  if ((&g_WorldSceneAuxResourceSlotTable)[arg1] == 0) {
    LoadWorldSceneAuxResourceSlotNoOp
              (g_CurrentWorldSceneContext,arg1,&g_WorldSceneAuxResourceSlotTable + arg1);
  }
  return;
}

