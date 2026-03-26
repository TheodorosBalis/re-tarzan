// Address: 0x0049A8C0

undefined4
CopyVirtualGameFileRangeIntoBuffer
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  iVar1 = GetVirtualGameFileSizeByPath(param_1);
  if ((param_4 < 0) || (iVar1 < param_4)) {
    param_4 = iVar1;
  }
  uVar2 = OpenVirtualGameFileByPath(param_1,&DAT_005156bc);
  SeekVirtualGameFileHandle(uVar2,param_3,0);
  uVar3 = ReadVirtualGameFileIntoBuffer(param_2,1,param_4,uVar2);
  CloseVirtualGameFileHandle(uVar2);
  return uVar3;
}


