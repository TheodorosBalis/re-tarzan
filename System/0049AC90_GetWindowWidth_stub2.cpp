#include "tarzan_ghidra_types.hpp"

// Address: 0x0049AC90
// Label: GetWindowWidth_stub2
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

char GetWindowWidth_stub2(void)

{
  int value;
  
  value = GetWindowWidth();
  return ((value < 0x280) - 1U & 8) + 8;
}

