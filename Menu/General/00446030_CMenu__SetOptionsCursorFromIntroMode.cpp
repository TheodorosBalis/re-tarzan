#include "tarzan_ghidra_types.hpp"

// Address: 0x00446030
// Label: CMenu::SetOptionsCursorFromIntroMode
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CMenu::SetOptionsCursorFromIntroMode(int menu)

{
  *(int *)(menu + 0x24) = (int)g_IntroMenuStartFlag % 3;
  return;
}

