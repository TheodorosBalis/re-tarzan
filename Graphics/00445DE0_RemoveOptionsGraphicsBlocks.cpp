#include "tarzan_ghidra_types.hpp"

// Address: 0x00445DE0
// Label: RemoveOptionsGraphicsBlocks
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void RemoveOptionsGraphicsBlocks(void)

{
  HideMenuGraphicBlock(&Options_MainFont);
  HideMenuGraphicBlock(&Options_OptionsSelections);
  HideMenuGraphicBlock(&Options_Difficulty);
  HideMenuGraphicBlock(&Options_Controller);
  HideMenuGraphicBlock(&Options_Sound);
  HideMenuGraphicBlock(&Options_SFXunused);
  ReleaseResourceSet(&ModelPorter);
  return;
}

