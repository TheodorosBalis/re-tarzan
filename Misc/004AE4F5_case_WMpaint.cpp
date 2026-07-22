#include "tarzan_ghidra_types.hpp"

// Address: 0x004AE4F5
// Label: case_WMpaint
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 case_WMpaint(void)

{
  HWND hWnd;
  int value;
  HDC hDC;
  HBRUSH hbr;
  HWND incomingStackArg;
  
  hWnd = incomingStackArg;
  BeginPaint(incomingStackArg,(LPPAINTSTRUCT)&stack0x0000001c);
  if (hWnd == mainWindowHandle) {
    value = CurrentGraphicsMode();
    if (value == 0) {
      if (hWnd != (HWND)0x0) {
        hDC = GetDC(hWnd);
        GetClientRect(hWnd,(LPRECT)&stack0x0000000c);
        hbr = GetStockObject(4);
        FillRect(hDC,(RECT *)&stack0x0000000c,hbr);
        ReleaseDC(hWnd,hDC);
        EndPaint(hWnd,(PAINTSTRUCT *)&stack0x0000001c);
        return 0;
      }
    }
    else {
      ShowFrameOnScreen();
    }
  }
  EndPaint(hWnd,(PAINTSTRUCT *)&stack0x0000001c);
  return 0;
}

