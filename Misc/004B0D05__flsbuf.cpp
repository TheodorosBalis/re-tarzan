#include "tarzan_ghidra_types.hpp"

// Address: 0x004B0D05
// Label: _flsbuf
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

uint _flsbuf(uint arg1,int *arg2)

{
  uint value3;
  uint value4;
  int value;
  int *intCursor;
  int value2;
  undefined *dataCursor;
  
  intCursor = arg2;
  value3 = arg2[3];
  value4 = arg2[4];
  if (((value3 & 0x82) == 0) || ((value3 & 0x40) != 0)) {
LAB_004b0e11:
    arg2[3] = value3 | 0x20;
  }
  else {
    if ((value3 & 1) != 0) {
      arg2[1] = 0;
      if ((value3 & 0x10) == 0) goto LAB_004b0e11;
      *arg2 = arg2[2];
      arg2[3] = value3 & 0xfffffffe;
    }
    value3 = arg2[3];
    arg2[1] = 0;
    arg2 = (int *)0x0;
    intCursor[3] = value3 & 0xffffffef | 2;
    if (((value3 & 0x10c) == 0) &&
       (((intCursor != (int *)&g_StdoutStream && (intCursor != (int *)&g_StderrStream)) ||
        (value2 = _isatty(value4), value2 == 0)))) {
      _getbuf(intCursor);
    }
    if ((*(ushort *)(intCursor + 3) & 0x108) == 0) {
      value2 = 1;
      arg2 = (int *)_write(value4,&arg1,1);
    }
    else {
      value = intCursor[2];
      value2 = *intCursor - value;
      *intCursor = value + 1;
      intCursor[1] = intCursor[6] + -1;
      if (value2 < 1) {
        if (value4 == 0xffffffff) {
          dataCursor = &g_InvalidFileDescriptorSlot;
        }
        else {
          dataCursor = (undefined *)
                   ((&g_FileDescriptorBlockTable)[(int)value4 >> 5] + (value4 & 0x1f) * 0x24);
        }
        if ((dataCursor[4] & 0x20) != 0) {
          _lseek(value4,0,2);
        }
      }
      else {
        arg2 = (int *)_write(value4,value,value2);
      }
      *(undefined1 *)intCursor[2] = (undefined1)arg1;
    }
    if (arg2 == (int *)value2) {
      return arg1 & 0xff;
    }
    intCursor[3] = intCursor[3] | 0x20;
  }
  return 0xffffffff;
}

