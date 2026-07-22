#include "tarzan_ghidra_types.hpp"

// Address: 0x004B694D
// Label: _get_osfhandle
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 _get_osfhandle(uint arg1)

{
  undefined4 *dataCursor;
  
  if ((arg1 < g_FileDescriptorCapacity) &&
     ((*(byte *)((&g_FileDescriptorBlockTable)[(int)arg1 >> 5] + 4 + (arg1 & 0x1f) * 0x24) & 1
      ) != 0)) {
    return *(undefined4 *)
            ((&g_FileDescriptorBlockTable)[(int)arg1 >> 5] + (arg1 & 0x1f) * 0x24);
  }
  dataCursor = (undefined4 *)_errno();
  *dataCursor = 9;
  dataCursor = (undefined4 *)__doserrno();
  *dataCursor = 0;
  return 0xffffffff;
}

