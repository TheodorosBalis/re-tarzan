#include "tarzan_ghidra_types.hpp"

// Address: 0x004AE9F0
// Label: IsGameRunningOnCD
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void IsGameRunningOnCD(void)

{
  char conditionMet;
  UINT value;
  int result;
  uint value2;
  uint value3;
  char *stringCursor;
  char *stringCursor2;
  CHAR localState2;
  char localState [7];
  
  GetModuleFileNameA((HMODULE)0x0,&localState2,2);
  value2 = 0xffffffff;
  stringCursor = &DAT_005175ec;
  do {
    stringCursor2 = stringCursor;
    if (value2 == 0) break;
    value2 = value2 - 1;
    stringCursor2 = stringCursor + 1;
    conditionMet = *stringCursor;
    stringCursor = stringCursor2;
  } while (conditionMet != '\0');
  value2 = ~value2;
  stringCursor = stringCursor2 + -value2;
  stringCursor2 = localState;
  for (value3 = value2 >> 2; value3 != 0; value3 = value3 - 1) {
    *(undefined4 *)stringCursor2 = *(undefined4 *)stringCursor;
    stringCursor = stringCursor + 4;
    stringCursor2 = stringCursor2 + 4;
  }
  for (value2 = value2 & 3; value2 != 0; value2 = value2 - 1) {
    *stringCursor2 = *stringCursor;
    stringCursor = stringCursor + 1;
    stringCursor2 = stringCursor2 + 1;
  }
  value = GetDriveTypeA(&localState2);
  if (value != 3) {
    InternalError(s_The_game_can_only_be_run_from_a_l_00518e6c);
  }
  result = LoadECMFilesAndInit();
  if (result != 0) {
    result = LoadECMinChunks_stub();
    if (result == 0) {
      bGameInitSuccess = 1;
    }
  }
  return;
}

