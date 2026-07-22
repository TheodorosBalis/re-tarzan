#include "tarzan_ghidra_types.hpp"

// Address: 0x004AC130
// Label: GetAssetPayloadSizeByPath
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 GetAssetPayloadSizeByPath(int arg1)

{
  char *stringCursor;
  undefined4 value;
  
  if (((arg1 != 0) && (stringCursor = *(char **)(arg1 + 8), stringCursor != (char *)0x0)) &&
     (*stringCursor != '\0')) {
    value = GetVirtualGameFileSizeByPath(stringCursor);
    return value;
  }
  return 0xffffffff;
}

