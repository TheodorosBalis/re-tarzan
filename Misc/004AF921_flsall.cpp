#include "tarzan_ghidra_types.hpp"

// Address: 0x004AF921
// Label: flsall
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int flsall(int arg1)

{
  int value;
  int value2;
  int value3;
  int value4;
  
  value2 = 0;
  value4 = 0;
  _lock(2);
  value3 = 0;
  if (0 < g_StreamSlotCount) {
    do {
      value = *(int *)(g_StreamSlotTable + value3 * 4);
      if ((value != 0) && ((*(byte *)(value + 0xc) & 0x83) != 0)) {
        _lock_file2(value3,value);
        value = *(int *)(g_StreamSlotTable + value3 * 4);
        if ((*(uint *)(value + 0xc) & 0x83) != 0) {
          if (arg1 == 1) {
            value = _fflush_lk(value);
            if (value != -1) {
              value2 = value2 + 1;
            }
          }
          else if ((arg1 == 0) && ((*(uint *)(value + 0xc) & 2) != 0)) {
            value = _fflush_lk(value);
            if (value == -1) {
              value4 = -1;
            }
          }
        }
        _unlock_file2(value3,*(undefined4 *)(g_StreamSlotTable + value3 * 4));
      }
      value3 = value3 + 1;
    } while (value3 < g_StreamSlotCount);
  }
  _unlock(2);
  if (arg1 != 1) {
    value2 = value4;
  }
  return value2;
}

