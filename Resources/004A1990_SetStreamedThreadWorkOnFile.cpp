#include "tarzan_ghidra_types.hpp"

// Address: 0x004A1990
// Label: SetStreamedThreadWorkOnFile
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SetStreamedThreadWorkOnFile
               (char *arg1,undefined4 arg2,undefined4 arg3,undefined4 arg4)

{
  char resultFlag;
  uint value;
  uint value2;
  char *stringCursor;
  char *stringCursor2;
  
  value = 0xffffffff;
  g_StreamedWorkFileHandle = 0;
  stringCursor = arg1;
  do {
    stringCursor2 = stringCursor;
    if (value == 0) break;
    value = value - 1;
    stringCursor2 = stringCursor + 1;
    resultFlag = *stringCursor;
    stringCursor = stringCursor2;
  } while (resultFlag != '\0');
  value = ~value;
  stringCursor = stringCursor2 + -value;
  stringCursor2 = (char *)&DAT_00724ad0;
  for (value2 = value >> 2; value2 != 0; value2 = value2 - 1) {
    *(undefined4 *)stringCursor2 = *(undefined4 *)stringCursor;
    stringCursor = stringCursor + 4;
    stringCursor2 = stringCursor2 + 4;
  }
  for (value = value & 3; value != 0; value = value - 1) {
    *stringCursor2 = *stringCursor;
    stringCursor = stringCursor + 1;
    stringCursor2 = stringCursor2 + 1;
  }
  _g_StreamedFileWorkState_Field0004 = arg2;
  g_StreamedFileWorkRequestState = (undefined1)arg3;
  _g_StreamedFileWorkState_Field0010 = arg4;
  g_ActiveStreamedPlaybackHandle = SetStreamedThreadWorkOnecm(arg1,arg2,arg3,arg4);
  g_ActiveStreamedWorkHandle = g_ActiveStreamedPlaybackHandle;
  return;
}

