#include "tarzan_ghidra_types.hpp"

// Address: 0x0049A880
// Label: GetVirtualGameFileSizeByPath
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 GetVirtualGameFileSizeByPath(undefined4 arg1)

{
  undefined4 value;
  undefined4 value2;
  
  value = OpenVirtualGameFileByPath(arg1,&s_FileModeReadBinary);
  SeekVirtualGameFileHandle(value,0,2);
  value2 = GetVirtualGameFileOffset(value);
  CloseVirtualGameFileHandle(value);
  return value2;
}

