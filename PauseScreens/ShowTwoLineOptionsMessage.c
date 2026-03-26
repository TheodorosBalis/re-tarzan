// Address: 0x0049E8B0

void ShowTwoLineOptionsMessage(char *param_1,char *param_2)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
  uVar2 = 0xffffffff;
  pcVar4 = param_1;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  if (~uVar2 - 1 < 0x29) {
    uVar2 = 0xffffffff;
    pcVar4 = param_2;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    if (~uVar2 - 1 < 0x29) {
      SetOptionsMenu(0xe);
      uVar2 = 0xffffffff;
      do {
        pcVar4 = param_1;
        if (uVar2 == 0) break;
        uVar2 = uVar2 - 1;
        pcVar4 = param_1 + 1;
        cVar1 = *param_1;
        param_1 = pcVar4;
      } while (cVar1 != '\0');
      uVar2 = ~uVar2;
      pcVar4 = pcVar4 + -uVar2;
      pcVar5 = PTR_s_a23456789_123456789_123456789_12_00516470;
      for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
        *(undefined4 *)pcVar5 = *(undefined4 *)pcVar4;
        pcVar4 = pcVar4 + 4;
        pcVar5 = pcVar5 + 4;
      }
      for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
        *pcVar5 = *pcVar4;
        pcVar4 = pcVar4 + 1;
        pcVar5 = pcVar5 + 1;
      }
      uVar2 = 0xffffffff;
      do {
        pcVar4 = param_2;
        if (uVar2 == 0) break;
        uVar2 = uVar2 - 1;
        pcVar4 = param_2 + 1;
        cVar1 = *param_2;
        param_2 = pcVar4;
      } while (cVar1 != '\0');
      uVar2 = ~uVar2;
      pcVar4 = pcVar4 + -uVar2;
      pcVar5 = PTR_s_b23456789_123456789_123456789_12_00516478;
      for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
        *(undefined4 *)pcVar5 = *(undefined4 *)pcVar4;
        pcVar4 = pcVar4 + 4;
        pcVar5 = pcVar5 + 4;
      }
      for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
        *pcVar5 = *pcVar4;
        pcVar4 = pcVar4 + 1;
        pcVar5 = pcVar5 + 1;
      }
    }
  }
  return;
}


