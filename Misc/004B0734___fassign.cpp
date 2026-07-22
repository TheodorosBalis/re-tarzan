#include "tarzan_ghidra_types.hpp"

// Address: 0x004B0734
// Label: __fassign
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* Library Function - Single Match
    __fassign
   
   Library: Visual Studio 2003 Release */

void __cdecl __fassign(int flag,char *argument,char *number)

{
  undefined4 localState2;
  undefined4 localState;
  
  if (flag != 0) {
    _atodbl(&localState2);
    *(undefined4 *)argument = localState2;
    *(undefined4 *)(argument + 4) = localState;
    return;
  }
  _atoflt(&number,number);
  *(char **)argument = number;
  return;
}

