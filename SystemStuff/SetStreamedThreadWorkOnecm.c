// Address: 0x00497E10

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint SetStreamedThreadWorkOnecm(undefined4 param_1,int *param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 *local_4;
  
  FUN_00498430();
  DAT_00719da4 = 0;
  if ((int)param_4 < 1) {
    param_4 = 1;
  }
  DAT_00719d7c = FetchAndGetHwdForGameFile(param_1,&DAT_005156bc);
  if (((DAT_00719d7c != 0) &&
      (iVar2 = LoadGameFileInBuffer(&DAT_00718f60,0xe18,1,DAT_00719d7c), iVar2 == 1)) &&
     ((*(byte *)(DAT_00719d7c + 0xc) & 0x20) == 0)) {
    if (DAT_00718f64 % 0xf == 0) {
      DAT_00718f64 = DAT_00718f64 - 1;
    }
    if ((DAT_00718f60 == 0x24d4345) && (param_4 < DAT_00718f64)) {
      local_8 = 0;
      local_4 = &local_24;
      _DAT_00719d88 = param_2;
      local_24 = 0x10001;
      local_20 = 0x5622;
      local_18 = 0x100002;
      local_1c = 0xac44;
      local_14 = 0x14;
      local_10 = 0x10090;
      local_c = 0x2b110;
      DAT_00719d8c = (int *)0x0;
      if ((param_2 != (int *)0x0) &&
         ((**(code **)(*param_2 + 0xc))(param_2,&local_14,&DAT_00719d8c,0), piVar4 = DAT_00719d8c,
         DAT_00719d8c != (int *)0x0)) {
        DAT_00719da0 = ConvertFpuTopToInt64();
        (**(code **)(*piVar4 + 0x34))(piVar4,0);
        (**(code **)(*DAT_00719d8c + 0x44))(DAT_00719d8c,0);
        (**(code **)(*DAT_00719d8c + 0x40))(DAT_00719d8c,0);
        (**(code **)(*DAT_00719d8c + 0x3c))(DAT_00719d8c,DAT_00719da0);
        FUN_004a8ef0(DAT_00719d8c,0);
      }
      DAT_00719d80 = param_4 - 1;
      iVar2 = (int)(param_4 - 1) / 0xf;
      if ((iVar2 != 0) && (iVar3 = 0, 0 < iVar2)) {
        piVar4 = &DAT_00718f68;
        do {
          iVar1 = *piVar4;
          piVar4 = piVar4 + 1;
          iVar3 = iVar3 + iVar1;
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
        if (0 < iVar3) {
          SetFilePTRofEfGFilewithCS(DAT_00719d7c,iVar3,1);
        }
      }
      DAT_00719d94 = 0;
      DAT_00719d90 = 1;
      DAT_00515848 = 0xffffffff;
      DAT_0051584c = 0;
      DAT_00719da8 = 1;
      DAT_00719d9c = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,StreamedThreadEntry,(LPVOID)0x0,0,
                                  (LPDWORD)&DAT_00719d98);
      if (DAT_00719d9c == (HANDLE)0x0) {
        DAT_00719da8 = 0;
        FUN_00498430();
        return 0;
      }
      SynchronizeWithStreamedThread(1);
      iVar2 = 0;
      if (DAT_00719da8 != 0) {
        do {
          if (4999 < iVar2) goto LAB_004980c1;
          Sleep(100);
          iVar2 = iVar2 + 100;
        } while (DAT_00719da8 != 0);
        if (4999 < iVar2) {
LAB_004980c1:
          FUN_00498430();
          return 0;
        }
      }
      return DAT_00718f64;
    }
  }
  FUN_00498430();
  return 0;
}


