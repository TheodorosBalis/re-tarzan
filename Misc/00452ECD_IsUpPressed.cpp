#include "tarzan_ghidra_types.hpp"

// Address: 0x00452ECD
// Label: IsUpPressed
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void __fastcall IsUpPressed(uint value)

{
  int savedEsi;
  
  if (((value & g_InputEdgeMask & 0x10) != 0) && (0 < *(int *)(savedEsi + 0x24))) {
    PlayAudioById(0xaa,(int *)0,(undefined4 *)0);
    *(int *)(savedEsi + 0x24) = *(int *)(savedEsi + 0x24) + -1;
    return;
  }
  return;
}

