#include "tarzan_ghidra_types.hpp"

// Address: 0x004AE320
// Label: ExitAfterFatalErrorCleanup
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ExitAfterFatalErrorCleanup(void)

{
  do {
    if (g_InstalledWindowsHook != (HHOOK)0x0) {
      UnhookWindowsHookEx(g_InstalledWindowsHook);
    }
    g_InstalledWindowsHook = (HHOOK)0x0;
    ShutdownGameRuntime();
    if (mainWindowHandle != (HWND)0x0) {
      SendNotifyMessageA(mainWindowHandle,0x10,0,0);
    }
    if (fileHandle != (HANDLE)0x0) {
      CloseHandle(fileHandle);
    }
    fileHandle = (HANDLE)0x0;
    exit();
  } while( true );
}

