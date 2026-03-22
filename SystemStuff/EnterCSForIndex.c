/* Address: 0x004B0B56 */

void EnterCSForIndex(uint param_1)

{
  if ((0x51907f < param_1) && (param_1 < 0x5192e1)) {
    MemAllocOrEnterCS(((int)(param_1 - 0x519080) >> 5) + 0x1c);
    return;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x20));
  return;
}

