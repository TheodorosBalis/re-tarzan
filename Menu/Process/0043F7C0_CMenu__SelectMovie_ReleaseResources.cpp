#include "tarzan_ghidra_types.hpp"

// Address: 0x0043F7C0
// Label: CMenu::SelectMovie_ReleaseResources
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CMenu::SelectMovie_ReleaseResources(void)

{
  ReleaseResourceSet(&g_SelectMovieIconSet);
  HideMenuGraphicBlock(&g_SelectMovieHeaderGraphicBlock);
  return;
}

