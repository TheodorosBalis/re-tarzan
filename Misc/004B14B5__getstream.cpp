#include "tarzan_ghidra_types.hpp"

// Address: 0x004B14B5
// Label: _getstream
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 * _getstream(void)

{
  int value;
  void *value3;
  int value2;
  undefined4 *bufferCursor;
  
  bufferCursor = (undefined4 *)0x0;
  _lock(2);
  value2 = 0;
  if (0 < g_StreamSlotCount) {
    do {
      value = *(int *)(g_StreamSlotTable + value2 * 4);
      if (value == 0) {
        value2 = value2 * 4;
        value3 = malloc(0x38);
        *(void **)(value2 + g_StreamSlotTable) = value3;
        if (*(int *)(value2 + g_StreamSlotTable) != 0) {
          InitializeCriticalSection
                    ((LPCRITICAL_SECTION)(*(int *)(value2 + g_StreamSlotTable) + 0x20));
          EnterCriticalSection((LPCRITICAL_SECTION)(*(int *)(value2 + g_StreamSlotTable) + 0x20));
          bufferCursor = *(undefined4 **)(value2 + g_StreamSlotTable);
LAB_004b1559:
          if (bufferCursor != (undefined4 *)0x0) {
            bufferCursor[4] = 0xffffffff;
            bufferCursor[1] = 0;
            bufferCursor[3] = 0;
            bufferCursor[2] = 0;
            *bufferCursor = 0;
            bufferCursor[7] = 0;
          }
        }
        break;
      }
      if ((*(byte *)(value + 0xc) & 0x83) == 0) {
        _lock_file2(value2,value);
        value = *(int *)(g_StreamSlotTable + value2 * 4);
        if ((*(byte *)(value + 0xc) & 0x83) == 0) {
          bufferCursor = *(undefined4 **)(g_StreamSlotTable + value2 * 4);
          goto LAB_004b1559;
        }
        _unlock_file2(value2,value);
      }
      value2 = value2 + 1;
    } while (value2 < g_StreamSlotCount);
  }
  _unlock(2);
  return bufferCursor;
}

