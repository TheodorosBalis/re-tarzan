// Address: 0x004AF270

undefined4 FileLoadedEpilogueWithCS(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if ((*(byte *)(param_1 + 0xc) & 0x40) == 0) {
    EnterCSForIndex(param_1);
    uVar1 = FileLoadedEpilogue(param_1);
    LeaveCSForIndex(param_1);
  }
  else {
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  return uVar1;
}


