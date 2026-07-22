#include "tarzan_ghidra_types.hpp"

// Address: 0x004AFAA4
// Label: ConvertFpuTopToInt64
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* Library Function - Single Match
    __ftol
   
   Library: Visual Studio */

longlong ConvertFpuTopToInt64(void)

{
  float10 fpuValue;
  
  return (longlong)ROUND(fpuValue);
}

