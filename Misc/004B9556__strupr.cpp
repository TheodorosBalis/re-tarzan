#include "tarzan_ghidra_types.hpp"

// Address: 0x004B9556
// Label: _strupr
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

char * _strupr(char *arg1)

{
  char resultFlag;
  size_t _Size;
  int value;
  char *stringCursor;
  bool flagByte;
  void *localState;
  
  localState = (void *)0x0;
  if (g_CrtMultibyteLocaleActive == 0) {
    resultFlag = *arg1;
    stringCursor = arg1;
    while (resultFlag != '\0') {
      resultFlag = *stringCursor;
      if (('`' < resultFlag) && (resultFlag < '{')) {
        *stringCursor = resultFlag + -0x20;
      }
      stringCursor = stringCursor + 1;
      resultFlag = *stringCursor;
    }
  }
  else {
    InterlockedIncrement((LONG *)&g_CrtLocaleRefCount);
    flagByte = g_CrtLocaleLockActive == 0;
    if (!flagByte) {
      InterlockedDecrement((LONG *)&g_CrtLocaleRefCount);
      _lock(0x13);
    }
    if (g_CrtMultibyteLocaleActive == 0) {
      if (flagByte) {
        InterlockedDecrement((LONG *)&g_CrtLocaleRefCount);
      }
      else {
        _unlock(0x13);
      }
      resultFlag = *arg1;
      stringCursor = arg1;
      while (resultFlag != '\0') {
        resultFlag = *stringCursor;
        if (('`' < resultFlag) && (resultFlag < '{')) {
          *stringCursor = resultFlag + -0x20;
        }
        stringCursor = stringCursor + 1;
        resultFlag = *stringCursor;
      }
    }
    else {
      _Size = ReturnLengthOfConvertedString
                        (g_CrtMultibyteLocaleActive,0x200,arg1,0xffffffff,0,0,0,1);
      if (((_Size != 0) && (localState = malloc(_Size), localState != (void *)0x0)) &&
         (value = ReturnLengthOfConvertedString
                            (g_CrtMultibyteLocaleActive,0x200,arg1,0xffffffff,localState,_Size,0,1),
         value != 0)) {
        strcpy(arg1,localState);
      }
      if (flagByte) {
        InterlockedDecrement((LONG *)&g_CrtLocaleRefCount);
      }
      else {
        _unlock(0x13);
      }
      free(localState);
    }
  }
  return arg1;
}

