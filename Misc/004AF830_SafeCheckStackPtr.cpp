#include "tarzan_ghidra_types.hpp"

// Address: 0x004AF830
// Label: SafeCheckStackPtr
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Unable to track spacebase fully for stack */

int SafeCheckStackPtr(void)

{
  uint inputEax;
  undefined1 *dataCursor;
  undefined4 savedRegister;
  
  dataCursor = &stack0x00000004;
  for (; 0xfff < inputEax; inputEax = inputEax - 0x1000) {
    dataCursor = dataCursor + -0x1000;
  }
  *(undefined4 *)(dataCursor + (-4 - inputEax)) = savedRegister;
  return 0;
}

