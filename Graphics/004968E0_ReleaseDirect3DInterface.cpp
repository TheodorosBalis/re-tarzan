#include "tarzan_ghidra_types.hpp"

// Address: 0x004968E0
// Label: ReleaseDirect3DInterface
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ReleaseDirect3DInterface(void)

{
  if (g_Direct3D != (int *)0x0) {
    (**(code **)(*g_Direct3D + 8))(g_Direct3D);
  }
  g_Direct3D = (int *)0x0;
  return;
}

