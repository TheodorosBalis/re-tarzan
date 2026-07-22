#include "tarzan_ghidra_types.hpp"

// Address: 0x004293F0
// Label: ResetFadeState
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ResetFadeState(void)

{
  *( undefined2 *)((int)&fadeIntensity + 2) = 0;
  _g_FadeCurrentBrightness = 0;
  _g_FadeTargetColor = 0;
  _g_FadeColorStep = 0;
  _g_FadeCurrentStep = 0;
  _g_FadeTargetBrightness = 0;
  _g_FadeStepDelta = 0;
  g_FadeDrawEnabled = 0x1000;
  _g_FadePreviousStatus = 0x1000;
  return;
}

