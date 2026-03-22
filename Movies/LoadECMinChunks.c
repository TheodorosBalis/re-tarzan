/* Address: 0x00494620 */

undefined4 LoadECMinChunks(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  bool bVar5;
  char *in_stack_00004014;
  
  SafeCheckStackPtr();
  if ((in_stack_00004014 == (char *)0x0) || (*in_stack_00004014 == '\0')) {
    return 0xfffffffd;
  }
  iVar1 = FetchAndGetHwdForGameFile(in_stack_00004014,&DAT_005156bc);
  if (iVar1 == 0) {
    return 0xfffffffe;
  }
  FUN_004af7bd(iVar1);
  DAT_0053a320 = 0;
  DAT_0053a328 = 0;
  DAT_0053a32c = 0;
  iVar2 = LoadGameFileInBuffer(&stack0x00000000,1,0x4010,iVar1);
  do {
    if (iVar2 < 1) {
      DAT_0053a328 = DAT_0053a328 ^ DAT_00515700;
      DAT_0053a32c = DAT_0053a32c ^ DAT_00515704;
      FileLoadedEpilogueWithCS(iVar1);
      return 0;
    }
    SetFilePTRofEfGFilewithCS(iVar1,1,0xfffffff0);
    uVar4 = iVar2 - 0x10;
    bVar5 = CARRY4(DAT_0053a328,uVar4);
    DAT_0053a328 = DAT_0053a328 + uVar4;
    DAT_0053a32c = DAT_0053a32c + ((int)uVar4 >> 0x1f) + (uint)bVar5;
    iVar2 = 0;
    if (0 < (int)uVar4) {
      do {
        if ((*(uint *)(&stack0x00000000 + iVar2) == DAT_00515700) &&
           (*(uint *)(&stack0x00000004 + iVar2) == DAT_00515704)) {
          if (DAT_0053a320 != 0) {
            return 0xfffffffb;
          }
          iVar3 = FUN_004af63a(iVar1);
          DAT_0053a320 = iVar3 + -8 + (iVar2 - uVar4);
          SetFilePTRofEfGFilewithCS(iVar1,0,DAT_0053a320 + 8);
          break;
        }
        bVar5 = CARRY4(DAT_0053a328,*(uint *)(&stack0x00000000 + iVar2));
        DAT_0053a328 = DAT_0053a328 + *(uint *)(&stack0x00000000 + iVar2);
        DAT_0053a32c = DAT_0053a32c + bVar5;
        iVar2 = iVar2 + 1;
      } while (iVar2 < (int)uVar4);
    }
    iVar2 = LoadGameFileInBuffer(&stack0x00000000,1,0x4010,iVar1);
  } while( true );
}

