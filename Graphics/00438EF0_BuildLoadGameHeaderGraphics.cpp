#include "tarzan_ghidra_types.hpp"

// Address: 0x00438EF0
// Label: BuildLoadGameHeaderGraphics
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void BuildLoadGameHeaderGraphics(void)

{
  LoadMenuGraphicBlock(&Menu_JanesFont);
  LoadMenuGraphicBlock(&LoadGame_SelectLevelLabels);
  InitJaneMenuScene();
  return;
}

