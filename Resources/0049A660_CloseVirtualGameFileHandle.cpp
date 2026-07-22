#include "tarzan_ghidra_types.hpp"

// Address: 0x0049A660
// Label: CloseVirtualGameFileHandle
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 CloseVirtualGameFileHandle(uint arg1)

{
  undefined4 value;
  
  if (g_IsTarzanFsdArchiveActive == 0) {
    value = fclose(arg1);
    return value;
  }
  if (0x800 < arg1) {
    return 0;
  }
  *(undefined4 *)(&g_TarzanFsdHandleSeekOffsets + arg1 * 4) = 0xffffffff;
  return 0;
}

