/* Address: 0x004B6852 */

undefined4 SetOsHandleForFileDescriptor(uint param_1,HANDLE param_2)

{
  undefined4 *puVar1;
  int iVar2;
  DWORD nStdHandle;
  
  if (param_1 < DAT_00c47360) {
    iVar2 = (param_1 & 0x1f) * 0x24;
    if (*(int *)((&DAT_00c47260)[(int)param_1 >> 5] + iVar2) == -1) {
      if (DAT_00519064 == 1) {
        if (param_1 == 0) {
          nStdHandle = 0xfffffff6;
        }
        else if (param_1 == 1) {
          nStdHandle = 0xfffffff5;
        }
        else {
          if (param_1 != 2) goto LAB_004b68ab;
          nStdHandle = 0xfffffff4;
        }
        SetStdHandle(nStdHandle,param_2);
      }
LAB_004b68ab:
      *(HANDLE *)((&DAT_00c47260)[(int)param_1 >> 5] + iVar2) = param_2;
      return 0;
    }
  }
  puVar1 = (undefined4 *)GetOrCreateTlsBlock_Stub2();
  *puVar1 = 9;
  puVar1 = (undefined4 *)GetOrCreateTlsBlock_stub3();
  *puVar1 = 0;
  return 0xffffffff;
}

