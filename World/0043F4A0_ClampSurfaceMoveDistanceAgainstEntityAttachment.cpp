#include "tarzan_ghidra_types.hpp"

// Address: 0x0043F4A0
// Label: ClampSurfaceMoveDistanceAgainstEntityAttachment
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int ClampSurfaceMoveDistanceAgainstEntityAttachment(int arg1,int arg2,int arg3)

{
  int entry;
  int entry2;
  int entry3;
  int entry4;
  int localState2;
  int localState;
  
  localState2 = GetEntitySceneObjectAttachmentList(arg2,&localState);
  if (localState2 == 0) {
    return arg3;
  }
  do {
    if (((((*(uint *)(localState + 0xc) & 0x40) != 0) &&
         ((*(uint *)(localState + 0xc) & 0xc0000000) == 0x40000000)) &&
        (*(int *)(arg2 + 0x108) == 1)) &&
       (*(int *)(arg2 + 0x110) == *(int *)(arg1 + 0x110))) {
      if (((int)*(short *)(localState + 8) + *(int *)(arg2 + 0x18) < *(int *)(arg1 + 0x18)) &&
         (*(int *)(arg1 + 0x18) - (int)*(short *)(arg1 + 0x142) <
          (int)*(short *)(localState + 2) + *(int *)(arg2 + 0x18))) {
        entry3 = *(int *)(arg2 + 0x10c);
        entry = *(int *)(arg1 + 0x10c);
        entry4 = (int)*(short *)(localState + 6);
        entry2 = entry3 - entry;
        if (entry2 < 0) {
          if ((-entry4 != entry2 && entry4 <= -entry2) &&
             (entry3 = (*(short *)(arg1 + 0x140) - entry) + entry4 + entry3, arg3 < entry3)) {
            *(uint *)(arg1 + 0x13c) = *(uint *)(arg1 + 0x13c) | 2;
            arg3 = entry3;
          }
        }
        else if ((entry4 < entry2) &&
                (entry = ((entry3 - *(short *)(arg1 + 0x140)) - entry4) - entry, entry < arg3))
        {
          *(uint *)(arg1 + 0x13c) = *(uint *)(arg1 + 0x13c) | 2;
          arg3 = entry;
        }
      }
    }
    localState2 = localState2 + -1;
  } while (localState2 != 0);
  return arg3;
}

