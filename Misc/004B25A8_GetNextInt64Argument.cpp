#include "tarzan_ghidra_types.hpp"

// Address: 0x004B25A8
// Label: GetNextInt64Argument
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined8 GetNextInt64Argument(int *value)

{
  *value = *value + 8;
  return *(undefined8 *)(*value + -8);
}

