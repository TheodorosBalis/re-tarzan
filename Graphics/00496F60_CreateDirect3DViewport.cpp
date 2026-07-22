#include "tarzan_ghidra_types.hpp"

// Address: 0x00496F60
// Label: CreateDirect3DViewport
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

bool CreateDirect3DViewport(void)

{
  undefined4 *dataCursor;
  int value;
  undefined4 scratchRect5 [7];
  undefined4 scratchRect;
  undefined4 scratchRect4;
  undefined4 scratchRect3;
  undefined4 scratchRect2;
  
  if (g_Direct3D != (int *)0x0) {
    g_Direct3DLastResult = (**(code **)(*g_Direct3D + 0x18))(g_Direct3D,&g_Direct3DViewport,0);
  }
  if ((g_Direct3DViewport != (int *)0x0) && (g_Direct3DDevice != (int *)0x0)) {
    g_Direct3DLastResult =
         (**(code **)(*g_Direct3DDevice + 0x18))(g_Direct3DDevice,g_Direct3DViewport);
  }
  dataCursor = scratchRect5;
  for (value = 0xb; value != 0; value = value + -1) {
    *dataCursor = 0;
    dataCursor = dataCursor + 1;
  }
  scratchRect5[0] = 0x2c;
  scratchRect5[3] = 0x280;
  scratchRect5[4] = 0x1e0;
  scratchRect = 0x44200000;
  scratchRect4 = 0x43f00000;
  scratchRect3 = 0;
  scratchRect2 = 0x3f800000;
  if (g_Direct3DViewport != (int *)0x0) {
    g_Direct3DLastResult = (**(code **)(*g_Direct3DViewport + 0x44))(g_Direct3DViewport,scratchRect5);
    if ((g_Direct3DViewport != (int *)0x0) && (g_Direct3DDevice != (int *)0x0)) {
      g_Direct3DLastResult =
           (**(code **)(*g_Direct3DDevice + 0x34))(g_Direct3DDevice,g_Direct3DViewport);
    }
  }
  return g_Direct3DViewport != (int *)0x0;
}

