#include "tarzan_ghidra_types.hpp"

// Address: 0x004ACB80
// Label: UpdateEntitySceneObjectAnimations
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void UpdateEntitySceneObjectAnimations(int arg1)

{
  int *intCursor;
  int entry;
  int entry2;
  int entry3;
  
  intCursor = *(int **)(arg1 + 0xc);
  if (intCursor != (int *)0x0) {
    entry = *intCursor;
    if (entry != 0) {
      entry2 = 0;
      entry3 = (int)intCursor + entry + 4;
      if (0 < *(int *)((int)intCursor + entry)) {
        do {
          UpdateEntitySceneObjectFramePointerAnimation(entry3,arg1);
          entry3 = entry3 + 0x14;
          entry2 = entry2 + 1;
        } while (entry2 < *(int *)((int)intCursor + entry));
      }
    }
    entry = intCursor[1];
    if (entry != 0) {
      entry2 = 0;
      entry3 = (int)intCursor + entry + 8;
      if (0 < *(int *)((int)intCursor + entry + 4)) {
        do {
          UpdateEntitySceneObjectFrameIndexAnimation(entry3,arg1);
          entry3 = entry3 + 0x10;
          entry2 = entry2 + 1;
        } while (entry2 < *(int *)((int)intCursor + entry + 4));
      }
    }
  }
  return;
}

