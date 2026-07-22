#include "tarzan_ghidra_types.hpp"

// Address: 0x00496890
// Label: ReleaseDirectDrawObject
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ReleaseDirectDrawObject(void)

{
  if (g_DirectDraw != (int *)0x0) {
    g_Direct3DLastResult = (**(code **)(*g_DirectDraw + 8))(g_DirectDraw);
  }
  g_DirectDraw = (int *)0x0;
  return;
}

