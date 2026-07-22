#include "tarzan_ghidra_types.hpp"

// Address: 0x0049A8C0
// Label: CopyVirtualGameFileRangeIntoBuffer
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4
CopyVirtualGameFileRangeIntoBuffer
          (undefined4 arg1,undefined4 arg2,undefined4 arg3,int arg4)

{
  int value;
  undefined4 value2;
  undefined4 value3;
  
  value = GetVirtualGameFileSizeByPath(arg1);
  if ((arg4 < 0) || (value < arg4)) {
    arg4 = value;
  }
  value2 = OpenVirtualGameFileByPath(arg1,&s_FileModeReadBinary);
  SeekVirtualGameFileHandle(value2,arg3,0);
  value3 = ReadVirtualGameFileIntoBuffer(arg2,1,arg4,value2);
  CloseVirtualGameFileHandle(value2);
  return value3;
}

