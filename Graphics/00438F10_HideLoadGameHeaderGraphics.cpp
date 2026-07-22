#include "tarzan_ghidra_types.hpp"

// Address: 0x00438F10
// Label: HideLoadGameHeaderGraphics
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void HideLoadGameHeaderGraphics(void)

{
  HideMenuGraphicBlock(&LoadGame_SelectLevelLabels);
  HideMenuGraphicBlock(&Menu_JanesFont);
  return;
}

