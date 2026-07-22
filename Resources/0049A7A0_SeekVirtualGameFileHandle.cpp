#include "tarzan_ghidra_types.hpp"

// Address: 0x0049A7A0
// Label: SeekVirtualGameFileHandle
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 SeekVirtualGameFileHandle(uint arg1,int arg2,int arg3)

{
  undefined4 value2;
  int value;
  
  if (g_IsTarzanFsdArchiveActive == 0) {
    value2 = fseek(arg1,arg2,arg3);
    return value2;
  }
  if (0x800 < arg1) {
    return 0xffffffff;
  }
  if (arg3 == 1) {
    value = *(int *)(&g_TarzanFsdHandleSeekOffsets + arg1 * 4);
  }
  else {
    if (arg3 != 2) goto LAB_0049a7e9;
    value = *(int *)(&g_TarzanFsdEntrySizes + arg1 * 0xc);
  }
  arg2 = value + arg2;
LAB_0049a7e9:
  *(int *)(&g_TarzanFsdHandleSeekOffsets + arg1 * 4) = arg2;
  if (*(uint *)(&g_TarzanFsdEntrySizes + arg1 * 0xc) <
      *(uint *)(&g_TarzanFsdHandleSeekOffsets + arg1 * 4)) {
    *(uint *)(&g_TarzanFsdHandleSeekOffsets + arg1 * 4) =
         *(uint *)(&g_TarzanFsdEntrySizes + arg1 * 0xc);
  }
  value2 = fseek(g_TarzanFsdArchiveHandle,
                *(int *)(&g_TarzanFsdEntryOffsets + arg1 * 0xc) +
                *(int *)(&g_TarzanFsdHandleSeekOffsets + arg1 * 4),0);
  return value2;
}

