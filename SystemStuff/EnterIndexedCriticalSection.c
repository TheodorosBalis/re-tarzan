// Address: 0x004B0B85

void EnterIndexedCriticalSection(int param_1,int param_2)

{
  if (param_1 < 0x14) {
    MemAllocOrEnterCS(param_1 + 0x1c);
    return;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(param_2 + 0x20));
  return;
}


