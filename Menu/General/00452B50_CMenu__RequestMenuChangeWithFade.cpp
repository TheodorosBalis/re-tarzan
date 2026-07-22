#include "tarzan_ghidra_types.hpp"

// Address: 0x00452B50
// Label: CMenu::RequestMenuChangeWithFade
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CMenu::RequestMenuChangeWithFade(int requestedMenu)

{
  CaptureKInputsInBuffer();
  TimeIDLEinMenu = 0;
  if (requestedMenu != g_NextMenu) {
    if (*(int *)(g_CurrentMenu + 0x1c) != -1) {
      PlayAudioById(*(int *)(g_CurrentMenu + 0x1c),(int *)0,(undefined4 *)0);
    }
    g_NextMenu = requestedMenu;
    InitiateFade(2,0x400);
  }
  return;
}

