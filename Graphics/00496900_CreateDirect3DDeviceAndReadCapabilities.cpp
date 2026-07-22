#include "tarzan_ghidra_types.hpp"

// Address: 0x00496900
// Label: CreateDirect3DDeviceAndReadCapabilities
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool CreateDirect3DDeviceAndReadCapabilities(void)

{
  int value;
  undefined4 *dataCursor;
  undefined4 scratchRect5 [9];
  undefined4 scratchRect4;
  undefined4 scratchRect3;
  undefined4 scratchRect2 [27];
  uint scratchRect7;
  uint scratchRect6;
  undefined4 scratchRect9 [51];
  undefined4 scratchRect;
  undefined1 scratchRect8 [424];
  
  dataCursor = scratchRect5;
  for (value = 0x17; value != 0; value = value + -1) {
    *dataCursor = 0;
    dataCursor = dataCursor + 1;
  }
  dataCursor = &scratchRect;
  for (value = 0x6b; value != 0; value = value + -1) {
    *dataCursor = 0;
    dataCursor = dataCursor + 1;
  }
  scratchRect5[0] = 0x5c;
  scratchRect5[1] = 0x1005;
  scratchRect5[3] = 2;
  scratchRect5[2] = 1;
  scratchRect4 = 0x38;
  scratchRect3 = 8;
  scratchRect = 0x1ac;
  if (g_Direct3D != (int *)0x0) {
    g_Direct3DLastResult = (**(code **)(*g_Direct3D + 0x1c))(g_Direct3D,scratchRect5,&scratchRect);
    if (g_Direct3D != (int *)0x0) {
      g_Direct3DLastResult =
           (**(code **)(*g_Direct3D + 0x20))
                     (g_Direct3D,scratchRect8,g_DirectDrawBackBufferSurface,&g_Direct3DDevice);
    }
  }
  dataCursor = scratchRect2;
  for (value = 0x33; value != 0; value = value + -1) {
    *dataCursor = 0;
    dataCursor = dataCursor + 1;
  }
  dataCursor = scratchRect9;
  for (value = 0x33; value != 0; value = value + -1) {
    *dataCursor = 0;
    dataCursor = dataCursor + 1;
  }
  scratchRect2[0] = 0xcc;
  scratchRect2[1] = 0x40;
  scratchRect9[0] = 0xcc;
  if (g_Direct3DDevice != (int *)0x0) {
    g_Direct3DLastResult =
         (**(code **)(*g_Direct3DDevice + 0xc))(g_Direct3DDevice,scratchRect2,scratchRect9);
  }
  if (((scratchRect7 & 0x80) == 0) || (_g_Direct3DDeviceCaps = 1, (scratchRect7 & 0x100) == 0)) {
    _g_Direct3DDeviceCaps = 0;
  }
  _g_Direct3DTextureFormat = scratchRect6 & 1;
  return g_Direct3DDevice != (int *)0x0;
}

