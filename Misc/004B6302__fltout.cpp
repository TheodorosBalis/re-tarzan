#include "tarzan_ghidra_types.hpp"

// Address: 0x004B6302
// Label: _fltout
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int * _fltout(undefined4 arg1,undefined4 arg2,int *arg3,int arg4)

{
  int *intCursor;
  int value;
  int value2;
  short localState4;
  char localState3;
  undefined1 localState2 [24];
  undefined4 localState;
  undefined4 localState6;
  undefined2 localState5;
  
  __dtold(&localState,&arg1);
  value2 = _fltout2(localState,localState6,localState5,0x11,0,&localState4);
  value = arg4;
  intCursor = arg3;
  arg3[2] = value2;
  *arg3 = (int)localState3;
  arg3[1] = (int)localState4;
  strcpy(arg4,localState2);
  intCursor[3] = value;
  return intCursor;
}

