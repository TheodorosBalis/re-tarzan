#include "tarzan_ghidra_types.hpp"

// Address: 0x004B88E2
// Label: RaiseStructuredFloatingPointException
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void RaiseStructuredFloatingPointException
               (uint *arg1,uint *arg2,uint arg3,uint arg4,undefined8 *arg5,
               undefined8 *arg6)

{
  uint *dataCursor;
  undefined8 *dataCursor2;
  byte flagByte;
  uint value;
  
  value = arg3;
  dataCursor = arg2;
  arg1[1] = 0;
  arg1[2] = 0;
  arg1[3] = 0;
  if ((arg3 & 0x10) != 0) {
    arg3 = 0xc000008f;
    arg1[1] = arg1[1] | 1;
  }
  if ((value & 2) != 0) {
    arg3 = 0xc0000093;
    arg1[1] = arg1[1] | 2;
  }
  if ((value & 1) != 0) {
    arg3 = 0xc0000091;
    arg1[1] = arg1[1] | 4;
  }
  if ((value & 4) != 0) {
    arg3 = 0xc000008e;
    arg1[1] = arg1[1] | 8;
  }
  if ((value & 8) != 0) {
    arg3 = 0xc0000090;
    arg1[1] = arg1[1] | 0x10;
  }
  arg1[2] = (~*arg2 & 1) << 4 | arg1[2] & 0xffffffef;
  arg1[2] = (~*arg2 & 4) << 1 | arg1[2] & 0xfffffff7;
  arg1[2] = ~*arg2 >> 1 & 4 | arg1[2] & 0xfffffffb;
  arg1[2] = ~*arg2 >> 3 & 2 | arg1[2] & 0xfffffffd;
  arg1[2] = ~*arg2 >> 5 & 1 | arg1[2] & 0xfffffffe;
  flagByte = GetX87StatusWord();
  dataCursor2 = arg6;
  if ((flagByte & 1) != 0) {
    arg1[3] = arg1[3] | 0x10;
  }
  if ((flagByte & 4) != 0) {
    arg1[3] = arg1[3] | 8;
  }
  if ((flagByte & 8) != 0) {
    arg1[3] = arg1[3] | 4;
  }
  if ((flagByte & 0x10) != 0) {
    arg1[3] = arg1[3] | 2;
  }
  if ((flagByte & 0x20) != 0) {
    arg1[3] = arg1[3] | 1;
  }
  value = *dataCursor & 0xc00;
  if (value == 0) {
    *arg1 = *arg1 & 0xfffffffc;
  }
  else {
    if (value == 0x400) {
      value = *arg1 & 0xfffffffd | 1;
    }
    else {
      if (value != 0x800) {
        if (value == 0xc00) {
          *arg1 = *arg1 | 3;
        }
        goto LAB_004b8a57;
      }
      value = *arg1 & 0xfffffffe | 2;
    }
    *arg1 = value;
  }
LAB_004b8a57:
  value = *dataCursor & 0x300;
  if (value == 0) {
    value = *arg1 & 0xffffffeb | 8;
LAB_004b8a8d:
    *arg1 = value;
  }
  else {
    if (value == 0x200) {
      value = *arg1 & 0xffffffe7 | 4;
      goto LAB_004b8a8d;
    }
    if (value == 0x300) {
      *arg1 = *arg1 & 0xffffffe3;
    }
  }
  *arg1 = (arg4 & 0xfff) << 5 | *arg1 & 0xfffe001f;
  arg1[8] = arg1[8] | 1;
  arg1[8] = arg1[8] & 0xffffffe3 | 2;
  *(undefined8 *)(arg1 + 4) = *arg5;
  arg1[0x14] = arg1[0x14] | 1;
  arg1[0x14] = arg1[0x14] & 0xffffffe3 | 2;
  *(undefined8 *)(arg1 + 0x10) = *arg6;
  GetAndClearX87StatusWord();
  RaiseException(arg3,0,1,(ULONG_PTR *)&arg1);
  if ((arg1[2] & 0x10) != 0) {
    *dataCursor = *dataCursor & 0xfffffffe;
  }
  if ((arg1[2] & 8) != 0) {
    *dataCursor = *dataCursor & 0xfffffffb;
  }
  if ((arg1[2] & 4) != 0) {
    *dataCursor = *dataCursor & 0xfffffff7;
  }
  if ((arg1[2] & 2) != 0) {
    *dataCursor = *dataCursor & 0xffffffef;
  }
  if ((arg1[2] & 1) != 0) {
    *dataCursor = *dataCursor & 0xffffffdf;
  }
  value = *arg1 & 3;
  if (value == 0) {
    *dataCursor = *dataCursor & 0xfffff3ff;
  }
  else {
    if (value == 1) {
      value = *dataCursor & 0xfffff7ff | 0x400;
    }
    else {
      if (value != 2) {
        if (value == 3) {
          *(byte *)((int)dataCursor + 1) = *(byte *)((int)dataCursor + 1) | 0xc;
        }
        goto LAB_004b8b62;
      }
      value = *dataCursor & 0xfffffbff | 0x800;
    }
    *dataCursor = value;
  }
LAB_004b8b62:
  value = *arg1 >> 2 & 7;
  if (value == 0) {
    value = *dataCursor & 0xfffff3ff | 0x300;
  }
  else {
    if (value != 1) {
      if (value == 2) {
        *dataCursor = *dataCursor & 0xfffff3ff;
      }
      goto LAB_004b8b8b;
    }
    value = *dataCursor & 0xfffff3ff | 0x200;
  }
  *dataCursor = value;
LAB_004b8b8b:
  *dataCursor2 = *(undefined8 *)(arg1 + 0x10);
  return;
}

