#include "tarzan_ghidra_types.hpp"

// Address: 0x004A2120
// Label: SetPageProtectionsForTarzan
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 SetPageProtectionsForTarzan(undefined4 *arg1,int arg2)

{
  undefined4 *dataCursor;
  bool flagByte;
  _union_530 _Var3;
  SIZE_T value2;
  BOOL value;
  DWORD localState6;
  _union_530 localState5;
  int localState4;
  int localState3;
  int localState2;
  uint localState;
  
  if (g_SystemPageSize == 0) {
    GetSystemInfo((LPSYSTEM_INFO)&localState5.s);
    g_SystemPageSize = localState4;
  }
  dataCursor = (undefined4 *)((int)arg1 + arg2);
  if (dataCursor <= arg1) {
    return 1;
  }
  do {
    value2 = VirtualQuery(arg1,(PMEMORY_BASIC_INFORMATION)&localState5.s,0x1c);
    if (value2 != 0x1c) {
      return 0;
    }
    arg1 = (undefined4 *)(localState3 + localState5.dwOemId);
    if (dataCursor < (undefined4 *)(localState3 + localState5.dwOemId)) {
      arg1 = dataCursor;
    }
    if (((localState2 == 0x1000) && ((localState & 0x100) == 0)) && (localState != 1)) {
      if ((localState == 8) || (localState == 0x80)) {
        flagByte = false;
        _Var3 = localState5;
      }
      else {
        flagByte = true;
        value = VirtualProtect((LPVOID)localState5,(int)arg1 - (int)localState5,0x40,&localState6);
        if (value == 0) {
          return 0;
        }
        _Var3 = localState5;
        if (localState6 != localState) {
          VirtualProtect((LPVOID)localState5,(int)arg1 - (int)localState5,localState6,&localState6);
          return 0;
        }
      }
      for (; _Var3.dwOemId < arg1; _Var3.dwOemId = _Var3.dwOemId + g_SystemPageSize) {
        *(undefined4 *)_Var3 = *(undefined4 *)_Var3;
      }
      if ((flagByte) &&
         (value = VirtualProtect((LPVOID)localState5,(int)arg1 - (int)localState5,localState,&localState6),
         value == 0)) {
        return 0;
      }
    }
    if (dataCursor <= arg1) {
      return 1;
    }
  } while( true );
}

