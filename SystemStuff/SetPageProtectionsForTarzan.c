/* Address: 0x004A2120 */

undefined4 SetPageProtectionsForTarzan(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  bool bVar2;
  _union_530 _Var3;
  SIZE_T SVar4;
  BOOL BVar5;
  DWORD local_28;
  _union_530 local_24;
  int local_20;
  int local_18;
  int local_14;
  uint local_10;
  
  if (DAT_0077c77c == 0) {
    GetSystemInfo((LPSYSTEM_INFO)&local_24.s);
    DAT_0077c77c = local_20;
  }
  puVar1 = (undefined4 *)((int)param_1 + param_2);
  if (puVar1 <= param_1) {
    return 1;
  }
  do {
    SVar4 = VirtualQuery(param_1,(PMEMORY_BASIC_INFORMATION)&local_24.s,0x1c);
    if (SVar4 != 0x1c) {
      return 0;
    }
    param_1 = (undefined4 *)(local_18 + local_24.dwOemId);
    if (puVar1 < (undefined4 *)(local_18 + local_24.dwOemId)) {
      param_1 = puVar1;
    }
    if (((local_14 == 0x1000) && ((local_10 & 0x100) == 0)) && (local_10 != 1)) {
      if ((local_10 == 8) || (local_10 == 0x80)) {
        bVar2 = false;
        _Var3 = local_24;
      }
      else {
        bVar2 = true;
        BVar5 = VirtualProtect((LPVOID)local_24,(int)param_1 - (int)local_24,0x40,&local_28);
        if (BVar5 == 0) {
          return 0;
        }
        _Var3 = local_24;
        if (local_28 != local_10) {
          VirtualProtect((LPVOID)local_24,(int)param_1 - (int)local_24,local_28,&local_28);
          return 0;
        }
      }
      for (; _Var3.dwOemId < param_1; _Var3.dwOemId = _Var3.dwOemId + DAT_0077c77c) {
        *(undefined4 *)_Var3 = *(undefined4 *)_Var3;
      }
      if ((bVar2) &&
         (BVar5 = VirtualProtect((LPVOID)local_24,(int)param_1 - (int)local_24,local_10,&local_28),
         BVar5 == 0)) {
        return 0;
      }
    }
    if (puVar1 <= param_1) {
      return 1;
    }
  } while( true );
}

