#include "tarzan_ghidra_types.hpp"

// Address: 0x004B25B8
// Label: GetNextShortArgument
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 GetNextShortArgument(int *value)

{
  *value = *value + 4;
  return CONCAT22((short)((uint)*value >> 0x10),*(undefined2 *)(*value + -4));
}

