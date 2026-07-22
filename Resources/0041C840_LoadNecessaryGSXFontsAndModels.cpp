#include "tarzan_ghidra_types.hpp"

// Address: 0x0041C840
// Label: LoadNecessaryGSXFontsAndModels
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void LoadNecessaryGSXFontsAndModels(undefined4 arg1)

{
  int value;
  
  RequestResourceSetLoad(arg1);
  value = ProcessModelLoadQueue();
  while (value != 0) {
    CompactModelHeapFully(&g_ModelLoadHeapState);
    value = ProcessModelLoadQueue();
  }
  FreeDeferredModelHeapBlocks(&g_ModelLoadHeapState);
  FreeDeferredModelHeapBlocks(&g_ModelLoadHeapState);
  FreeDeferredModelHeapBlocks(&g_ModelLoadHeapState);
  FreeDeferredModelHeapBlocks(&g_ModelLoadHeapState);
  FreeDeferredModelHeapBlocks(&g_ModelLoadHeapState);
  return;
}

