/* Address: 0x0049A620 */

int AppendMenuEgfPath(char *param_1)

{
  int iVar1;
  char cVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = 0;
  iVar4 = 0;
  iVar5 = 0;
  cVar2 = *param_1;
  while (cVar2 != '\0') {
    bVar3 = (byte)iVar4;
    iVar4 = iVar4 + 8;
    iVar6 = iVar6 + ((int)cVar2 << (bVar3 & 0x1f));
    if (0x18 < iVar4) {
      iVar4 = 0;
    }
    iVar1 = iVar5 + 1;
    iVar5 = iVar5 + 1;
    cVar2 = param_1[iVar1];
  }
  return iVar6 + iVar5;
}

