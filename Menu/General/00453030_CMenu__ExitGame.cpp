#include "tarzan_ghidra_types.hpp"

// Address: 0x00453030
// Label: CMenu::ExitGame
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CMenu::ExitGame(void)

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

