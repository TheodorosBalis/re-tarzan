#include "tarzan_ghidra_types.hpp"

// Address: 0x004AE120
// Label: InitWindowFrameExtraHeight
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void InitWindowFrameExtraHeight(void)

{
  int value;
  int value2;
  int value3;
  
  value = GetSystemMetrics(0x2e);
  value2 = GetSystemMetrics(8);
  value3 = GetSystemMetrics(4);
  g_WindowFrameExtraHeight = value3 + (value + value2) * 2;
  return;
}

