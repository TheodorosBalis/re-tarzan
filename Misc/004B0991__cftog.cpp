#include "tarzan_ghidra_types.hpp"

// Address: 0x004B0991
// Label: _cftog
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int _cftog(undefined8 *arg1,int arg2,int arg3,undefined4 arg4)

{
  int value;
  char *stringCursor;
  char *stringCursor2;
  undefined1 localState3 [24];
  int localState2;
  int localState;
  
  _fltout(*arg1,&localState2,localState3);
  value = localState + -1;
  stringCursor = (char *)((uint)(localState2 == 0x2d) + arg2);
  _fptostr(stringCursor,arg3,&localState2);
  localState = localState + -1;
  if ((localState < -4) || (arg3 <= localState)) {
    FormatScientificFloatString(arg2,arg3,arg4,&localState2,1);
  }
  else {
    if (value < localState) {
      do {
        stringCursor2 = stringCursor;
        stringCursor = stringCursor2 + 1;
      } while (*stringCursor2 != '\0');
      stringCursor2[-1] = '\0';
    }
    FormatFixedFloatString(arg2,arg3,&localState2,1);
  }
  return 0;
}

