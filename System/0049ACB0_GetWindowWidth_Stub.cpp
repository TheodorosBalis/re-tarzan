#include "tarzan_ghidra_types.hpp"

// Address: 0x0049ACB0
// Label: GetWindowWidth_Stub
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

char GetWindowWidth_Stub(void)

{
  int value;
  
  value = GetWindowWidth();
  return ((value < 0x280) - 1U & 8) + 8;
}

