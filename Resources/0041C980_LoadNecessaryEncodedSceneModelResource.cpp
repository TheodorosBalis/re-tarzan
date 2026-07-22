#include "tarzan_ghidra_types.hpp"

// Address: 0x0041C980
// Label: LoadNecessaryEncodedSceneModelResource
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void LoadNecessaryEncodedSceneModelResource(undefined4 arg1)

{
  int entry;
  
  RequestEncodedSceneModelResourceLoad(arg1);
  entry = ProcessModelLoadQueue();
  while (entry != 0) {
    CompactModelHeapFully(&g_ModelLoadHeapState);
    entry = ProcessModelLoadQueue();
  }
  return;
}

