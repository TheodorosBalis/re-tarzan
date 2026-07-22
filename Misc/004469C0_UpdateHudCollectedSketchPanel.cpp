#include "tarzan_ghidra_types.hpp"

// Address: 0x004469C0
// Label: UpdateHudCollectedSketchPanel
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void UpdateHudCollectedSketchPanel(void)

{
  int value;
  
  if (g_HudCollectedSketchScene != 0) {
    if (((byte)g_GameplayStateFlags & 1) != 0) {
      if (*(int *)(g_HudCollectedSketchScene + 0x18) < 0x110) {
        *(int *)(g_HudCollectedSketchScene + 0x18) =
             *(int *)(g_HudCollectedSketchScene + 0x18) + 0x30;
        return;
      }
      *(undefined4 *)(g_HudCollectedSketchScene + 0x18) = 0x110;
      return;
    }
    value = *(int *)(g_HudCollectedSketchScene + 0x18);
    if (g_HudCollectedSketchSlideTicks < 0) {
      if (-0x80 < value) {
        *(int *)(g_HudCollectedSketchScene + 0x18) = value + -0x30;
        return;
      }
    }
    else {
      if (value < 0x110) {
        *(int *)(g_HudCollectedSketchScene + 0x18) = value + 0x30;
        g_HudCollectedSketchSlideTicks = g_HudCollectedSketchSlideTicks + -1;
        return;
      }
      *(undefined4 *)(g_HudCollectedSketchScene + 0x18) = 0x110;
      g_HudCollectedSketchSlideTicks = g_HudCollectedSketchSlideTicks + -1;
    }
  }
  return;
}

