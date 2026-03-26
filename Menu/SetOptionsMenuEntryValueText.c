// Address: 0x0049F200

void SetOptionsMenuEntryValueText(int *param_1,char *param_2)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  char cVar5;
  
  if (param_2 != (char *)0x0) {
    iVar3 = 0;
    pcVar1 = (char *)*param_1;
    cVar5 = *pcVar1;
    while (cVar5 != '\0') {
      if (cVar5 == ':') {
        iVar3 = iVar3 + 2;
        goto LAB_0049f22e;
      }
      iVar2 = iVar3 + 1;
      iVar3 = iVar3 + 1;
      cVar5 = pcVar1[iVar2];
    }
    iVar3 = 0;
LAB_0049f22e:
    pcVar4 = pcVar1 + iVar3;
    cVar5 = pcVar1[iVar3];
    while (cVar5 != '\0') {
      cVar5 = *param_2;
      if (cVar5 == '\0') {
        cVar5 = ' ';
      }
      else {
        param_2 = param_2 + 1;
      }
      *pcVar4 = cVar5;
      iVar3 = iVar3 + 1;
      pcVar4 = (char *)(*param_1 + iVar3);
      cVar5 = *pcVar4;
    }
  }
  return;
}


