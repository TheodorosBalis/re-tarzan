#include "tarzan_ghidra_types.hpp"

// Address: 0x004B25F3
// Label: __heap_select
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int __heap_select(void)

{
  char resultFlag;
  BOOL value;
  DWORD apiResult;
  int value2;
  char *stringCursor;
  byte savedRegister;
  char localState [4240];
  char localState2 [260];
  DWORD localState5;
  uint localState4;
  DWORD localState3;
  CHAR aCStackY_18 [4];
  
  SafeCheckStackPtr();
  localState5 = 0x94;
  value = GetVersionExA((LPOSVERSIONINFOA)&localState5);
  if (((value == 0) || (localState3 != 2)) || (localState4 < 5)) {
    builtin_memcpy(aCStackY_18,"M&K",4);
    apiResult = GetEnvironmentVariableA("__MSVCRT_HEAP_SELECT",localState,0x1090);
    if (apiResult != 0) {
      stringCursor = localState;
      while (localState[0] != '\0') {
        resultFlag = *stringCursor;
        if (('`' < resultFlag) && (resultFlag < '{')) {
          *stringCursor = resultFlag + -0x20;
        }
        stringCursor = stringCursor + 1;
        localState[0] = *stringCursor;
      }
      aCStackY_18[0] = -0x75;
      aCStackY_18[1] = '&';
      aCStackY_18[2] = 'K';
      aCStackY_18[3] = '\0';
      value2 = strncmp("__GLOBAL_HEAP_SELECTED",localState,0x16);
      if (value2 == 0) {
        stringCursor = localState;
      }
      else {
        aCStackY_18[0] = -0x53;
        aCStackY_18[1] = '&';
        aCStackY_18[2] = 'K';
        aCStackY_18[3] = '\0';
        GetModuleFileNameA((HMODULE)0x0,localState2,0x104);
        stringCursor = localState2;
        while (localState2[0] != '\0') {
          resultFlag = *stringCursor;
          if (('`' < resultFlag) && (resultFlag < '{')) {
            *stringCursor = resultFlag + -0x20;
          }
          stringCursor = stringCursor + 1;
          localState2[0] = *stringCursor;
        }
        stringCursor = (char *)strstr();
      }
      if ((stringCursor != (char *)0x0) && (value2 = strchr(), value2 != 0)) {
        stringCursor = (char *)(value2 + 1);
        resultFlag = *stringCursor;
        while (resultFlag != '\0') {
          if (*stringCursor == ';') {
            *stringCursor = '\0';
          }
          else {
            stringCursor = stringCursor + 1;
          }
          resultFlag = *stringCursor;
        }
        builtin_memcpy(aCStackY_18,"\x13\'K",4);
        value2 = strtoul();
        if (value2 == 2) {
          return 2;
        }
        if (value2 == 3) {
          return 3;
        }
        if (value2 == 1) {
          return 1;
        }
      }
    }
    GetExecutableSubsystemVersion();
    value2 = 3 - (uint)(savedRegister < 6);
  }
  else {
    value2 = 1;
  }
  return value2;
}

