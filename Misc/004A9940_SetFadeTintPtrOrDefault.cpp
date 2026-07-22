#include "tarzan_ghidra_types.hpp"

// Address: 0x004A9940
// Label: SetFadeTintPtrOrDefault
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void SetFadeTintPtrOrDefault(undefined *arg1)

{
  if (arg1 == (undefined *)0x0) {
    arg1 = &DAT_00a439f0;
  }
  g_FadeTintRgbPtr = arg1;
  return;
}

