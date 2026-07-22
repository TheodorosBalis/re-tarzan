#include "tarzan_ghidra_types.hpp"

// Address: 0x004B071C
// Label: _positive
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _positive(double *arg1)

{
  if (_g_DoubleZero <= *arg1) {
    return 1;
  }
  return 0;
}

