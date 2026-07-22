#include "tarzan_ghidra_types.hpp"

// Address: 0x0049A690
// Label: ReadVirtualGameFileIntoBuffer
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int ReadVirtualGameFileIntoBuffer(undefined4 arg1,uint arg2,uint arg3,uint arg4)

{
  int value;
  
  if (g_IsTarzanFsdArchiveActive == 0) {
    value = fread(arg1,arg2,arg3,arg4);
    if ((value < (int)arg3) && ((*(byte *)(arg4 + 0xc) & 0x20) != 0)) {
      InternalError(s_FSYS_fread_1__00515c30);
    }
    return value;
  }
  if (0x800 < arg4) {
    return 0;
  }
  if ((g_ReadVirtualGameFileIntoBuffer_Global_00515AD0 != arg4) ||
     (*(int *)(&g_TarzanFsdHandleSeekOffsets + arg4 * 4) == 0)) {
    g_ReadVirtualGameFileIntoBuffer_Global_00515AD0 = arg4;
    fseek(g_TarzanFsdArchiveHandle,
          *(int *)(&g_TarzanFsdEntryOffsets + arg4 * 0xc) +
          *(int *)(&g_TarzanFsdHandleSeekOffsets + arg4 * 4),0);
  }
  if (*(uint *)(&g_TarzanFsdEntrySizes + arg4 * 0xc) <=
      arg2 * arg3 + *(int *)(&g_TarzanFsdHandleSeekOffsets + arg4 * 4)) {
    arg3 = arg2;
    if (arg2 == 0) {
      arg3 = 1;
    }
    arg3 = (*(uint *)(&g_TarzanFsdEntrySizes + arg4 * 0xc) -
              *(int *)(&g_TarzanFsdHandleSeekOffsets + arg4 * 4)) / arg3;
  }
  value = fread(arg1,arg2,arg3,g_TarzanFsdArchiveHandle);
  *(uint *)(&g_TarzanFsdHandleSeekOffsets + arg4 * 4) =
       *(int *)(&g_TarzanFsdHandleSeekOffsets + arg4 * 4) + value * arg2;
  return value;
}

