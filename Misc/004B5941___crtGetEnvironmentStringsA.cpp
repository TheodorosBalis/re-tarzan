#include "tarzan_ghidra_types.hpp"

// Address: 0x004B5941
// Label: __crtGetEnvironmentStringsA
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

LPSTR __crtGetEnvironmentStringsA(void)

{
  char resultFlag;
  WCHAR value;
  WCHAR *value5;
  WCHAR *value6;
  int value2;
  size_t _Size;
  LPSTR value3;
  char *stringCursor;
  LPWCH lpWideCharStr;
  LPCH value4;
  LPSTR localState;
  char *stringCursor2;
  
  lpWideCharStr = (LPWCH)0x0;
  value4 = (LPCH)0x0;
  if (g_CrtEnvironmentStringsMode == 0) {
    lpWideCharStr = GetEnvironmentStringsW();
    if (lpWideCharStr != (LPWCH)0x0) {
      g_CrtEnvironmentStringsMode = 1;
LAB_004b5998:
      if ((lpWideCharStr == (LPWCH)0x0) &&
         (lpWideCharStr = GetEnvironmentStringsW(), lpWideCharStr == (LPWCH)0x0)) {
        return (LPSTR)0x0;
      }
      value = *lpWideCharStr;
      value6 = lpWideCharStr;
      while (value != L'\0') {
        do {
          value5 = value6;
          value6 = value5 + 1;
        } while (*value6 != L'\0');
        value6 = value5 + 2;
        value = *value6;
      }
      value2 = ((int)value6 - (int)lpWideCharStr >> 1) + 1;
      _Size = WideCharToMultiByte(0,0,lpWideCharStr,value2,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
      localState = (LPSTR)0x0;
      if (((_Size != 0) && (value3 = malloc(_Size), value3 != (LPSTR)0x0)) &&
         (value2 = WideCharToMultiByte(0,0,lpWideCharStr,value2,value3,_Size,(LPCSTR)0x0,(LPBOOL)0x0),
         localState = value3, value2 == 0)) {
        free(value3);
        localState = (LPSTR)0x0;
      }
      FreeEnvironmentStringsW(lpWideCharStr);
      return localState;
    }
    value4 = GetEnvironmentStrings();
    if (value4 == (LPCH)0x0) {
      return (LPSTR)0x0;
    }
    g_CrtEnvironmentStringsMode = 2;
  }
  else {
    if (g_CrtEnvironmentStringsMode == 1) goto LAB_004b5998;
    if (g_CrtEnvironmentStringsMode != 2) {
      return (LPSTR)0x0;
    }
  }
  if ((value4 == (LPCH)0x0) && (value4 = GetEnvironmentStrings(), value4 == (LPCH)0x0)) {
    return (LPSTR)0x0;
  }
  resultFlag = *value4;
  stringCursor = value4;
  while (resultFlag != '\0') {
    do {
      stringCursor2 = stringCursor;
      stringCursor = stringCursor2 + 1;
    } while (*stringCursor != '\0');
    stringCursor = stringCursor2 + 2;
    resultFlag = *stringCursor;
  }
  value3 = malloc((size_t)(stringCursor + (1 - (int)value4)));
  if (value3 == (LPSTR)0x0) {
    value3 = (LPSTR)0x0;
  }
  else {
    memmove(value3,value4,stringCursor + (1 - (int)value4));
  }
  FreeEnvironmentStringsA(value4);
  return value3;
}

