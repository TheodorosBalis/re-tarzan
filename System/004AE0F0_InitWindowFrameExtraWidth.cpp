#include "tarzan_ghidra_types.hpp"

// Address: 0x004AE0F0
// Label: InitWindowFrameExtraWidth
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void InitWindowFrameExtraWidth(void)

{
  int value;
  int value2;
  
  value = GetSystemMetrics(0x2d);
  value2 = GetSystemMetrics(7);
  g_WindowFrameExtraWidth = (value + value2) * 2;
  return;
}

