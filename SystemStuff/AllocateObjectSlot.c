/* Address: 0x004B672F */

int AllocateObjectSlot(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  int local_8;
  int local_4;
  
  iVar4 = -1;
  MemAllocOrEnterCS(0x12);
  local_8 = 0;
  local_4 = 0;
  piVar3 = &DAT_00c47260;
  while (puVar2 = (undefined4 *)*piVar3, puVar1 = puVar2, puVar2 != (undefined4 *)0x0) {
    for (; puVar2 < puVar1 + 0x120; puVar2 = puVar2 + 9) {
      if ((*(byte *)(puVar2 + 1) & 1) == 0) {
        if (puVar2[2] == 0) {
          MemAllocOrEnterCS(0x11);
          if (puVar2[2] == 0) {
            InitializeCriticalSection((LPCRITICAL_SECTION)(puVar2 + 3));
            puVar2[2] = puVar2[2] + 1;
          }
          LeaveCSforObjectInTable(0x11);
        }
        EnterCriticalSection((LPCRITICAL_SECTION)(puVar2 + 3));
        if ((*(byte *)(puVar2 + 1) & 1) == 0) {
          *puVar2 = 0xffffffff;
          iVar4 = ((int)puVar2 - *piVar3) / 0x24 + local_4;
          if (iVar4 != -1) goto LAB_004b6841;
          break;
        }
        LeaveCriticalSection((LPCRITICAL_SECTION)(puVar2 + 3));
      }
      puVar1 = (undefined4 *)*piVar3;
    }
    local_4 = local_4 + 0x20;
    piVar3 = piVar3 + 1;
    local_8 = local_8 + 1;
    if (0xc4735f < (int)piVar3) goto LAB_004b6841;
  }
  puVar2 = AllocateIfNullThenInit_stub(0x480);
  if (puVar2 != (undefined4 *)0x0) {
    DAT_00c47360 = DAT_00c47360 + 0x20;
    (&DAT_00c47260)[local_8] = puVar2;
    puVar1 = puVar2;
    for (; puVar2 < puVar1 + 0x120; puVar2 = puVar2 + 9) {
      *(undefined1 *)(puVar2 + 1) = 0;
      *puVar2 = 0xffffffff;
      puVar2[2] = 0;
      *(undefined1 *)((int)puVar2 + 5) = 10;
      puVar1 = (undefined4 *)(&DAT_00c47260)[local_8];
    }
    iVar4 = local_8 << 5;
    EnsureObjectCriticalSectionAndEnter(iVar4);
  }
LAB_004b6841:
  LeaveCSforObjectInTable(0x12);
  return iVar4;
}

