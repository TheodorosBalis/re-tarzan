#include "tarzan_ghidra_types.hpp"

// Address: 0x004B7158
// Label: ConvertCPandUpdateBuffer
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

BOOL ConvertCPandUpdateBuffer
               (DWORD arg1,LPCSTR arg2,int arg3,LPWORD arg4,UINT arg5,LCID arg6,
               int arg7)

{
  undefined1 *bufferCursor;
  BOOL value;
  int value2;
  WORD scratchBuffer3 [2];
  undefined1 *scratchBuffer2;
  void *scratchBuffer;
  code *scratchBuffer5;
  undefined *scratchBuffer6;
  undefined4 scratchBuffer4;
  
  scratchBuffer4 = 0xffffffff;
  scratchBuffer6 = &DAT_004ba920;
  scratchBuffer5 = _except_handler3;
  scratchBuffer = ExceptionList;
  scratchBuffer2 = &stack0xffffffc8;
  value2 = StringType;
  ExceptionList = &scratchBuffer;
  bufferCursor = &stack0xffffffc8;
  if (StringType == 0) {
    ExceptionList = &scratchBuffer;
    value = GetStringTypeW(1,L"",1,scratchBuffer3);
    value2 = 1;
    bufferCursor = scratchBuffer2;
    if (value == 0) {
      value = GetStringTypeA(0,1,"",1,scratchBuffer3);
      if (value == 0) {
        ExceptionList = scratchBuffer;
        return 0;
      }
      value2 = 2;
      bufferCursor = scratchBuffer2;
    }
  }
  scratchBuffer2 = bufferCursor;
  StringType = value2;
  if (StringType != 2) {
    if (StringType == 1) {
      if (arg5 == 0) {
        arg5 = g_CrtLocaleCodePage;
      }
      value2 = MultiByteToWideChar(arg5,(-(uint)(arg7 != 0) & 8) + 1,arg2,arg3,
                                  (LPWSTR)0x0,0);
      if (value2 != 0) {
        scratchBuffer4 = 0;
        SafeCheckStackPtr();
        scratchBuffer2 = &stack0xffffffc8;
        memset(&stack0xffffffc8,0,value2 * 2);
        scratchBuffer4 = 0xffffffff;
        if ((&stack0x00000000 != (undefined1 *)0x38) &&
           (value2 = MultiByteToWideChar(arg5,1,arg2,arg3,(LPWSTR)&stack0xffffffc8,value2),
           value2 != 0)) {
          value = GetStringTypeW(arg1,(LPCWSTR)&stack0xffffffc8,value2,arg4);
          ExceptionList = scratchBuffer;
          return value;
        }
      }
    }
    ExceptionList = scratchBuffer;
    return 0;
  }
  if (arg6 == 0) {
    arg6 = g_CrtMultibyteLocaleActive;
  }
  value = GetStringTypeA(arg6,arg1,arg2,arg3,arg4);
  ExceptionList = scratchBuffer;
  return value;
}

