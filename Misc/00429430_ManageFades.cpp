#include "tarzan_ghidra_types.hpp"

// Address: 0x00429430
// Label: ManageFades
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ManageFades(void)

{
  int value;
  
  value = (int)FadeBrightness;
  if ((*( undefined2 *)((int)&fadeIntensity + 2) & 0x8000) == 0) {
    g_FadeDrawEnabled = 0x1000;
  }
  else {
    if ((*( undefined2 *)((int)&fadeIntensity + 2) & 3) != 0) {
      if ((*( undefined2 *)((int)&fadeIntensity + 2) & 1) == 0) {
        value = value - (uint)(ushort)fadeIntensity;
        if (value < 0) {
          value = 0;
        }
      }
      else {
        value = value + (uint)(ushort)fadeIntensity;
        if (0xfff < value) {
          ResetFadeState();
        }
      }
    }
    FadeBrightness = (short)value;
    g_FadeDrawEnabled = value;
  }
  if (FadeBrightness == 0) {
    FadeStatus = FadeStatus + 1;
  }
  _g_FadePreviousStatus = g_FadeDrawEnabled;
  return;
}

