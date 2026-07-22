#include "tarzan_ghidra_types.hpp"

// Address: 0x00453260
// Label: ProcessMenuButtonSequences
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ProcessMenuButtonSequences(void)

{
  undefined **dataCursor;
  int menuIndex;
  
  dataCursor = &PTR_SetSceneAnchorAspectPreset_4x3_004f1fe0;
  menuIndex = 3;
  do {
    UpdateMenuButtonSequenceDetector(dataCursor);
    dataCursor = dataCursor + 0x24;
    menuIndex = menuIndex + -1;
  } while (menuIndex != 0);
  return;
}

