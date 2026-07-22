#include "tarzan_ghidra_types.hpp"

// Address: 0x004386F0
// Label: UpdateCurrentWorldSceneAuxResourceIfLoaded
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void UpdateCurrentWorldSceneAuxResourceIfLoaded(int arg1)

{
  if ((&g_WorldSceneAuxResourceSlotTable)[arg1] != 0) {
    UpdateWorldSceneAuxResourceNoOp
              (g_CurrentWorldSceneContext,arg1,(&g_WorldSceneAuxResourceSlotTable)[arg1]);
  }
  return;
}

