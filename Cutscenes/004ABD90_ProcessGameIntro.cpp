#include "tarzan_ghidra_types.hpp"

// Address: 0x004ABD90
// Label: ProcessGameIntro
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ProcessGameIntro(void)

{
  int value;
  undefined4 *dataCursor;
  
  dataCursor = &g_LevelTransitionContext;
  for (value = 0x1a; value != 0; value = value + -1) {
    *dataCursor = 0;
    dataCursor = dataCursor + 1;
  }
  dataCursor = &g_ModelHierarchyPackedTransformCursor;
  for (value = 0x47; value != 0; value = value + -1) {
    *dataCursor = 0;
    dataCursor = dataCursor + 1;
  }
  ProcessTheIntro();
  return;
}

