// Address: 0x0049A880

undefined4 GetVirtualGameFileSizeByPath(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = OpenVirtualGameFileByPath(param_1,&DAT_005156bc);
  SeekVirtualGameFileHandle(uVar1,0,2);
  uVar2 = GetVirtualGameFileOffset(uVar1);
  CloseVirtualGameFileHandle(uVar1);
  return uVar2;
}


