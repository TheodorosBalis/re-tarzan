#include "tarzan_ghidra_types.hpp"

// Address: 0x00429370
// Label: InitiateFade
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void InitiateFade(ushort arg1,undefined2 arg2)

{
  *( undefined2 *)((int)&fadeIntensity + 0) = arg2;
  *( undefined2 *)((int)&fadeIntensity + 2) = arg1 | 0x8000;
  FadeStatus = 0;
  if (((arg1 & 0x10) != 0) && ((arg1 & 3) != 0)) {
    FadeBrightness = (-(ushort)((arg1 & 1) != 0) & 0xf001) + 0x1000;
  }
  _g_FadeCurrentBrightness = 0;
  _g_FadeTargetColor = 0;
  _g_FadeColorStep = 0;
  _g_FadeCurrentStep = 0;
  _g_FadeTargetBrightness = 0;
  _g_FadeStepDelta = 0;
  g_FadeDrawEnabled = (int)FadeBrightness;
  _g_FadePreviousStatus = (int)FadeBrightness;
  return;
}

