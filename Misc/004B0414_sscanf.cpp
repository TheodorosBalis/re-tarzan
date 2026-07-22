#include "tarzan_ghidra_types.hpp"

// Address: 0x004B0414
// Label: sscanf
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int sscanf(char *arg1,undefined4 arg2)

{
  char *localState4;
  size_t localState3;
  char *localState2;
  undefined4 localState;
  
  localState = 0x49;
  localState2 = arg1;
  localState4 = arg1;
  localState3 = strlen(arg1);
  _input(&localState4,arg2,&stack0x0000000c);
  return 0;
}

