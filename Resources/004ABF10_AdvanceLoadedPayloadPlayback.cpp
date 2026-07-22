#include "tarzan_ghidra_types.hpp"

// Address: 0x004ABF10
// Label: AdvanceLoadedPayloadPlayback
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 AdvanceLoadedPayloadPlayback(int arg1)

{
  int value;
  
  value = *(int *)(arg1 + 0xc);
  if (*(int *)(arg1 + 0x10) < *(int *)(arg1 + 0x1c + value * 8)) {
    *(int *)(arg1 + 0x10) = *(int *)(arg1 + 0x10) + 1;
    return *(undefined4 *)(arg1 + 0x20 + *(int *)(arg1 + 0xc) * 8);
  }
  *(undefined4 *)(arg1 + 0x10) = 1;
  if (value < *(int *)(arg1 + 0x14)) {
    *(int *)(arg1 + 0xc) = value + 1;
    return *(undefined4 *)(arg1 + 0x20 + (value + 1) * 8);
  }
  *( undefined1 *)((int)&g_GameplayStateFlags + 0) = (byte)g_GameplayStateFlags | 0x10;
  return *(undefined4 *)(arg1 + 0x20 + *(int *)(arg1 + 0xc) * 8);
}

