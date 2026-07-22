#include "tarzan_ghidra_types.hpp"

// Address: 0x00496A50
// Label: ReleaseDirect3DDevice
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ReleaseDirect3DDevice(void)

{
  if (g_Direct3DDevice != (int *)0x0) {
    (**(code **)(*g_Direct3DDevice + 8))(g_Direct3DDevice);
  }
  g_Direct3DDevice = (int *)0x0;
  return;
}

