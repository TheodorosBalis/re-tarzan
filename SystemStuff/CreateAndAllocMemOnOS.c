/* Address: 0x004B273B */

undefined4 CreateAndAllocMemOnOS(int param_1)

{
  int iVar1;
  
  newHeapPTR = HeapCreate((uint)(param_1 == 0),0x1000,0);
  if (newHeapPTR != (HANDLE)0x0) {
    OsVerResult = GetOSresult();
    if (OsVerResult == 3) {
      iVar1 = MemoryAlloc(0x3f8);
    }
    else {
      if (OsVerResult != 2) {
        return 1;
      }
      iVar1 = ShouldAllocateVirtualToo();
    }
    if (iVar1 != 0) {
      return 1;
    }
    HeapDestroy(newHeapPTR);
  }
  return 0;
}

