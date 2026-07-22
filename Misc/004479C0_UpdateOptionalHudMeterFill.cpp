#include "tarzan_ghidra_types.hpp"

// Address: 0x004479C0
// Label: UpdateOptionalHudMeterFill
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void UpdateOptionalHudMeterFill(void)

{
  int value;
  
  if (g_OptionalHudMeterScene == 0) {
    _g_OptionalHudMeterFrameQuad = 0;
    _g_OptionalHudMeterFillQuad = 0;
    return;
  }
  _g_OptionalHudMeterTargetFill = (g_OptionalHudMeterValue << 7) / g_OptionalHudMeterMax;
  if (g_OptionalHudMeterDisplayedFill < _g_OptionalHudMeterTargetFill) {
    g_OptionalHudMeterDisplayedFill = g_OptionalHudMeterDisplayedFill + 2;
    if (g_OptionalHudMeterDisplayedFill <= _g_OptionalHudMeterTargetFill) goto LAB_00447a0d;
  }
  else if ((g_OptionalHudMeterDisplayedFill <= _g_OptionalHudMeterTargetFill) ||
          (g_OptionalHudMeterDisplayedFill = g_OptionalHudMeterDisplayedFill + -2,
          _g_OptionalHudMeterTargetFill <= g_OptionalHudMeterDisplayedFill)) goto LAB_00447a0d;
  g_OptionalHudMeterDisplayedFill = _g_OptionalHudMeterTargetFill;
LAB_00447a0d:
  if (g_OptionalHudMeterDisplayedFill < 1) {
    g_OptionalHudMeterDisplayedFill = 0;
  }
  value = g_OptionalHudMeterDisplayedFill;
  if (0x80 < g_OptionalHudMeterDisplayedFill) {
    value = 0x80;
  }
  _g_OptionalHudMeterFillClipWidth = 0x80 - (short)value;
  return;
}

