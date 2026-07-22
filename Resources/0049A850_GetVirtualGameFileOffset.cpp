#include "tarzan_ghidra_types.hpp"

// Address: 0x0049A850
// Label: GetVirtualGameFileOffset
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 GetVirtualGameFileOffset(uint arg1)

{
  undefined4 value;
  
  if (g_IsTarzanFsdArchiveActive == 0) {
    value = ftell(arg1);
    return value;
  }
  if (0x800 < arg1) {
    return 0xffffffff;
  }
  return *(undefined4 *)(&g_TarzanFsdHandleSeekOffsets + arg1 * 4);
}

