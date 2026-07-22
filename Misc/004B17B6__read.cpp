#include "tarzan_ghidra_types.hpp"

// Address: 0x004B17B6
// Label: _read
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 _read(uint arg1,undefined4 arg2,undefined4 arg3)

{
  undefined4 value;
  undefined4 *dataCursor;
  
  if ((arg1 < g_FileDescriptorCapacity) &&
     ((*(byte *)((&g_FileDescriptorBlockTable)[(int)arg1 >> 5] + 4 + (arg1 & 0x1f) * 0x24) & 1
      ) != 0)) {
    _lock_fhandle(arg1);
    value = _read_lk(arg1,arg2,arg3);
    _unlock_fhandle(arg1);
    return value;
  }
  dataCursor = (undefined4 *)_errno();
  *dataCursor = 9;
  dataCursor = (undefined4 *)__doserrno();
  *dataCursor = 0;
  return 0xffffffff;
}

