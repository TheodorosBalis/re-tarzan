#include "tarzan_ghidra_types.hpp"

// Address: 0x004B16DA
// Label: _filbuf
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

uint _filbuf(undefined4 *arg1)

{
  byte flagByte;
  uint value2;
  int value;
  undefined *dataCursor;
  
  value2 = arg1[3];
  if (((value2 & 0x83) != 0) && ((value2 & 0x40) == 0)) {
    if ((value2 & 2) == 0) {
      arg1[3] = value2 | 1;
      if ((value2 & 0x10c) == 0) {
        _getbuf(arg1);
      }
      else {
        *arg1 = arg1[2];
      }
      value = _read(arg1[4],arg1[2],arg1[6]);
      arg1[1] = value;
      if ((value != 0) && (value != -1)) {
        if ((arg1[3] & 0x82) == 0) {
          value2 = arg1[4];
          if (value2 == 0xffffffff) {
            dataCursor = &g_InvalidFileDescriptorSlot;
          }
          else {
            dataCursor = (undefined *)
                     ((&g_FileDescriptorBlockTable)[(int)value2 >> 5] + (value2 & 0x1f) * 0x24);
          }
          if ((dataCursor[4] & 0x82) == 0x82) {
            arg1[3] = arg1[3] | 0x2000;
          }
        }
        if (((arg1[6] == 0x200) && ((arg1[3] & 8) != 0)) && ((arg1[3] & 0x400) == 0)) {
          arg1[6] = 0x1000;
        }
        arg1[1] = value + -1;
        flagByte = *(byte *)*arg1;
        *arg1 = (byte *)*arg1 + 1;
        return (uint)flagByte;
      }
      arg1[3] = arg1[3] | (-(uint)(value != 0) & 0x10) + 0x10;
      arg1[1] = 0;
    }
    else {
      arg1[3] = value2 | 0x20;
    }
  }
  return 0xffffffff;
}

