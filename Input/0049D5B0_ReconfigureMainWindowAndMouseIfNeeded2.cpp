#include "tarzan_ghidra_types.hpp"

// Address: 0x0049D5B0
// Label: ReconfigureMainWindowAndMouseIfNeeded2
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ReconfigureMainWindowAndMouseIfNeeded2(HWND windowHandle,int messageId,int wParam)

{
  HWND hWnd;
  int value;
  int value2;
  HDC hDC;
  HBRUSH hbr;
  RECT scratchRect2;
  RECT scratchRect;
  
  hWnd = windowHandle;
  if (g_GlideSavedWindowStyle != 0) {
    SetWindowLongA(windowHandle,-0x10,-0x70000000);
    SetWindowLongA(windowHandle,-0x14,8);
    value = GetSystemMetrics(1);
    if (value < wParam) {
      windowHandle = (HWND)wParam;
    }
    else {
      windowHandle = (HWND)GetSystemMetrics(1);
    }
    value2 = GetSystemMetrics(0);
    value = messageId;
    if (messageId <= value2) {
      value = GetSystemMetrics(0);
    }
    SetWindowPos(hWnd,(HWND)0xffffffff,0,0,value,(int)windowHandle,0x548);
    scratchRect2.left = 0;
    scratchRect2.top = 0;
    scratchRect2.right = GetSystemMetrics(0);
    scratchRect2.bottom = GetSystemMetrics(1);
    hDC = GetDC((HWND)0x0);
    hbr = GetStockObject(4);
    FillRect(hDC,&scratchRect2,hbr);
    ReleaseDC((HWND)0x0,hDC);
    scratchRect.left = messageId / 2;
    scratchRect.top = wParam / 2;
    scratchRect.right = scratchRect.left;
    scratchRect.bottom = scratchRect.top;
    SetCursorPos(scratchRect.left,scratchRect.left);
    ClipCursor(&scratchRect);
    value = ShowCursor(0);
    while (-1 < value) {
      value = ShowCursor(0);
    }
  }
  return;
}

