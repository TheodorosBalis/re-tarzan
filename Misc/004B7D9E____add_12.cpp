#include "tarzan_ghidra_types.hpp"

// Address: 0x004B7D9E
// Label: ___add_12
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* Library Function - Single Match
    ___add_12
   
   Library: Visual Studio 2003 Release */

void ___add_12(undefined4 *arg1,undefined4 *arg2)

{
  int value;
  
  value = AddUInt32WithCarry(*arg1,*arg2,arg1);
  if (value != 0) {
    value = AddUInt32WithCarry(arg1[1],1,arg1 + 1);
    if (value != 0) {
      arg1[2] = arg1[2] + 1;
    }
  }
  value = AddUInt32WithCarry(arg1[1],arg2[1],arg1 + 1);
  if (value != 0) {
    arg1[2] = arg1[2] + 1;
  }
  AddUInt32WithCarry(arg1[2],arg2[2],arg1 + 2);
  return;
}

