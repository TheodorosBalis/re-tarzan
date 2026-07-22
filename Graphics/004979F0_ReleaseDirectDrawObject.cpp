#include "tarzan_ghidra_types.hpp"

// Address: 0x004979F0
// Label: ReleaseDirectDrawObject
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ReleaseDirectDrawObject_004979F0(void)

{
  if (g_DirectDrawObject != (int *)0x0) {
    g_DirectDrawLastResult = (**(code **)(*g_DirectDrawObject + 8))(g_DirectDrawObject);
  }
  g_DirectDrawObject = (int *)0x0;
  return;
}

