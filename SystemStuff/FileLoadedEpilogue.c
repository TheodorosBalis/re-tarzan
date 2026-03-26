// Address: 0x004AF2A1

/* Library Function - Single Match
    __fclose_lk
   
   Library: Visual Studio 2003 Release */

undefined4 FileLoadedEpilogue(FILE *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0xffffffff;
  if ((param_1->_flag & 0x83) != 0) {
    uVar2 = FUN_004af8bc(param_1);
    AllocOrFreeMem(param_1);
    iVar1 = CheckToCloseHandleWithCS(param_1->_file);
    if (iVar1 < 0) {
      uVar2 = 0xffffffff;
    }
    else if (param_1->_tmpfname != (char *)0x0) {
      AllocOrFreeMemOnHeapPTR(param_1->_tmpfname);
      param_1->_tmpfname = (char *)0x0;
    }
  }
  param_1->_flag = 0;
  return uVar2;
}


