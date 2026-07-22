#include "tarzan_ghidra_types.hpp"

// Address: 0x004B9216
// Label: _setmode_lk
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int _setmode_lk(uint arg1,int arg2)

{
  byte flagByte;
  undefined4 *dataCursor;
  byte flagByte2;
  
  flagByte = *(byte *)((&g_FileDescriptorBlockTable)[(int)arg1 >> 5] + 4 + (arg1 & 0x1f) * 0x24);
  if (arg2 == 0x8000) {
    flagByte2 = flagByte & 0x7f;
  }
  else {
    if (arg2 != 0x4000) {
      dataCursor = (undefined4 *)_errno();
      *dataCursor = 0x16;
      return -1;
    }
    flagByte2 = flagByte | 0x80;
  }
  *(byte *)((&g_FileDescriptorBlockTable)[(int)arg1 >> 5] + 4 + (arg1 & 0x1f) * 0x24) = flagByte2;
  return (-(uint)((flagByte & 0x80) != 0) & 0xffffc000) + 0x8000;
}

