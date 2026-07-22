#include "tarzan_ghidra_types.hpp"

// Address: 0x00442380
// Label: CEntities::AdvanceEntityScriptTimer
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

short CEntities::AdvanceEntityScriptTimer(int entry)

{
  Entity *entity = (Entity *)entry;
  short shortValue;
  int entry2;
  int entry3;
  short shortValue2;
  short shortValue3;
  
  shortValue3 = 0;
  *(short *)(entry + 0x28) = *(short *)(entry + 0x28) + -1;
  if (*(short *)(entry + 0x28) < 0) {
    while( true ) {
      *(short *)(entry + 0x2a) = *(short *)(entry + 0x2a) + 1;
      shortValue2 = *(short *)(entry + 0x2a);
      shortValue = *(short *)(*(int *)(entry + 0x20) + shortValue2 * 2);
      if (-1 < shortValue) break;
      switch(shortValue) {
      case -0x8000:
        *(undefined2 *)(entry + 0x2a) = 0;
        if (shortValue3 == 0) {
          shortValue3 = 2;
        }
        break;
      case -0x7fff:
        entry2 = *(int *)(entry + 0x24);
        if (entry2 != 0) {
          *(short *)(entry + 0x2c) = *(short *)(entry + 0x2c) + 1;
          while( true ) {
            entry3 = *(int *)(entry2 + *(short *)(entry + 0x2c) * 4);
            if (entry3 != 0) break;
            shortValue2 = *(short *)(entry + 0x2c) + 1;
            *(short *)(entry + 0x2c) = shortValue2;
            *(undefined2 *)(entry + 0x2c) = *(undefined2 *)(entry2 + shortValue2 * 4);
          }
          *(int *)(entry + 0x20) = entry3;
        }
        *(undefined2 *)(entry + 0x2a) = 0;
        *(undefined2 *)(entry + 0x28) = 0xffff;
        if (shortValue3 == 0) {
          shortValue3 = 3;
        }
        break;
      case -0x7ffb:
        *(short *)(entry + 0x2a) = shortValue2 + 1;
        shortValue3 = *(short *)(*(int *)(entry + 0x20) + (short)(shortValue2 + 1) * 2);
        break;
      case -0x7ffa:
        *(short *)(entry + 0x2a) = shortValue2 + 1;
        shortValue3 = (*(undefined2 **)(entry + 0x20))[(short)(shortValue2 + 1)];
        *(undefined2 *)(entry + 0x28) = **(undefined2 **)(entry + 0x20);
        return shortValue3;
      }
    }
    if (*(int *)(entry + 0x18) != 0) {
      DecodeEncodedEntitySceneObjectIdToSourceRef(*(int *)(entry + 0x18),(int)shortValue);
    }
    *(undefined2 *)(entry + 0x28) = **(undefined2 **)(entry + 0x20);
  }
  return shortValue3;
}

