#include "tarzan_ghidra_types.hpp"

// Address: 0x004AE3B0
// Label: CheckDisplayCapabilities
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 CheckDisplayCapabilities(void)

{
  HDC hdc;
  int result;
  
  hdc = GetDC((HWND)0x0);
  if (hdc == (HDC)0x0) {
    return 0;
  }
  result = GetDeviceCaps(hdc,0xc);
  if (0xe < result) {
    result = GetDeviceCaps(hdc,0xe);
    if (result == 1) {
      ReleaseDC((HWND)0x0,hdc);
      return 1;
    }
  }
  ReleaseDC((HWND)0x0,hdc);
  return 0;
}

