// Address: 0x004AF46A

undefined4 SetFilePTRofEfGFilewithCS(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  EnterCSForIndex(param_1);
  uVar1 = SetFilePTRofEfGFile(param_1,param_2,param_3);
  LeaveCSForIndex(param_1);
  return uVar1;
}


