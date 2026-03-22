/* Address: 0x004B0BA8 */

void LeaveCSForIndex(uint param_1)

{
  if ((0x51907f < param_1) && (param_1 < 0x5192e1)) {
    LeaveCSforObjectInTable(((int)(param_1 - 0x519080) >> 5) + 0x1c);
    return;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x20));
  return;
}

