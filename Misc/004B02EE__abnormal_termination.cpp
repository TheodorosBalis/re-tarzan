#include "tarzan_ghidra_types.hpp"

// Address: 0x004B02EE
// Label: _abnormal_termination
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 _abnormal_termination(void)

{
  undefined4 value;
  
  value = 0;
  if ((*(code **)((int)ExceptionList + 4) == _local_unwind2_exception_handler) &&
     (*(int *)((int)ExceptionList + 8) == *(int *)(*(int *)((int)ExceptionList + 0xc) + 0xc))) {
    value = 1;
  }
  return value;
}

