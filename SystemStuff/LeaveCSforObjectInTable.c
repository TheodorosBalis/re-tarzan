/* Address: 0x004B1CCD */

void LeaveCSforObjectInTable(int param_1)

{
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)(&DAT_0051948c + param_1 * 4));
  return;
}

