/* Address: 0x004B14B5 */

undefined4 * InitializeObjectTable(void)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  undefined4 *puVar4;
  
  puVar4 = (undefined4 *)0x0;
  MemAllocOrEnterCS(2);
  iVar3 = 0;
  if (0 < DAT_00c48380) {
    do {
      iVar1 = *(int *)(DAT_00c47364 + iVar3 * 4);
      if (iVar1 == 0) {
        iVar3 = iVar3 * 4;
        pvVar2 = AllocateIfNullThenInit_stub(0x38);
        *(void **)(iVar3 + DAT_00c47364) = pvVar2;
        if (*(int *)(iVar3 + DAT_00c47364) != 0) {
          InitializeCriticalSection((LPCRITICAL_SECTION)(*(int *)(iVar3 + DAT_00c47364) + 0x20));
          EnterCriticalSection((LPCRITICAL_SECTION)(*(int *)(iVar3 + DAT_00c47364) + 0x20));
          puVar4 = *(undefined4 **)(iVar3 + DAT_00c47364);
LAB_004b1559:
          if (puVar4 != (undefined4 *)0x0) {
            puVar4[4] = 0xffffffff;
            puVar4[1] = 0;
            puVar4[3] = 0;
            puVar4[2] = 0;
            *puVar4 = 0;
            puVar4[7] = 0;
          }
        }
        break;
      }
      if ((*(byte *)(iVar1 + 0xc) & 0x83) == 0) {
        EnterIndexedCriticalSection(iVar3,iVar1);
        iVar1 = *(int *)(DAT_00c47364 + iVar3 * 4);
        if ((*(byte *)(iVar1 + 0xc) & 0x83) == 0) {
          puVar4 = *(undefined4 **)(DAT_00c47364 + iVar3 * 4);
          goto LAB_004b1559;
        }
        LeaveIndexedCriticalSection(iVar3,iVar1);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < DAT_00c48380);
  }
  LeaveCSforObjectInTable(2);
  return puVar4;
}

