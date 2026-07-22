#include "tarzan_ghidra_types.hpp"

// Address: 0x00462340
// Label: TarzanToTheRescue::ChooseRhinoRandomActiveTarget
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 TarzanToTheRescue::ChooseRhinoRandomActiveTarget(int arg1)

{
  int *intCursor;
  int value;
  int value2;
  int value3;
  int value4;
  
  value4 = g_ActiveEntityListHead;
  if (g_ActiveEntityListHead != 0) {
    do {
      value2 = CEntities::FindEntityAttachmentByFlags(arg1,0x10000000);
      value = g_ActiveEntityListHead;
      if ((value2 != 0) && (*(int *)(value2 + 0x34) == 0)) {
        if (*(int *)(value2 + 0x38) == 0) {
          value3 = 0;
        }
        else {
          value3 = RandomModulo(*(int *)(value2 + 0x38));
        }
        *(int *)(value2 + 0x40) = value3;
        for (; value3 != 0; value3 = value3 + -1) {
          value = *(int *)(value + 0x20);
        }
        if (value != arg1) {
          if (value != 0) {
            value = *(int *)(value + 0x38);
            *(undefined4 *)(value2 + 0x54) = *(undefined4 *)(value + 0x14);
            *(undefined4 *)(value2 + 0x58) = *(undefined4 *)(value + 0x18);
            *(undefined4 *)(value2 + 0x5c) = *(undefined4 *)(value + 0x1c);
          }
          *(undefined4 *)(value2 + 0x34) = 1;
        }
      }
      intCursor = (int *)(value4 + 0x20);
      value4 = *intCursor;
    } while (*intCursor != 0);
    return 0;
  }
  return 0;
}

