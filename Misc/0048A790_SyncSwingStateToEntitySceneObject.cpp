#include "tarzan_ghidra_types.hpp"

// Address: 0x0048A790
// Label: SyncSwingStateToEntitySceneObject
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void SyncSwingStateToEntitySceneObject(int arg1,int arg2)

{
  short state;
  short *value;
  int entry;
  
  value = (short *)GetEntitySceneObjectAttachmentBlock(arg1);
  if (value == (short *)0x0) {
    entry = *(int *)(arg1 + 0x18);
    *(int *)(arg1 + 0x94) = entry;
    *(int *)(arg1 + 0x98) = entry + 0x800;
    *(int *)(arg1 + 0x88) = (entry + 0x800) - entry;
  }
  else {
    state = *value;
    *(short *)(arg2 + 0x12) = state;
    if (state != 0) {
      *(short *)(arg2 + 0x12) = state + -1;
      *(int *)(arg1 + 0x94) =
           ((int)value[3] * *(int *)(arg1 + 0xac) >> 0xc) + *(int *)(arg1 + 0x18);
      entry = ((int)value[(uint)*(ushort *)(arg2 + 0x12) * 4 + 3] * *(int *)(arg1 + 0xac) >>
              0xc) + *(int *)(arg1 + 0x18);
      *(int *)(arg1 + 0x98) = entry;
      *(int *)(arg1 + 0x88) = entry - *(int *)(arg1 + 0x94);
      return;
    }
  }
  return;
}

