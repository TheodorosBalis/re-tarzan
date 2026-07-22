#include "tarzan_ghidra_types.hpp"

// Address: 0x004AEFA0
// Label: ResolveMapSymbolForAddress
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 ResolveMapSymbolForAddress(uint arg1)

{
  char resultFlag;
  int value;
  int value2;
  uint value3;
  uint value4;
  uint value5;
  char *stringCursor;
  char *stringCursor2;
  undefined4 localState;
  CHAR localState2 [1024];
  undefined1 localState4 [1024];
  undefined1 localState3 [1024];
  
  value3 = 0xffffffff;
  value5 = 0xffffffff;
  stringCursor = s_Label_unknown_00518fb8;
  do {
    stringCursor2 = stringCursor;
    if (value3 == 0) break;
    value3 = value3 - 1;
    stringCursor2 = stringCursor + 1;
    resultFlag = *stringCursor;
    stringCursor = stringCursor2;
  } while (resultFlag != '\0');
  value3 = ~value3;
  stringCursor = stringCursor2 + -value3;
  stringCursor2 = (char *)0xc46800;
  for (value4 = value3 >> 2; value4 != 0; value4 = value4 - 1) {
    *(undefined4 *)stringCursor2 = *(undefined4 *)stringCursor;
    stringCursor = stringCursor + 4;
    stringCursor2 = stringCursor2 + 4;
  }
  for (value3 = value3 & 3; value3 != 0; value3 = value3 - 1) {
    *stringCursor2 = *stringCursor;
    stringCursor = stringCursor + 1;
    stringCursor2 = stringCursor2 + 1;
  }
  GetModuleFileNameA((HMODULE)0x0,localState2,0x400);
  value3 = 0xffffffff;
  stringCursor = localState2;
  do {
    if (value3 == 0) break;
    value3 = value3 - 1;
    resultFlag = *stringCursor;
    stringCursor = stringCursor + 1;
  } while (resultFlag != '\0');
  localState2[~value3 - 4] = 'm';
  value3 = 0xffffffff;
  stringCursor = localState2;
  do {
    if (value3 == 0) break;
    value3 = value3 - 1;
    resultFlag = *stringCursor;
    stringCursor = stringCursor + 1;
  } while (resultFlag != '\0');
  localState2[~value3 - 3] = 'a';
  value3 = 0xffffffff;
  stringCursor = localState2;
  do {
    if (value3 == 0) break;
    value3 = value3 - 1;
    resultFlag = *stringCursor;
    stringCursor = stringCursor + 1;
  } while (resultFlag != '\0');
  localState2[~value3 - 2] = 'p';
  value = fopen(localState2,0x518fb4);
  if (value != 0) {
    value2 = fgets(localState2,0x400,value);
    while (value2 != 0) {
      value2 = sscanf(localState2,s__lx__lx__s__lx__s_00518fa0,localState4,localState4,localState3,
                     &localState,localState4);
      if (((value2 == 5) && (value3 = arg1 - localState, localState < arg1)) && (value3 < value5))
      {
        LoadSFX(0xc46800,s_Label_at__08lX_is___s__00518f88,localState,localState3);
        value5 = value3;
      }
      value2 = fgets(localState2,0x400,value);
    }
    fclose(value);
  }
  return 0xc46800;
}

