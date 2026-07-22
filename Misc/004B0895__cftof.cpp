#include "tarzan_ghidra_types.hpp"

// Address: 0x004B0895
// Label: _cftof
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int _cftof(undefined8 *arg1,int arg2,int arg3)

{
  undefined1 localState3 [24];
  int localState2;
  int localState;
  
  _fltout(*arg1,&localState2,localState3);
  _fptostr((uint)(localState2 == 0x2d) + arg2,localState + arg3,&localState2);
  FormatFixedFloatString(arg2,arg3,&localState2,0);
  return arg2;
}

