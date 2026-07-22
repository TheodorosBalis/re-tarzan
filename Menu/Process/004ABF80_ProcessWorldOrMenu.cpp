#include "tarzan_ghidra_types.hpp"

// Address: 0x004ABF80
// Label: ProcessWorldOrMenu
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ProcessWorldOrMenu(void)

{
  ManageFades();
  ProcessModelLoadQueue();
  UpdateEntity3DSounds();
  GetInputs();
  if (g_ActiveWorldOrMenuProcessFn != (code *)0x0) {
    (*g_ActiveWorldOrMenuProcessFn)();
  }
  DoNothing5();
  FreeDeferredModelHeapBlocks(&g_ModelLoadHeapState);
  return;
}

