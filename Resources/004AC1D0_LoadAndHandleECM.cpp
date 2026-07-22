#include "tarzan_ghidra_types.hpp"

// Address: 0x004AC1D0
// Label: LoadAndHandleECM
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void LoadAndHandleECM(uint arg1)

{
  if (g_LoadAndHandleECM_Global_00517828 != 0) {
    g_LoadAndHandleECM_Global_00517828 = 0;
    LoadAndHandleMovie(0xffffffff,0);
    LoadAndHandleMovie(0xffffffff,0);
  }
  LoadAndHandleMovie(arg1 & 0xffff3fff,1);
  return;
}

