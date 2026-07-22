#include "tarzan_ghidra_types.hpp"

// Address: 0x004B8DAC
// Label: SetErrnoFromFloatingPointError
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void SetErrnoFromFloatingPointError(int arg1)

{
  undefined4 *dataCursor;
  
  if (arg1 == 1) {
    dataCursor = (undefined4 *)_errno();
    *dataCursor = 0x21;
  }
  else if ((1 < arg1) && (arg1 < 4)) {
    dataCursor = (undefined4 *)_errno();
    *dataCursor = 0x22;
    return;
  }
  return;
}

