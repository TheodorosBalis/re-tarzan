#include "tarzan_ghidra_types.hpp"

// Address: 0x00497030
// Label: ReleaseDirect3DViewport
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ReleaseDirect3DViewport(void)

{
  if (g_Direct3DViewport != (int *)0x0) {
    (**(code **)(*g_Direct3DViewport + 8))(g_Direct3DViewport);
  }
  g_Direct3DViewport = (int *)0x0;
  return;
}

