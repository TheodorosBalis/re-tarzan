#include "tarzan_ghidra_types.hpp"

// Address: 0x004AA030
// Label: SetProjectionScreenOrigin
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SetProjectionScreenOrigin(int arg1,int arg2)

{
  g_ProjectionScreenOriginX = (float)arg1;
  _g_ProjectionScreenOriginY = (float)arg2;
  return;
}

