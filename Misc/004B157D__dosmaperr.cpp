#include "tarzan_ghidra_types.hpp"

// Address: 0x004B157D
// Label: _dosmaperr
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void _dosmaperr(uint arg1)

{
  uint *dataCursor;
  undefined4 *dataCursor2;
  int value;
  
  dataCursor = (uint *)__doserrno();
  value = 0;
  *dataCursor = arg1;
  dataCursor = &DAT_00519300;
  do {
    if (arg1 == *dataCursor) {
      dataCursor2 = (undefined4 *)_errno();
      *dataCursor2 = *(undefined4 *)(&g_CrtDosErrnoMapTable + value * 8);
      return;
    }
    dataCursor = dataCursor + 2;
    value = value + 1;
  } while ((int)dataCursor < 0x519468);
  if ((0x12 < arg1) && (arg1 < 0x25)) {
    dataCursor2 = (undefined4 *)_errno();
    *dataCursor2 = 0xd;
    return;
  }
  if ((0xbb < arg1) && (arg1 < 0xcb)) {
    dataCursor2 = (undefined4 *)_errno();
    *dataCursor2 = 8;
    return;
  }
  dataCursor2 = (undefined4 *)_errno();
  *dataCursor2 = 0x16;
  return;
}

