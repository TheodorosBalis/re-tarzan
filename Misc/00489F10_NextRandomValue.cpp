#include "tarzan_ghidra_types.hpp"

// Address: 0x00489F10
// Label: NextRandomValue
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int NextRandomValue(void)

{
  g_PrngStateA = g_PrngStateA + g_PrngStateB;
  g_PrngStateB = g_PrngStateB + (g_PrngStateA - (g_PrngStateA >> 0x1f));
  return 0;
}

