#include "tarzan_ghidra_types.hpp"

// Address: 0x00445730
// Label: GetEntitySceneObjectAttachmentList
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int GetEntitySceneObjectAttachmentList(undefined4 arg1,int *arg2)

{
  short *value;
  
  value = (short *)GetEntitySceneObjectAttachmentBlock(arg1);
  if ((value != (short *)0x0) && (value[1] != 0)) {
    *arg2 = (int)(value + *value * 4 + 2);
    return (int)value[1];
  }
  return 0;
}

