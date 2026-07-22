#include "tarzan_ghidra_types.hpp"

// Address: 0x004B0A9A
// Label: SetGlobalsToAllocatedMem
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void SetGlobalsToAllocatedMem(void)

{
  int value;
  undefined **dataCursor;
  uint value2;
  undefined4 *dataCursor2;
  
  value = 0x14;
  if (g_StreamSlotCount == 0) {
    value = 0x200;
  }
  else if (0x13 < g_StreamSlotCount) goto LAB_004b0ab9;
  g_StreamSlotCount = value;
LAB_004b0ab9:
  g_StreamSlotTable = calloc(g_StreamSlotCount,4);
  if (g_StreamSlotTable == 0) {
    g_StreamSlotCount = 0x14;
    g_StreamSlotTable = calloc(0x14,4);
    if (g_StreamSlotTable == 0) {
      __amsg_exit(0x1a);
    }
  }
  value = 0;
  dataCursor = &PTR_DAT_00519080;
  do {
    *(undefined ***)(value + g_StreamSlotTable) = dataCursor;
    dataCursor = dataCursor + 8;
    value = value + 4;
  } while ((int)dataCursor < 0x519300);
  value2 = 0;
  dataCursor2 = (undefined4 *)0x519090;
  do {
    value = *(int *)((&g_FileDescriptorBlockTable)[(int)value2 >> 5] + (value2 & 0x1f) * 0x24);
    if ((value == -1) || (value == 0)) {
      *dataCursor2 = 0xffffffff;
    }
    dataCursor2 = dataCursor2 + 8;
    value2 = value2 + 1;
  } while ((int)dataCursor2 < 0x5190f0);
  return;
}

