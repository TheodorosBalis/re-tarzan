#include "tarzan_ghidra_types.hpp"

// Address: 0x00445880
// Label: FindSceneAttachmentByMask
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

short * FindSceneAttachmentByMask(short *arg1,ushort arg2)

{
  int foundIndex;
  
  foundIndex = (int)*arg1;
  arg1 = arg1 + 2;
  while( true ) {
    if (foundIndex == 0) {
      return (short *)0x0;
    }
    foundIndex = foundIndex + -1;
    if ((arg1[3] & arg2) != 0) break;
    arg1 = arg1 + 4;
  }
  return arg1;
}

