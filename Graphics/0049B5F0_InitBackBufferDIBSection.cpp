#include "tarzan_ghidra_types.hpp"

// Address: 0x0049B5F0
// Label: InitBackBufferDIBSection
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 InitBackBufferDIBSection(HWND graphicsObject)

{
  HDC hdc;
  int value;
  undefined4 *bufferCursor;
  
  if (isGraphicsInitialized != 0) {
    return 1;
  }
  if (graphicsObject == (HWND)0x0) {
    return 0;
  }
  g_SoftwareFrameBufferLocked = 0;
  g_SoftwareBackBufferWindowHandle = graphicsObject;
  hdc = GetDC(graphicsObject);
  BitMapInfo_Struct = hdc;
  if (hdc == (HDC)0x0) {
    ReleaseSoftwareBackBufferDIBSection();
    isGraphicsInitialized = 0;
    return 0;
  }
  bufferCursor = &g_SoftwareBackBufferBitmapInfo_Field0000;
  for (value = 0xb; value != 0; value = value + -1) {
    *bufferCursor = 0;
    bufferCursor = bufferCursor + 1;
  }
  g_SoftwareBackBufferBitmapInfo_Field0000 = 0x28;
  _g_SoftwareBackBufferBitmapInfo_Field000C = 1;
  _g_SoftwareBackBufferBitmapInfo_Field000E = 0x10;
  _g_SoftwareBackBufferBitmapInfo_Field0010 = 0;
  g_SoftwareBackBufferBitmapInfo_Field0004 = 0x140;
  _g_SoftwareBackBufferBitmapInfo_Field0008 = 0xffffff10;
  lpvBitsColorDataPTR = 0;
  g_SoftwareBackBufferDIBSection =
       CreateDIBSection(hdc,(BITMAPINFO *)&g_SoftwareBackBufferBitmapInfo_Field0000,0,
                        (void **)&lpvBitsColorDataPTR,(HANDLE)0x0,0);
  isGraphicsInitialized = 1;
  return 1;
}

