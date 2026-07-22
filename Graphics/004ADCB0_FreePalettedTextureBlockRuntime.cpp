#include "tarzan_ghidra_types.hpp"

// Address: 0x004ADCB0
// Label: FreePalettedTextureBlockRuntime
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void FreePalettedTextureBlockRuntime(int *graphicsObject)

{
  int *intCursor;
  int value;
  int *intCursor2;
  int value2;
  int localState;
  
  if (graphicsObject != (int *)0x0) {
    if ((graphicsObject[1] != 0) && (value = 0, 0 < *graphicsObject)) {
      value2 = graphicsObject[1] + 0x10;
      do {
        FreePalettedTextureAtlasRect(value2);
        value = value + 1;
        value2 = value2 + 0x26;
      } while (value < *graphicsObject);
    }
    intCursor = (int *)graphicsObject[3];
    if ((intCursor != (int *)0x0) && (*intCursor != 0)) {
      localState = 0;
      intCursor = (int *)(*intCursor + (int)intCursor);
      intCursor2 = intCursor + 1;
      if (0 < *intCursor) {
        do {
          value = *intCursor2 + (int)intCursor2;
          value2 = 0;
          if (0 < intCursor2[2]) {
            do {
              FreePalettedTextureAtlasRect(value);
              value2 = value2 + 1;
              value = value + 4;
            } while (value2 < intCursor2[2]);
          }
          localState = localState + 1;
          intCursor2 = intCursor2 + 5;
        } while (localState < *intCursor);
      }
    }
    if (graphicsObject[4] != 0) {
      intCursor = (int *)graphicsObject[5];
      value = 0;
      if (0 < graphicsObject[4]) {
        do {
          if (*intCursor != 0) {
            FreeModelHeapBlock(*intCursor,&g_ModelLoadHeapState);
          }
          *intCursor = 0;
          intCursor = (int *)((int)intCursor + 0x72);
          value = value + 1;
        } while (value < graphicsObject[4]);
      }
    }
  }
  return;
}

