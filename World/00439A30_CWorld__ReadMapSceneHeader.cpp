#include "tarzan_ghidra_types.hpp"

// Address: 0x00439A30
// Label: CWorld::ReadMapSceneHeader
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 CWorld::ReadMapSceneHeader(undefined4 *arg1)

{
  undefined4 value;
  int entry;
  
  entry = LoadAssetPayloadRange(*arg1,0,0x34);
  value = *(undefined4 *)(entry + 0x2c);
  FreeModelHeapBlock(entry,&g_ModelLoadHeapState);
  return value;
}

