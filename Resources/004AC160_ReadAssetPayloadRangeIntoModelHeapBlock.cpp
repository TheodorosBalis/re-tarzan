#include "tarzan_ghidra_types.hpp"

// Address: 0x004AC160
// Label: ReadAssetPayloadRangeIntoModelHeapBlock
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 ReadAssetPayloadRangeIntoModelHeapBlock(int arg1,int arg2,int arg3,int arg4)

{
  char *stringCursor;
  undefined4 value;
  
  if ((((arg1 != 0) && (arg3 != 0)) &&
      (stringCursor = *(char **)(arg1 + 8), stringCursor != (char *)0x0)) && (*stringCursor != '\0')) {
    value = CopyVirtualGameFileRangeIntoBuffer(stringCursor,arg3,arg2 << 0xb,arg4 << 0xb);
    return value;
  }
  return 0xffffffff;
}

