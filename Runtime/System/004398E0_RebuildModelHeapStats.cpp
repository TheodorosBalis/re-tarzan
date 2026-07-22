#include "tarzan_ghidra_types.hpp"

// Address: 0x004398E0
// Label: RebuildModelHeapStats
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void RebuildModelHeapStats(int arg1)

{
  int value;
  
  _g_ModelHeapLargestFreeBlockBytes = 0;
  value = *(int *)(arg1 + 4);
  _g_ModelHeapTotalFreeBytes = 0;
  g_ModelHeapFreeBlockCount = 0;
  for (; value != 0; value = *(int *)(value + 0x14)) {
    g_ModelHeapFreeBlockCount = g_ModelHeapFreeBlockCount + 1;
    _g_ModelHeapLargestFreeBlockBytes = *(int *)(value + 8) * 4;
    _g_ModelHeapTotalFreeBytes = _g_ModelHeapTotalFreeBytes + _g_ModelHeapLargestFreeBlockBytes;
  }
  return;
}

