#include "tarzan_ghidra_types.hpp"

// Address: 0x004B0171
// Label: doexit
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void doexit(UINT arg1,int arg2,int arg3)

{
  HANDLE hProcess;
  undefined4 *dataCursor;
  UINT uExitCode;
  
  _lockexit();
  if (g_CrtExitProcessInProgress == 1) {
    uExitCode = arg1;
    hProcess = GetCurrentProcess();
    TerminateProcess(hProcess,uExitCode);
  }
  _g_CrtExitCallbackState = 1;
  g_CrtStreamsInitialized = (undefined1)arg3;
  if (arg2 == 0) {
    if ((g_CrtOnExitTableStart != (undefined4 *)0x0) &&
       (dataCursor = (undefined4 *)(g_CrtExitListState - 4), g_CrtOnExitTableStart <= dataCursor)) {
      do {
        if ((code *)*dataCursor != (code *)0x0) {
          (*(code *)*dataCursor)();
        }
        dataCursor = dataCursor + -1;
      } while (g_CrtOnExitTableStart <= dataCursor);
    }
    _initterm(&DAT_004bc034,&DAT_004bc03c);
  }
  _initterm(&DAT_004bc040,&DAT_004bc044);
  if (arg3 == 0) {
    g_CrtExitProcessInProgress = 1;
                    /* WARNING: Subroutine does not return */
    ExitProcess(arg1);
  }
  _unlockexit();
  return;
}

