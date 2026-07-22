#include "tarzan_ghidra_types.hpp"

// Address: 0x004A9380
// Label: RebuildSortedRenderPacketTable
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void RebuildSortedRenderPacketTable(void)

{
  ushort *dataCursor;
  ushort value3;
  short *value4;
  int value;
  ushort *dataCursor2;
  int value2;
  undefined4 *dataCursor3;
  
  value2 = g_RenderPacketCount;
  if (0 < g_RenderPacketCount) {
    dataCursor2 = &g_SortedRenderPacketFlags;
    value = g_RenderPacketCount;
    do {
      value = value + -1;
      *dataCursor2 = (&g_RenderPacketSortTable)[*dataCursor2];
      dataCursor2 = dataCursor2 + 0x1e;
    } while (value != 0);
  }
  dataCursor3 = &g_RenderPacketSortBucketCounts;
  for (value = 0x400; value != 0; value = value + -1) {
    *dataCursor3 = 0;
    dataCursor3 = dataCursor3 + 1;
  }
  if (0 < value2) {
    dataCursor2 = &g_SortedRenderPacketFlags;
    value = value2;
    do {
      value3 = *dataCursor2;
      dataCursor2 = dataCursor2 + 0x1e;
      value4 = (short *)((int)&g_RenderPacketSortBucketCounts + (uint)value3 * 2);
      *value4 = *value4 + 1;
      value = value + -1;
    } while (value != 0);
  }
  value4 = (short *)((int)&g_RenderPacketSortBucketCounts + 2);
  do {
    *value4 = *value4 + value4[-1];
    value4 = value4 + 1;
  } while ((int)value4 < 0xa05a80);
  if (-1 < value2 + -1) {
    dataCursor2 = &g_SortedRenderPacketFlags + (value2 + -1) * 0x1e;
    do {
      dataCursor = dataCursor2 + -0x1b;
      value3 = *dataCursor2;
      dataCursor2 = dataCursor2 + -0x1e;
      value4 = (short *)((int)&g_RenderPacketSortBucketCounts + (uint)value3 * 2);
      *value4 = *value4 + -1;
      value2 = value2 + -1;
      *(ushort **)
       (&g_SortedRenderPacketPointerTable +
       (uint)*(ushort *)((int)&g_RenderPacketSortBucketCounts + (uint)value3 * 2) * 4) = dataCursor;
    } while (value2 != 0);
  }
  return;
}

