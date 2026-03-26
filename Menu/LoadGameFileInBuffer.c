// Address: 0x004AF523

undefined4
LoadGameFileInBuffer(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  EnterCSForIndex(param_4);
  uVar1 = LoadGameFileInMem2(param_1,param_2,param_3,param_4);
  LeaveCSForIndex(param_4);
  return uVar1;
}


