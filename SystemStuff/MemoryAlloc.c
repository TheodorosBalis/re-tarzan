// Address: 0x004B2798

undefined4 MemoryAlloc(undefined4 param_1)

{
  mallocPTR = HeapAlloc(newHeapPTR,0,0x140);
  if (mallocPTR == (LPVOID)0x0) {
    return 0;
  }
  DAT_00c47234 = 0;
  DAT_00c47238 = 0;
  DAT_00c47230 = mallocPTR;
  DAT_00c47240 = param_1;
  DAT_00c47228 = 0x10;
  return 1;
}


