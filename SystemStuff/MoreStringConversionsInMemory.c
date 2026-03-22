/* Address: 0x004B55E3 */

byte * MoreStringConversionsInMemory(void)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  
  if (DAT_00c4838c == 0) {
    ConvertStringBuffersIfNeeded();
  }
  bVar1 = *EXEfilePath;
  pbVar4 = EXEfilePath;
  if (bVar1 == 0x22) {
    while( true ) {
      pbVar3 = pbVar4;
      bVar1 = pbVar3[1];
      pbVar4 = pbVar3 + 1;
      if ((bVar1 == 0x22) || (bVar1 == 0)) break;
      iVar2 = FUN_004b756d(bVar1);
      if (iVar2 != 0) {
        pbVar4 = pbVar3 + 2;
      }
    }
    if (*pbVar4 == 0x22) goto LAB_004b5620;
  }
  else {
    while (0x20 < bVar1) {
      bVar1 = pbVar4[1];
      pbVar4 = pbVar4 + 1;
    }
  }
  for (; (*pbVar4 != 0 && (*pbVar4 < 0x21)); pbVar4 = pbVar4 + 1) {
LAB_004b5620:
  }
  return pbVar4;
}

