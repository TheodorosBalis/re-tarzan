/* Address: 0x004B0BD7 */

void LeaveIndexedCriticalSection(int param_1,int param_2)

{
  if (param_1 < 0x14) {
    LeaveCSforObjectInTable(param_1 + 0x1c);
    return;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_2 + 0x20));
  return;
}

