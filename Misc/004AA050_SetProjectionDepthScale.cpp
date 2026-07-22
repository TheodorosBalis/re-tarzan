#include "tarzan_ghidra_types.hpp"

// Address: 0x004AA050
// Label: SetProjectionDepthScale
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void SetProjectionDepthScale(int arg1)

{
  int value;
  
  value = arg1;
  arg1 = 1;
  if (0 < value) {
    arg1 = value;
  }
  g_ProjectionDepthScale = (float)arg1;
  return;
}

