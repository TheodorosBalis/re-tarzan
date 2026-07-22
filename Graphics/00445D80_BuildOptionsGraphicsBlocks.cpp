#include "tarzan_ghidra_types.hpp"

// Address: 0x00445D80
// Label: BuildOptionsGraphicsBlocks
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void BuildOptionsGraphicsBlocks(void)

{
  LoadMenuGraphicBlock(&Options_MainFont);
  LoadMenuGraphicBlock(&Options_OptionsSelections);
  LoadMenuGraphicBlock(&Options_Difficulty);
  LoadMenuGraphicBlock(&Options_Controller);
  LoadMenuGraphicBlock(&Options_Sound);
  LoadMenuGraphicBlock(&Options_SFXunused);
  ResetMenuModelSet(&ModelPorter);
  LoadNecessaryGSXFontsAndModels(&ModelPorter);
  return;
}

