#include "tarzan_ghidra_types.hpp"

// Address: 0x0042DC30
// Label: BuildParabolicMotionOffsetTable
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void BuildParabolicMotionOffsetTable(void)

{
  int offset;
  int *intCursor;
  int offset2;
  int offset3;
  
  offset = 0;
  offset2 = 0;
  intCursor = &g_ParabolicArcHeightOffsetTable;
  do {
    offset3 = offset * offset;
    offset = offset + 1;
    *intCursor = offset2 - (offset3 >> 1);
    intCursor = intCursor + 1;
    offset2 = offset2 + 0x80;
  } while ((int)intCursor < 0x51cc94);
  return;
}

