#include "tarzan_ghidra_types.hpp"

// Address: 0x0049B6B0
// Label: ReleaseSoftwareBackBufferDIBSection
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ReleaseSoftwareBackBufferDIBSection(void)

{
  UnlockSoftwareFrameBuffer();
  if (BitMapInfo_Struct != (HDC)0x0) {
    ReleaseDC(g_SoftwareBackBufferWindowHandle,BitMapInfo_Struct);
    BitMapInfo_Struct = (HDC)0x0;
  }
  if (g_SoftwareBackBufferDIBSection != (HGDIOBJ)0x0) {
    DeleteObject(g_SoftwareBackBufferDIBSection);
    g_SoftwareBackBufferDIBSection = (HGDIOBJ)0x0;
  }
  isGraphicsInitialized = 0;
  if (g_InvalidateWindowAfterDibRelease != 0) {
    InvalidateRect((HWND)0x0,(RECT *)0x0,1);
  }
  g_InvalidateWindowAfterDibRelease = 0;
  return;
}

