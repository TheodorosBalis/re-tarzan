#include "tarzan_ghidra_types.hpp"

// Address: 0x004B77D9
// Label: ZeroBufferC47000
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ZeroBufferC47000(void)

{
  int value;
  undefined4 *bufferCursor;
  
  bufferCursor = &DAT_00c47120;
  for (value = 0x40; value != 0; value = value + -1) {
    *bufferCursor = 0;
    bufferCursor = bufferCursor + 1;
  }
  *(undefined1 *)bufferCursor = 0;
  g_CrtCurrentCodePage = 0;
  _g_CrtMbCodePageActive = 0;
  g_CrtLocaleIdForCodePage = 0;
  DAT_00c47000 = 0;
  DAT_00c47004 = 0;
  DAT_00c47008 = 0;
  return;
}

