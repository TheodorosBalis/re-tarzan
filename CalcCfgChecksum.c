/* Address: 0x00494880 */

int CalcCfgChecksum(void)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 0x43464733;
  uVar1 = 4;
  do {
    iVar2 = iVar2 + ((int)*(char *)((int)&tarzanCFGbuffer + uVar1) <<
                    (sbyte)((ulonglong)uVar1 % 0x17));
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0xb8);
  return iVar2;
}

