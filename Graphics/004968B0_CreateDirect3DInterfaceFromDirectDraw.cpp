#include "tarzan_ghidra_types.hpp"

// Address: 0x004968B0
// Label: CreateDirect3DInterfaceFromDirectDraw
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

bool CreateDirect3DInterfaceFromDirectDraw(void)

{
  if (g_DirectDraw != (undefined4 *)0x0) {
    g_Direct3DLastResult = (**(code **)*g_DirectDraw)(g_DirectDraw,&DAT_004babb8,&g_Direct3D);
  }
  return g_Direct3D != 0;
}

