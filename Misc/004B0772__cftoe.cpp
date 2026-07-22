#include "tarzan_ghidra_types.hpp"

// Address: 0x004B0772
// Label: _cftoe
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int _cftoe(undefined8 *arg1,int arg2,int arg3,undefined4 arg4)

{
  undefined1 localState2 [24];
  int localState [4];
  
  _fltout(*arg1,localState,localState2);
  _fptostr((uint)(0 < arg3) + arg2 + (uint)(localState[0] == 0x2d),arg3 + 1,localState);
  FormatScientificFloatString(arg2,arg3,arg4,localState,0);
  return arg2;
}

