#include "tarzan_ghidra_types.hpp"

// Address: 0x004B259B
// Label: GetNextIntArgument
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 GetNextIntArgument(int *value)

{
  *value = *value + 4;
  return *(undefined4 *)(*value + -4);
}

