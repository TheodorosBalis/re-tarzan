#include "tarzan_ghidra_types.hpp"

// Address: 0x004A9960
// Label: SetFadeBrightnessAndTint
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void SetFadeBrightnessAndTint(int arg1,int arg2)

{
  if (arg1 < 0) {
    arg1 = 0;
  }
  else if (0x1000 < arg1) {
    arg1 = 0x1000;
  }
  g_FadeBrightnessInverse = 0x1000 - arg1;
  SetFadeTintPtrOrDefault(arg2);
  if (arg2 == 0) {
    g_FadeTintRgbPtr = &DAT_00a43a00;
    return;
  }
  g_FadeTintRgbPtr = (undefined *)arg2;
  return;
}

