#include "tarzan_ghidra_types.hpp"

// Address: 0x004B0B42
// Label: _fcloseall
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int _fcloseall(void)

{
  int value;
  int value2;
  int value3;
  int value4;
  
  value = _flushall();
  if (g_CrtStreamsInitialized == '\0') {
    return value;
  }
  value3 = 0;
  _lock(2);
  value = 3;
  if (3 < g_StreamSlotCount) {
    do {
      value4 = value * 4;
      value2 = *(int *)(value4 + g_StreamSlotTable);
      if (value2 != 0) {
        if (((*(byte *)(value2 + 0xc) & 0x83) != 0) && (value2 = fclose(value2), value2 != -1)) {
          value3 = value3 + 1;
        }
        if (0x13 < value) {
          DeleteCriticalSection((LPCRITICAL_SECTION)(*(int *)(value4 + g_StreamSlotTable) + 0x20));
          free(*(undefined4 *)(value4 + g_StreamSlotTable));
          *(undefined4 *)(value4 + g_StreamSlotTable) = 0;
        }
      }
      value = value + 1;
    } while (value < g_StreamSlotCount);
  }
  _unlock(2);
  return value3;
}

