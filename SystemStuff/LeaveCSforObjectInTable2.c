/* Address: 0x004B69EE */

void LeaveCSforObjectInTable2(uint param_1)

{
  LeaveCriticalSection
            ((LPCRITICAL_SECTION)
             ((&DAT_00c47260)[(int)param_1 >> 5] + 0xc + (param_1 & 0x1f) * 0x24));
  return;
}

