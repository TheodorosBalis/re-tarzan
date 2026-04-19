// 0x004398e0

void RebuildModelHeapStats(int param_1)

{
  int iVar1;
  
  _g_ModelHeapLargestFreeBlockBytes = 0;
  iVar1 = *(int *)(param_1 + 4);
  _g_ModelHeapTotalFreeBytes = 0;
  g_ModelHeapFreeBlockCount = 0;
  for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x14)) {
    g_ModelHeapFreeBlockCount = g_ModelHeapFreeBlockCount + 1;
    _g_ModelHeapLargestFreeBlockBytes = *(int *)(iVar1 + 8) * 4;
    _g_ModelHeapTotalFreeBytes = _g_ModelHeapTotalFreeBytes + _g_ModelHeapLargestFreeBlockBytes;
  }
  return;
}