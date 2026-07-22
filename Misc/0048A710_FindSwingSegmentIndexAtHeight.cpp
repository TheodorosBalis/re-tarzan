#include "tarzan_ghidra_types.hpp"

// Address: 0x0048A710
// Label: FindSwingSegmentIndexAtHeight
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int FindSwingSegmentIndexAtHeight(int arg1,int arg2)

{
  short shortValue;
  short *value3;
  uint value;
  int foundIndex;
  uint value2;
  int foundIndex2;
  int foundIndex3;
  
  foundIndex2 = 0;
  value3 = (short *)GetEntitySceneObjectAttachmentBlock(arg1);
  if ((value3 != (short *)0x0) && (shortValue = *value3, shortValue != 0)) {
    if (0 < shortValue) {
      value3 = value3 + 3;
      foundIndex3 = 0xfffff;
      do {
        value = (((int)*value3 * *(int *)(arg1 + 0xac) >> 0xc) - arg2) +
                *(int *)(arg1 + 0x18);
        value2 = (int)value >> 0x1f;
        foundIndex = (value ^ value2) - value2;
        if (foundIndex3 <= foundIndex) {
          return foundIndex2;
        }
        foundIndex2 = foundIndex2 + 1;
        value3 = value3 + 4;
        foundIndex3 = foundIndex;
      } while (foundIndex2 < shortValue);
    }
  }
  return foundIndex2;
}

