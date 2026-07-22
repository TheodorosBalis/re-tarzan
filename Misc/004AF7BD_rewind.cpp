#include "tarzan_ghidra_types.hpp"

// Address: 0x004AF7BD
// Label: rewind
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void rewind(int arg1)

{
  uint value;
  undefined *dataCursor;
  
  value = *(uint *)(arg1 + 0x10);
  _lock_file(arg1);
  _flush(arg1);
  *(uint *)(arg1 + 0xc) = *(uint *)(arg1 + 0xc) & 0xffffffcf;
  if (value == 0xffffffff) {
    dataCursor = &g_InvalidFileDescriptorSlot;
  }
  else {
    dataCursor = (undefined *)((&g_FileDescriptorBlockTable)[(int)value >> 5] + (value & 0x1f) * 0x24);
  }
  dataCursor[4] = dataCursor[4] & 0xfd;
  if ((*(uint *)(arg1 + 0xc) & 0x80) != 0) {
    *(uint *)(arg1 + 0xc) = *(uint *)(arg1 + 0xc) & 0xfffffffc;
  }
  _lseek(value,0,0);
  _unlock_file(arg1);
  return;
}

