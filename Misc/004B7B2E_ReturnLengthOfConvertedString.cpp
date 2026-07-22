#include "tarzan_ghidra_types.hpp"

// Address: 0x004B7B2E
// Label: ReturnLengthOfConvertedString
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int ReturnLengthOfConvertedString
              (LCID arg1,uint arg2,LPCSTR arg3,int arg4,LPWSTR arg5,int arg6,
              UINT arg7,int arg8)

{
  int value;
  int value2;
  void *localState;
  code *localState3;
  undefined *localState4;
  undefined4 localState2;
  
  localState2 = 0xffffffff;
  localState4 = &DAT_004ba968;
  localState3 = _except_handler3;
  localState = ExceptionList;
  ExceptionList = &localState;
  if (g_CrtLCMapStringMode == 0) {
    ExceptionList = &localState;
    value = LCMapStringW(0,0x100,L"",1,(LPWSTR)0x0,0);
    if (value == 0) {
      value = LCMapStringA(0,0x100,"",1,(LPSTR)0x0,0);
      if (value == 0) {
        ExceptionList = localState;
        return 0;
      }
      g_CrtLCMapStringMode = 2;
    }
    else {
      g_CrtLCMapStringMode = 1;
    }
  }
  if (0 < arg4) {
    arg4 = BackwardScanForZero(arg3,arg4);
  }
  if (g_CrtLCMapStringMode == 2) {
    value = LCMapStringA(arg1,arg2,arg3,arg4,(LPSTR)arg5,arg6);
    ExceptionList = localState;
    return value;
  }
  if (g_CrtLCMapStringMode == 1) {
    if (arg7 == 0) {
      arg7 = g_CrtLocaleCodePage;
    }
    value = MultiByteToWideChar(arg7,(-(uint)(arg8 != 0) & 8) + 1,arg3,arg4,(LPWSTR)0x0,
                                0);
    if (value != 0) {
      localState2 = 0;
      SafeCheckStackPtr();
      localState2 = 0xffffffff;
      if ((&stack0x00000000 != (undefined1 *)0x3c) &&
         (value2 = MultiByteToWideChar(arg7,1,arg3,arg4,(LPWSTR)&stack0xffffffc4,value),
         value2 != 0)) {
        value2 = LCMapStringW(arg1,arg2,(LPCWSTR)&stack0xffffffc4,value,(LPWSTR)0x0,0);
        if (value2 != 0) {
          if ((arg2 & 0x400) == 0) {
            localState2 = 1;
            SafeCheckStackPtr();
            localState2 = 0xffffffff;
            if (&stack0x00000000 == (undefined1 *)0x3c) {
              ExceptionList = localState;
              return 0;
            }
            value = LCMapStringW(arg1,arg2,(LPCWSTR)&stack0xffffffc4,value,
                                 (LPWSTR)&stack0xffffffc4,value2);
            if (value == 0) {
              ExceptionList = localState;
              return 0;
            }
            if (arg6 == 0) {
              arg6 = 0;
              arg5 = (LPWSTR)0x0;
            }
            value2 = WideCharToMultiByte(arg7,0x220,(LPCWSTR)&stack0xffffffc4,value2,(LPSTR)arg5
                                        ,arg6,(LPCSTR)0x0,(LPBOOL)0x0);
            value = value2;
          }
          else {
            if (arg6 == 0) {
              ExceptionList = localState;
              return value2;
            }
            if (arg6 < value2) {
              ExceptionList = localState;
              return 0;
            }
            value = LCMapStringW(arg1,arg2,(LPCWSTR)&stack0xffffffc4,value,arg5,arg6);
          }
          if (value != 0) {
            ExceptionList = localState;
            return value2;
          }
        }
      }
    }
  }
  ExceptionList = localState;
  return 0;
}

